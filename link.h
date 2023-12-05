#ifndef __LINK_H__
#define __LINK_H__

#include <string>

class Link {
    int xcoord;
    int ycoord;
    bool player1owns; // true when owned by player1, false when owned by player2
    bool visible; // starts of not visible by opponent, turns true if identity/strength is revealed
    bool isData; // true if Link is data, false if Link is virus
    int strength; // must be an int from 1-4 inclusive

public: 

    Link();
    ~Link();
    
    // set coords, and other fields (using the -link1 and -link2 commands in main)
    void setCoords(int x, int y); // sets xcoord and ycoord fields
    void setOwner(int player); // sets player1owns field
    void setVisibility(bool visible); // sets visible field
    void setData(bool contents); // sets isData field
    void setStrength(int strength); // sets strength field

    // accessor functions
    int getXCoord() const; 
    int getYCoord() const;
    int getOwner() const; 
    bool getVisibility() const; 
    bool getData() const; 
    int getStrength() const; 

    // link movement
    void moveLink(std::string dir); // dir is one of up, down, left, right

    // printing link info
    void print(int playerTurn) const;
    // want to have all the ability methods here

};

#endif
