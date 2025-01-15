#ifndef __ACTIONNABLE__
#define __ACTIONNABLE__

class Actionnable
{
public:
  virtual void on() = 0;    // Méthode virtuelle pure pour allumer
  virtual void off() = 0;   // Méthode virtuelle pure pour éteindre
  virtual ~Actionnable() {} // Destructeur virtuel pour permettre la destruction correcte des objets dérivés
};

#endif
