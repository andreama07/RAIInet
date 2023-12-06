#include "graphicsdisplay.h"
#include "cell.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(Xwindow &xw, int n) : xw(xw), gridSize(n), theDisplay(n, vector<bool>(n, false)) {
    // Initialize with all cells off (WHITE)
    // Rounding up in the case where there's a remainder 
    cellSize = 500 / n + (500 % n != 0 ? 1 : 0);
}

void GraphicsDisplay::notify(Cell & c) {
    int row = c.getRow();
    int col = c.getCol();
    bool state = c.getState();
    theDisplay[row][col] = state;
    
    // Calculate position and size of the cell in the window
    int x = col * cellSize;
    int y = row * cellSize;

    // Choose color based on the state of the cell (True = Black, False = White)
    int color = state ? Xwindow::Black : Xwindow::White;

    // Fill only the cell that changed 
    xw.fillRectangle(x, y, cellSize, cellSize, color);
}

GraphicsDisplay::~GraphicsDisplay() {}

SubscriptionType GraphicsDisplay::subType() {
  return SubscriptionType::All;
}

// clears the graphical display when needed and makes a new one
void GraphicsDisplay::clearDisplay() {
    theDisplay.clear();
    theDisplay.resize(gridSize, std::vector<bool>(gridSize, false));
    draw(); // Optionally redraw the cleared display
}

// draws the entire grid 
void GraphicsDisplay::draw() {
    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < gridSize; ++col) {
            int color = theDisplay[row][col] ? Xwindow::Black : Xwindow::White;
            xw.fillRectangle(col * cellSize, row * cellSize, cellSize, cellSize, color);
        }
    }
}
