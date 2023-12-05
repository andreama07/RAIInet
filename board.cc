#include <iostream>
#include <vector>
#include <string>
#include "board.h"
using namespace std;

Board::Board() : boardSize{8}, td{nullptr} {}// sets default parameters of the board 


bool Board::isWithinBounds(int x, int y) const { // this function is done 
  // need a size filed
  return ((x <= boardSize - 1 && x >= 0) && (y <= boardSize - 1 && y >= 0));
}

Board::~Board() { // nothing might actually need to be done here as nothing uses "new"
  p1links.clear();
  p2links.clear();
  boardSize = 0;
  delete td;
}

void Board::init() { // initializes board with empty links and attaches textDisplay

  for (int i = 0; i < boardSize; i++) { // sets player 1's 8 links
    Link link;
    if (i == 3 || i == 4) {
      link.setCoords(1, i);
    } else {
      link.setCoords(0, i);
    }
    p1links.emplace_back(link);
  }
  for (int i = 0; i < boardSize; i++) { // sets player 2's 8 links
    Link link;
    if (i == 3 || i == 4) {
      link.setCoords(6, i);
    } else {
      link.setCoords(7, i);
    }
    p2links.emplace_back(link);
  }
  // add observers
  td = new TextDisplay();
  // gd = new GraphicDisplay();

  // need to attach as observers 


}

void Board::placeLink(int x, int y, Link& link) {
  if (!isWithinBounds(x, y)) {
    // return false; // out of bounds, might not be able to use placeLink when working with the download fucntion
  }

  if (isSquareOccupied(x,y)) {
    // return false; // square is occupied, would need to use this for the battle function
  }

}

void Board::setData(int playerNum, int linkNum, bool isData) {
  if (playerNum == 1) {
    p1links.at(linkNum).setData(isData);
  } else if (playerNum == 2) {
    p2links.at(linkNum).setData(isData);
  } else {
    cout << "invalid playerNum" << endl;
  }
}

void Board::setStrength(int playerNum, int linkNum, int strength) {
  if (playerNum == 1) {
    //cout << "strength in board: " << strength << endl;
    p1links.at(linkNum).setStrength(strength);
  } else if (playerNum == 2) {
    p2links.at(linkNum).setStrength(strength);
  } else {
    cout << "invalid playerNum" << endl;
  }
}


void Board::moveLink(int startX, int startY, string dir) {
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
    // return 1; 
    cout << "no valid direction given" << endl;
  } 


// Check if both start and end positions are within bounds
  if (!isValidPosition(endX, endY)) {
    // return 2; 
    cout << "end position not valid" << endl;
  }

  // Check if the starting position is occupied by a link
 // if (!isSquareOccupied(startX, startY)) {
 //   return false; // No link at the starting position
 // }

  // Handle the case where the destination is occupied
  if (isSquareOccupied(endX, endY)) {
    // battle will happen here
    // return 3; 
    cout << "battle needs to occur" << endl;
  }

  // Move the link
  // board[endX][endY] = board[startX][startY];
  // board[startX][startY] = nullptr;
  // return true;
} 

Link* Board::getLinkAt(int x, int y) {
  if (isWithinBounds(x, y)) {
    //return board[x][y];
  }
  return nullptr;
}

void Board::removeLink(int x, int y) {
  if (isWithinBounds(x, y)) {
    //board[x][y] = nullptr; 
  }
}

/* void Board::activateFirewall(int x, int y, int playerNumber) {
  if (isWithinBounds(x,y)) {
    firewall[x][y] = std::make_unique<Firewall>(x, y, playerNumber);
  }
} 

bool Board::isFirewall(int x, int y) const {
  if (isWithinBounds(x, y)) {
    return firewalls[x][y];
  }
  return false;
} */

bool Board::getData(int playerNum, int linkNum) {
  if (playerNum == 1) {
    return p1links.at(linkNum).getData();
  } else if (playerNum == 2) {
    return p2links.at(linkNum).getData();
  } else {
    cout << "invalid playerNum" << endl;
    return false;
  }
}

int Board::getStrength(int playerNum, int linkNum) {
  if (playerNum == 1) {
    return p1links.at(linkNum).getStrength();
  } else if (playerNum == 2) {
    return p2links.at(linkNum).getStrength();
  } else {
    cout << "invalid playerNum" << endl;
    return 0;
  }
}

bool Board::isSquareOccupied(int x, int y) const {
  // return isWithinBounds(x,y) && board[x][y] != nullptr;
  return false;
}

bool Board::isValidPosition(int x, int y) const {
  // return ((x <= boardSize - 1 && x >= 0) && (y <= boardSize && y >= -1));
  return true;
}

ostream &operator<<(ostream &out, const Board &g) { // Not done, still thinking about it 
  // out << "entered board print function" << endl;
  out << *g.td;
  return out;
}

