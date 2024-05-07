#include "main.h"
//引脚初始化
void HC_SR04_Pin_Init()
{
    pinMode(Echo_Pin,INPUT);
    pinMode(Trig_Pin,OUTPUT);
}
//距离探测
float Distance_Check()
{
    digitalWrite(Trig_Pin,LOW);
    delayMicroseconds(2);
    digitalWrite(Trig_Pin,HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig_Pin,LOW);
    return (pulseIn(Echo_Pin,HIGH)/58.0);
}