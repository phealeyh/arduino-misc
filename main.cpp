/* Program: LED Time Flasher
 * Name: Phealey Hang
 * ---------------------
 * This program will take a variable
 * and display an LED for the length of time
 * according to the variable it is currently at
 * all numbers will be converted to seconds when
 * delaying.
 */

/* Libraries */
#include <Arduino.h>

/* Constants */
#define led 13
#define milli_to_seconds 1000

void setup() {
  //sets the led to output mode
  pinMode(led,OUTPUT);
}

void loop() {
  //blink for the amount that count is currently on
  //e.g. 0 will be at 0 seconds
  static int count = 0;
  digitalWrite(led, HIGH);
  delay(count * milli_to_seconds);
  digitalWrite(led,LOW);
  delay(count * milli_to_seconds);
  ++count;
}
