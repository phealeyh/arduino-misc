class InputFlasher
{
  //public functions and variabless
  public:
    InputFlasher(int led);
    void flash(int flashes);
  //private functions and variables
  private:
    static const int _milli_to_seconds = 1000;
    int _led;
};
