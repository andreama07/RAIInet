#include "graphicsdisplay.h"
#include "link.h"

const int White = 0;
const int Green = 1;
const int Red = 2;
const int Black = 3;
const int Blue = 4; // For Player 1 booster
const int Yellow = 5; // For Player 2 booster
const int Purple = 6; // Player 1 server 
const int Orange = 7; // Player 2 server



GraphicsDisplay::GraphicsDisplay(Xwindow &xw, int n) : xw(xw), boardSize(n), theGraphic(n, std::vector<int>(n, Xwindow::White)) {
    cellSize = 500 / n + (500 % n != 0 ? 1 : 0);
    xw.fillRectangle(0, 0, 80, 80, Xwindow::Blue); // Initialize the cell size
    // Rest of the constructor
}

void GraphicsDisplay::notify(Link &l, std::string action) {
  int x = l.getXCoord();
  int y = l.getYCoord();
  int prevX = l.getPrevX();
  int prevY = l.getPrevY();

  if (action == "moved") {
    // Clear the previous cell
    theGraphic[prevX][prevY] = White;

    // Draw the link at the new position
    int color = l.getData() ? Green : Red; // Green for data, red for virus
    if (!l.getVisibility()) color = Black; // Black if not visible
    if (l.isBoosted()) color = (l.getOwner()) ? Blue : Yellow; // Blue or Yellow if boosted

    theGraphic[x][y] = color;
  } else if (action == "downloaded") {
    theGraphic[x][y] = White; // Clear the cell if the link is downloaded
  }

  // Redraw the cell with the updated color
  xw.fillRectangle(x * cellSize, y * cellSize, cellSize, cellSize, theGraphic[x][y]);
}

GraphicsDisplay::~GraphicsDisplay() {}

void GraphicsDisplay::draw() {
  // Calculate middle positions for the servers
  int mid1 = boardSize / 2 - 1; // Middle position for Player 1's server
  int mid2 = boardSize / 2;     // Middle position for Player 2's server, assuming even number of cells

  for (int x = 0; x < boardSize; ++x) {
    for (int y = 0; y < boardSize; ++y) {
      // Check if we're at the server position for either player
      if (x == mid1 && y == mid1) {
        // Set Player 1's server to blue
        theGraphic[x][y] = Purple;
      } else if (x == mid2 && y == mid2) {
        // Set Player 2's server to yellow
        theGraphic[x][y] = Orange;
      }
      
      // Draw the cell
      xw.fillRectangle(x * cellSize, y * cellSize, cellSize, cellSize, theGraphic[x][y]);
    }
  }
}
