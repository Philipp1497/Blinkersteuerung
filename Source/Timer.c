#include "Timer.h"

int counter = 0;

extern int flag;
extern int richtungs_blinken_flag;
//extern int rechts_blinken_flag;
//extern int links_blinken_flag;
extern int pressed;

void blinken(long blinkmode);

interrupt void cpu_timer0_isr(void)
{
    CpuTimer0.InterruptCount++;

    zuendungstaster();
    warntaster();
    rechtsblinken();
    linksblinken();

    if(pressed == 0)
    {
        richtungs_blinken_flag = 0;
    }
    if(flag == 1)
    {
        richtungs_blinken_flag = 0;
        blinken(0x00180000);
    }
    if(flag == 0 && richtungs_blinken_flag == 0)
    {
        counter = 0;
        GpioDataRegs.GPACLEAR.all = 0x00180000;
    }
    if(pressed == 1)
    {
        if(flag == 0 && richtungs_blinken_flag == 1)
        {
            blinken(0x00100000);
        }
        if(flag == 0 && richtungs_blinken_flag == 2)
        {
            blinken(0x00080000);
        }
    }


   // Acknowledge this interrupt to receive more interrupts from group 1
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

void blinken(long blinkmode)
{
    if(counter < 10)
    {
        GpioDataRegs.GPADAT.all = blinkmode;
        counter++;
    }
    if(counter >= 10)
    {
        GpioDataRegs.GPACLEAR.all = 0x00180000;
        counter++;
        if(counter == 20)
        {
            counter = 0;
        }
    }
}
