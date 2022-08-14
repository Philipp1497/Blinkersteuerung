#include "DSP280x_Device.h"     // DSP280x Headerfile Include File
#include "DSP280x_Examples.h"   // DSP280x Examples Include File
#include "Init.h"
#include "Taster.h"

/*#define     BUT     GpioDataRegs.GPADAT.bit.GPIO9
#define     LED_ON  GpioDataRegs.GPASET.bit.GPIO20
#define     LED_OFF GpioDataRegs.GPASET.all |= BIT11
*/

/**

    Gpio Belegung:

    Warnblinktaster:    Gpio23 = Versorgung ,   Gpio26 = Signal

    Rechtsblinktaster:  Gpio7  = Versorgung ,   Gpio22 = Signal

    Linksblinktaster:   Gpio3  = Versorgung ,   Gpio17 = Signal

    Versorgung LEDS:    Gpio20 , Gpio19

**/
extern int zuendung_aktiv;

//interrupt void pin_26_isr(void);
void Gpio_select(void);
#ifndef CEEDLING
int AppMain(void)
{
   init();
   Gpio_select();

   while(1)
   {
       if(zuendung_aktiv == 1)
       {
           GpioDataRegs.GPACLEAR.all |= BIT11; //Status Led an
       }
       else
       {
           GpioDataRegs.GPASET.all |= BIT11;
       }
   }
   return 0;
}
#endif
#ifdef CEEDLING
int AppMain(void)
{
   init();
   Gpio_select();

   if(zuendung_aktiv == 1)
   {
	   GpioDataRegs.GPACLEAR.all |= BIT11; //Status Led an
   }
   else
   {
	   GpioDataRegs.GPASET.all |= BIT11;
   }
   return 0;
}
#endif

#ifndef CEEDLING
int main(void)
{
   return AppMain();
}
#endif
void Gpio_select(void)
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all = 0x00000000;  // All GPIO
    GpioCtrlRegs.GPAMUX2.all = 0x00000000;  // All GPIO
    GpioCtrlRegs.GPAMUX1.all = 0x00000000;  // All GPIO
    GpioDataRegs.GPASET.bit.GPIO3;   //output letch is set
    GpioDataRegs.GPASET.bit.GPIO7;   //output letch is set
    GpioDataRegs.GPASET.bit.GPIO23;   //output letch is set
    GpioCtrlRegs.GPADIR.all = 0x00980888;   //  GPIO3,GPIO7,GPIO11, GPIO19, GPIO20 and GPIO23 are outputs

    GpioDataRegs.GPASET.all |= BIT11;

    GpioCtrlRegs.GPACTRL.all = 0x0000ff00;  //input qualification 510xTsysclkout for GPIO8-15
    GpioCtrlRegs.GPAQSEL1.bit.GPIO9 = 2;    //6 samples
//    GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL |= 0x1A; //Enable GPIO26 as Interrupt Source
//    XIntruptRegs.XINT1CR.bit.ENABLE |= 0x01;
//    XIntruptRegs.XINT1CR.bit.POLARITY |= 0x00;


    EDIS;
     
}



/*interrupt void pin_26_isr(void)
{
    if(flag == 0)
    {
        flag = 1;
        //counter = 0;
    }
    else
    {
        flag = 0;
        //counter = 0;
        //GpioDataRegs.GPACLEAR.all = 0x00180000;
    }

    // Acknowledge this interrupt to receive more interrupts from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}*/
//===========================================================================
// No more.
//===========================================================================
