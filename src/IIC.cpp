#include "main.h"
static u8 flag=0;
LedControl lc=LedControl(12,11,13,1);
u8 lc1=0,lc2=0,lc3=0;
void IIC_Init()
{
  Wire.begin(0xAA);             // Wire初始化, 并以从设备地址0xAA的身份加入IIc总线
}

void IIC_Receieve()
{
  Wire.onReceive(receiveEvent); // 注册一个IIC事件，用于响应主机的数据发送
}
void IIC_Request()
{
  Wire.onRequest(requestEvent); // 注册一个IIC事件，用于响应主机的数据请求

}

// 当主机发送的数据被收到时，将触发 receiveEvent() 事件
void receiveEvent(int Angthing)
{
  while (Wire.available()>0)
  {
    if(flag==0)
    {
      IIC_DataGet.head = Wire.read(); // 以字符形式接收数据
      lc.setRow(0,0,lc1++);
      Serial.println(IIC_DataGet.head); // 串口输出该字符串
      flag++;
    }else if(flag==1)
    {
      IIC_DataGet.u8date= Wire.read(); // 以字符形式接收数据
      lc.setRow(0,1,lc2++);
      Serial.println(IIC_DataGet.u8date); // 串口输出该字符串
      flag++;
    }else if(flag==2)
    {
      IIC_DataGet.u16date= Wire.read(); // 以字符形式接收数据
      lc.setRow(0,2,lc3++);
      Serial.println(IIC_DataGet.u16date); // 串口输出该字符串
      flag=0;
    }

      // long Angle= Wire.read(); // 以字符形式接收数据
      // Serial.println(Angle); // 串口输出该字符串

  }
}
// 每当主机请求数据时,该函数便会执行
// 在setup()中,该函数被注册为一个事件
void requestEvent()
{
  Wire.write("hello "); // 用6B的信息回应主机的请求，hello后带一个空格
}
