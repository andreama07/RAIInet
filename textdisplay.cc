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
}

void TextDisplay::notify(Link &l) {
  // implement the textdisplay
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
