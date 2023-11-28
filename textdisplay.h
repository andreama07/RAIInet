#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include "observer.h"

class Link;

class TextDisplay: public Observer {
  std::vector<std::vector<char>> theDisplay;
  const int boardSize = 8;

public:
  TextDisplay();

  void notify(Link &l) override;

  ~TextDisplay();

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
