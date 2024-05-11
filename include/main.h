#ifndef __MAIN_H
#define __MAIN_H

//系统头文件
#include "Arduino.h"
#include "MsTimer2.h"  
#include <Servo.h>
#include "Wire.h"
#include "SoftwareSerial.h"
#include "Ultrasonic.h"

//用户头文件
#include "MPU6050.h"
#include "MyPID.h"
#include "LedControl.h"
#include "IIC.h"
#include "HC_SR04.h"
#include "Grayscale.h"

//宏定义变量
#define Highdis 5.0
#define Servent_Address 0xAA

void Confinguration(void) ;// 外设初始化总函数
void myTimerFunction();
void serialEvent();
#endif
