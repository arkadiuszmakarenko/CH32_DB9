/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2020/04/30
 * Description        : Main program body.
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

/*
 *@Note
 *USART Print debugging routine:
 *USART1_Tx(PA9).
 *This example demonstrates using USART1(PA9) as a print debug port output.
 *
 */

#include "debug.h"

/*******************************************************************************/
/* Header File */
#include <USB_Host/usb_gamepad.h>
#include <USB_Host/usb_mouse.h>
#include <USB_Host/usb_keyboard.h>
#include "USB_Host/usb_host_config.h"
#include "utils.h"
#include "tim.h"
#include "mouseAmiga.h"
#include "mouseMSX.h"
#include "gpio.h"
#include "gamepadAmiga.h"
#include "gamepadMSX.h"

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */



int main(void)
{
    uint8_t CONFIG1 = 0;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(115200);
    DUG_PRINTF( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    DUG_PRINTF( "SystemClk:%d\r\n", SystemCoreClock );
    DUG_PRINTF( "USBHD HOST KM Test\r\n" );

    /* Initialize timer for obtaining keyboard and mouse data at regular intervals */
    TIM3_Init( 9, SystemCoreClock / 10000 - 1 );
    DUG_PRINTF( "TIM3 Init OK!\r\n" );

    /* Configure USB clock and initialize USB host */
#if DEF_USBHD_PORT_EN
    USBHD_RCC_Init( );
    USBHD_Host_Init( ENABLE , PWR_VDD_SupplyVoltage());
    memset( &RootHubDev.bStatus, 0, sizeof( ROOT_HUB_DEVICE ) );
    memset( &HostCtl[ DEF_USBHD_PORT_INDEX * DEF_ONE_USB_SUP_DEV_TOTAL ].InterfaceNum, 0, DEF_ONE_USB_SUP_DEV_TOTAL * sizeof( HOST_CTL ) );
#endif
	GPIO_Config();
	 //Read value of CONFIG1
	CONFIG1 = GPIO_ReadInputDataBit(CONFIG1_GPIO_Port, CONFIG1_Pin);


	DUG_PRINTF( "CONFIG1:%d\r\n", CONFIG1);

	while (1) {
		USBH_MainDeal();

		//Handle HID Device
		if (RootHubDev.bType == USB_DEV_CLASS_HID) {

			for (int itf = 0; itf < DEF_INTERFACE_NUM_MAX; itf++) {
				//Handle mouse
				if (HostCtl[0].Interface[itf].HIDRptDesc.type
						== REPORT_TYPE_MOUSE) {
					HID_MOUSE_Info_TypeDef *mousemap = USBH_GetMouseInfo(
							&HostCtl[0].Interface[itf]);
	                 if(CONFIG1)
	                 {
	                    ProcessMouse(mousemap);
	                 }else
	                 {
	                    ProcessMouseMSX(mousemap);
	                 }
				}

				//Handle gamepad
				if (HostCtl[0].Interface[itf].HIDRptDesc.type
						== REPORT_TYPE_JOYSTICK) {

		HID_gamepad_Info_TypeDef *gamepad = GetGamepadInfo(
							&HostCtl[0].Interface[itf]);

		                    if(CONFIG1)
                            {
                                ProcessGamepadAmiga(gamepad);
                            } else
                            {
                                ProcessGamepadMSX(gamepad);
                            }
				}
			}
		}

		//Handle HUB Device

		if (RootHubDev.bType == USB_DEV_CLASS_HUB) {

			//Iterate over all devices
			for (uint8_t device = 1; device < 5; device++)
			{
				//Iterate over all interfaces
				for (int itf = 0; itf < DEF_INTERFACE_NUM_MAX; itf++) {
					//Handle mouse
					if (HostCtl[device].Interface[itf].HIDRptDesc.type
							== REPORT_TYPE_MOUSE) {
						HID_MOUSE_Info_TypeDef *mousemap = USBH_GetMouseInfo(
								&HostCtl[device].Interface[itf]);


                        if(CONFIG1)
                        {
							ProcessMouse(mousemap);
                        }else
                         {
							ProcessMouseMSX(mousemap);
                         }

					}

					//Handle gamepad
					if (HostCtl[device].Interface[itf].HIDRptDesc.type
							== REPORT_TYPE_JOYSTICK) {

			HID_gamepad_Info_TypeDef *gamepad = GetGamepadInfo(
								&HostCtl[device].Interface[itf]);

			                if(CONFIG1)
			                {
			                    ProcessGamepadAmiga(gamepad);
			                } else
			                {
			                    ProcessGamepadMSX(gamepad);
			                }

					    }
				    }
				}
			}
		}
	}
