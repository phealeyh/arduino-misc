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

void Input::printString(String string){

}
