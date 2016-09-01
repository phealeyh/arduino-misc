/* Libraries */
#include <Arduino.h>
#include <String.h>
#include "Input.h"
/* This program will allow you to input a led and select it.
It will then ask you what mode you want the pin to be at. The input
type will be done via serial communication (keyboard) */

/* Constants and variables */

void setup() {
  Serial.begin(9600);
}

void loop() {
  char *string = "hello";
  //int read = Input::readIntBetween(1,13);
  Serial.println(string);
} //end loop
