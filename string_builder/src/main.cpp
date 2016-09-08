/* Libraries */
#include <Arduino.h>
#include <String.h>
#include "Input.h"
/* This program will be testing the string builder
 * class. It will be testing the static function
 * for retrieving inputs between a certain number.
 * */

/* Constants and variables */

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Enter a number between 0-13");
  Serial.println(Input::readIntBetween(0, 13));
} //end loop
