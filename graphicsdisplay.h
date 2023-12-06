<<<<<<< HEAD
#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__
#include <iostream>
#include <vector>
#include "observer.h"
#include "link.h"
#include "window.h"
#include "firewall.h"

class Link;

class GraphicsDisplay: public Observer {
  Xwindow &xw; // Reference to the Xwindow object for graphical operations
  int boardSize; // The size of the grid
  int cellSize; // Size of each cell in the window
  std::vector<std::vector<int>> theGraphic; // 2D vector to keep track of cell states

public:
  GraphicsDisplay(Xwindow &xw, int n); // Constructor

 void notify(Link &l, std::string action) override;
=======
// #ifndef __GRAPHICSDISPLAY_H__
// #define __GRAPHICSDISPLAY_H__
// #include "observer.h"
// #include "window.h"
// #include "link.h"
// #include <vector>
// class Cell;

// class GraphicsDisplay : public Observer {
//   Xwindow &xw; // Reference to the Xwindow object for graphical operations
//   int gridSize; // The size of the grid
//   int cellSize; // Size of each cell in the window
//   std::vector<std::vector<bool>> theDisplay; // 2D vector to keep track of cell states

//  public:
//   GraphicsDisplay(Xwindow &xw, int n); // Constructor

//   ~GraphicsDisplay(); // Destructor
>>>>>>> c202e418e04561cadcdf13048ee015557b3b69b8

//   void notify(Link &l, std::string action, char winner = ' ') override;

<<<<<<< HEAD
  void draw(); // redraws only the cells that have been changed
};

#endif

=======
//   void clearDisplay(); // Clears the graphical display when needed

//   void draw(); // redraws only the cells that have been changed
// };

// #endif
>>>>>>> c202e418e04561cadcdf13048ee015557b3b69b8
