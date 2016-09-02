#ifndef PIN_h
#define PIN_h

#include <Arduino.h>
#include <String.h>

class Pin{

  public:
    Pin();
    Pin(const int &led, String ioMode);
    const String printSettings();
    void setVoltage(String voltage);
    const int getLed();

  private:
    int _led;
    String _ioMode;
    void setPin();

};

#endif
