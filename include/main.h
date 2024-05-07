#ifndef __MAIN_H
#define __MAIN_H

//系统头文件
#include "Arduino.h"
#include "MsTimer2.h"  
#include <Servo.h>
#include "Wire.h"
//用户头文件
#include "MPU6050.h"
#include "MyPID.h"
#include "Servo_Driver.h"
#include "LedControl.h"
#include "IIC.h"

void Confinguration(void) ;// 外设初始化总函数

#endif
