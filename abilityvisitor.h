#ifndef __ABILITYVISITOR_H__
#define __ABILITYVISITOR_H__

class Link;
class Player;
class GameBoard;

class AbilityVisitor {
public:
    virtual void visitLink(Link& link) = 0;
    virtual void visitPlayer(Player& player) = 0;
    virtual void visitGameBoard(GameBoard& board) = 0;

    virtual ~AbilityVisitor() = default;
};

#endif 
