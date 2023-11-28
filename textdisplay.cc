#include <iostream>
#include "textdisplay.h"
// will need to include board or link

using namespace std;

TextDisplay::TextDisplay(int n) : boardSize{n} {
  for (int i = 0; i < n; i++) {
    vector<char> row;
    theDisplay.emplace_back(row);
    for (int j = 0; j < n; j++) {
      theDisplay.at(i).emplace_back('_');
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
