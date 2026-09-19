#ifndef __MOTOR_H
#define __MOTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

void Motor_Init(void);
void Motor_SetSpeed(int16_t speed);
void Motor_Stop(void);

#ifdef __cplusplus
}
#endif

#endif /* __MOTOR_H */
