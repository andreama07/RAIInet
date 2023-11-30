#include <iostream>
#include <vector>
#include <string>
#include "board.h"
using namespace std;

Board::Board() { // initializes the board 
  board.resize(boardSize, std::vector<Link*>(boardSize, nullptr)); 
  firewalls.resize(boardSize, std::vector<bool>(boardSize, false)); 
}

bool Board::isWithinBounds(int x, int y) { // this function is done 
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

void Board::placeLink(int x, int y, Link& link) {
  if (!isWithinBounds(x, y)) {
    return false; // out of bounds, might not be able to use placeLink when working with the download fucntion
  }

  if (isSquareOccupied(x,y)) {
    return false; // square is occupied, would need to use this for the battle function
  }

  board[x][y] = &link; 
  return true; 
}

bool Board::moveLink(int startX, int startY, int endX, int endY, string dir) {
  // Check if both start and end positions are within bounds
  
  if (dir == "up") {
    endY++;
  } else if (dir == "down") {
    endY--;
  } else if (dir == "left") {
    endX--;
  } else if (dir == "right") {
    endX++;
  }

  int endY;
  int endX;
  if (dir == "up") {
    endY = startY++;
  } else if (dir == "down") {
    endY = startY--;
  } else if (dir == "left") {
    endX = endX--;
  } else if (dir == "right") {
    endX = endX++;
  }

  if (!isValidPosition(startX, startY) || !isValidPosition(endX, endY)) {
    return false; // position not valid
  }

  // Check if the starting position is occupied by a link
  if (!isSquareOccupied(startX, startY)) {
    return false; // No link at the starting position
  }

  // Handle the case where the destination is occupied
  if (isSquareOccupied(endX, endY)) {
    // battle will happen here
    return false;
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
    return board[x][y] = nullptr; 
  }
}

void Board::activateFirewall(int x, int y) {
  if (isWithinBounds(x,y)) {
    firewalls[x][y] = true;
  }
}

bool Board::isFirewall(int x, int y) {
  if (isWithinBounds) {
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

