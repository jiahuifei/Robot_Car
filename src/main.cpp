#include "main.h"
// extern LedControl lc;
// extern u8 lc1, lc2, lc3;
// SoftwareSerial mySerial(13, 11);

void setup()
{
    Confinguration();
    //   lc.shutdown(0,false);
    //   lc.setIntensity(0,4);
    //   lc.clearDisplay(0);

    //   lc.setRow(0,0,0xff);
    //   lc.setRow(0,1,B10000001);
    //   lc.setRow(0,2,B10100101);
    //   lc.setRow(0,3,B10000001);
    //   lc.setRow(0,4,B11000011);
    //   lc.setRow(0,5,B10100101);
    //   lc.setRow(0,6,B10011001);
    //   lc.setRow(0,7,0xff);
    IIC_Receieve();
}

void loop()
{
    // if(IIC_DataGet.head=='s')
    // {
    // if(IIC_DataGet.u8date==1)
    // Trace();
    // Angle_Trace();
    // Motor_Start('L',150);
    // Motor_Start('r',-150);

    // }
    // RDlongData= RecieveData[2]<<12+RecieveData[3]<<8+RecieveData[4]<<4+RecieveData[5];
}

void Confinguration()
{
    IIC_Init();
    Trace_Gray_Pin_Init();
    Motor_Pin_Init();
    Serial.begin(115200); // 串口初始化化
}

void StateZero() // 灰度循迹
{
    Trace();
}
void StateOne() // 角度循迹
{
    Angle_Trace();
}
void StateTwo() // 过隧道
{
    Trace();
    Servo_Enable(0);
    ServoGo(0, Hole_ServoAngle);
}
void StateThree() // 灰度循迹
{
    Trace();
}
