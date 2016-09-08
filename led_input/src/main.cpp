/* Libraries */
#include <Arduino.h>
#include <String.h>
#include "Pins.h"
#include "Input.h";

/* This program will allow you to input a led and select it.
It will then ask you what mode you want the pin to be at(ON/OFF). The input
type will be done via serial communication (keyboard) */

/* Constants and variables */
#define DIGITAL_PINS 13

//pins will hold an array
//of pins
Pins *pins;


void setup() {
  Serial.begin(9600);
  pins = new Pins(DIGITAL_PINS);
}



void loop() {
  Serial.println("Please select a pin to configure on 1-13: ");
  //this will prompt and select a pin between 0 and 13, the readIntBetween will allow
  //us to handle out-of-bounds exceptions by getting the maximum amount of pins within
  //the class
  Pin pin = pins->getPin(Input::readIntBetween(0,pins->pinAmount()));
  Serial.println(pin.getPin());
  Serial.println("Will this pin be on or off? (ON/OFF) ");
  pin.setVoltage(Input::readString());
  Serial.println("Voltage is set");

}
