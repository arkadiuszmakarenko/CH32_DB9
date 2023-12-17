#ifndef __GAMEPAD_H
#define __GAMEPAD_H

#include "USB_Host/usb_gamepad.h"
#include "gpio.h"

void ProcessGamepad(HID_gamepad_Info_TypeDef* joymap);

#endif
