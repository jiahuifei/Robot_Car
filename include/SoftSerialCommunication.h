#include "main.h"

#ifndef SoftSerialCommunication_h
#define SoftSerialCommunication_h

template <typename T>
class SoftSerialCommunication
{
public:
    SoftSerialCommunication(int rx, int tx);
    void begin(long speed);
    void send(T dataToSend);
    void receive(T* dataReceived);
private:
    SoftwareSerial _mySerial;
};
#endif

