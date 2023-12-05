#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include <string>
#include "link.h"
#include "abilityvisitor.h"

class Player {
    int playerNum;
    std::vector<char> abilities; // need to figure out where abilities go
    std::vector<bool> abilityUsed;
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
    char getAbility(int id) const;

    void setAbility(int id, char letter);
    void setUsed(int id);
    void incrementDownloadedData();
    void incrementDownloadedVirus();
    void decrementAbilityCount();
    void printAbilities();

    // Other player-specific methods

};

#endif 
