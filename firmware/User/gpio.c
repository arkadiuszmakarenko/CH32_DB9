#include "gpio.h"

void GPIO_Config()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);


    GPIO_InitTypeDef GPIO_InitStructure = {0};

    /*Configure GPIO pin Output Level */
    GPIO_WriteBit(LED1_GPIO_Port,LED1_Pin, Bit_SET);
    GPIO_WriteBit(LED2_GPIO_Port,LED2_Pin, Bit_SET);
    GPIO_WriteBit(LED3_GPIO_Port,LED3_Pin, Bit_SET);

    //GPIO_WriteBit(GPIOC, KBD_DATA_Pin| KBD_CLOCK_Pin | KB_RESET_GPIO_Pin, Bit_SET);
    //Configure input CONFIG1
    GPIO_InitStructure.GPIO_Pin = CONFIG1_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(CONFIG1_GPIO_Port, &GPIO_InitStructure);




    /*Configure LEDS*/
    GPIO_InitStructure.GPIO_Pin = LED1_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED1_GPIO_Port, &GPIO_InitStructure);


    GPIO_InitStructure.GPIO_Pin = LED2_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED2_GPIO_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED3_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED3_GPIO_Port, &GPIO_InitStructure);

    /*Configure DB9 PINS*/
    GPIO_InitStructure.GPIO_Pin = PIN1_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(PIN1_GPIO_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = PIN2_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(PIN2_GPIO_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = PIN3_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(PIN3_GPIO_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = PIN4_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(PIN4_GPIO_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = PIN85_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(PIN85_GPIO_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = PIN79_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(PIN79_GPIO_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = PIN6_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(PIN6_GPIO_Port, &GPIO_InitStructure);


}
