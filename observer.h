#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include <string>

class Link;

// enum class SubscriptionType { All, SwitchOnly };
// we might need an enum for player1, player2 and which colour to set them (can also make them class fields)

class Observer {
 public:
  virtual void notify(Link &l, std::string action, char winner = ' ') = 0;  // l is the Link that called the notify method
  virtual ~Observer() = default;
};
#endif
