#include "main.h"

// LedControl lc = LedControl(12, 11, 13, 1);
// u8 lc1 = 0, lc2 = 0, lc3 = 0;

SoftwareSerial mySerial(9, 10); // 定义D9、D10分别为RX、TX
Ultrasonic myHC(Trig_Pin,Echo_Pin);

unsigned char Re_buf[11], counter = 0;
unsigned char sign = 0;
static float angle[3];

u8 SendHex[6];


void Confinguration(void) // 外设初始化总函数
{
  // IIC_Init();
  // HC_SR04_Pin_Init();
  // RedLight_Pin_Init();
  Serial.begin(115200);
  myComm.begin(115200);
}

void setup()
{
  Confinguration();
  // lc.shutdown(0, false);
  // lc.setIntensity(0, 8);
  // lc.clearDisplay(0);
}
void loop()
{
  // 超声传感器检测斜坡
  if ( myHC.read()< Highdis)
  {
    SendData.state = 's';
    SendData.u8data= 1;
    myComm.send(SendData);
    // IIC_Transmission(Servent_Address,IIC_State);
    // Serial.print(IIC_State.u8date,HEX);
    // lc.setRow(0, 0, lc1++);
    // Serial.println("i am here");
    // Serial.println();
  }
  // 隧道红外检测
  if (!Top_RedLight_value)
  {
    SendData.state = 's';
    SendData.u8data= 2;
    myComm.send(SendData);
    // IIC_Transmission(Servent_Address, IIC_State);
    // lc.setRow(0, 1, lc2++);
    // Serial.println("i am here1");
    // Serial.println();
  }
  //  任务红外检测
  if (!Bottom_RedLight_value)
  {
    SendData.state = 's';
    SendData.u8data= 3;
    myComm.send(SendData);
    // IIC_Transmission(Servent_Address, IIC_State);
    // lc.setRow(0, 2, lc3++);
    // Serial.println("i am here2");
    // Serial.println();
  }
  serialEvent();
  delay(1);
}
void serialEvent()
{
  while(Serial.available())
  {
    Re_buf[counter] = (unsigned char)Serial.read();
    if (counter == 0 && Re_buf[0] != 0x55)
      return; // 第0号数据不是帧头
    counter++;
    if (counter == 11) // 接收到11个数据
    {
      counter = 0; // 重新赋值，准备下一帧数据的接收
      if (Re_buf[0] == 0x55) // 检查帧头
      {
        switch (Re_buf[1])
        {
        case 0x51:
          break;
        case 0x52:
          break;
        case 0x53:
          angle[0] = (short(Re_buf[3] << 8 | Re_buf[2])) / 32768.0 * 180;
          angle[1] = (short(Re_buf[5] << 8 | Re_buf[4])) / 32768.0 * 180;
          angle[2] = (short(Re_buf[7] << 8 | Re_buf[6])) / 32768.0 * 180;
          // Serial.print("<any>:");
          // Serial.print(angle[0]);
          // Serial.print(",");
          // // Serial.print(" ");
          // Serial.print(angle[1]);
          // Serial.print(",");
          // // Serial.print(" ");
          // Serial.print(angle[2]);
          // Serial.println();
          int64_t SendAngle=int64_t (angle[2]*100);
          if(SendHex[0]=='s')
          {
            SendHex[0] = 'a';
            SendHex[1] = 0;
            mySerial.write(SendAngle>>32);
            mySerial.write(SendAngle>>16);
            mySerial.write(SendAngle>>8);
            mySerial.write(SendAngle);

          }
          break;
        }
      }
      break;
    }   
  }
}