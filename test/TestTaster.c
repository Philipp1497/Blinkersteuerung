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


void setUp(void)
{
}

void tearDown(void)
{
}

void testZuendungstaster()
{
	zuendungstaster();
}

void testWarntaster()
{
	warntaster();
}

void testRechtsblinken()
{
	rechtsblinken();
}

void testLinksblinken()
{
	linksblinken();
}