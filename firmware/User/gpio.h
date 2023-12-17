#ifndef __GPIO_H
#define __GPIO_H

#include "ch32v10x_gpio.h"

#define LED_Pin GPIO_Pin_0
#define LED_GPIO_Port GPIOC

#define RB_Pin GPIO_Pin_14
#define RB_GPIO_Port GPIOB

#define MB_Pin GPIO_Pin_3
#define MB_GPIO_Port GPIOB

#define LB_Pin GPIO_Pin_15
#define LB_GPIO_Port GPIOB


#define RHQ_Pin GPIO_Pin_4
#define RHQ_GPIO_Port GPIOB
#define LVQ_Pin GPIO_Pin_5
#define LVQ_GPIO_Port GPIOB
#define BH_Pin GPIO_Pin_6
#define BH_GPIO_Port GPIOB
#define FV_Pin GPIO_Pin_7
#define FV_GPIO_Port GPIOB
#define KBD_DATA_GPIO_Port GPIOC
#define KBD_DATA_Pin GPIO_Pin_12
#define KBD_CLOCK_GPIO_Port GPIOC
#define KBD_CLOCK_Pin GPIO_Pin_3
#define KB_RESET_GPIO_Port GPIOC
#define KB_RESET_GPIO_Pin GPIO_Pin_15


void GPIO_Config();


#endif
