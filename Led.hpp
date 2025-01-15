#ifndef __LED__
#define __LED__

#include "Actionnable.hpp"

class Led : public Actionnable
{
private:
  int _pin;

public:
  Led(int pin);
  void on() override;
  void off() override;

  // legacy
  // void blink(unsigned long time_in_ms = 1000);
  // void fadeIn(unsigned long time_in_ms = 1000);
};

#endif;