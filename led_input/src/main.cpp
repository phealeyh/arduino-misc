/* Libraries */
#include <Arduino.h>
#include <String.h>
#include "Input.h"
#include "Pin.h"
/* This program will allow you to input a led and select it.
It will then ask you what mode you want the pin to be at. The input
type will be done via serial communication (keyboard) */

/* Constants and variables */
#define led 13
Pin pin13(13,"OUTPUT");
Pin pin12(12,"OUTPUT");

/*Functional prototypes */
void promptVoltageSettings(Pin &pin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Please select a pin to configure on (13)/(12): ");
  String selection = Input::readString();
  Serial.println(selection + " has been selected.");

  if(selection.toInt() == 13){
    promptVoltageSettings(pin13);
  }
  else if(selection.toInt() == 12){
    promptVoltageSettings(pin12);
  }

  Serial.println(selection + " has been configured");
} //end loop

void promptVoltageSettings(Pin &pin){
  Serial.println("Will this pin be on or off? (ON/OFF) ");
  String selection = Input::readString();
  Serial.println("Setting pin to " + selection);
  pin.setVoltage(selection);
}
