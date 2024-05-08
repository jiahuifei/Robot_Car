#include "main.h"

unsigned char Re_buf[11], counter = 0;
unsigned char sign = 0;
float angle[3];

void setup()
{
  Confinguration();
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
}
void loop()
{
  // 超声传感器检测斜坡
  float DC=Distance_Check() ;
  if (DC < Highdis)
  {
    IIC_State.u8date = 1;
    IIC_State.longdate = 0;
    IIC_Transmission(Servent_Address, IIC_State);
    lc.setRow(0,0,lc1++);
    // Serial.print(DC);
    // Serial.println();
  }
  // 隧道红外检测
  if (!Top_RedLight_value)
  {
    IIC_State.u8date = 2;
    IIC_Transmission(Servent_Address, IIC_State);
    lc.setRow(0,1,lc2++);
    // Serial.print(!Top_RedLight_value);
    // Serial.println();
  }
//  任务红外检测
  if (!Bottom_RedLight_value)
  {
    IIC_State.u8date = 3;
    IIC_Transmission(Servent_Address, IIC_State);
    lc.setRow(0,2,lc3++);
    // Serial.print(!Bottom_RedLight_value);
    // Serial.println();
  }
  delay(500);
}
void Confinguration(void) // 外设初始化总函数
{
  IIC_Init();
  HC_SR04_Pin_Init();
  RedLight_Pin_Init();
  Serial.begin(9600);
}
