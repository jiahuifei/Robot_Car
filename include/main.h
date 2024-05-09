#ifndef __MAIN_H
#define __MAIN_H

//系统头文件
#include <Arduino.h>
#include "MsTimer2.h"  
#include <Servo.h>
#include <Wire.h>
#include "SoftwareSerial.h"
//用户头文件
#include "MPU6050.h"
#include "MyPID.h"
#include "Motor_Driver.h"
#include "Servo_Driver.h"
#include "LedControl.h"
#include "IIC.h"
#include "HC_SR04.h"
#include "Grayscale.h"
#include "SoftSerialCommunication.h"

void Confinguration();
void StateZero();//灰度循迹
void StateOne();
void StateTwo();
void StateThree();
#endif
