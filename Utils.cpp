#include "Utils.hpp"
#include "Arduino.h"

unsigned long toMilliseconds(int count, TimeUnit unit)
{

  switch (unit)
  {
  case MILLISECOND:
    return count * 1UL;
  case SECOND:
    return count * 1000UL;
  case MINUTE:
    return count * 60 * 1000UL;
  case HOUR:
    return count * 60 * 60 * 1000UL;
  }
}
