#include "main.h"
//定义舵机IO口
uint8_t ServoPin[2]={Servo_Arm_Pin,Servo_Hand_Pin};
//定义舵机数组
Servo MyServo[2];
/*
  舵机使能函数
  参数：舵机序数;0,1
*/
void Servo_Enable(uint8_t Servo_Serial)
{
  if(!MyServo[Servo_Serial].attached()) 
    MyServo[Servo_Serial].attach(ServoPin[Servo_Serial]); 
  pinMode(ServoPin[Servo_Serial], OUTPUT);
}

/*
  舵机使能函数
  参数：舵机序数;1,2
*/
void Servo_Disable(uint8_t Servo_Serial)
{
  MyServo[Servo_Serial].detach(); 
  pinMode(ServoPin[Servo_Serial], LOW);
}

/*
  舵机转动函数
  参数1：舵机序数;1,2
  参数2：转动角度数值
*/
void ServoGo(int Servo_Serial , int where)
{
  if(where!=200)
  {
    if(where==201) Servo_Disable(Servo_Serial);
    else
    {
      Servo_Enable(Servo_Serial);
      MyServo[Servo_Serial].write(where);
    }
  }  
}

