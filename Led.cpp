#include "Arduino.h"
#include "Led.hpp"

Led::Led(int pin) : _pin(pin)
{
  pinMode(_pin, OUTPUT);
  this->off();
}

void Led::on()
{
  // les relais inversent le signal
  digitalWrite(_pin, LOW);
}

void Led::off()
{
  // les relais inversent le signal
  digitalWrite(_pin, HIGH);
}

// void Led::blink(unsigned long time_in_ms)
// {
//   this->on();
//   delay(time_in_ms);
//   this->off();
//   delay(time_in_ms);
// }

// void Led::fadeIn(unsigned long time_in_ms)
// {
//   int max_brightness_fade = 50; // max brightness before "pop" effect
//   unsigned long step_duration = time_in_ms / max_brightness_fade;

//   for (auto brightness = 0; brightness <= max_brightness_fade; brightness++)
//   {
//     analogWrite(_pin, brightness);
//     delay(step_duration);
//   }

//   this->on(); // "pop" effect
// }
