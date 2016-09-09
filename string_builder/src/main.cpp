/* Libraries */
#include <Arduino.h>
#include <String.h>
#include "Input.h"
/* This program will be testing the string builder
 * class. It will be testing the static function
 * for retrieving inputs pertaining to a particular word in an array
 * */

/* Constants and variables */
String words[] = {"ON","OFF"};
void setup() {
  Serial.begin(9600);
}

void loop() {

  Serial.println(Input::readStringUntilFound(words));
} //end loop
