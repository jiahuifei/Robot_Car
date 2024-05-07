#include "main.h"

// 用户函数
void Confinguration(void); // 外设初始化总函数

void setup()
{
  Confinguration();

}
void loop()
{
    //超声传感器检测
    if(Distance_Check() < XiepoHighdis)
    {
      IIC_State.u8date=2;
      IIC_Transmission(Servent_Address,IIC_State);
    }
  
}
void Confinguration(void) // 外设初始化总函数
{
  IIC_Init();
  HC_SR04_Pin_Init();

}