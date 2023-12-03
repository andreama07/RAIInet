#ifndef __GAMECONTROL_H__
#define __GAMECONTROL_H__

#include <board.h>
#include <firewall.h>
#include <link.h>
#include <observer.h>
#include <abilityvisitor.h>
#include <linkboost.h>


class gameControl {
public:
    gameControl();
    ~gameControl();
    void Interact();
};

#endif