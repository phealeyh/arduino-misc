/* Program: LED Flasher
 * Name: Phealey Hang
 * ---------------------
 * This program will take an input and flash for the
 * amount given by the user. The input will be an integer
 * between 1-10. Each flash will be a second longer than
 * before when looping over.
 */

/* Libraries */
#include <Arduino.h>
#include "InputFlasher.h"
/* Constants and variables */
#define led 13
InputFlasher myInput(led);
void setup() {
  //establish serial link
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    //get input number and convert ascii to int
    int number = (Serial.read() - '0');
    if(number >= 0 && number <= 10) myInput.flash(number);
  }
}
