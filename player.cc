#include <vector>
#include <string>
#include "player.h"


Player::Player(int playerNum) : downloadedDataCount(0), downloadedVirusCount(0), abilitiyCount(5), playerNum(playerNum) {}

// Methods for link management

void Player::addLink(const Link& link) {
    links.emplace_back(link); //could push_back also work??
}

Link& Player::getLink(int linkId) { //linkID will be the vowels that represent the link
    return links.at(linkId);
} // might not be needed, trying to think when Player might need to access a specific link
// I'm confused as to how we should store the links, they're ints in the vector, but actualy being placed as chars
// do we make a specific char a number? ... I think this is how I'm going to implement it 
// meaning that 0 = a , 1 = b, 2 = c .... 7 = h

const std::vector<Link>& Player::getLinks() const {
    return links;
} // returns the entire list of links that a player has


// Methods for ability management

void Player::addAbility(AbilityVisitor* ability) {
    abilities.emplace_back(ability);
}

AbilityVisitor* Player::getAbility(int abilityId) { // this on is a bit more complex, work in progress 
    return abilities.at(abilityId); 
} // should the user remember which ability is stored where?
// or keep calling this until they get the ability they want before calling useAbility function?

void Player::useAbility(int abilityId, Link& targetLink) {
    AbilityVisitor *ability = getAbility(abilityId);
    if (ability) { // chekc to make sure that it's not nullptr
        ability->visit(targetLink); // link that is being affected
    }
}

void Player::useAbility(int abilityId, GameBoard& targetBoard) { // this one would be called when the firewall ability is used since it affects the board and not links
    AbilityVisitor *ability = getAbility(abilityId);
    if (ability) { // chekc to make sure that it's not nullptr
        ability->visit(targetBoard); // link that is being affected
    }
}

// Game status methods

int Player::getDownloadedDataCount() const {
    return downloaadedDataCount; 
}

int Player::getDownloadedVirusCount() const {
    return downloadedVirusCount;
}

void Player::incrementDownloadedData() {
    ++downloadedDataCount;
}

void Player::incrementDownloadedVirus() {
    ++downloadedVirusCount;
}

int Player::getPlayerNum() const {
    return PlayerNum;
}

Player::~Player() {
    for (AbilityVisitor *ability : abilities) {
        delete ability; 
    }
}

int Player::getAbilityCount() const {
    return abilitiyCount;
}

void Player::decrementAbilityCount() {
    --abilitiyCount;
}

// Other player-specific methods

