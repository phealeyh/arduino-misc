/* Libraries */
#include <Arduino.h>
#include <String.h>
#include "Input.h"
#include "Pin.h"
/* This program will allow you to input a led and select it.
It will then ask you what mode you want the pin to be at(ON/OFF). The input
type will be done via serial communication (keyboard) */

/* Constants and variables */
#define DIGITAL_PINS 13

Pin *pinArray;

/*Functional prototypes */
void promptVoltageSettings(Pin &pin);
Pin &getPin(String pinNumber);
void initialisePins();

void setup() {
  Serial.begin(9600);
  //initialise the array
  pinArray = new Pin[DIGITAL_PINS];
  initialisePins();
}

void initialisePins(){
  //initialise the elements within the array
  for(int i = 0; i < DIGITAL_PINS; i++){
    //shift by one so that the lowest
    //element is 1 and set them to output by default
    Pin *pin = new Pin(i + 1, "OUTPUT");
    pinArray[i] = *pin;
    delete pin;
  }
}


void loop() {
  Serial.println("Please select a pin to configure on 1-13: ");
  Pin pin = getPin(Input::readString());
  Serial.print(pin.getLed());
  Serial.println(" has been selected.");
  promptVoltageSettings(pin);
  Serial.print(pin.getLed());
  Serial.println(" has been configured");
}

//returns an actual pin from the array that is equal
//to the pin given
Pin &getPin(String pinNumber){
  int number = pinNumber.toInt();
  for(int i = 0; i < DIGITAL_PINS; i++){
    if(pinArray[i].getLed() == number) return pinArray[i];
  }
}

void promptVoltageSettings(Pin &pin){
  Serial.println("Will this pin be on or off? (ON/OFF) ");
  String selection = Input::readString();
  Serial.println("Setting pin to " + selection);
  pin.setVoltage(selection);
}
