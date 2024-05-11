#include "main.h"

typedef struct
{
    char head;
    uint8_t u8date;
    int intdate;
}Information;

Information IIC_DataGet=
{
    .head=0,
    .u8date=0,
    .intdate=0
};

static u8 flag = 0;
void IIC_Init()
{
  Wire.begin(0xAA); // Wire初始化, 并以从设备地址0xAA的身份加入IIc总线
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
  while (Wire.available() > 0)
  {
    if (flag == 0)
    {
      IIC_DataGet.head = Wire.read(); // 以字符形式接收数据
      // lc.setRow(0,0,lc1++);
      // Serial.println(IIC_DataGet.head); // 串口输出该字符串
      flag++;
    }
    else if (flag == 1)
    {
      IIC_DataGet.u8date = Wire.read(); // 以字符形式接收数据
      // lc.setRow(0,1,lc2++);
      // Serial.println(IIC_DataGet.u8date); // 串口输出该字符串
      flag++;
    }
    else if (flag == 2)
    {
      IIC_DataGet.intdate = IIC_Read_IntNumber(); // 以字符形式接收数据
      // lc.setRow(0,2,lc3++);
      // Serial.println(IIC_DataGet.intdate); // 串口输出该字符串
      flag = 0;

      if(trace_state<5&&trace_state>0)
      {
        AngleValue = IIC_DataGet.intdate;
        Serial.println(AngleValue);
        if (AngleValue / 100.0 > 3) // 右转
        {
          Motor_Start('L', 220);
          Motor_Start('r', -150);
          Serial.println("r");
        }
        else if (AngleValue / 100.0 < -3) // 左转
        {
          Motor_Start('l', -150);
          Motor_Start('r', 220);
          Serial.println("l");
        }
        else
        {
          Motor_Start('l', 220);
          Motor_Start('r', 220);
          Serial.println("z");
        }
      }
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

int IIC_Read_IntNumber()
{
  byte receivedBytes[4]; // 创建一个包含4个字节的数组
  // 读取4个字节的数据
  for (int i = 0; i < 4; i++)
  {
    receivedBytes[i] = Wire.read();
  }
  // 重新组装成int类型的数据
  int receivedData = int(receivedBytes[0] << 24) +
                     int(receivedBytes[1] << 16) +
                     int(receivedBytes[2] << 8) +
                     int(receivedBytes[3]);
  return receivedData;
}
