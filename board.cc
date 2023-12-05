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
  delete p1;
  delete p2;
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
  p1 = new Player(1);
  p2 = new Player(2);
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

void Board::setPlayerTurn(int player) {
  playerTurn = player;
}

bool Board::getData(int playerNum, int linkNum) const {
  if (playerNum == 1) {
    return p1links.at(linkNum).getData();
  } else if (playerNum == 2) {
    return p2links.at(linkNum).getData();
  } else {
    cout << "invalid playerNum" << endl;
    return false;
  }
}

int Board::getStrength(int playerNum, int linkNum) const {
  if (playerNum == 1) {
    return p1links.at(linkNum).getStrength();
  } else if (playerNum == 2) {
    return p2links.at(linkNum).getStrength();
  } else {
    cout << "invalid playerNum" << endl;
    return 0;
  }
}

int Board::getPlayerTurn() const {
  return playerTurn;
}

Player* Board::getPlayer(int player) const {
  if (player == 1) {
    return p1; 
  } else { // player == 2
    return p2;
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

void Board::printLink(int playerNum, int linkNum, int playerTurn) const {
  if (playerNum == 1) {
    p1links.at(linkNum).print(playerTurn);
  } else if (playerNum == 2) {
    p2links.at(linkNum).print(playerTurn);
  } else {
    cout << "invalid playerNum" << endl;
  }
}

ostream &operator<<(ostream &out, const Board &b) { 
  // out << "entered board print function" << endl;
  out << "Player 1:" << endl; // printing out player 1 info
  out << "Downloaded: " << b.getPlayer(2)->getDownloadedDataCount() << "D, " << b.getPlayer(2)->getDownloadedVirusCount() << "V" << endl; 
  out << "Abilities: " << b.getPlayer(2)->getAbilityCount() << endl;
  if (b.getPlayerTurn() == 1) {
    for (int i = 0; i < 8; i++) { 
      out << char(i + 'a') << ": ";
      b.printLink(1, i, 1);
      if (i == 3) {
        out << endl;
      }
    }
  } else { // p2 turn
    for (int i = 0; i < 8; i++) { 
      cout << char(i + 'a') << ": ";
      b.printLink(1, i, 2);
      if (i == 3) {
        out << endl;
      }
    }
  }
  out << endl;
  out << *b.td;
  out << "Player 2:" << endl; // printing out player 2 info
  out << "Downloaded: " << b.getPlayer(2)->getDownloadedDataCount() << "D, " << b.getPlayer(2)->getDownloadedVirusCount() << "V" << endl; 
  out << "Abilities: " << b.getPlayer(2)->getAbilityCount() << endl;
  if (b.getPlayerTurn() == 1) {
    for (int i = 0; i < 8; i++) { 
      out << char(i + 'A') << ": ";
      b.printLink(2, i, 1);
      if (i == 3) {
        out << endl;
      }
    }
  } else { // p2 turn
    for (int i = 0; i < 8; i++) { 
      cout << char(i + 'A') << ": ";
      b.printLink(2, i, 2);
      if (i == 3) {
        out << endl;
      }
    }
  }
  
  return out;
}

