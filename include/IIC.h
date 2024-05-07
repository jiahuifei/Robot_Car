#ifndef __IIC_H
#define __IIC_H

typedef struct
{
    char head;
    uint8_t u8date;
    long longdate;
}Information;

//从机状态结构体
static Information IIC_State=
{
    .head='s',
    .u8date=0,
    .longdate=0
};
//陀螺仪数据结构体
static Information IIC_Duoji=
{
    .head='a',
    .u8date=0,
    .longdate=0
};

void IIC_Init();
void IIC_Transmission(u8 addr,Information Inform);
void IIC_Recieve();

#endif

