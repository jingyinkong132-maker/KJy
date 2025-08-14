#ifndef __BEEP_H__
#define __BEEP_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
#include "main.h"

#define BEEP_PORT GPIOA
#define LED_PORT GPIOA

#define BEEP_PIN GPIO_PIN_8
#define LED1_PIN GPIO_PIN_4

#define BEEP_ON HAL_GPIO_WritePin(BEEP_PORT, BEEP_PIN, GPIO_PIN_SET)
#define BEEP_OFF HAL_GPIO_WritePin(BEEP_PORT, BEEP_PIN, GPIO_PIN_RESET)
#define LED_ON HAL_GPIO_WritePin(LED_PORT, LED1_PIN, GPIO_PIN_SET)
#define LED_OFF HAL_GPIO_WritePin(LED_PORT, LED1_PIN, GPIO_PIN_RESET)

//void BEEP_Alarm(u8 time);
void BEEP_Setup(void);

#ifdef __cplusplus
}
#endif

#endif