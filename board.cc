#include <iostream>
#include <vector>
#include <string>
#include "board.h"
using namespace std;

Board::Board() { // initializes the board 
  board.resize(boardSize, std::vector<Link*>(boardSize, nullptr)); 
  firewalls.resize(boardSize, std::vector<bool>(boardSize, false)); 
}

bool Board::isWithinBounds(int x, int y) const { // this function is done 
  // need a size filed
  return ((x <= boardSize - 1 && x >= 0) && (y <= boardSize - 1 && y >= 0));
}

Board::~Board() { // nothing might actually need to be done here as nothing uses "new"
  for (int i = 0; i < boardSize; i++) {
    board.at(i).clear();
  }
  boardSize = 0;
  // delete td;
}

void Board::init() { // might not actually need this 


  // add observers?
  //td = new TextDisplay(n);
  // need to attach as observers 
  // helloo

  
}

bool Board::placeLink(int x, int y, Link& link) {
  if (!isWithinBounds(x, y)) {
    return false; // out of bounds, might not be able to use placeLink when working with the download fucntion
  }

  if (isSquareOccupied(x,y)) {
    return false; // square is occupied, would need to use this for the battle function
  }

  board[x][y] = &link; 
  return true; 
}

int Board::moveLink(int startX, int startY, std::string dir) { // we are going to assume that the user is going to write up, down... or are we going by north, south...
  int endY = startY; 
  int endX = startX;


  if (dir == "up") {
    --endY; // prefix modifies the value immediately
  } else if (dir == "down") {
    ++endY;
  } else if (dir == "left") {
    --endX;
  } else if (dir == "right") {
    ++endX;
  } else {
    return 1; // no valid direction 
  } 


// Check if both start and end positions are within bounds
  if (!isValidPosition(endX, endY)) {
    return 2; // end position not valid
  }

  // Check if the starting position is occupied by a link
 // if (!isSquareOccupied(startX, startY)) {
 //   return false; // No link at the starting position
 // }

  // Handle the case where the destination is occupied
  if (isSquareOccupied(endX, endY)) {
    // battle will happen here
    return 3; // battle needs to occur 
  }

  // Move the link
  board[endX][endY] = board[startX][startY];
  board[startX][startY] = nullptr;
  return true;
} 

Link* Board::getLinkAt(int x, int y) {
  if (isWithinBounds(x, y)) {
    return board[x][y];
  }
  return nullptr;
}

void Board::removeLink(int x, int y) {
  if (isWithinBounds(x, y)) {
    board[x][y] = nullptr; 
  }
}

void Board::activateFirewall(int x, int y, int playerNumber) {
  if (isWithinBounds(x,y)) {
    firewall[x][y] = std::make_unique<Firewall>(x, y, playerNumber);
  }
}

bool Board::isFirewall(int x, int y) const {
  if (isWithinBounds(x, y)) {
    return firewalls[x][y];
  }
  return false;
}

bool Board::isSquareOccupied(int x, int y) const {
  return isWithinBounds(x,y) && board[x][y] != nullptr;
}

bool Board::isValidPosition(int x, int y) const {
  return ((x <= boardSize - 1 && x >= 0) && (y <= boardSize && y >= -1));
}

ostream &operator<<(ostream &out, const Board &g) { // Not done, still thinking about it 
  // out << "entered board print function" << endl;
  out << *g.td;
  return out;
}

