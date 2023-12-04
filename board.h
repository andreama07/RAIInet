#ifndef __BOARD_H__
#define __BOARD_H__

#include "link.h"
#include "firewall.h"
#include "textdisplay.h"
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
    // Helper method
    bool isWithinBounds(int x, int y) const;
    
public:
    Board();
    ~Board();

    // Methods for setting up and managing the board
    void init(); // might not need this 
    void placeLink(int x, int y, Link& link);
    bool moveLink(int startX, int startY, std::string dir);
    Link* getLinkAt(int x, int y);
    void removeLink(int x, int y); // downloading is basically removing it, and just updating the download section
    void activateFirewall(int x, int y, int playerNumber);
    bool isFirewall(int x, int y) const;
    int firewallPlayer(int x, int y) const;


    // Utility methods for checking board state
    bool isSquareOccupied(int x, int y) const;
    bool isValidPosition(int x, int y) const;

    // Other methods related to board management
    
    friend std::ostream &operator<<(std::ostream &out, const Board &g);

};

#endif // __BOARD_H__
