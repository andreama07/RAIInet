#include <iostream>
#include <string>

using namespace std;

int main () {
    string init;
    string command;
    // start with any setup needed for testing
    // loops while input is not quit, EOF

    // setup
    // find a better way to loop around this
    while (true) {
        cin >> init;
        if (init == "-ability1") {
            string abilities;
            cin >> abilities;
            // give player 5 abilities with their first letter caps
            // ex LFDSP
            // if not specified, use the default 5 powerups
        } else if (init == "-ability2") {
            string abilities;
            cin >> abilities;
            // same as above but for player 2
        } else if (init == "-link1") {
            string f;
            cin >> f;
            // file with player 1s links
            // if no file, then randomize
        } else if (init == "-link2") {
            string f;
            cin >> f;
            // same as above but for player 2
        } else if (init == "graphics") {
            // enable graphical interface
        }
    }


    // interactions
    while (true) {
        cin >> command;
        if (command == "move") {
            // make sure the next is a calid link for the player
            // implement
            string pLink;
            cin >> pLink;
            string dir;
            cin >> dir;
            // move such link in said direction
            // implement 
            //redraw graph in text and graphics
            // for the graphic redraw, redraw as little as possible
        }
        else if (command == "abilities") {
            // display all abilities player has with an ID 1-5
            // make an indication whether it was used or not
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
            string f;
            cin >> f;
            // execute the sequence of commands found in file
        }
        // or if EOF
        else if (command == "quit") {
            // exit game
        }
    }
}