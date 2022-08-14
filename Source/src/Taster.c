#include "Taster.h"
#include "Timer.h"


extern int counter;
extern int blinkcounter;
int flag = 0;

int richtungs_blinken_flag = 0; // 1: rechts blinken  2: links blinken
int zuendung_aktiv = 0;

int zuendung = 1;
int warn_zustand = 1;
int rechts_blink_zustand = 1;
int links_blink_zustand = 1;

void zuendungstaster(void)
{
    if(zuendung == 1 && GpioDataRegs.GPADAT.bit.GPIO9 == 0)   //Taster wird gedrueckt (fallende Flanke)
        {
        zuendung = 2;
            if(zuendung_aktiv == 0)
            {
                zuendung_aktiv = 1;
            }
            else
            {
                zuendung_aktiv = 0;
            }
        }
        else if (zuendung == 2 && GpioDataRegs.GPADAT.bit.GPIO9 == 0)   //Taster wird gehalten
        {
            zuendung = 3;
        }
        else if (zuendung == 3 && GpioDataRegs.GPADAT.bit.GPIO9 == 1)   //Taster wird losgelassen (steigende Flanke)
        {
            zuendung = 4;
        }
        else if (zuendung == 4 && GpioDataRegs.GPADAT.bit.GPIO9 == 1)   //Taster losgelassen
        {
            zuendung = 1;
        }
}



void warntaster(void)
{
    if(warn_zustand == 1 && GpioDataRegs.GPADAT.bit.GPIO26 == 0)   //Taster wird gedrueckt (steigende Flanke)
    {
        warn_zustand = 2;
        if(flag == 0)
        {
            counter = 0;
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    else if (warn_zustand == 2 && GpioDataRegs.GPADAT.bit.GPIO26 == 0)   //Taster wird gehalten
    {
         warn_zustand = 3;
    }
    else if (warn_zustand == 3 && GpioDataRegs.GPADAT.bit.GPIO26 == 1)   //Taster wird losgelassen (fallende Flanke)
    {
        warn_zustand = 4;
    }
    else if (warn_zustand == 4 && GpioDataRegs.GPADAT.bit.GPIO26 == 1)   //Taster losgelassen
    {
        warn_zustand = 1;
    }

}



void rechtsblinken(void)
{
    if(rechts_blink_zustand == 1 && GpioDataRegs.GPADAT.bit.GPIO22 == 0)   //Taster wird gedrueckt (steigende Flanke)
    {
        rechts_blink_zustand = 2;
        switch(richtungs_blinken_flag){
        case 0:
            richtungs_blinken_flag = 1;
            break;
        case 1:
            counter = 1;
            blinkcounter = 0;
            break;
        case 2:
            counter = 1;
            blinkcounter = 0;
            richtungs_blinken_flag = 1;
            break;
        }
//        if(richtungs_blinken_flag == 0)
//        {
//            richtungs_blinken_flag = 1;
//        }
//        else if(richtungs_blinken_flag == 1)
//        {
//            richtungs_blinken_flag = 0;
//        }
    }
    else if (rechts_blink_zustand == 2 && GpioDataRegs.GPADAT.bit.GPIO22 == 0)   //Taster wird gehalten
    {
        rechts_blink_zustand = 3;
    }
    else if (rechts_blink_zustand == 3 && GpioDataRegs.GPADAT.bit.GPIO22 == 1)   //Taster wird losgelassen (fallende Flanke)
    {
        rechts_blink_zustand = 4;
        //richtungs_blinken_flag = 0;
    }
    else if (rechts_blink_zustand == 4 && GpioDataRegs.GPADAT.bit.GPIO22 == 1)   //Taster losgelassen
    {
        rechts_blink_zustand = 1;
    }
}


void linksblinken(void)
{
    if(links_blink_zustand == 1 && GpioDataRegs.GPADAT.bit.GPIO17 == 0)   //Taster wird gedrueckt (steigende Flanke)
    {
        links_blink_zustand = 2;
        switch(richtungs_blinken_flag){
        case 0:
            richtungs_blinken_flag = 2;
            break;
        case 1:
            counter = 1;
            blinkcounter = 0;
            richtungs_blinken_flag = 2;
            break;
        case 2:
            counter = 1;
            blinkcounter = 0;
            break;
        }
//        if(richtungs_blinken_flag == 0)
//        {
//            richtungs_blinken_flag = 2;
//        }
//        else if (richtungs_blinken_flag == 2)
//        {
//            richtungs_blinken_flag = 0;
//        }
    }
    else if (links_blink_zustand == 2 && GpioDataRegs.GPADAT.bit.GPIO17 == 0)   //Taster wird gehalten
    {
        links_blink_zustand = 3;
    }
    else if (links_blink_zustand == 3 && GpioDataRegs.GPADAT.bit.GPIO17 == 1)   //Taster wird losgelassen (fallende Flanke)
    {
        links_blink_zustand = 4;
        //richtungs_blinken_flag = 0;
    }
    else if (links_blink_zustand == 4 && GpioDataRegs.GPADAT.bit.GPIO17 == 1)   //Taster losgelassen
    {
        links_blink_zustand = 1;
    }

}
