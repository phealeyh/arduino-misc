#include "RemoteBuilder.h"
#include "Pins.h"
#define DIGITAL_PINS 13
#define PIN_NUMBER 11

RemoteBuilder *remote;
Pins *pins;

bool numberIsPin(int number);

void setup(){
  Serial.begin(9600);
  pins = new Pins(DIGITAL_PINS);
  remote = new RemoteBuilder(pins->getPin(PIN_NUMBER).getPin());
  remote->getIRreceiver()->enableIRIn();  // Start the receiver
}

void loop() {
  if(remote->getIRreceiver()->decode(remote->getResults())){ //get remote code
    int number = remote->getCorrespondingPin(remote->getResults()->value);
    if(numberIsPin(number)){
      Pin pin = pins->getPin(number);
      Serial.println(pin.getPin());
    }
    remote->getIRreceiver()->resume();

  }
}

bool numberIsPin(int number){
  return number <= DIGITAL_PINS && number >= 0;
}
