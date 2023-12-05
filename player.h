#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include <string>
#include "Link.h"
#include "AbilityVisitor.h"

class Player {
    // int playerNum; doesn't have to be here 
    std::vector<Link*> links;
    std::vector<AbilityVisitor*> abilities;
    //int downloadedDataCount;
    //int downloadedVirusCount;
   // int abilitiyCount;

    // Other methods needed

public:

    Player(); // should it be MIL initialized????

    // Methods for link management
    void addLink(const Link& link);
    Link& getLink(int linkId);
    const std::vector<Link>& getLinks() const;

    // Methods for ability management
    void addAbility(AbilityVisitor* ability);
    AbilityVisitor* getAbility(int abilityId);
    void useAbility(int abilityId, Link& targetLink);
    void useAbility(int abilityId, GameBoard& targetBoard);

    // Game status methods
    int getDownloadedDataCount() const;
    int getDownloadedVirusCount() const;
    void incrementDownloadedData();
    void incrementDownloadedVirus();

    // Other player-specific methods

};

#endif 
