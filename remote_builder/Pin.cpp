#include <Arduino.h>
#include <string.h>

#include "Pin.h"

Pin::Pin(){

}

Pin::Pin(const int &pin, String ioMode){
  _pin = pin;
  _ioMode = ioMode;

  _pinState = 0;
  digitalWrite(_pin, _pinState);
  //set pinMode here
  setPin();
}

const String Pin::printSettings(){
  return _ioMode;
}

const int Pin::getPin(){
  return _pin;
}


void Pin::setVoltage(String voltage){
  voltage.toUpperCase();
  if(voltage.equals("OFF")){
    _pinState = 0;
  }
  else if(voltage.equals("ON")){
    _pinState = 1;
  }
  digitalWrite(_pin,_pinState);
}

//helper function that sets the pin
//to the correct settings
void Pin::setPin(){
  if(_ioMode == "OUTPUT"){
    pinMode(_pin,OUTPUT);
  }
  else if(_ioMode == "INPUT"){
    pinMode(_pin,INPUT);
  }
}

void Pin::switchPin(){
  if(_pinState){
    _pinState = 0;
  }
  else{
    _pinState = 1;
  }
  digitalWrite(_pin,_pinState);
}
