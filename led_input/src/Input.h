
#ifndef INPUT_h
#define INPUT_h


#include <Arduino.h>
#include <string.h>

class Input{
  public:
  Input();
  static String readString();
  static int readIntBetween(const int &min, const int &max);
  static String readStringUntilFound(String *words);

  private:
  static bool stringExists(const String &target, String *words);
};


#endif
