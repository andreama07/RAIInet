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

// helper functions for the commands:
void move() {
    string pLink;
    cin >> pLink;
    string dir;
    cin >> dir;
    // fill with end and start positions
    int x = xcoord(pLink);
    int y = ycoord(pLink);
    b.moveLink( x, y, dir); 
    //redraw graph in text and graphics
    // for the graphic redraw, redraw as little as possible
}

void print_abilities() {
    for (int i = 0; i < 5; i++) {
        cout << i << " " << abilities1[i] << endl;
    }
}

void use_ability() {
    int n;
    cin >> n;
    // uses ability with ID n 
    // depending on ability, require further input
}

void display_board() {
    // need graphics display
}


int main (int argc, char *argv[]) {

    string init;
    string command;
    string ability1[5];
    string ability2[5];
    Link *p1links[8]; // needs to be a pointer
    Link *p2links[8];

    std::array<pair<char, int>, 8> link1;
    std::array<pair<char, int>, 8> link2;


    for(int i = 0; i < argc; i++) {
       cout << "i " << argv[i] << endl;
    }


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
}


