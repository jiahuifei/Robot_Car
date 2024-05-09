#include "SoftSerialCommunication.h"

template <typename T>
SoftSerialCommunication<T>::SoftSerialCommunication(int rx, int tx) : _mySerial(rx, tx) {}

template <typename T>
void SoftSerialCommunication<T>::begin(long speed)
{
    _mySerial.begin(speed);
}

template <typename T>
void SoftSerialCommunication<T>::send(T dataToSend)
{
    _mySerial.write((char*)&dataToSend, sizeof(dataToSend));
}

template <typename T>
void SoftSerialCommunication<T>::receive(T* dataReceived)
{
    if (_mySerial.available())
    {
        _mySerial.readBytes((char*)dataReceived, sizeof(*dataReceived));
    }
}