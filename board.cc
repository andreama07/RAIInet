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
    link.setOwner(1);
    if (i == 3 || i == 4) {
      link.setCoords(1, i);
    } else {
      link.setCoords(0, i);
    }
    p1links.emplace_back(link);
  }
  for (int i = 0; i < boardSize; i++) { // sets player 2's 8 links
    Link link;
    link.setOwner(2);
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
  // add players (used for abilities and stats)
  p1 = new Player(1); 
  p2 = new Player(2);
  
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


void Board::moveLink(char link, string dir) {
  int linkNum, x, y, initiatingPlayer;
  if (playerTurn == 1) {
    linkNum = link - 'a';
    initiatingPlayer = 1;
    x = p1links.at(linkNum).getXCoord();
    y = p1links.at(linkNum).getYCoord();
    p1links.at(linkNum).setPrevCoords(x, y); // keeping track of coords before moving
    if (dir.compare("up") == 0) {
      x--;
    } else if (dir.compare("down") == 0) {
      x++;
    } else if (dir.compare("left") == 0) {
      y--;
    } else if (dir.compare("right") == 0) {
      y++;
    }
    p1links.at(linkNum).setCoords(x, y); // updating coords after moving
    td->notify(p1links.at(linkNum));
  } else {
    linkNum = link - 'A';
    initiatingPlayer = 2;
    x = p2links.at(linkNum).getXCoord();
    y = p2links.at(linkNum).getYCoord();
    p2links.at(linkNum).setPrevCoords(x, y); // keeping track of coords before moving
    if (dir.compare("up") == 0) {
      x--;
    } else if (dir.compare("down") == 0) {
      x++;
    } else if (dir.compare("left") == 0) {
      y--;
    } else if (dir.compare("right") == 0) {
      y++;
    }
    p2links.at(linkNum).setCoords(x, y); // updating coords after moving
    td->notify(p2links.at(linkNum));
  }
  
  // check for battle
  bool oppOccupied = false;
  int oppx, oppy, oppNum;
  if (playerTurn == 1) {
    linkNum = link - 'a';
    x = p1links.at(linkNum).getXCoord();
    y = p1links.at(linkNum).getYCoord();
    for (int i = 0; i < 8; i++) {
      oppx = p2links.at(i).getXCoord();
      oppy = p2links.at(i).getYCoord();
      if (x == oppx && y == oppy) {
        oppOccupied = true;
        oppNum = i;
        break;
      }
    }
  } else{
    linkNum = link - 'A';
    x = p2links.at(linkNum).getXCoord();
    y = p2links.at(linkNum).getYCoord();
    for (int i = 0; i < 8; i++) {
      oppx = p1links.at(i).getXCoord();
      oppy = p1links.at(i).getYCoord();
      if (x == oppx && y == oppy) {
        oppOccupied = true;
        oppNum = i;
        break;
      }
    }
  }

  //battle
  int mystrength;
  int oppstrength;
  if (oppOccupied) {
    // need to reveal links
    if (playerTurn == 1) {
      linkNum = link - 'a';
      mystrength = p1links.at(linkNum).getStrength();
      oppstrength = p2links.at(oppNum).getStrength();
      
      if (mystrength > oppstrength) { // p1 wins battle
        // download link of p2
      } else if (mystrength < oppstrength) { // p2 wins battle

      } else { // tie
        if (initiatingPlayer == 1) { // p1 wins battle

        } else { // p2 wins battle

        }
      }

    } else { //p2 turn
      linkNum = link - 'A';
      mystrength = p2links.at(linkNum).getStrength();
      oppstrength = p1links.at(oppNum).getStrength();

      if (mystrength > oppstrength) { // p2 wins battle
        // download link of p1
      } else if (mystrength < oppstrength) { // p1 wins battle

      } else { // tie
        if (initiatingPlayer == 2) { // p2 wins battle

        } else { // p1 wins battle

        }
      }
    }
  }
  cout << *this << endl;

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

bool Board::occupiedByOwn(int x, int y) const {
  bool occupied = false;
  if (playerTurn == 1) {
    for (long unsigned int i = 0; i < p1links.size(); i++) {
      if (p1links.at(i).getXCoord() == x && p1links.at(i).getYCoord() == y) {
        occupied = true;
      }
    }
  } else { // playerTurn == 2
    for (long unsigned int i = 0; i < p2links.size(); i++) {
      if (p2links.at(i).getXCoord() == x && p2links.at(i).getYCoord() == y) {
        occupied = true;
      }
    }
  }
  return occupied;
}

bool Board::isValidMove(char link, string dir) const {
  int linkNum, x, y;
  if (playerTurn == 1) {
    linkNum = link - 'a';
    x = p1links.at(linkNum).getXCoord();
    y = p1links.at(linkNum).getYCoord();
  } else {
    linkNum = link - 'A';
    x = p2links.at(linkNum).getXCoord();
    y = p2links.at(linkNum).getYCoord();
  }
  if (dir.compare("up") == 0) {
    x--;
    cout << "moving up: " << x << ", " << y << endl;
  } else if (dir.compare("down") == 0) {
    x++;
    cout << "moving down " << x << ", " << y << endl;
  } else if (dir.compare("left") == 0) {
    y--;
    cout << "moving left " << x << ", " << y << endl;
  } else if (dir.compare("right") == 0) {
    y++;
    cout << "moving right " << x << ", " << y << endl;
  }
  if (y < 0 || y >= boardSize || x < 0 || x >= boardSize) { // check if new position is within the board
    cout << "coords outside of board" << endl;
    return false;
  } else if (occupiedByOwn(x, y)) { // check if new position already has one of player's pieces
    cout << "occupiedByOwn" << endl;
    return false;
  }
  return true;
}

bool Board::isValidLink(char c) const {
  if (playerTurn == 1 && c >= 'a' && c <= 'h') {
    return true;
  } else if (playerTurn == 2 && c >= 'A' && c <= 'H') {
    return true;
  } else {
    return false;
  }
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
  out << endl << "========" << endl;
  out << *b.td; // printing out the board
  out << "========" << endl;
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

