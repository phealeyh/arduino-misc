#include <Arduino.h>
#include <String.h>
#include "Input.h"

Input::Input(){
}

//reads a specifc string until an enter is hit
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
  input.remove(input.length() - 1);
  return input;
}

void Input::printString(String string){

}
