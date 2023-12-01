#ifndef __LINKBOOST_H__
#define __LINKBOOST_H__

#include "AbilityVisitor.h"

class LinkBoost : public AbilityVisitor {
public:
    void visitLink(Link& link) override;
    // Implementations for Player and GameBoard might be empty if they are not relevant
    void visitPlayer(Player& player) override {}
    void visitGameBoard(GameBoard& board) override {}

    // Additional methods if needed
};

#endif 
