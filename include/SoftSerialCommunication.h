#ifndef SoftSerialCommunication_h
#define SoftSerialCommunication_h

#include "SoftwareSerial.h"

struct MyData {
  int value1;
  float value2;
  char value3;
};

class SoftSerialCommunication
{
public:
    SoftSerialCommunication(int rx, int tx);
    void begin(long speed);
    void send(const MyData& dataToSend);
    void receive(MyData* dataReceived);
private:
    SoftwareSerial _mySerial;
};

#endif
