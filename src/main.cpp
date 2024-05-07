#include "main.h"

void setup()
{
    Confinguration();
    
}

void loop()
{

    IIC_Receieve();  
    delay(500);
    
}

void Confinguration()
{
    IIC_Init();
    HC_SR04_Pin_Init();
    Serial.begin(9600);//串口初始化化
}

//从机接收数据并解析
void IIC_Receieve()
{
    //用iic发送结构体数据

}
