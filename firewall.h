#ifndef __FIREWALL_H__
#define __FIREWALL_H__
#include "link.h"

class Firewall {
    int xcoord;
    int ycoord;
    bool isActive; 
    int PlayerNum; 


public:
    Firewall();
    ~Firewall();

    bool firewallAffect(Link &link); 

};

#endif
