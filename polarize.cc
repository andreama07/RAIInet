#include "abilityvisitor.h"

void AbilityVisitor::visitLink(Link& link) {
    if (link.isData()) {
        link.isData() = false;

    } else {
        link.isData() = true;
    }
}


