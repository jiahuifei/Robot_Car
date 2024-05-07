#include "main.h"
//电机引脚初始函数
void Motor_Pin_Init(void)
{
  pinMode(MotorA_Pin1, OUTPUT);
  pinMode(MotorA_Pin2, OUTPUT);
  pinMode(MotorA_Pin1, OUTPUT);
  pinMode(MotorB_Pin2, OUTPUT);
}

/*
  电机操作函数
  第一个参数：电机序号;a/A,b/B
  第二个参数：移动方向;0,1
*/
void Motor_Start(char Motor_Serial,uint8_t dirction)
{
  switch (Motor_Serial)
  {
    case 'a':
    case 'A':
    {
      digitalWrite(MotorA_Pin1,dirction);
      digitalWrite(MotorA_Pin2,!dirction);
      break;
    }
    case 'b':
    case 'B':
    {
      digitalWrite(MotorB_Pin1,dirction);
      digitalWrite(MotorB_Pin2,!dirction);
      break;
    }
  }
}

/*
  电机停止函数
  第一个参数：电机序号;a/A,b/B
*/
void Motor_Stop(char Motor_Serial)
{
  switch (Motor_Serial)
  {
    case 'a':
    case 'A':
    {
      digitalWrite(MotorA_Pin1,LOW);
      digitalWrite(MotorA_Pin2,LOW);
      break;
    }
    case 'b':
    case 'B':
    {
      digitalWrite(MotorB_Pin1,LOW);
      digitalWrite(MotorB_Pin2,LOW);
      break;
    }
  }
}
