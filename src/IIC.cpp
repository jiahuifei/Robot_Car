#include "main.h"

void IIC_Init()
{
  Wire.begin(); // Wire初始化，作为主机加入到IIC总线
}

// 定义一个byte变量以便串口调试
void IIC_Transmission(u8 addr,Information Inform)
{
  Wire.beginTransmission(addr); // 向地址为0xAA的从机传送数据
  Wire.write(Inform.head);        		// 发送的字符串
  Wire.write(Inform.u8date);          // 发送的u8数据
  IIC_Wirte_IntNumber(Inform.intdate);
  Wire.endTransmission(); // 结束传送
}

void IIC_Recieve()
{
  Wire.requestFrom(0xAA, 6); // 向0xAA号机请求6B的数据

  while (Wire.available()) // 等待从机发送数据
  {
    // char c = Wire.read(); 		// 以字符形式接受并读取从机发来的一个字节的数据
    // Serial.print(c);         	// 串口输出该字符
  }
}

void IIC_Wirte_IntNumber(int dataToSend)
{
  byte bytesToSend[4];  // 创建一个包含4个字节的数组
  bytesToSend[0] = (byte)((dataToSend >> 24) & 0xFF);  // 最高字节
  bytesToSend[1] = (byte)((dataToSend >> 16) & 0xFF);
  bytesToSend[2] = (byte)((dataToSend >> 8) & 0xFF);
  bytesToSend[3] = (byte)(dataToSend & 0xFF);  // 最低字节
  Wire.write(bytesToSend, 4); // 发送4个字节的数据
}