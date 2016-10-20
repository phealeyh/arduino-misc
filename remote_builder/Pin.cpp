#include <Arduino.h>
#include <String.h>

#include "Pin.h"

Pin::Pin(){

}

Pin::Pin(const int &pin, String ioMode){
  _pin = pin;
  _ioMode = ioMode;
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
    digitalWrite(_pin,LOW);
  }
  else if(voltage.equals("ON")){
    digitalWrite(_pin,HIGH);
  }
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
