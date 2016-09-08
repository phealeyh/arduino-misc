#include <Arduino.h>
#include <String.h>
#include "Input.h"

Input::Input(){
}

//This will keep accepting a char from the serial
//read function and appending it to a string
// until enter is hit
// Note: This function does exactly the same
// thing as the readStringUntil function from
// the standard arduino library. I am using this instead
// because I dont want the if statement embedded within the
// main program.
String Input::readString(){
  String input;
  char c;
  while(true){
    if(Serial.available() > 0){
      c = Serial.read();
      if(c == '\n') break;
      input += c;
    }
  }
  //remove the enter key appended to the end
  input.remove(input.length() - 1);
  return input;
}
//This input will keep looping until the user enters
//a number between the given minimum and maximum argument variables
int Input::readIntBetween(const int &min, const int &max){
  String read;
  char c;
  while(true){
    if(Serial.available() > 0){
      c = Serial.read();
      read += c;
      if(c == '\n'){
        if(read.toInt() >= min && read.toInt() <= max) break;
        else{
          Serial.println("Please enter a number between the range.");
          read = "";
        }
      }
    }
  }
  return read.toInt();
}
