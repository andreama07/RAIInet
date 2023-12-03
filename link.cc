#include "link.h"
#include <iostream>

using namespace std;
//new
Link::Link() {}

Link::~Link() {}

void Link::setCoords(int x, int y) {
    xcoord = x;
    ycoord = y;
}

void Link::setPlayer(int owner) {
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


