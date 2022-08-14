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

int zuendung_aktiv;
int flag;
int richtungs_blinken_flag; // 1: rechts blinken  2: links blinken
int zuendung_aktiv;

int zuendung;
int warn_zustand;
int rechts_blink_zustand;
int links_blink_zustand;

void setUp(void)
{
}

void tearDown(void)
{
}

void testTimerIsr()
{
	zuendung_aktiv = 0;
	
	zuendungstaster_Expect();
    warntaster_Expect();
    rechtsblinken_Expect();
    linksblinken_Expect();
	cpu_timer0_isr();
	
	TEST_ASSERT_EQUAL(0, richtungs_blinken_flag);
}

void testBlinken()
{
	blinken(LED_BEIDE);
}