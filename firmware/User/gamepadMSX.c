#include <gamepadMSX.h>

void ProcessGamepadMSX(HID_gamepad_Info_TypeDef* joymap)
{

			if (joymap == NULL) return;

			 DUG_PRINTF( "Gamepad MSX val(%02x)\r\n", joymap->gamepad_data );

				//RIGHT
			    GPIO_WriteBit(PIN4_GPIO_Port, PIN4_Pin, !(joymap->gamepad_data & 0x1));

			    //LEFT
			    GPIO_WriteBit(PIN3_GPIO_Port, PIN3_Pin, !(joymap->gamepad_data >> 1 & 0x1));

			    //DOWN
				GPIO_WriteBit(PIN2_GPIO_Port, PIN2_Pin, !(joymap->gamepad_data >> 2 & 0x1));

				//UP
				GPIO_WriteBit(PIN1_GPIO_Port, PIN1_Pin, !(joymap->gamepad_data >> 3 & 0x1));

				//BUTTON1
				GPIO_WriteBit(PIN6_GPIO_Port, PIN6_Pin, !(joymap->gamepad_data >> 4 & 0x1));

				//BUTTON2
				GPIO_WriteBit(PIN79_GPIO_Port, PIN79_Pin, !(joymap->gamepad_data >> 5 & 0x1));

}
