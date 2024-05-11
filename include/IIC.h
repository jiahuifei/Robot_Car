#ifndef __IIC_H
#define __IIC_H

//从机状态结构体
void IIC_Init();
void IIC_Receieve();
void IIC_Request();
void receiveEvent(int Angthing);
void requestEvent();
int IIC_Read_IntNumber();

#endif

