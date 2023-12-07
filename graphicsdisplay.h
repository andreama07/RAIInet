#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__
#include "observer.h"
#include "window.h"
#include <vector>

class Link;

class GraphicsDisplay : public Observer {
  Xwindow theGraphic; // Reference to the Xwindow object for graphical operations
  int boardSize; // The size of the grid
  int linkSize; // Size of each link in the window

 public:
  GraphicsDisplay(); // Constructor

  void notify(Link &l, std::string action, char winner = ' ') override;

  ~GraphicsDisplay(); // Destructor

};

#endif
