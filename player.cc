#include <vector>
#include <string>
#include <iostream>

#include "player.h"

using namespace std;

Player::Player(int playerNum) : playerNum(playerNum), downloadedDataCount(0), downloadedVirusCount(0), abilityCount(5) {
    // adding the default abilities
    abilities.emplace_back('L');
    abilities.emplace_back('F');
    abilities.emplace_back('D');
    abilities.emplace_back('S');
    abilities.emplace_back('P');
    for (int i = 0; i < 5; i++) {
        abilityUsed.emplace_back(false); // abilities start unused
    }
}

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

char Player::getAbility(int id) const { // id is an int from 1-5, our vector has indices 0-4
    return abilities.at(id - 1);
}

// updating methods

void Player::setAbility(int id, char letter) { // id is an int from 0-4 already
    abilities.at(id) = letter;
}

void Player::setUsed(int id) { // id is an int from 1-5, our vector has indices 0-4
    abilityUsed.at(id - 1) = true;
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

void Player::printAbilities() {
    for (int i = 0; i < 5; i++) {
        cout << "Ability " << i << ": ";
        if (abilities.at(i) == 'L') {
            cout << "Link Boost - ";
        } else if (abilities.at(i) == 'F') {
            cout << "Firewall - ";
        } else if (abilities.at(i) == 'D') {
            cout << "Download - ";
        } else if (abilities.at(i) == 'P') {
            cout << "Polarize - ";
        } else if (abilities.at(i) == 'S') {
            cout << "Scan - ";
        } // can add more abilities if we have time
        // show if used or not
        if (abilityUsed.at(i)) {
            cout << "USED" << endl;
        } else { // ability not used
            cout << "NOT USED" << endl;
        }
    }
}

// Other player-specific methods

