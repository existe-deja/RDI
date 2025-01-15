#ifndef __SCENE__
#define __SCENE__

#include "Led.hpp"

class Scene
{
private:
  Led *_led;               // Référence à une classe
  void (Led::*action)();   // Pointeur vers une méthode de la classe
  unsigned long duration;  // Durée pendant laquelle la scène dure
  unsigned long startTime; // Moment où la scène a commencé

public:
  Scene::Scene(Led *led, void (Led::*action)(), unsigned long duration);
  bool play();
};

#endif
