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

String& Input::readStringUntilFound(String *word){

}
