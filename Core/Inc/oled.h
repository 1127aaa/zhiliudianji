#ifndef __OLED_H
#define __OLED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

uint8_t OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowString(uint8_t x, uint8_t page, const char *str);
void OLED_ShowSpeed(int16_t speed);

#ifdef __cplusplus
}
#endif

#endif /* __OLED_H */
