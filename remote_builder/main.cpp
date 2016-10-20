#include "RemoteBuilder.h"
#include "Pins.h"
#define codes 21
#define DIGITAL_PINS 13
#define PIN_NUMBER 11

RemoteBuilder *remote;
Pins *pins;

void setup(){
  Serial.begin(9600);
  pins = new Pins(DIGITAL_PINS);
  remote = new RemoteBuilder(pins->getPin(PIN_NUMBER).getPin(), codes);
  remote->getIRreceiver()->enableIRIn();  // Start the receiver
}

void loop() {
  remote->recordRemoteSignal();
}
