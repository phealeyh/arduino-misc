#include <Arduino.h>
#include <String.h>

#include "Pin.h"

Pin::Pin(){

}

Pin::Pin(const int &led, String ioMode){
  _led = led;
  _ioMode = ioMode;
  //set pinMode here
  setPin();
}

const String Pin::printSettings(){
  return _ioMode;
}

const int Pin::getLed(){
  return _led;
}


void Pin::setVoltage(String voltage){
  voltage.toUpperCase();
  if(voltage.equals("OFF")){
    digitalWrite(_led,LOW);
  }
  else if(voltage.equals("ON")){
    digitalWrite(_led,HIGH);
  }
}

//helper function that sets the pin
//to the correct settings
void Pin::setPin(){
  if(_ioMode == "OUTPUT"){
    pinMode(_led,OUTPUT);
  }
  else if(_ioMode == "INPUT"){
    pinMode(_led,INPUT);
  }
}
