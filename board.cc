#include <iostream>
#include <vector>
#include "grid.h"
using namespace std;

Board::Board() {}

bool isWithinBounds(int x, int y) {
    // need a size filed
  if (x <= 8 && y <= 8) {
    return true;
  } else {
    return false;
  }
}

Board::~Board() { 
  for (int i = 0; i < boardSize; i++) {
    board.at(i).clear();
  }
  boardSize = 0;
  // delete td;
}

void Board::init() {
  // add links into the board


  // add observers?
  td = new TextDisplay(n);
  // need to attach as observers 
  // helloo
  
  
}

ostream &operator<<(ostream &out, const Grid &g) {
  // out << "entered board print function" << endl;
  out << *g.td;
  return out;
}


