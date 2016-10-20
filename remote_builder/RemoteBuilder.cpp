
#include "RemoteBuilder.h"


RemoteBuilder::RemoteBuilder(){
  recv_pin = 11;
  irrecv = new IRrecv(recv_pin);
}

RemoteBuilder::RemoteBuilder(const int pinNumber, const int codeAmount){
  recv_pin = pinNumber;
  irrecv = new IRrecv(recv_pin);
  remote_codes = new char[codeAmount];
}

int RemoteBuilder::getRecveiverPin(){
  return recv_pin;
}


IRrecv* RemoteBuilder::getIRreceiver(){
  return irrecv;
}

decode_results* RemoteBuilder::getResults(){
  return &results;
}

//this function should be used within the loop function
//it will basically detect a remote signal and print it out
void RemoteBuilder::recordRemoteSignal(){

  if (irrecv->decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv->resume(); // Receive the next value
  }

}
