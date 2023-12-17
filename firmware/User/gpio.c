#include "gpio.h"

void GPIO_Config()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);


    GPIO_InitTypeDef GPIO_InitStructure = {0};

    /*Configure GPIO pin Output Level */
    GPIO_WriteBit(LED_GPIO_Port,LED_Pin, Bit_SET);
    GPIO_WriteBit(GPIOB, RHQ_Pin|LVQ_Pin|BH_Pin|FV_Pin, Bit_RESET);
    GPIO_WriteBit(GPIOB, LB_Pin|RB_Pin|MB_Pin, Bit_SET);
    GPIO_WriteBit(GPIOC, KBD_DATA_Pin| KBD_CLOCK_Pin | KB_RESET_GPIO_Pin, Bit_SET);


    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /*Configure GPIO pins : PCPin PCPin PCPin */
    GPIO_InitStructure.GPIO_Pin = LED_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);


    GPIO_InitStructure.GPIO_Pin = LB_Pin|RB_Pin|MB_Pin|RHQ_Pin|LVQ_Pin|BH_Pin
                            |FV_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);


    GPIO_InitStructure.GPIO_Pin = KBD_DATA_Pin| KBD_CLOCK_Pin | KB_RESET_GPIO_Pin ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;;
    GPIO_Init(GPIOC, &GPIO_InitStructure);


}
