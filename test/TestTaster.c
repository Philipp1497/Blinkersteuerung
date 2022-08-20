#include "unity.h"
#include "UnityHelper.h"
#include "DSP280x_PieCtrl.c"
#include "DSP280x_CpuTimers.c"

#include "DSP280x_GlobalVariableDefs.c"
#include "DSP280x_Device.h"     // DSP280x Headerfile Include File
#include "DSP280x_Examples.h"   // DSP280x Examples Include File
//#include "Init.h"
#include "Taster.h"
#include "Timer.h"


int flag;
int richtungs_blinken_flag;
int zuendung;
int zuendung_aktiv;
int warn_zustand;
int rechts_blink_zustand;
int links_blink_zustand;

void setUp(void)
{
}

void tearDown(void)
{
}

void testZuendungstaster_whenZuendungWasNotActive()
{
	zuendung_aktiv = 0;
	zuendung = 1;
	GpioDataRegs.GPADAT.bit.GPIO9 = 0;
	zuendungstaster();
	
	TEST_ASSERT_EQUAL(1, zuendung_aktiv);
}

void testZuendungstaster_whenZuendungWasActive()
{
	zuendung_aktiv = 1;
	zuendung = 1;
	GpioDataRegs.GPADAT.bit.GPIO9 = 0;
	zuendungstaster();
	
	TEST_ASSERT_EQUAL(0, zuendung_aktiv);
}

void testZuendungstaster_State1TransitionTo2()
{
	zuendung = 1;
	GpioDataRegs.GPADAT.bit.GPIO9 = 0;
	zuendungstaster();
	
	TEST_ASSERT_EQUAL(2, zuendung);
}

void testZuendungstaster_State2TransitionTo3()
{
	zuendung = 2;
	GpioDataRegs.GPADAT.bit.GPIO9 = 0;
	zuendungstaster();
	
	TEST_ASSERT_EQUAL(3, zuendung);
}

void testZuendungstaster_State3TransitionTo4()
{
	zuendung = 3;
	GpioDataRegs.GPADAT.bit.GPIO9 = 1;
	zuendungstaster();
	
	TEST_ASSERT_EQUAL(4, zuendung);
}

void testZuendungstaster_State4TransitionTo1()
{
	zuendung = 4;
	GpioDataRegs.GPADAT.bit.GPIO9 = 1;
	zuendungstaster();
	
	TEST_ASSERT_EQUAL(1, zuendung);
}


void testWarntaster_whenWarnblinkenWasNotActive()
{
	flag = 0;
	warn_zustand = 1;
	GpioDataRegs.GPADAT.bit.GPIO26 = 0;
	warntaster();
	
	TEST_ASSERT_EQUAL(1, flag);
	printf("Requirement F1002.1 tested!");
}

void testWarntaster_whenWarnblinkenWasActive()
{
	flag = 1;
	warn_zustand = 1;
	GpioDataRegs.GPADAT.bit.GPIO26 = 0;
	warntaster();
	
	TEST_ASSERT_EQUAL(0, flag);
	printf("Requirement F1002.2 tested!");
}

void testWarntaster_State1TransitionTo2()
{
	warn_zustand = 1;
	GpioDataRegs.GPADAT.bit.GPIO26 = 0;
	warntaster();
	
	TEST_ASSERT_EQUAL(2, warn_zustand);
	printf("Requirement F1001.3 tested!");
	printf("Requirement F1001.4 tested!");
}

void testWarntaster_State2TransitionTo3()
{
	warn_zustand = 2;
	GpioDataRegs.GPADAT.bit.GPIO26 = 0;
	warntaster();
	
	TEST_ASSERT_EQUAL(3, warn_zustand);
}

void testWarntaster_State3TransitionTo4()
{
	warn_zustand = 3;
	GpioDataRegs.GPADAT.bit.GPIO26 = 1;
	warntaster();
	
	TEST_ASSERT_EQUAL(4, warn_zustand);
}

