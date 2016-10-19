
#include "RemoteBuilder.h"

RemoteBuilder::RemoteBuilder(){
  RECV_PIN = 11;
  irrecv = new IRrecv(RECV_PIN);
}
