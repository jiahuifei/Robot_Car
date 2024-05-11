#include "main.h"


SoftSerialCommunication::SoftSerialCommunication(int rx, int tx) : _mySerial(rx, tx) {}

void SoftSerialCommunication::begin(long speed)
{
    _mySerial.begin(speed);
}

void SoftSerialCommunication::send(const MyData& dataToSend)
{
    _mySerial.write((const byte*)&dataToSend, sizeof(dataToSend));
}

void SoftSerialCommunication::receive(MyData* dataReceived)
{
    if (_mySerial.available() >= sizeof(*dataReceived))
    {
        _mySerial.readBytes((char*)dataReceived, sizeof(*dataReceived));
    }
}
