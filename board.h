#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__

#include "Link.h"
#include <vector>
#include <utility> // For std::pair

class GameBoard {
    std::vector<std::vector<Link*>> board; // 2D grid of pointers to Link objects

    // Helper method
    bool isWithinBounds(int x, int y) const;
    
public:
    GameBoard();

    // Methods for setting up and managing the board
    void placeLink(int x, int y, Link& link);
    bool moveLink(int startX, int startY, int endX, int endY);
    Link* getLinkAt(int x, int y);
    void removeLink(int x, int y);

    // Utility methods for checking board state
    bool isSquareOccupied(int x, int y) const;
    bool isValidPosition(int x, int y) const;

    // Other methods related to board management

};

#endif // GAME_BOARD_H
