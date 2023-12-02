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
            for (int i = 0; i < 5; i++){
                if (abilities[i] == "L") {
                    // they have a Link ability
                } else if (abilities[i] == "F") {
                    // have firewall ability
                } else if (abilities[i] == "D") {
                    // have download ability
                } else if (abilities[i] == "S") {
                    // have scan ability
                } else if (abilities[i] == "P") {
                    // have polarize ability
                } else {
                    // send the default abilities
                    break;
                    
                }
            }
        } else if (init == "-ability2") {
            string abilities;
            cin >> abilities;
            // same as above but for player 2
            for (int i = 0; i < 5; i++){
                if (abilities[i] == "L") {
                    // they have a Link ability
                } else if (abilities[i] == "F") {
                    // have firewall ability
                } else if (abilities[i] == "D") {
                    // have download ability
                } else if (abilities[i] == "S") {
                    // have scan ability
                } else if (abilities[i] == "P") {
                    // have polarize ability
                } else {
                    // send the default abilities
                    break; 
                }
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
    GameControl::Interactions();

   

}