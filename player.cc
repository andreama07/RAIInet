#include <vector>
#include <string>
#include "player.h"


Player::Player(int playerNum) : playerNum(playerNum), downloadedDataCount(0), downloadedVirusCount(0), abilityCount(5) {}

Player::~Player() {}

// Game status methods

int Player::getPlayerNum() const {
    return playerNum;
}

int Player::getDownloadedDataCount() const {
    return downloadedDataCount; 
}

int Player::getDownloadedVirusCount() const {
    return downloadedVirusCount;
}

int Player::getAbilityCount() const {
    return abilityCount;
}

void Player::incrementDownloadedData() {
    downloadedDataCount++;
}

void Player::incrementDownloadedVirus() {
    downloadedVirusCount++;
}

void Player::decrementAbilityCount() {
    abilityCount--;
}

// Other player-specific methods

