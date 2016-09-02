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

Pin& Pins::getPin(String pinNumber){
  int pin = pinNumber.toInt();
  for(int i = 0; i <= _pin_amount; i++){
    if(pinArray[i].getLed() == pin) return pinArray[i];
  }
}



//destroy pinArray
void Pins::destoryPins(){
  delete pinArray;
}
