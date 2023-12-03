#ifndef __LINK_H__
#define __LINK_H__

#include <string>

class Link {
    int xcoord;
    int ycoord;
    bool player1owns; // true when owned by player1, false when owned by player2
    bool visible = false; // starts of not visible by opponent, turns true if identity/strength is revealed
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
    int getXCoord(); 
    int getYCoord();
    int getOwner(); 
    bool getVisibility(bool visible); 
    bool getData(bool contents); 
    int getStrength(int strength); 

    // link movement
    void moveLink(std::string dir); // dir is one of up, down, left, right

    // want to have all the ability methods here

};

#endif
