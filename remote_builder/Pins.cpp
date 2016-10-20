#include <Arduino.h>
#include <String.h>

#include "Pins.h"

//default constructor
Pins::Pins(){

}

Pins::Pins(const int &pin_amount){
  _pin_amount = pin_amount;
  pinArray = new Pin[pin_amount];
  //initialise elements within
  initialisePins();
}

void Pins::initialisePins(){
  for(int i = 0; i <= _pin_amount; i++){
    Pin *pin = new Pin(i,"OUTPUT");
    pinArray[i] = *pin;
    delete pin;
  }
}

Pin& Pins::getPin(int pinNumber){
  return pinArray[pinNumber];
}


//destroy pinArray
void Pins::destoryPins(){
  delete pinArray;
}

const int& Pins::pinAmount(){
  return _pin_amount;
}
