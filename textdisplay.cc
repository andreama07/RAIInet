#include <iostream>
#include "textdisplay.h"
// will need to include board or link

using namespace std;

TextDisplay::TextDisplay() : boardSize{8} {
  for (int i = 0; i < boardSize; i++) {
    vector<char> row;
    theDisplay.emplace_back(row);
    for (int j = 0; j < boardSize; j++) {
      theDisplay.at(i).emplace_back('.');
    }
  }
  for (int i = 0; i < boardSize; i++) { // sets player 1's side
    if (i == 3 || i == 4) {
      theDisplay.at(1).at(i) = i + 'a';
      theDisplay.at(0).at(i) = 'S';
    } else {
      theDisplay.at(0).at(i) = i + 'a';
    }
  }
  for (int i = 0; i < boardSize; i++) { // sets player 2's side
    if (i == 3 || i == 4) {
      theDisplay.at(6).at(i) = i + 'A';
      theDisplay.at(7).at(i) = 'S';
    } else {
      theDisplay.at(7).at(i) = i + 'A';
    }
  }
}

void TextDisplay::notify(Link &l) {
  // cout << "entered notify function in td" << endl;
  // implement the textdisplay
  // set old coordinates to an empty char
  int prevX = l.getPrevX();
  int prevY = l.getPrevY();
  char prevChar = theDisplay.at(prevX).at(prevY);
  theDisplay.at(prevX).at(prevY) = '.';
  // cout << "set old coords" << endl;

  // move link to new spot on td
  int curX = l.getXCoord();
  int curY = l.getYCoord();
  // cout << "new coords: " << curX << ", " << curY << endl; 
  theDisplay.at(curX).at(curY) = prevChar;
  // cout << "about to leave notify function" << endl;
}

TextDisplay::~TextDisplay() {
    // don't need to rly do anything rn cuz everything is just chars
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  // out << "entered td print function" << endl;
  for (int i = 0; i < td.boardSize; i++) {
    for (int j = 0; j < td.boardSize; j++) {
      out << td.theDisplay.at(i).at(j);
    }
    out << endl;
  }
  return out;
}
