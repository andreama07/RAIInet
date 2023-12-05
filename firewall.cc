#include "firewall.h"
using namespace std;

Firewall::Firewall(int x, int y, int playerNum) : x(x), y(y), isActive(true), playerNum(playerNum) {}

Firewall::~Firewall() {}

bool Firewall::firewallAffect(Link &link) {
    if (!isActive) return false;

    if (!link.player1owns()) { // true when owned by player 1
        // opponent links are revealed

        if (!link.isData()) {
            // download the link

        } else {

        }
    }

}


