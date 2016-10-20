
#include "RemoteBuilder.h"

RemoteBuilder::RemoteBuilder(){
  recv_pin = 11;
  irrecv = new IRrecv(recv_pin);
  initialiseCodes();
}

RemoteBuilder::RemoteBuilder(const int pinNumber){
  recv_pin = pinNumber;
  irrecv = new IRrecv(recv_pin);
  initialiseCodes();
}

void RemoteBuilder::initialiseCodes(){
  codes[0] = '0xFFA25D'; //ch-
  codes[1] = '0xFF629D'; //ch
  codes[2] = '0xFFE21D'; //ch+
  codes[3] = '0xFF22DD'; //prev
  codes[4] = '0xFF02FD'; //next
  codes[5] = '0xFFC23D'; //play/pause
  codes[6] = '0xFFE01F'; //vol-
  codes[7] = '0xFFA857'; //vol+
  codes[8] = '0xFF906F'; //eq
  codes[9] = '0xFF6897'; //0
  codes[10] = '0xFF9867'; //100+
  codes[11] = '0xFFB04F'; //200+
  codes[12] = '0xFF30CF'; //1
  codes[13] = '0xFF18E7'; //2
  codes[14] = '0xFF7A85'; //3
  codes[15] = '0xFF10EF'; //4
  codes[16] = '0xFF38C7'; //5
  codes[17] = '0xFF5AA5'; //6
  codes[18] = '0xFF42BD'; //7
  codes[19] = '0xFF4AB5'; //8
  codes[20] = '0xFF52AD'; //9
}

char* RemoteBuilder::getCodes(){
  return codes;
}

int RemoteBuilder::getCorrespondingPin(unsigned long codeNumber){
  switch(codeNumber){
    case 0xFF6897: return 0;
    case 0xFF30CF: return 1;
    case 0xFF18E7: return 2;
    case 0xFF7A85: return 3;
    case 0xFF10EF: return 4;
    case 0xFF38C7: return 5;
    case 0xFF5AA5: return 6;
    case 0xFF42BD: return 7;
    case 0xFF4AB5: return 8;
    case 0xFF52AD: return 9;
  }
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
