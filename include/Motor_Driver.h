#ifndef __MOTOR_DRIVER_H
#define __MOTOR_DRIVER_H

#include "Arduino.h"

//定义电机引脚
#define MotorA_Pin1 9
#define MotorA_Pin2 10
#define MotorB_Pin1 5
#define MotorB_Pin2 6
//定义转向
#define forward 0
#define backward 1
//相关函数

//电机引脚初始函数
void Motor_Pin_Init(void);

/*
  电机操作函数
  第一个参数：电机序号;a/A,b/B
  第二个参数：移动方向;0,1
*/
void Motor_Start(char Motor_Serial,uint8_t dirction);

/*
  电机停止函数
  第一个参数：电机序号;a/A,b/B
*/
void Motor_Stop(char Motor_Serial);

#endif
