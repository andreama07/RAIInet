#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__

#include "Link.h"
#include <vector>

class Board {
    std::vector<std::vector<Link*>> board; // 2D grid of pointers to Link objects
    boardSize = 8;
    // Helper method
    bool isWithinBounds(int x, int y) const;
    
public:
    Board();
    ~Board();

    // Methods for setting up and managing the board
    void init();
    void placeLink(int x, int y, Link& link);
    bool moveLink(int startX, int startY, int endX, int endY);
    Link* getLinkAt(int x, int y);
    void removeLink(int x, int y);

    // Utility methods for checking board state
    bool isSquareOccupied(int x, int y) const;
    bool isValidPosition(int x, int y) const;

    // Other methods related to board management
    
    friend std::ostream &operator<<(std::ostream &out, const Grid &g);

};

#endif // GAME_BOARD_H
