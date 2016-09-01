#include <Arduino.h>
#include <String.h>
#include "Input.h"

Input::Input(){
}

//This will keep accepting a char from the serial
//read function and appending it to a string
// until enter is hit
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

int& Input::readIntBetween(const int &min, const int &max){
  char c;
  int number;
  while(true){
    if(Serial.available() > 0){
      Serial.print("Please enter a number between ");
      Serial.print(min);
      Serial.print(max);
      c = Serial.read();
      if(c >= min && c <= max && c == '\n'){
        number = c;
        break;
      }
    }
  }
  number;
  return number;
}