void testWarntaster_State4TransitionTo1()
{
	warn_zustand = 4;
	GpioDataRegs.GPADAT.bit.GPIO26 = 1;
	warntaster();
	
	TEST_ASSERT_EQUAL(1, warn_zustand);
}





void testRechtsblinken_RichtungsBlinkenAus()
{
	rechts_blink_zustand = 1;
	GpioDataRegs.GPADAT.bit.GPIO22 = 0;
	richtungs_blinken_flag = 0;
	rechtsblinken();
}

void testRechtsblinken_RechtsblinkenAktiviert()
{
	rechts_blink_zustand = 1;
	GpioDataRegs.GPADAT.bit.GPIO22 = 0;
	richtungs_blinken_flag = 1;
	rechtsblinken();
}

void testRechtsblinken_LinksblinkenAktiviert()
{
	rechts_blink_zustand = 1;
	GpioDataRegs.GPADAT.bit.GPIO22 = 0;
	richtungs_blinken_flag = 2;
	rechtsblinken();
}

void testRechtsblinken_State1TransitionTo2()
{
	rechts_blink_zustand = 1;
	GpioDataRegs.GPADAT.bit.GPIO22 = 0;
	rechtsblinken();
	
	TEST_ASSERT_EQUAL(2, rechts_blink_zustand);
	
	printf("Requirement F1001.2 tested!");
	printf("Requirement F1001.4 tested!");
}

void testRechtsblinken_State2TransitionTo3()
{
	rechts_blink_zustand = 2;
	GpioDataRegs.GPADAT.bit.GPIO22 = 0;
	rechtsblinken();
	
	TEST_ASSERT_EQUAL(3, rechts_blink_zustand);
}

void testRechtsblinken_State3TransitionTo4()
{
	rechts_blink_zustand = 3;
	GpioDataRegs.GPADAT.bit.GPIO22 = 1;
	rechtsblinken();
	
	TEST_ASSERT_EQUAL(4, rechts_blink_zustand);
}

void testRechtsblinken_State4TransitionTo1()
{
	rechts_blink_zustand = 4;
	GpioDataRegs.GPADAT.bit.GPIO22 = 1;
	rechtsblinken();
	
	TEST_ASSERT_EQUAL(1, rechts_blink_zustand);
}



void testLinksblinken_RichtungsBlinkenAus()
{
	links_blink_zustand = 1;
	GpioDataRegs.GPADAT.bit.GPIO17 = 0;
	richtungs_blinken_flag = 0;
	linksblinken();
}

void testLinksblinken_RechtsblinkenAktiviert()
{
	links_blink_zustand = 1;
	GpioDataRegs.GPADAT.bit.GPIO17 = 0;
	richtungs_blinken_flag = 1;
	linksblinken();
}

void testLinksblinken_LinksblinkenAktiviert()
{
	links_blink_zustand = 1;
	GpioDataRegs.GPADAT.bit.GPIO17 = 0;
	richtungs_blinken_flag = 2;
	linksblinken();
}

void testLinksblinken_State1TransitionTo2()
{
	links_blink_zustand = 1;
	GpioDataRegs.GPADAT.bit.GPIO17 = 0;
	linksblinken();
	
	TEST_ASSERT_EQUAL(2, links_blink_zustand);
	
	printf("Requirement F1001.1 tested!");
	printf("Requirement F1001.4 tested!");
}

void testLinksblinken_State2TransitionTo3()
{
	links_blink_zustand = 2;
	GpioDataRegs.GPADAT.bit.GPIO17 = 0;
	linksblinken();
	
	TEST_ASSERT_EQUAL(3, links_blink_zustand);
}

void testLinksblinken_State3TransitionTo4()
{
	links_blink_zustand = 3;
	GpioDataRegs.GPADAT.bit.GPIO17 = 1;
	linksblinken();
	
	TEST_ASSERT_EQUAL(4, links_blink_zustand);
}

void testLinksblinken_State4TransitionTo1()
{
	links_blink_zustand = 4;
	GpioDataRegs.GPADAT.bit.GPIO17 = 1;
	linksblinken();
	
	TEST_ASSERT_EQUAL(1, links_blink_zustand);
}