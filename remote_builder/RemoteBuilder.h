#ifndef REMOTEBUILDER_H
#define REMOTEBUILDER_H

#include <Arduino.h>
#include <IRremote.h>


class RemoteBuilder{

  public:
    RemoteBuilder();
    RemoteBuilder(const int pinNumber);
    int getRecveiverPin();
    IRrecv* getIRreceiver();
    decode_results* getResults();
    char* getCodes();
    int getCorrespondingPin(unsigned long codeNumber);

  private:
    int recv_pin;
    IRrecv *irrecv;
    decode_results results;
    char codes[21];
    void initialiseCodes();

};

#endif
