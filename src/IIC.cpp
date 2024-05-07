#include "main.h"

void IIC_Init()
{
  Wire.begin(0xAA);             // Wire初始化, 并以从设备地址0xAA的身份加入IIc总线
  Wire.onReceive(receiveEvent); // 注册一个IIC事件，用于响应主机的数据发送
  Wire.onRequest(requestEvent); // 注册一个IIC事件，用于响应主机的数据请求
}

// 当主机发送的数据被收到时，将触发 receiveEvent() 事件
void receiveEvent(int Angthing)
{
  // 循环读取收到的数据，最后一个数据单独读取
  while (1 < Wire.available())
  {
    char c = Wire.read(); // 以字符形式接收数据
    Serial.print(c);      // 串口输出该字符串
  }
  int x = Wire.read(); // 以整型形式接收数据
  Serial.println(x);   // 串口输出该整型变量
}
// 每当主机请求数据时,该函数便会执行
// 在setup()中,该函数被注册为一个事件
void requestEvent()
{
  Wire.write("hello "); // 用6B的信息回应主机的请求，hello后带一个空格
}
