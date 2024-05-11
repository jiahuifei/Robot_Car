#include "main.h"

int  AngleValue;
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
  第一个参数：电机序号;r/R,l/L
  第二个参数：移动方向和速度;-255~255
*/
void Motor_Start(char Motor_Serial,int16_t Speed)
{
  switch (Motor_Serial)
  {
    case 'r':
    case 'R':
    {
      if(Speed>0)
      {
        analogWrite(MotorA_Pin1,Speed);
        analogWrite(MotorA_Pin2,0);
      }else 
      {
        analogWrite(MotorA_Pin1,0);
        analogWrite(MotorA_Pin2,-Speed);
      }
      break;
    }
    case 'l':
    case 'L':
    {
      if(Speed>0)
      {
        analogWrite(MotorB_Pin1,Speed);
        analogWrite(MotorB_Pin2,0);
      }else 
      {
        analogWrite(MotorB_Pin1,0);
        analogWrite(MotorB_Pin2,-Speed);
      }
      break;
    }
  }
}

/*
  电机停止函数
  第一个参数：电机序号;r/R,l/L
*/
void Motor_Stop(char Motor_Serial)
{
  switch (Motor_Serial)
  {
    case 'r':
    case 'R':
    {
      analogWrite(MotorA_Pin1,0);
      analogWrite(MotorA_Pin2,0);
      break;
    }
    case 'l':
    case 'L':
    {
      analogWrite(MotorB_Pin1,0);
      analogWrite(MotorB_Pin2,0);
      break;
    }
  }
}

void Trace()
{
  int turn_judge = Trace_Gray_Output('l') - Trace_Gray_Output('r');
          // Serial.print("<any>:");
          // Serial.print(Trace_Gray_Output('l'));
          // Serial.print(",");
          // // Serial.print(" ");
          // Serial.print(Trace_Gray_Output('r'));
          // Serial.print(",");
          // // Serial.print(" ");
          // Serial.print(turn_judge);
          // Serial.println();
  if (turn_judge > R_judge) // 如果右侧传感器探测到黑线，向右转
  {
    Motor_Start('L',220);
    Motor_Start('r',-150);
  }
  else if (turn_judge < L_judge) // 如果左侧传感器探测到黑线，向左转
  {
    Motor_Start('l',-150);
    Motor_Start('r',220);
  }
  else // 两侧传感器均探测到黑线，直行
  {
    Motor_Start('l',220);
    Motor_Start('r',220);
  }
}

void Angle_Trace()
{
  //   AngleValue=IIC_Receieve();
  //   Serial.println(AngleValue);
  // if(AngleValue/100.0>1.5)//右转
  // {
  //   // Motor_Start('L',220);
  //   // Motor_Start('r',-150);
  //   Serial.println("r");
  // }else if (AngleValue/100.0<-1.5)//左转
  // {
  //   // Motor_Start('l',-150);
  //   // Motor_Start('r',220);
  //    Serial.println("l");
  // }else
  // {
  //   // Motor_Start('l',220);
  //   // Motor_Start('r',220);
  //   Serial.println("z");
  // }
}