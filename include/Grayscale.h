#ifndef __GRAYSCALE_H
#define __GRAYSCALE_H

//定义近红外引脚
#define Top_RedLight_Pin  8
#define Bottom_RedLight_Pin  A2

//循迹灰度传感器参数
#define Trace_L_max 1000
#define Trace_L_min 0
#define Trace_R_max 700
#define Trace_R_min 0

//宏定义函数
#define Top_RedLight_value digitalRead(Top_RedLight_Pin)
#define Bottom_RedLight_value digitalRead(Bottom_RedLight_Pin)

// 引脚初始化
void RedLight_Pin_Init();

#endif 
