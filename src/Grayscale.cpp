#include "main.h"

// 循迹灰度引脚初始化
void Trace_Gray_Pin_Init()
{
    pinMode(Trace_Left_Pin , INPUT);
    pinMode(Trace_Right_Pin , INPUT);
}
// 近红外引脚初始化
void RedLight_Pin_Init()
{
    pinMode(RedLight_Pin , INPUT);
}

// 循迹灰度数据处理
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/*
  循迹灰度数据获得函数
  参数：传感器序号;l/L,r/R
*/
long Trace_Gray_Output(char Gray_Serial)
{
    switch (Gray_Serial)
    {
    case 'r':
    case 'R':
    {
        return (map(Traceright_value, Trace_R_min, Trace_R_max, 0, 255));
        break;
    }
    case 'l':
    case 'L':
    {
        return (map(Traceleft_value, Trace_L_min, Trace_L_max, 0, 255));
        break;
    }
    }
}
