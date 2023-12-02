#include <iostream>
#include <string>

using namespace std;

int main () {

    string init;
    string command;
    string ability1[5];
    string ability2[5];
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
                    ability1[i] = "Link";
                } else if (abilities[i] == "F") {
                    // have firewall ability
                    ability1[i] = "Firewall";
                } else if (abilities[i] == "D") {
                    // have download ability
                    ability1[i] = "Download";
                } else if (abilities[i] == "S") {
                    // have scan ability
                    ability1[i] = "Scan";
                } else if (abilities[i] == "P") {
                    // have polarize ability
                    ability1[i] = "Polarize";
                } else {
                    // send the default abilities
                    ability1[0] = "Link";
                    ability1[1] = "Firewall";
                    ability1[2] = "Download";
                    ability1[3] = "Scan";
                    ability1[4] = "Polarize";
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
                    ability2[i] = "Link";
                } else if (abilities[i] == "F") {
                    // have firewall ability
                    ability2[i] = "Firewall";
                } else if (abilities[i] == "D") {
                    // have download ability
                    ability2[i] = "Download";
                } else if (abilities[i] == "S") {
                    // have scan ability
                    ability2[i] = "Scan";
                } else if (abilities[i] == "P") {
                    // have polarize ability
                    ability2[i] = "Polarize";
                } else {
                    // send the default abilities
                    ability2[0] = "Link";
                    ability2[1] = "Firewall";
                    ability2[2] = "Download";
                    ability2[3] = "Scan";
                    ability2[4] = "Polarize";
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
}