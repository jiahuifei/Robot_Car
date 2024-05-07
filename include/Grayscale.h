#ifndef __GRAYSCALE_H
#define __GRAYSCALE_H

//循迹灰度传感器引脚
#define Trace_Left_Pin A4
#define Trace_Right_Pin  A3

//定义近红外引脚
#define Top_RedLight_Pin_  12
#define Bottom_RedLight_Pin_  11

//循迹灰度传感器参数
#define Trace_L_max 1000
#define Trace_L_min 0
#define Trace_R_max 700
#define Trace_R_min 0

//宏定义函数
#define Traceleft_value analogRead(Trace_Left_Pin)
#define Traceright_value analogRead(Trace_Right_Pin)
#define RedLight_value analogRead(RedLight_Pin)

// 引脚初始化
void Trace_Gray_Pin_Init();
void RedLight_Pin_Init();

// 循迹灰度数据处理
long map(long x, long in_min, long in_max, long out_min, long out_max);

/*
  循迹灰度数据获得函数
  参数：传感器序号;l/L,r/R
*/
long Trace_Gray_Output(char Gray_Serial);

#endif 
