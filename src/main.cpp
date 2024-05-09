#include "main.h"
extern LedControl lc;
extern u8 lc1,lc2,lc3;
SoftwareSerial mySerial(13,11);

struct myData
{
    char  state;
    uint8_t  u8data;
    float   floatdata;
};
myData RecieveData;
SoftSerialCommunication<myData> myComm(13, 11);



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
    // IIC_Receieve();  

}

void loop()
{
    // if(IIC_DataGet.head=='s')
    // {
    //     if(IIC_DataGet.u8date==1)
    //         StateZero();
    // }
    myComm.receive(&RecieveData);
    Serial.print(RecieveData.state);
    Serial.print(RecieveData.u8data);
    Serial.print(RecieveData.floatdata);
    // RDlongData= RecieveData[2]<<12+RecieveData[3]<<8+RecieveData[4]<<4+RecieveData[5];
}

void Confinguration()
{
    // IIC_Init();
    // HC_SR04_Pin_Init();
    Serial.begin(115200);//串口初始化化
    mySerial.begin(115200);
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
