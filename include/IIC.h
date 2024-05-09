#ifndef __IIC_H
#define __IIC_H

typedef struct
{
    char head;
    uint8_t u8date;
    int intdate;
}Information;

//从机状态结构体
static Information IIC_State=
{
    .head='s',
    .u8date=0,
    .intdate=0
};
//陀螺仪数据结构体
static Information IIC_Duoji=
{
    .head='a',
    .u8date=0,
    .intdate=0
};

void IIC_Init();
void IIC_Transmission(u8 addr,Information Inform);
void IIC_Recieve();
void IIC_Wirte_IntNumber(int dataToSend);

#endif

