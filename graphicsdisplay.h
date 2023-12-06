#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__
#include "observer.h"
#include "window.h"
#include <vector>
class Cell;

class GraphicsDisplay : public Observer {
  Xwindow &xw; // Reference to the Xwindow object for graphical operations
  int gridSize; // The size of the grid
  int cellSize; // Size of each cell in the window
  std::vector<std::vector<bool>> theDisplay; // 2D vector to keep track of cell states

 public:
  GraphicsDisplay(Xwindow &xw, int n); // Constructor

 void notify(Cell &c) override;
 SubscriptionType subType() override;

  ~GraphicsDisplay(); // Destructor

  void clearDisplay(); // Clears the graphical display when needed

  void draw(); // redraws only the cells that have been changed
};

#endif
