#include <Arduino.h>
#include "InputFlasher.h"

//implement the constructor and functions
InputFlasher::InputFlasher(int led){
  _led = led;
  //set the pin mode and set it to output
  pinMode(led,OUTPUT);
}

//This function will flash based on the
//amount given. Each flash will
//flash a second longer than the previous one

void InputFlasher::flash(int flashes){
  for(int i = 0; i < flashes; i++){
    digitalWrite(_led,HIGH);
    delay(_milli_to_seconds * (i + 1)); //the addition is used for making sure
    //it doesnt times by 0
    digitalWrite(_led,LOW);
    delay(_milli_to_seconds);
  }
}
