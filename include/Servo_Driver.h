#ifndef __SERVO_DRIVER_H
#define __SERVO_DRIVER_H

#include "Arduino.h"
#include <Servo.h>
//相关函数
void Servo_Enable(uint8_t Servo_Serial);
void Servo_Disable(uint8_t Servo_Serial);
void ServoGo(int Servo_Serial , int where);

#endif
