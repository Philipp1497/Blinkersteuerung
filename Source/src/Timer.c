#include "Timer.h"


#define LED_RECHTS      0x00100000
#define LED_LINKS       0x00080000
#define LED_BEIDE       0x00180000

int counter = 1;
int blinkcounter = 0;

extern int flag;
extern int richtungs_blinken_flag;
extern int zuendung_aktiv;

extern int links_blink_zustand;
extern int rechts_blink_zustand;



void cpu_timer0_isr(void)
{
    CpuTimer0.InterruptCount++;

    zuendungstaster();
    warntaster();
    rechtsblinken();
    linksblinken();

    if(zuendung_aktiv == 0)
    {
        richtungs_blinken_flag = 0;
        blinkcounter = 0;
    }
    if(flag == 1)
    {
        richtungs_blinken_flag = 0;
        blinkcounter = 0;
        blinken(LED_BEIDE);
    }
    if(flag == 0 && richtungs_blinken_flag == 0)
    {
        counter = 1;
        blinkcounter = 0;
        GpioDataRegs.GPACLEAR.all = LED_BEIDE;
    }
    if(zuendung_aktiv == 1)
    {
        if(blinkcounter >= 60 && links_blink_zustand != 3 && rechts_blink_zustand != 3)
        {
            richtungs_blinken_flag = 0;
            blinkcounter = 0;
        }
        if(((links_blink_zustand == 3) || (rechts_blink_zustand == 3)) && blinkcounter >= 60)
        {
            blinkcounter = 59; // falls noch aktives Signal, weiter blinken
        }

        if(flag == 0 && richtungs_blinken_flag == 1 && blinkcounter < 60)
        {
            blinkcounter++;
            blinken(LED_RECHTS);
        }
        if(flag == 0 && richtungs_blinken_flag == 2 && blinkcounter < 60)
        {
            blinkcounter++;
            blinken(LED_LINKS);
        }

    }


   // Acknowledge this interrupt to receive more interrupts from group 1
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

void blinken(long blinkmode)
{
    if(counter <= 10)
    {
        GpioDataRegs.GPADAT.all = blinkmode;
    }
    if(counter > 10)
    {
        GpioDataRegs.GPACLEAR.all = LED_BEIDE;
    }
    if(counter == 21)
    {
        counter = 1;
    }
    counter++;
}

