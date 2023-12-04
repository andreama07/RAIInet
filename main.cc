#include <iostream>
#include <string>
#include <fstream>
#include "link.h"
#include "board.h"
#include "gameControl.h"
#include "player.h"
#include "textdisplay.h"

using namespace std;

int main () {

    string init;
    string command;
    string ability1[5];
    string ability2[5];
    Link p1links[8];
    Link p2links[8];
    // start with any setup needed for testing
    // loops while input is not quit, EOF
    for (int i = 0; i < 8; i++) {
        Link p1empty;
        p1links[i] = p1empty;
    }
    for (int i = 0; i < 8; i++) {
        Link p2empty;
        p2links[i] = p2empty;
    }

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
            string fname;
            cin >> fname;
            if (fname == "\n") {
                // randomize the links

            } else {
                ifstream f{fname}; 
                string s;
                int count = 0;
                while (f >> s) {
                    // set whether the link is a data or a virus
                    if (s[0] == "V") {
                        p1links[count].setData(false);
                    } else if (s[0] == "D") {
                        p1links[count].setData(true);
                    } else {
                        cout << "invalid link information" << endl;
                        break;
                    }
                    // set the strength of the link
                    if (s[1] == "1") {
                        p1links[count].setStrength(1);
                    } else if (s[1] == "2") {
                        p1links[count].setStrength(2);
                    } else if (s[1] == "3") {
                        p1links[count].setStrength(3);
                    } else if (s[1] == "4") {
                        p1links[count].setStrength(4);
                    } else {
                        cout << "strength is invalid" << endl;
                    }
                    p1links[count].setVisibility(false); // always starts as false until the link is revealed
                    count++;
                    if (count >= 8) { // if there is extra information is the file
                        break;
                    }
                }
            }
            // file with player 1s links
            // if no file, then randomize
        } else if (init == "-link2") {
            // same as above but for player 2
            string fname;
            cin >> fname;
            if (fname == "\n") {
                // randomize the links

            } else {
                ifstream f{fname}; 
                string s;
                int count = 0;
                while (f >> s) {
                    // set whether the link is a data or a virus
                    if (s[0] == "V") {
                        p2links[count].setData(false);
                    } else if (s[0] == "D") {
                        p2links[count].setData(true);
                    } else {
                        cout << "invalid link information" << endl;
                        break;
                    }
                    // set the strength of the link
                    if (s[1] == "1") {
                        p2links[count].setStrength(1);
                    } else if (s[1] == "2") {
                        p2links[count].setStrength(2);
                    } else if (s[1] == "3") {
                        p2links[count].setStrength(3);
                    } else if (s[1] == "4") {
                        p2links[count].setStrength(4);
                    } else {
                        cout << "strength is invalid" << endl;
                    }
                    p2links[count].setVisibility(false); // always starts as false until the link is revealed
                    count++;
                    if (count >= 8) { // if there is extra information is the file
                        break;
                    }
                }
            }
        } else if (init == "graphics") {
            // enable graphical interface
        }
        }
    }
    // GameControl::Interactions();
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
            int x = xcoord(pLink);
            int y = ycoord(pLink);
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
                // call the function to read
            } 
            // execute the sequence of commands found in file
        }
        // or if EOF
        else if (command == "quit") {
            // exit game
        }
    }
}

