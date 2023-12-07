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
    // cout << "entered notify function in td" << endl;
  // implement the textdisplay
  if (action.compare("moved") == 0) { // if link just moved, update on td
    // set old coordinates to an empty char
    int prevX = l.getPrevX();
    int prevY = l.getPrevY();
    theGraphic.fillRectangle(prevX*linkSize, prevY*linkSize, linkSize, linkSize, 0);

    // move link to new spot on td
    int curX = l.getXCoord();
    int curY = l.getYCoord();
    // cout << "new coords: " << curX << ", " << curY << endl; 
    if (l.getVisibility()) { // if visible
      if (l.getData()) { // if is data
        theGraphic.fillRectangle(curX*linkSize, curY*linkSize, linkSize, linkSize, 3);
      } else { // if is virus
        theGraphic.fillRectangle(curX*linkSize, curY*linkSize, linkSize, linkSize, 2);
      }
    } else { // not visible
      theGraphic.fillRectangle(curX*linkSize, curY*linkSize, linkSize, linkSize, 1); // set to black square
    }
  } else if (action.compare("downloaded") == 0) { // link just got downloaded, update on td
    int curX = l.getXCoord();
    int curY = l.getYCoord();
    theGraphic.fillRectangle(curX*linkSize, curY*linkSize, linkSize, linkSize, 0);
  } else if (action.compare("won") == 0) { // link just won a battle, update on td
    int curX = l.getXCoord();
    int curY = l.getYCoord();
    if (l.getData()) { // if is data
      theGraphic.fillRectangle(curX*linkSize, curY*linkSize, linkSize, linkSize, 3);
    } else { // if is virus
      theGraphic.fillRectangle(curX*linkSize, curY*linkSize, linkSize, linkSize, 2);
    }
  }
  // cout << "about to leave notify function" << endl;
}

GraphicsDisplay::~GraphicsDisplay() {}

