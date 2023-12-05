#include "AbilityVisitor.h"

void DownloadAbility::visitLink(Link& link) {
    // Assuming you have a method to check if the link belongs to the opponent
    if (link.player1own()) {
        player.downloaddata
        player.removedata
        // This could involve removing the link from the game board, changing its state, etc.
    }
}

// true when owned by player1, false when owned by player2