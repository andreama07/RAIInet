#include <gameControl.h>
#include <board.h>

gameControl::gameControl() {}

gameControl::~gameControl() {}

    // put this in a function??
    Board b;
  // interactions
void Interact() {
    while (true) {
        cin >> command;
        if (command == "move") {
            // make sure the next is a calid link for the player
            // implement
            string pLink;
            cin >> pLink;
            string dir;
            cin >> dir;
            // fill with end and start positions
            int x = getXCoord(pLink);
            int y = getYCoord(pLink);
            b.moveLink( x, y, dir);
            // move such link in said direction
            // implement 
            //redraw graph in text and graphics
            // for the graphic redraw, redraw as little as possible
        }
        else if (command == "abilities") {
            // display all abilities player has with an ID 1-5
            // make an indication whether it was used or not
            for (int i = 0; i < 5; i++) {
                cout << i << " " << abilities1[i] << endl;
            }
        }
        else if (command == "ability") {
            int n;
            cin >> n;
            // uses ability with ID n 
            // depending on ability, require further input
        }
        else if (command == "board") {
            // display board
        }
        else if(command == "sequence") {
            string fName;
            cin >> fName;
            ifstream f{fName};
            string command;
            while (f >> s) {
                // execute each s here
            } 
            // execute the sequence of commands found in file
        }
        // or if EOF
        else if (command == "quit") {
            // exit game
        }
    }
}