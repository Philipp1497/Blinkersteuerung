#include "DSP280x_Device.h"
#include "DSP280x_Examples.h"

void Gpio_select(void)
{

   
    EALLOW;
	GpioCtrlRegs.GPAMUX1.all = 0x00000000;  // All GPIO
	GpioCtrlRegs.GPAMUX2.all = 0x00000000;  // All GPIO
	GpioCtrlRegs.GPAMUX1.all = 0x00000000;  // All GPIO
    	GpioCtrlRegs.GPADIR.all = 0x00000800;   // GIOA11 is output
    EDIS;
     
}




