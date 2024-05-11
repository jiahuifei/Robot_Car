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
//IIC状态初始机初始化
void IIC_Init();
//IIC数据请求和发送
void IIC_Transmission(u8 addr,Information Inform);
//IIC数据应答和接受
void IIC_Recieve();
//IIC发送四字节函数
void IIC_Wirte_IntNumber(int dataToSend);

#endif

