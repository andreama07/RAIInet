#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include <string>
#include "link.h"
#include "abilityvisitor.h"

class Player {
    int playerNum;
    // std::vector<Link*> links; // links probably just go in board
    // std::vector<AbilityVisitor*> abilities; // need to figure out where abilities go
    int downloadedDataCount;
    int downloadedVirusCount;
    int abilityCount;

    // Other methods needed

public:

    Player(int playerNum); 
    ~Player();
    // Game status methods
    int getPlayerNum() const;
    int getDownloadedDataCount() const;
    int getDownloadedVirusCount() const;
    int getAbilityCount() const;
    void incrementDownloadedData();
    void incrementDownloadedVirus();
    void decrementAbilityCount();

    // Other player-specific methods

};

#endif 
