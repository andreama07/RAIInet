#ifndef __FIREWALL_H__
#define __FIREWALL_H__
#include "link.h"

class Firewall {
    int xcoord;
    int ycoord;
    bool isActive; 
    int playerNum; 


public:
    Firewall(int x, int y, int playerNum);
    ~Firewall();

    void firewallAffect(Link &link); 

};

#endif
