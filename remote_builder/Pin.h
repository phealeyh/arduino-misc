#ifndef PIN_h
#define PIN_h

#include <Arduino.h>
#include <String.h>

class Pin{

  public:
    Pin();
    Pin(const int &pin, String ioMode);
    const String printSettings();
    void setVoltage(String voltage);
    const int getPin();

  private:
    int _pin;
    String _ioMode;
    void setPin();

};

#endif
