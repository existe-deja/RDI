#include "Utils.hpp"
#include "Led.hpp"
#include "Scene.hpp"

const int TOTAL_LEDS = 5;
Led leds[TOTAL_LEDS] = {Led(2), Led(3), Led(4), Led(5), Led(6)};

const int SCENARIO_LENGTH = 16;
Scene *scenario[SCENARIO_LENGTH];
unsigned int currentSceneIndex = 0;

int finalSceneCount = 0;

void turnOffAllLeds()
{
  for (auto led : leds)
  {
    led.off();
  }
}

void turnOnAllLeds()
{
  for (auto led : leds)
  {
    led.on();
  }
}

void blinkAllLeds()
{
  for (auto led : leds)
  {
    led.on();
  }
  delay(toMilliseconds(500, MILLISECOND));
  for (auto led : leds)
  {
    led.off();
  }
  delay(toMilliseconds(500, MILLISECOND));
}

void rideAllLeds()
{
  for (int i = 0; i < TOTAL_LEDS - 1; i++)
  {

    leds[i].on();
    delay(toMilliseconds(500, MILLISECOND));
    leds[i].off();
  }

  for (int i = TOTAL_LEDS - 1; i >= 0; i--)
  {
    leds[i].on();
    delay(toMilliseconds(500, MILLISECOND));
    leds[i].off();
  }
}

void setup()
{
  void (Led::*action)() = &Led::on;

  scenario[0] = new Scene(&leds[0], &Led::off, toMilliseconds(6, MINUTE));
  scenario[1] = new Scene(&leds[0], &Led::on, toMilliseconds(6, MINUTE));
  scenario[2] = new Scene(&leds[1], &Led::on, toMilliseconds(6, MINUTE));
  scenario[3] = new Scene(&leds[2], &Led::on, toMilliseconds(6, MINUTE));
  scenario[4] = new Scene(&leds[2], &Led::off, toMilliseconds(500, MILLISECOND));
  scenario[5] = new Scene(&leds[1], &Led::off, toMilliseconds(3, MINUTE));
  scenario[6] = new Scene(&leds[1], &Led::on, toMilliseconds(3, MINUTE));
  scenario[7] = new Scene(&leds[2], &Led::on, toMilliseconds(6, MINUTE));
  scenario[8] = new Scene(&leds[3], &Led::on, toMilliseconds(1, MINUTE));
  scenario[9] = new Scene(&leds[3], &Led::off, toMilliseconds(1, MINUTE));
  scenario[10] = new Scene(&leds[3], &Led::on, toMilliseconds(1, MINUTE));
  scenario[11] = new Scene(&leds[3], &Led::off, toMilliseconds(1, MINUTE));
  scenario[12] = new Scene(&leds[3], &Led::on, toMilliseconds(10, MINUTE));
  scenario[13] = new Scene(&leds[4], &Led::on, toMilliseconds(1, SECOND));
  scenario[14] = new Scene(&leds[4], &Led::off, toMilliseconds(45, SECOND));
  scenario[15] = new Scene(&leds[4], &Led::on, toMilliseconds(1, SECOND));
}

void loop()
{
  if (scenario[currentSceneIndex] != nullptr)
  {
    bool isSceneFinished = scenario[currentSceneIndex]->play();
    if (isSceneFinished)
    {
      currentSceneIndex++;
    }
  }

  if (currentSceneIndex >= SCENARIO_LENGTH && finalSceneCount <= 3)
  {
    blinkAllLeds();
    blinkAllLeds();
    blinkAllLeds();
    rideAllLeds();

    finalSceneCount++;
  }
  if (finalSceneCount == 4)
  {
    turnOnAllLeds();
    finalSceneCount++;
  }
}
