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

//initialises an object that
//contains an array to 13 pins
//and sets them to output
Pins *pins;

/*Functional prototypes */

void setup() {
  Serial.begin(9600);
  pins = new Pins(DIGITAL_PINS);
  //initialise the array
}



void loop() {
  Serial.println("Please select a pin to configure on 1-13: ");
  Pin pin = pins->getPin(Input::readString());
  Serial.println(pin.getLed());
  Serial.println("Will this pin be on or off? (ON/OFF) ");
  pin.setVoltage(Input::readString());
  Serial.println("Voltage is set");

}
