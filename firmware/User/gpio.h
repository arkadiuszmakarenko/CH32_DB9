#ifndef __GPIO_H
#define __GPIO_H

#include "ch32v10x_gpio.h"

//CONFIG
#define CONFIG1_Pin GPIO_Pin_11
#define CONFIG1_GPIO_Port GPIOB


//LEDs
#define LED1_Pin GPIO_Pin_9
#define LED1_GPIO_Port GPIOB

#define LED2_Pin GPIO_Pin_12
#define LED2_GPIO_Port GPIOB

#define LED3_Pin GPIO_Pin_14
#define LED3_GPIO_Port GPIOC



//BUTTONS
#define RB_Pin GPIO_Pin_3
#define RB_GPIO_Port GPIOB

#define MB_Pin GPIO_Pin_6
#define MB_GPIO_Port GPIOB

#define LB_Pin GPIO_Pin_15
#define LB_GPIO_Port GPIOA

//DIRECTIONS
#define RHQ_Pin GPIO_Pin_4
#define RHQ_GPIO_Port GPIOB

#define LVQ_Pin GPIO_Pin_5
#define LVQ_GPIO_Port GPIOB

#define BH_Pin GPIO_Pin_7
#define BH_GPIO_Port GPIOB

#define FV_Pin GPIO_Pin_8
#define FV_GPIO_Port GPIOB

//DB9 PIN

#define PIN1_Pin GPIO_Pin_8
#define PIN1_GPIO_Port GPIOB

#define PIN2_Pin GPIO_Pin_7
#define PIN2_GPIO_Port GPIOB

#define PIN3_Pin GPIO_Pin_5
#define PIN3_GPIO_Port GPIOB

#define PIN4_Pin GPIO_Pin_4
#define PIN4_GPIO_Port GPIOB

#define PIN85_Pin GPIO_Pin_6
#define PIN85_GPIO_Port GPIOB

#define PIN79_Pin GPIO_Pin_3
#define PIN79_GPIO_Port GPIOB

#define PIN6_Pin GPIO_Pin_15
#define PIN6_GPIO_Port GPIOA










void GPIO_Config();


#endif
