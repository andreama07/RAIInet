// #ifndef __WINDOW_H__
// #define __WINDOW_H__
// #include <X11/Xlib.h>
// #include <iostream>
// #include <string>

// class Xwindow {
//   Display *d;
//   Window w;
//   int s;
//   GC gc;
//   unsigned long colours[10];

//  public:
//   Xwindow(int width=500, int height=500);  // Constructor; displays the window.
//   ~Xwindow();                              // Destructor; destroys the window.

<<<<<<< HEAD
  Xwindow(const Xwindow&) = delete;
  Xwindow &operator=(const Xwindow&) = delete;

  enum {White=0, Black, Red, Green, Blue, Yellow, Purple, Orange}; // Available colours.
  // Black for unknown 
  // Red for viruses
  // Green for data
  // Blue for firewall of 1
  // Purple for firewall of 2

  // Draws a rectangle
  void fillRectangle(int x, int y, int width, int height, int colour=Black); // might change to white instead
  
  void drawRectangle(int x, int y, int width, int height);
=======
//   enum {White=0, Black, Red, Green, Blue}; // Available colours.

//   // Draws a rectangle
//   void fillRectangle(int x, int y, int width, int height, int colour=Black);
>>>>>>> c202e418e04561cadcdf13048ee015557b3b69b8

//   // Draws a string
//   void drawString(int x, int y, std::string msg);

// };

// #endif
