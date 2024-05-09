#ifndef __SERVO_DRIVER_H
#define __SERVO_DRIVER_H

#define Servo_Arm_Pin  7
#define Servo_Hand_Pin  11

#define Hole_ServoAngle 90
//相关函数
void Servo_Enable(uint8_t Servo_Serial);
void Servo_Disable(uint8_t Servo_Serial);
void ServoGo(int Servo_Serial , int where);

#endif
