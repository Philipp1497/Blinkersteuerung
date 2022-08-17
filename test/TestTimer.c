#include "unity.h"
#include "UnityHelper.h"
#include "DSP280x_PieCtrl.c"
#include "DSP280x_CpuTimers.c"

#include "DSP280x_GlobalVariableDefs.c"
#include "DSP280x_Device.h"     // DSP280x Headerfile Include File
#include "DSP280x_Examples.h"   // DSP280x Examples Include File
//#include "Init.h"
#include "MockTaster.h"
#include "Timer.h"


#define LED_BEIDE       0x00180000
int counter;

int zuendung_aktiv;

int zuendung;
int warn_zustand;
int rechts_blink_zustand;
int links_blink_zustand;

int blinkcounter;

void setUp(void)
{
}

void tearDown(void)
{
}


int zuendung_aktiv; //Zündungsflag: 0 = Zündung aus, 1 = Zündung an
int flag;			//Warnblinkflag:  0 = Warnblinken aus, 1 = Warnblinken an
int richtungs_blinken_flag; // 0:keine Blinkanforderung  1: rechts blinken  2: links blinken

void testTimerIsr_when_ZuendungAndWarnblinkenAreNotActive()
{
	zuendung_aktiv = 0;		
	flag = 0;				
	
	zuendungstaster_Expect();
    warntaster_Expect();
    rechtsblinken_Expect();
    linksblinken_Expect();
	cpu_timer0_isr();
	
	TEST_ASSERT_EQUAL(0, richtungs_blinken_flag);
	printf("Requirement F1006 tested!");
}


void testTimerIsr_when_warnblinkenIsActive()
{
	flag = 1;
	
	zuendungstaster_Expect();
    warntaster_Expect();
    rechtsblinken_Expect();
    linksblinken_Expect();
	cpu_timer0_isr();
	
	TEST_ASSERT_EQUAL(0, richtungs_blinken_flag);
	printf("Requirement FXX tested!");
}

void testTimerIsr_when_rechtsblinken()
{
	flag = 0;
	zuendung_aktiv = 1;
	richtungs_blinken_flag = 1;
	blinkcounter = 0;
	
	zuendungstaster_Expect();
    warntaster_Expect();
    rechtsblinken_Expect();
    linksblinken_Expect();
	cpu_timer0_isr();
	
	//TEST_ASSERT_EQUAL(0, richtungs_blinken_flag);
	printf("Requirement FXX tested!");
}

void testTimerIsr_when_linksblinken()
{
	flag = 0;
	zuendung_aktiv = 1;
	richtungs_blinken_flag = 2;
	blinkcounter = 0;
	
	zuendungstaster_Expect();
    warntaster_Expect();
    rechtsblinken_Expect();
    linksblinken_Expect();
	cpu_timer0_isr();
	
	//TEST_ASSERT_EQUAL(0, richtungs_blinken_flag);
	printf("Requirement FXX tested!");
}

void testTimerIsr_blinkenLaengerAlsDreiSekunden()
{
	flag = 0;
	zuendung_aktiv = 1;
	links_blink_zustand = 3;
	blinkcounter = 60;
	
	zuendungstaster_Expect();
    warntaster_Expect();
    rechtsblinken_Expect();
    linksblinken_Expect();
	cpu_timer0_isr();
	
	//TEST_ASSERT_EQUAL(0, richtungs_blinken_flag);
	printf("Requirement FXX tested!");
}

void testTimerIsr_blinkenKuerzerAlsDreiSekunden()
{
	flag = 0;
	zuendung_aktiv = 1;
	links_blink_zustand = 1;
	blinkcounter = 60;
	
	zuendungstaster_Expect();
    warntaster_Expect();
    rechtsblinken_Expect();
    linksblinken_Expect();
	cpu_timer0_isr();
	
	//TEST_ASSERT_EQUAL(0, richtungs_blinken_flag);
	printf("Requirement FXX tested!");
}

void testBlinken_when_countIsZero()
{
	//turn on Leds test Case
	counter = 0;
	blinken(LED_BEIDE);
}

void testBlinken_when_countIsGreaterTen()
{
	//turn off Leds test Case
	counter = 11;
	blinken(LED_BEIDE);
}

void testBlinken_when_countIsTwentyOne()
{
	//reset Counter test Case
	counter = 21;
	blinken(LED_BEIDE);
}