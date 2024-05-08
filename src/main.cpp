#include "main.h"

void setup()
{
    Confinguration();
//   LedControl lc=LedControl(12,11,13,1);

//   lc.shutdown(0,false);
//   lc.setIntensity(0,8);
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
    if(IIC_DataGet.head=='s')
    {
        if(IIC_DataGet.u8date==1)
            StateZero();
    }
}

void Confinguration()
{
    IIC_Init();
    // HC_SR04_Pin_Init();
    Serial.begin(9600);//串口初始化化
}

void StateZero()//灰度循迹
{
    Trace();
}
void StateOne()//灰度循迹
{
    Trace();
}
void StateTwo()//灰度循迹
{
    Trace();
}
void StateThree()//灰度循迹
{
    Trace();
}
