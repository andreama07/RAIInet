#include <iostream>
#include <string>
#include <fstream>
#include "link.h"
#include "board.h"

//#include "gameControl.h"
#include "player.h"
#include "textdisplay.h"

using namespace std;

// ************ need help calling the abilities *******************
/* void use_ability() {
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


// helper functions for main
bool isValidDir(string dir) {
    if (dir.compare("up") == 0 || dir.compare("down") == 0 || dir.compare("left") == 0|| dir.compare("right") == 0) {
        return true;
    } else {
        return false;
    }
}


// START OF MAIN FUNCTION
int main (int argc, char *argv[]) {

    // initialize the variables that are needed
    string ability1[5];
    string ability2[5];

    // outputting command line arguments for testing
    // for(int i = 0; i < argc; i++) {
    //    cout << i << " " << argv[i] << endl;
    // }

    Board b;
    b.init();
    // setup for the game
    for(int i = 0; i < argc; i++) {
        string input = argv[i]; 
        if (input[0] == '-') {
            string curInput = input.substr(1); 
            if (curInput == "ability1") {
                i++;
                string abilities = argv[i]; 
                for (long unsigned int q = 0; q < abilities.length(); q++) {
                    b.getPlayer(1)->setAbility(q, abilities[q]);
                    // cout << ability1[q];
                }
                
            } else if (curInput == "ability2") {
                i++;
                string abilities = argv[i]; 
                for (long unsigned int q = 0; q < abilities.length(); q++) {
                    b.getPlayer(2)->setAbility(q, abilities[q]);
                    // cout << ability2[q];
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
    // output textdisplay
    b.setPlayerTurn(1);
    cout << b << endl;

    string command;
    bool endGame; 
    while (!endGame) { // while the game is not over
        while (cin >> command) { // while there is still input
            if (command == "move") {
                // cout << "move link" << endl;
                char link;
                string dir;
                cin >> link;
                cin >> dir;
                if (b.isValidLink(link)) {
                    if (isValidDir(dir)) {
                        if (b.isValidMove(link, dir)) {
                            b.moveLink(link, dir);
                        } else {
                            cout << "not a valid move" << endl;
                            continue;
                        }
                    } else {
                        cout << "not a valid direction" << endl;
                        continue;
                    }
                } else {
                    cout << "not a valid link for you" << endl;
                    continue;
                }
                if (b.getPlayerTurn() == 1) { // turn is over after a link is moved
                    b.setPlayerTurn(2);
                    cout << "Player 2 Turn!" << endl;
                } else {
                    b.setPlayerTurn(1);
                    cout << "Player 1 Turn!" << endl;
                }
            } else if (command == "abilities") {
                cout << "print out abilities" << endl;
                if (b.getPlayerTurn() == 1) {
                    b.getPlayer(1)->printAbilities();
                } else { // player2 turn
                    b.getPlayer(2)->printAbilities();
                }
            } else if (command == "ability") {
                cout << "use a specific ability" << endl;
                int ID;
                char ab;
                cin >> ID;
                if (b.getPlayerTurn() == 1) {
                    ab = b.getPlayer(1)->getAbility(ID);
                    if (ab == 'L') {
                        // implement link boost
                        char link;
                        cin >> link;
                    } else if (ab == 'F') {
                        //implement firewall

                    } else if (ab == 'D') {
                        //implement download
                        char link;
                        cin >> link;
                        if (b.getPlayerTurn() == 1) {
                            if (link >= 'A'  && link <='H') { // valid opponent link (need to check if already downloaded)
                                // download and update player fields + td
                            } else {
                                cout << "invalid opponent link to download" << endl;
                                continue;
                            }
                        } else { // player2 turn
                            if (link >= 'a'  && link <='h') { // valid opponent link (need to check if already downloaded)
                                // download and update player fields + td
                            } else {
                                cout << "invalid opponent link to download" << endl;
                                continue;
                            }
                        }
                        // update player fields, update td
                        

                    } else if (ab == 'S') {
                        //implement scan
                        char link;
                        cin >> link;
                        if (link >= 'a' && link <= 'h') {
                            p1links.at(link-'a').setVisibility(true);
                        } else if (link >= 'A' && link <= 'H') {
                            p2links.at(link-'A').setVisibility(true);
                        } else {
                            cout << "invalid link to scan" << endl;
                            continue
                        }
                        // need to update player fields
                        //update td
                        g.td->notify();
                    } else if (ab == 'P') {
                        //implement polarize

                    } // can add more abilities here
                } else { // player2 turn
                    ab = b.getPlayer(2)->getAbility(ID);
                }
                

            } else if (command == "board") {
                // cout << "print out the board" << endl;
                cout << b << endl;
            } else if (command == "quit") { // need to check end of game statuses (4V or 4D)
                // cout << "ending the game" << endl;
                break;
            } else if (command == "sequence") {
                cout << "execute the commands in the given file" << endl;
                string fName;
                cin >> fName;
                ifstream f{fName};
                string s;
                while (f >> s) {
                    // same as non-file implementation (copy paste in)
                }
            } 
        }
        endGame = true;
    }
}


