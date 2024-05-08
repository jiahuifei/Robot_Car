#include "main.h"
// 近红外引脚初始化
void RedLight_Pin_Init()
{
    pinMode(Top_RedLight_Pin, INPUT);
    pinMode(Bottom_RedLight_Pin,INPUT);
}

