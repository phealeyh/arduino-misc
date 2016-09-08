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

//declares a pointer to Pins that
//contains an array to 13 pins
//and sets them to output
Pins *pins;


void setup() {
  Serial.begin(9600);
  //initialise the pins object
  pins = new Pins(DIGITAL_PINS);
}



void loop() {
  Serial.println("Please select a pin to configure on 1-13: ");
  Pin pin = pins->getPin(Input::readString());
  Serial.println(pin.getPin());
  Serial.println("Will this pin be on or off? (ON/OFF) ");
  pin.setVoltage(Input::readString());
  Serial.println("Voltage is set");

}
