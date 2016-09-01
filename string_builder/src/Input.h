
#ifndef INPUT_h
#define INPUT_h


#include <Arduino.h>
#include <String.h>

class Input{
  public:
  Input();
  static String readString();
  static int& readIntBetween(const int &min, const int &max);

  private:

};


#endif
