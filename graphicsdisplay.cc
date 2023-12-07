#include "graphicsdisplay.h"
#include "firewall.h"
#include "link.h"
#include <vector>
#include <string>

using namespace std;

GraphicsDisplay::GraphicsDisplay() : boardSize(8) {
  // Initialize with all cells off (WHITE)
  // Rounding up in the case where there's a remainder 
  linkSize = 500 / boardSize + (500 % boardSize != 0 ? 1 : 0);
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      theGraphic.fillRectangle(i*linkSize, j*linkSize, linkSize, linkSize, 0); // colours all squares white to start
    }
  }
  for (int i = 0; i < boardSize; i++) { // sets player 1's side
    if (i == 3 || i == 4) {
      theGraphic.fillRectangle(i*linkSize, 1*linkSize, linkSize, linkSize, 1); // colours links black
      theGraphic.fillRectangle(i*linkSize, 0, linkSize, linkSize, 4); // colours servers blue
    } else {
      theGraphic.fillRectangle(i*linkSize, 0, linkSize, linkSize, 1);
    }
  }
  for (int i = 0; i < boardSize; i++) { // sets player 2's side
    if (i == 3 || i == 4) {
      theGraphic.fillRectangle(i*linkSize, 6*linkSize, linkSize, linkSize, 1); // colours links black
      theGraphic.fillRectangle(i*linkSize, 7*linkSize, linkSize, linkSize, 4); // colours servers blue
    } else {
      theGraphic.fillRectangle(i*linkSize, 7*linkSize, linkSize, linkSize, 1);
    }
  }
}

void GraphicsDisplay::notify(Link & l, string action, char winner) {
    // int row = l.getRow();
    // int col = l.getCol();
    // bool state = c.getState();
    // theGraphic[row][col] = state;
    
    // Calculate position and size of the cell in the window
    /* int x = col * cellSize;
    int y = row * cellSize;

    // Choose color based on the state of the cell (True = Black, False = White)
    int color = state ? Xwindow::Black : Xwindow::White;

    // Fill only the cell that changed 
    xw.fillRectangle(x, y, cellSize, cellSize, color); */
}

GraphicsDisplay::~GraphicsDisplay() {}

