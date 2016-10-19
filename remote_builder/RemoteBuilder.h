#ifndef REMOTEBUILDER_H
#define REMOTEBUILDER_H

#include <Arduino.h>
#include <IRremote.h>


class RemoteBuilder{

  public:
    RemoteBuilder();
  private:
      int RECV_PIN;
      //pointer to an IRrecv object
      IRrecv *irrecv;
      decode_results results;

};

#endif
