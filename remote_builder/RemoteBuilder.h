#ifndef REMOTEBUILDER_H
#define REMOTEBUILDER_H

#include <Arduino.h>
#include <IRremote.h>


class RemoteBuilder{

  public:
    RemoteBuilder();
    RemoteBuilder(const int pinNumber, const int codeAmount);
    int getRecveiverPin();
    IRrecv* getIRreceiver();
    decode_results* getResults();
    void recordRemoteSignal();

  private:
    int recv_pin;
    IRrecv *irrecv;
    decode_results results;
    char* remote_codes;
    
};

#endif
