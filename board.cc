#include <iostream>
#include <vector>
#include <string>
#include "board.h"

using namespace std;

Board::Board() : boardSize{8}, td{nullptr} {}// sets default parameters of the board 


bool Board::isWithinBounds(int x, int y) const {  // check that we are in the board
  return ((x <= boardSize - 1 && x >= 0) && (y <= boardSize - 1 && y >= 0));
}

Board::~Board() { // nothing uses "new"
  p1links.clear();
  p2links.clear();
  boardSize = 0;
  // td = nullptr;
  // p1 = nullptr;
  // p2 = nullptr;
}

void Board::init() { // initializes board with empty links and attaches textDisplay

    // default random links
    std::vector<string> links1 = { "v1", "v2", "v3", "v4", "d1", "d2", "d3", "d4"};
    std::vector<string> links2 = { "v1", "v2", "v3", "v4", "d1", "d2", "d3", "d4"};
    
    // make a default seed value that takes the systems current time
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    // make a random number using the default seed
    std::default_random_engine rng{seed};
    // shuffle 1000 times
    for ( int i = 0; i < 1000; i++ ) {
		  std::shuffle( links1.begin(), links1.end(), rng );
      std::shuffle( links2.begin(), links2.end(), rng );			
	  }

  for (int i = 0; i < boardSize; i++) { // sets player 1's 8 links
    Link link;
    link.setOwner(1);
    if (i == 3 || i == 4) {
      link.setCoords(1, i);
    } else {
      link.setCoords(0, i);
    }
    if (links1.at(i)[0] =='v') {
      link.setData(false);
    } else {
      link.setData(true);
    }
    link.setStrength(links1.at(i)[1] - '0');
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
    if (links2.at(i)[0] =='v') {
      link.setData(false);
    } else {
      link.setData(true);
    }
    link.setStrength(links2.at(i)[1] - '0');
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

void Board::linkBoost(char link, int abilityID) { 
  // Ensure linkNum is within bounds
  int linkNum;
  if (playerTurn == 1) {
    if (link >= 'a' && link <= 'h') {
      linkNum = link - 'a';
      p1links.at(linkNum).setBoosted();
      p1->decrementAbilityCount(); // used up one ability
      p1->setUsed(abilityID); // set the linkBoost ability to used
    } else {
      cout << "invalid link to boost" << endl;
    }
  } else { // player2 turn
    if (link >= 'A' && link <= 'H') {
      linkNum = link - 'A';
      p2links.at(linkNum).setBoosted();
      p2->decrementAbilityCount(); // used up one ability
      p2->setUsed(abilityID); // set the linkBoost ability to used
    } else {
      cout << "invalid link to boost" << endl;
    }
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
      if (p1links.at(linkNum).isBoosted()) {
        x-=2;
      } else {
        x--;
      }
    } else if (dir.compare("down") == 0) {
      if (p1links.at(linkNum).isBoosted()) {
        x+=2;
      } else {
        x++;
      }
    } else if (dir.compare("left") == 0) {
      if (p1links.at(linkNum).isBoosted()) {
        y-=2;
      } else {
        y--;
      }
    } else if (dir.compare("right") == 0) {
      if (p1links.at(linkNum).isBoosted()) {
        x+=2;
      } else {
        x++;
      }
    }
    // reached other side
    if (x == boardSize - 1) {
      // opponents server port
      if (y == 3 || y == 4) {
        // download link onto player 2
        download(linkNum + 'a', 2);
      } else {
        // download link to self
        download(linkNum + 'a', 1);
      }
    }
    p1links.at(linkNum).setCoords(x, y); // updating coords after moving
    td->notify(p1links.at(linkNum), "moved");
  } else {
    linkNum = link - 'A';
    initiatingPlayer = 2;
    x = p2links.at(linkNum).getXCoord();
    y = p2links.at(linkNum).getYCoord();
    p2links.at(linkNum).setPrevCoords(x, y); // keeping track of coords before moving
    if (dir.compare("up") == 0) {
      if (p2links.at(linkNum).isBoosted()) {
        x-=2;
      } else {
        x--;
      }
    } else if (dir.compare("down") == 0) {
      if (p2links.at(linkNum).isBoosted()) {
        x+=2;
      } else {
        x++;
      }
    } else if (dir.compare("left") == 0) {
      if (p2links.at(linkNum).isBoosted()) {
        y-=2;
      } else {
        y--;
      }
    } else if (dir.compare("right") == 0) {
      if (p2links.at(linkNum).isBoosted()) {
        y+=2;
      } else {
        y++;
      }
    }
    // reached other side
    if (x == 0) {
      // oponents server port
      if (y == 3 || y == 4) {
        // download link onto player 1
        download(linkNum + 'A', 1);
      } else {
        // download link to self
        download(linkNum + 'A', 2);
      }
    }
    p2links.at(linkNum).setCoords(x, y); // updating coords after moving
    td->notify(p2links.at(linkNum), "moved");
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
  } else {
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
        cout << "mystrength > oppstrength" << endl;
        download(oppNum + 'A', 1);
        td->notify(p1links.at(linkNum), "won");
      } else if (mystrength < oppstrength) { // p2 wins battle
        cout << "mystrength < oppstrength" << endl;
        download(linkNum + 'a', 2);
        td->notify(p2links.at(oppNum), "won");
      } else { // tie
        if (initiatingPlayer == 1) { // p1 wins battle
          cout << "tie but i moved" << endl;
          download(oppNum + 'A', 1);
          td->notify(p1links.at(linkNum), "won");
        } else { // p2 wins battle
          cout << "tie but they moved" << endl;
          download(linkNum + 'a', 2);
          td->notify(p2links.at(oppNum), "won");
        }
      }

    } else { //p2 turn
      linkNum = link - 'A';
      mystrength = p2links.at(linkNum).getStrength();
      oppstrength = p1links.at(oppNum).getStrength();

      if (mystrength > oppstrength) { // p2 wins battle
        // download link of p1
        cout << "mystrength > oppstrength" << endl;
        download(oppNum + 'a', 2);
        td->notify(p2links.at(linkNum), "won");
      } else if (mystrength < oppstrength) { // p1 wins battle
        cout << "mystrength < oppstrength" << endl;
        download(linkNum + 'A', 1);
        td->notify(p2links.at(oppNum), "won");
      } else { // tie
        if (initiatingPlayer == 2) { // p2 wins battle
          cout << "tie but i moved" << endl;
          download(oppNum + 'a', 2);
          td->notify(p2links.at(linkNum), "won");
        } else { // p1 wins battle
          cout << "tie but they moved" << endl;
          download(linkNum + 'A', 1);
          td->notify(p2links.at(oppNum), "won");
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

// check if new position is within the board  
  if (playerTurn == 1) {
    if (x < 0 || x > boardSize || y < 0 || y >= boardSize) {
      cout << "coords outside of board" << endl;
      return false;
    }
  } else { // player 2
    if (x < -1 || x >= boardSize || y < 0 || y >= boardSize) {
      cout << "coords outside of board" << endl;
      return false;
    }
  }

  if (occupiedByOwn(x, y)) { // check if new position already has one of player's pieces
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

void Board::download(char link, int player, int abilityID) {
  cout << "entered board download" << endl;
  int linkNum;

  if (abilityID == 0) { // used as a helper function, not an ability
    if (link >= 'A' && link <='H') {
      linkNum = link - 'A';
      if (!p2links.at(linkNum).getDownloaded()) { // if not already downloaded
        p2links.at(linkNum).setDownloaded(true); // download
        td->notify(p2links.at(linkNum), "downloaded"); // notify text display (will change to a dot)
        p2links.at(linkNum).setCoords(-1, -1); // set coords off board
        if (p2links.at(linkNum).getData()) { // if the downloaded link is a data
          if (player == 1) { // p1 downloads the data
            p1->incrementDownloadedData(); 
          } else { // p2 downloads the data
            p2->incrementDownloadedData();
          }
        } else { // if the downloaded link is a virus
          if (player == 1) { // p1 downloads the data
            p1->incrementDownloadedVirus(); 
          } else { // p2 downloads the data
            p2->incrementDownloadedVirus();
          }
        }
      } else {
        cout << "link is already downloaded" << endl;
      }
    } else if (link >= 'a'  && link <='h') {
      linkNum = link - 'a';
      if (!p1links.at(linkNum).getDownloaded()) { // if not already downloaded
        p1links.at(linkNum).setDownloaded(true); // download
        td->notify(p1links.at(linkNum), "downloaded"); // notify text display (will change to a dot)
        p1links.at(linkNum).setCoords(-1, -1); // set coords off board
        if (p1links.at(linkNum).getData()) { // if the downloaded link is a data
          if (player == 1) { // p1 downloads the data
            p1->incrementDownloadedData(); 
          } else { // p2 downloads the data
            p2->incrementDownloadedData();
          }
        } else { // if the downloaded link is a virus
          if (player == 1) { // p1 downloads the data
            p1->incrementDownloadedVirus(); 
          } else { // p2 downloads the data
            p2->incrementDownloadedVirus();
          }
        }
      } else {
        cout << "link is already downloaded" << endl;
      }
    } else {
      cout << "invalid link" << endl;
    }
  } else { // abilityID != 0 (one of the players is using an ability)
    if (playerTurn == 1) {
      if ((link >= 'A' && link <='H')) { // valid opponent link (need to check if already downloaded)
        // download and update player fields + td
        linkNum = link - 'A';
        if (!p2links.at(linkNum).getDownloaded()) { // if not already downloaded
          p2links.at(linkNum).setDownloaded(true); // download
          td->notify(p2links.at(linkNum), "downloaded"); // notify text display (will change to a dot)
          p2links.at(linkNum).setCoords(-1, -1); // set coords off board
          if (p2links.at(linkNum).getData()) { // if the downloaded link is a data
            p1->incrementDownloadedData();
          } else { // if the downloaded link is a virus
            p1->incrementDownloadedVirus();
          }
          p1->decrementAbilityCount(); // used up one ability
          p1->setUsed(abilityID); // set the download ability to used
        } else {
          cout << "link is already downloaded" << endl;
        }
      } else {
        cout << "invalid opponent link to download" << endl;
      }
    } else { // player2 turn
      if (link >= 'a'  && link <='h') { // valid opponent link (need to check if already downloaded)
        // download and update player fields + td
        linkNum = link - 'a';
        if (!p1links.at(linkNum).getDownloaded()) { // if not already downloaded
          p1links.at(linkNum).setDownloaded(true); // download
          td->notify(p1links.at(linkNum), "downloaded"); // notify text display (will change to a dot)
          p1links.at(linkNum).setCoords(-1, -1); // set coords off board
          if (p1links.at(linkNum).getData()) { // if the downloaded link is a data
            p2->incrementDownloadedData();
          } else { // if the downloaded link is a virus
            p2->incrementDownloadedVirus();
          }
          p2->decrementAbilityCount(); // used up one ability
          p2->setUsed(abilityID); // set the download ability to used
        } else {
          cout << "link is already downloaded" << endl;
        }
      } else {
        cout << "invalid opponent link to download" << endl;
      }
    }
  }
}

void Board::scan(char link, int abilityID) {
  int linkNum;
  if (link >= 'a' && link <= 'h') {
    linkNum = link - 'a';
    p1links.at(linkNum).setVisibility(true);
  } else if (link >= 'A' && link <= 'H') {
    linkNum = link - 'A';
    p2links.at(linkNum).setVisibility(true);
  } else {
    cout << "invalid link to scan" << endl;
  }
  // need to update player fields
  //update td
  if (playerTurn == 1) {
    p1->decrementAbilityCount(); // used up one ability
    p1->setUsed(abilityID); // set the download ability to used
  } else {
    p2->decrementAbilityCount(); // used up one ability
    p2->setUsed(abilityID); // set the download ability to used
  }
  // td->notify(); 
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
  out << "Downloaded: " << b.getPlayer(1)->getDownloadedDataCount() << "D, " << b.getPlayer(1)->getDownloadedVirusCount() << "V" << endl; 
  out << "Abilities: " << b.getPlayer(1)->getAbilityCount() << endl;
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

