#ifndef __UTILS__
#define __UTILS__

#include "Actionnable.hpp";

enum TimeUnit
{
  MILLISECOND,
  SECOND,
  MINUTE,
  HOUR,
};

unsigned long toMilliseconds(int count, TimeUnit unit);

#endif