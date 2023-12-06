#include "link.h"
#include <iostream>
#include <string>

using namespace std;

Link::Link() : visible{false}, downloaded{false}, boosted{false} {}

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
    this->visible = visible;
}

void Link::setData(bool contents) {
    isData = contents;
}

void Link::setStrength(int strength) {
    this->strength = strength;
}

void Link::setPrevCoords(int x, int y) {
    prevX = x;
    prevY = y;
}

void Link::setDownloaded(bool b) {
    downloaded = b;
}

// start of accessor methods 

int Link::getXCoord() const {
    return xcoord;
}

int Link::getYCoord() const {
    return ycoord;
}

int Link::getOwner() const {
    if (player1owns) {
        return 1;
    } else {
        return 2;
    }
} 

bool Link::getVisibility() const {
    return visible;
}

bool Link::getData() const {
    return isData;
}

int Link::getStrength() const {
    // cout << "strength in link: " << strength << endl;
    return strength;
}

int Link::getPrevX() const {
    return prevX;
}

int Link::getPrevY() const {
    return prevY;
}

bool Link::getDownloaded() const {
    return downloaded;
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

bool Link::isBoosted() const { // LA Added 
    return boosted;
}

void Link::setBoosted() { // sets boosted to true after using it 
    if (!boosted) {
        boosted = true;
    }
}

void Link::print(int playerTurn) const {
    if (playerTurn == 1) {
        if (player1owns || (!player1owns && visible)) {
            if (isData) {
                cout << "D";
            } else { // is a virus
                cout << "V";
            }
            cout << strength << " ";
        } else { // p2owns and not visible
            cout << "? ";
        }
    } else { // playerTurn == 2
        if (!player1owns || (player1owns && visible)) {
            if (isData) {
                cout << "D";
            } else { // is a virus
                cout << "V";
            }
            cout << strength << " ";
        } else { // p1owns and not visible
            cout << "? ";
        }
    }
}




