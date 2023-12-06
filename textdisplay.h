#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include "observer.h"
#include "link.h"

class Link;

class TextDisplay: public Observer {
  std::vector<std::vector<char>> theDisplay;
  int boardSize;

public:
  TextDisplay();

  void notify(Link &l, std::string action, char winner = ' ') override;

  ~TextDisplay();

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
