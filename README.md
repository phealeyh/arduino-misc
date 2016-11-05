# arduino-misc - A collection of personal programs

count_blinker - A simple blinking program that blinks pin 13's LED. Each blink will be a second longer since the use a static variable will be used to increment it.

input_blinker - Similiar to the blinking program but will take in an actual integer as an input for determining how long an LED will light up for.

led_input - This program will have the ability to control the high/low voltage of the 13 pins found within the pins object. The use of a keyboard will be used to prompt the user to select which pin he/she wants controlled and whether it will be set to high or low.

string_builder - A simple library for building strings using the Enter('\n') key as a terminator and used to retrieve key words and numbers when typed. This provides a safer way of handling exceptions when finding specific words or elements within an array.

remote_builder - A program that will allow you to control the high/low voltage of various digital i/o pins. It will be used in conjuction with the Pins library to allow the user to have control over them through a remote.