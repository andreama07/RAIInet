#include <iostream>
#include <string>
#include <fstream>
#include "link.h"
#include "board.h"

//#include "gameControl.h"
#include "player.h"
#include "textdisplay.h"

using namespace std;

// helper functions for the commands:

/* void move() {
    string pLink;
    cin >> pLink;
    string dir;
    cin >> dir;
    // fill with end and start positions
    int x = xcoord(pLink);
    int y = ycoord(pLink);
    pLink.moveLink( x, y, dir); 
    //redraw graph in text and graphics
    // for the graphic redraw, redraw as little as possible
}

void print_abilities() {
    for (int i = 0; i < 5; i++) {
        if 
        cout << i << " " << abilities1[i] << endl;
    }
}

// ************ need help calling the abilities *******************
void use_ability() {
    int n;
    cin >> n;
    // uses ability with ID n 
    string ab = ability1[n - 1];

    // add a - if used
    ability1[n-1] = "-" + "ab";
    // firewall
    if (ab == "F") {
        int x;
        int y;
        cin >> x >> y;
        // player num p
        firewall(x, y, p);
        
    } else if (ab == "S") {
        // scan
        Link l;
        cin >> l;
        scan(l);
    } else if (ab == "P") {
        //polarize
        Link l;
        cin >> l;
        polarize(l);
    } else if (ab == "L") {
        // link boost
        Link l;
        cin >> l;
        linkboost(l);
    } else if (ab == "D") {
        // download
        Link l;
        cin >> l;
        download(l);
    }
    // depending on ability, require further input
}

void display_board() {
    // need graphics display
} */


// START OF MAIN FUNCTION
int main (int argc, char *argv[]) {

    // initialize the variables that are needed
    string init;
    string command;

    string ability1[5];
    string ability2[5];

    // Player p;

    for(int i = 0; i < argc; i++) {
       cout << i << " " << argv[i] << endl;
    }

    Board b;
    b.init();
    // initialize the game
    for(int i = 0; i < argc; i++) {
        string input = argv[i]; 
        if (input[0] == '-') {
            string curInput = input.substr(1); 
            if (curInput == "ability1") {
                i++;
                string abilities = argv[i]; 
                for (long unsigned int q = 0; q < abilities.length(); q++) {
                    ability1[q] = abilities[q];
                }
                
            } else if (curInput == "ability2") {
                i++;
                string abilities = argv[i]; 
                for (long unsigned int q = 0; q < abilities.length(); q++) {
                    ability2[q] = abilities[q];
                } 
            } else if (curInput == "link1") {
                i++;
                ifstream file{argv[i]};
                string tmp; 
                int counter = 0;
                while (file >> tmp) {
                    
                    if (tmp[0] == 'D') {
                        b.setData(1, counter, true);
                    } else { // first letter is "V"
                        b.setData(1, counter, false);
                    }
                        // cout << "strength val: " << tmp[1] - '0' << endl;
                        b.setStrength(1, counter, tmp[1] - '0');
                    counter++;
                }
            } else if (curInput == "link2") {
                i++;
                ifstream file{argv[i]};
                string tmp; 
                int counter = 0;
                while (file >> tmp) {
                    if (tmp[0] == 'D') {
                        b.setData(2, counter, true);
                    } else { // first letter is "V"
                        b.setData(2, counter, false);
                    }
                        b.setStrength(2, counter, tmp[1] - '0');
                    counter++;
                }
            } else if (curInput == "graphics") {
                cout << "graphics" << endl; // refers to window.cc X11
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        cout << "P1 Link: " << i << " is " << b.getData(1, i) << " Strength: " << b.getStrength(1, i) << endl;
    }
    for (int i = 0; i < 8; i++) {
        cout << "P2 Link: " << i << " is " << b.getData(2, i) << " Strength: " << b.getStrength(2, i) << endl;
    }
    cout << b << endl;

    // take in the commands
    while (true) {
        // move();
        // print_abilities();
        // use_ability();
        // display_board();
        cin >> command;
        if (command == "move") {
            cout << "move link" << endl;
        } else if (command == "abilities") {
            cout << "print out abilities" << endl;
        } else if (command == "ability") {
            cout << "use a specific ability" << endl;
        } else if (command == "board") {
            cout << "print out the board" << endl;
        } else if (command == "sequence") {
            cout << "execute the commands in the given file" << endl;
            /* string fName;
            cin >> fName;
            ifstream f{fName};
            string command;
            while (f >> s) {
                if (s == "move") {
                    move();
                } else if (s == "abilities") {
                    print_abilities();
                } else if (s == "ability") {
                    use_ability();
                } else if (s == "board") {
                    display_board();
                } else if (s == "quit") {
                    break;
                }
            } */
        } else if (command == "quit") {
            cout << "ending the game" << endl;
            break;
        }
    }
}


