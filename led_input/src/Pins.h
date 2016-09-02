#ifndef PINS_H
#define PINS_H

#include "Pin.h"

class Pins{
  public:
    Pins();
    Pins(const int &pin_amount);
    void destoryPins();
    Pin &getPin(String pinNumber);

  private:
    int _pin_amount;
    Pin *pinArray;
    void initialisePins();


};

#endif
