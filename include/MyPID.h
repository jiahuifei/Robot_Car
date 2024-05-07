#ifndef __MyPID_H
#define __MyPID_H
#include "Arduino.h"
//位置式PID控制结构体
typedef struct {
  float Target_value;   //目标值
	float NowError;        //当前偏差 
	float LastError;     // Error[-1],上次偏差 
	float PrevError;    //Error[-2],上上偏差 
	float Kp,Ki,Kd;     //比例、积分、微分系数
	float Integral;     //积分值
	float Output_value;   //输出值
}PID;

void PID_Param_Init(PID PosionPID);
float PosionPID_Realize(PID *pid, float Actual_value);
float AddPID_Realize(PID *pid, float Actual_value);

#endif
