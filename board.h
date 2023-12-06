#ifndef __BOARD_H__
#define __BOARD_H__

#include "link.h"
#include "firewall.h"
#include "textdisplay.h"
#include "player.h"
//#include "Direction"
#include <vector>
#include <string>

class Board {
    //std::vector<std::vector<Link*>> board; // 2D grid of pointers to Link objects
    std::vector<Link> p1links; // vector to store player 1's links
    std::vector<Link> p2links; // vector to store player 2's links
    std::vector<std::vector<Firewall>> firewalls; // 2D vector of Firewalls
    int boardSize; 
    TextDisplay* td;
    Player* p1;
    Player* p2;
    int playerTurn;
    // Helper method
    bool isWithinBounds(int x, int y) const;
    
public:
    Board();
    ~Board();

    // Methods for setting up and managing the board
    void init(); 
    void setData(int playerNum, int linkNum, bool isData);
    void setStrength(int playerNum, int linkNum, int strength);
    void moveLink(char link, std::string dir);
    Link* getLinkAt(int x, int y);
    void removeLink(int x, int y); // downloading is basically removing it, and just updating the download section
    void activateFirewall(int x, int y, int playerNumber);
    bool isFirewall(int x, int y) const;
    void setPlayerTurn(int player);
    void useLinkBoost(int playerNum, int linkNum);

    // board accessor methods
    bool getData(int playerNum, int linkNum) const;
    int getStrength(int playerNum, int linkNum) const;
    int getPlayerTurn() const;
    Player* getPlayer(int player) const;

    // Utility methods for checking board state
    bool occupiedByOwn(int x, int y) const;
    bool isValidMove(char link, std::string dir) const;
    bool isValidLink(char c) const;

    // Ability functions
    bool download(char link, int abilityID = 0);
    void scan(char link, int abilityID);

    // Other methods related to board management
    void printLink(int playerNum, int linkNum, int playerTurn) const;
    
    friend std::ostream &operator<<(std::ostream &out, const Board &b);

};

#endif // __BOARD_H__
