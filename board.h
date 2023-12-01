#ifndef __BOARD_H__
#define __BOARD_H__

#include "Link.h"
//#include "Direction"
#include <vector>


class Board {
    std::vector<std::vector<Link*>> board; // 2D grid of pointers to Link objects
    std::vector<std::vector<Firewall> firewalls; // 2D vector of Firewalls
    int boardSize = 8; 
    // Helper method
    bool isWithinBounds(int x, int y) const;
    
public:
    Board();
    ~Board();

    // Methods for setting up and managing the board
    void init(); // might not need this 
    void placeLink(int x, int y, Link& link);
    bool moveLink(int startX, int startY, int endX, int endY, string dir);
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
