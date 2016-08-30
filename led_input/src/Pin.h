#ifndef PIN_h
#define PIN_h

#include <Arduino.h>
#include <String.h>

class Pin{

  public:
    Pin(const int &led, String ioMode);
    const String printSettings();
    void setVoltage(String voltage);


  private:
    int _led;
    String _ioMode;
    void setPin();

};

#endif
