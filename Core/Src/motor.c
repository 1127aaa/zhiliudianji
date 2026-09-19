#include "motor.h"
#include "tim.h"

void Motor_Init(void)
{
  /* 退出待机模式，使能 TB6612 */
  HAL_GPIO_WritePin(STBY_GPIO_Port, STBY_Pin, GPIO_PIN_SET);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}

void Motor_SetSpeed(int16_t speed)
{
  /* speed: -100 ~ +100，正数正转，负数反转，0 停止 */
  if (speed > 100) {
    speed = 100;
  } else if (speed < -100) {
    speed = -100;
  }

  if (speed > 0) {
    HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_RESET);
  } else if (speed < 0) {
    HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_SET);
    speed = -speed;
  } else {
    Motor_Stop();
    return;
  }

  /* ARR = 99，故 CCR1 数值即占空比百分比 */
  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, (uint32_t)speed);
}

void Motor_Stop(void)
{
  /* 惯性停车（滑行停止） */
  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
  HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_RESET);
}
