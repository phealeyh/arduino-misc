
#ifndef INPUT_h
#define INPUT_h


#include <Arduino.h>
#include <String.h>

class Input{
  public:
  Input();
  static String readString();
  void printString(String string);

  private:

};


#endif
