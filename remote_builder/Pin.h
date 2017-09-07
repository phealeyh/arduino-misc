#ifndef PIN_h
#define PIN_h

#include <Arduino.h>
#include <string.h>

class Pin{

  public:
    Pin();
    Pin(const int &pin, String ioMode);
    const String printSettings();
    void setVoltage(String voltage);
    const int getPin();
    void switchPin();

  private:
    int _pin;
    String _ioMode;
    bool _pinState;
    void setPin();

};

#endif
