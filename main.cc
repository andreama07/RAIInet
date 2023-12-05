#include <iostream>
#include <string>
#include <fstream>
//#include "link.h"
//#include "board.h"
//#include "gamecontroller.h"
#include "player.h"
//#include "textdisplay.h"
#include <array>
#include <utility>

using namespace std;

int main (int argc, char *argv[]) {

    // initialize the variables that are needed
    string init;
    string command;
    string ability1[5];
    string ability2[5];
    Link *p1links[8]; // needs to be a pointer
    Link *p2links[8];

    std::array<pair<char, int>, 8> link1;
    std::array<pair<char, int>, 8> link2;

    Player p;

    for(int i = 0; i < argc; i++) {
       cout << "i " << argv[i] << endl;
    }


    // helper functions for the commands:

    void move() {
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
    }


    // initialize the game
    for(int i = 0; i < argc; i++) {
        string input = argv[i]; 
        if (input[0] == '-') {
            string currinp = input.substr(1); 
            if (currinp == "ability1") {
                ++i;
                string abilities = argv[i]; 
                for (int q = 0; q < abilities.length(); q++) {
                    ability1[q] = abilities[q];
                }
                
            } else if (currinp == "ability2") {
                ++i;
                string abilities = argv[i]; 
                for (int q = 0; q < abilities.length(); q++) {
                    ability2[q] = abilities[q];
                } 
            } else if (currinp == "link1") {
                ++i;
                ifstream file{argv[i]};
                string tmp; 
                int counter = 0;
                while (file >> tmp) {
                    link1[counter].first = tmp[0];
                    link1[counter].second = tmp[1] - '0';
                    counter++;
                }
            } else if (currinp == "link2") {
                ++i;
                ifstream file{argv[i]};
                string tmp; 
                int counter = 0;
                while (file >> tmp) {
                    link2[counter].first = tmp[0];
                    link2[counter].second = tmp[1] - '0';
                    counter++;
                }
            } else if (currinp == "graphics") {
                cout << "graphics" << endl; // refers to window.cc X11
            }
        }
       cout << "i " << argv[i] << endl;
    }
    for (auto p: link1) {
        cout << "Link: " << p.first << " " << "Strength: " << p.second << endl;
    }
    for (auto p: link2) {
        cout << "Link: " << p.first << " " << "Strength: " << p.second << endl;
    }

    // take in the commands
    while (true) {
        move();
        print_abilities();
        use_ability();
        display_board();
        cin >> command;
        if (command == "sequence") {
            string fName;
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
            } 
        } else if (command == "quit") {
            break;
        }
    }
}


