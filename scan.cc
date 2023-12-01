#include "abilityvisitor.h"
#include "<iostream>

void AbilityVisitor::visitLink(Link& link) {
    
    cout << "Link Type: " << link.getType() << ", Strength: " << link.getStrength() << endl;
    
} // is there a way to get the type?? 


