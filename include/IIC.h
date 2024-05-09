#ifndef __IIC_H
#define __IIC_H

typedef struct
{
    char head;
    uint8_t u8date;
    int intdate;
}Information;
//从机状态结构体
static Information IIC_DataGet=
{
    .head=0,
    .u8date=0,
    .intdate=0
};

void IIC_Init();
void IIC_Receieve();
void IIC_Request();
void receiveEvent(int Angthing);
void requestEvent();
int IIC_Read_IntNumber();

#endif

