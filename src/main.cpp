#include "main.h"
LedControl lc = LedControl(12, 11, 13, 1);
static u8 lc1 = 0, lc2 = 0, lc3 = 0;
// SoftwareSerial mySerial(13, 11);

Ultrasonic myHC(Trig_Pin, Echo_Pin);
u8 trace_state = 0;

void setup()
{
    Confinguration();
    lc.shutdown(0, false);
    lc.setIntensity(0, 4);
    lc.clearDisplay(0);
    //   lc.setRow(0,0,0x0);
    //   lc.setRow(0,1,0x1c);
    //   lc.setRow(0,2,0x14);
    //   lc.setRow(0,3,0x14);
    //   lc.setRow(0,4,0x14);
    //   lc.setRow(0,5,0x14);
    //   lc.setRow(0,6,B10011001);
    //   lc.setRow(0,7,0xff);
    IIC_Receieve();
}

void loop()
{
    Serial.println(myHC.read());
    while (trace_state == 0)
    {
        lc.setRow(0, 0, B00000001);
        Trace();
        if (myHC.read() < 9)
            trace_state = 1;
    }
    while (trace_state == 1)
    {
        lc.setRow(0, 0, B00000010);

        if (myHC.read() > 15)
            trace_state = 2;
    }
    while (trace_state == 2)
    {
        lc.setRow(0, 0, B00000100);

        if (myHC.read() < 14)
            trace_state = 3;
    }
    while (trace_state == 3)
    {
        lc.setRow(0, 0, B00001000);

        if (myHC.read() > 15)
            trace_state = 4; // 减速
    }
    while (trace_state == 4) // 下坡
    {
        lc.setRow(0, 0, B00010000);

        if (myHC.read() < 9)
            trace_state = 5;
    }
    while (trace_state == 5)
    {
        lc.setRow(0, 0, B00100000);

        Trace();
        if (digitalRead(8) == 0)
            trace_state = 6;
    }
    while (trace_state == 6)
    {
        lc.setRow(0, 0, B01000000);

        Trace();
        if (digitalRead(8) == 1)
            trace_state = 7;
    }
    while (trace_state == 7)
    {
        lc.setRow(0, 0, B10000000);

        Trace();
        if (myHC.read() < 7)
            trace_state = 8;
    }
    while (trace_state == 8)
    {
        lc.setRow(0, 1, B00000001);

        Trace();
        if (myHC.read() < 7)
            trace_state = 8;
    }
    delay(1);
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
    pinMode(8, INPUT);
    pinMode(7, INPUT);
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
