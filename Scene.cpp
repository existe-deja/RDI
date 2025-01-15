#include "Scene.hpp"
#include "Arduino.h"

Scene::Scene(Led *led, void (Led::*action)(), unsigned long duration)
    : _led(led), action(action), duration(duration), startTime(0) {}

bool Scene::play()
{
  if (startTime == 0)
  {
    startTime = millis(); // Enregistrer l'heure de début
    (_led->*action)();    // Exécuter l'action de la LED (allumer ou éteindre)
  }

  auto curentTime = millis() - startTime;
  if (curentTime >= duration)
  {
    return true; // La scène est terminée
  }
  return false; // La scène n'est pas encore terminée
}