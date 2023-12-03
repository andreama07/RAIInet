#include "link.h"
#include <iostream>
#include <string>

using namespace std;
//new
Link::Link() {}

Link::~Link() {}

void Link::setCoords(int x, int y) {
    xcoord = x;
    ycoord = y;
}

void Link::setOwner(int owner) {
    if (owner == 1) {
        player1owns = true;
    }
    else if (owner == 2) {
        player1owns = false;
    }
    else {
        cout << "not a valid player" << endl;
    }
}

void Link::setVisibility(bool visible) {
    this.visible = visible;
}

void Link::setData(bool contents) {
    isData = contents;
}

void Link::setStrength(int strength) {
    this.strength = strength;
}

void Link::moveLink(std::string dir) {
    // might need to check if this is a valid new coord
    // might need to consider p1 vs p2 link
    if (player1owns) { 
        if (dir == "up") { // moving up is moving to the bottom of the board 
        ycoord++;
        } else if (dir == "down") {
            ycoord--;
        } else if (dir == "left") { // moving left looks like moving to the right of the board
            xcoord++;
        } else if (dir == "right") {
            xcoord--;
        } else {
            cout << "not a valid direction" << endl;
        } 
    } else {
        if (dir == "up") { // moving up is moving to the top of the board 
            ycoord--;
        } else if (dir == "down") {
            ycoord++;
        } else if (dir == "left") { // moving left looks like moving to the left of the board
            xcoord--;
        } else if (dir == "right") {
            xcoord++;
        } else {
            cout << "not a valid direction" << endl;
        } 
    }
}

int Link::getXCoord() {
    return xcoord;
}

int Link::getYCoord() {
    return ycoord;
}

int Link::getOwner() {
    if (player1owns) {
        return 1;
    } else {
        return 2;
    }
} 

bool Link::getVisibility(bool visible) {
    return visible;
}

bool Link::getData(bool contents) {
    return isData;
}

int Link::getStrength(int strength) {
    return strength;
}


