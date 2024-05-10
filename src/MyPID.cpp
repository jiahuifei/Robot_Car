#include "main.h"
// 定义实际速度或位置
int Actual_value;

/**
 * @brief  PID参数初始化
 *	@note 	无
 * @retval 无
 */
void PID_Param_Init(PID PosionPID)
{
  PosionPID.Target_value = 0.0;
  PosionPID.Output_value = 0.0;
  PosionPID.NowError = 0.0;
  PosionPID.LastError = 0.0;
  PosionPID.Integral = 0.0;
  PosionPID.Kp = 0.02;
  PosionPID.Ki = 0.1;
  PosionPID.Kd = 0.05;
}

/**
 * @brief  位置PID算法实现
 * @param  Actual_value:实际测量值
 *	@note 	无
 * @retval 通过PID计算后的输出
 */
float PosionPID_Realize(PID *pid, float Actual_value)
{
  /*计算目标值与实际值的误差*/
  if (abs(Actual_value) > 1)
  {
    pid->NowError = pid->Target_value - Actual_value;
    /*积分项*/
    pid->Integral += pid->NowError;

    //积分限幅
    if(pid->Integral > maxIntegral) pid->Integral=maxIntegral;
    else if(pid->Integral < minIntegral) pid->Integral=minIntegral;

    pid->Output_value = pid->Kp * pid->NowError + pid->Ki * pid->Integral 
                        + pid->Kd * (pid->NowError - pid->LastError);
    
    /*误差传递*/
    pid->LastError = pid->NowError;
    
  }
  else
  {

    pid->LastError = 0;

    pid->NowError = 0;
  }
  /*返回当前实际值*/
  return pid->Output_value;
}

/**
 * @brief  速度PID算法实现
 * @param  Actual_value:实际值
 *	@note 	无
 * @retval 通过PID计算后的输出
 */
float AddPID_Realize(PID *pid, float Actual_value)
{
  /*计算目标值与实际值的误差*/
  pid->NowError = pid->Target_value - Actual_value;
  /*PID算法实现，照搬公式*/
  pid->Output_value = pid->Kp * (pid->NowError); //+ pid->Ki * pid->NowError + pid->Kd * (pid->NowError - 2 * pid->LastError + pid->PrevError);
  /*误差传递*/
  pid->PrevError = pid->LastError;
  pid->LastError = pid->NowError;
  /*返回当前实际值*/
  return pid->Output_value;
}
