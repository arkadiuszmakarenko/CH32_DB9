#ifndef __MOUSEMSX_H
#define __MOUSEMSX_H

#include "stdint.h"
#include "USB_Host/usb_mouse.h"
#include "utils.h"

void ProcessMouseMSX(HID_MOUSE_Info_TypeDef *mousemap);

#endif
