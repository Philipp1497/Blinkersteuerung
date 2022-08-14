#include "unity.h"
#include "UnityHelper.h"
#include "DSP280x_PieCtrl.c"
#include "DSP280x_CpuTimers.c"

#include "DSP280x_PieVect.c"
#include "DSP280x_DefaultIsr.c"
#include "DSP280x_DefaultIsr.h"
#include "DSP280x_PieVect.h"


#include "DSP280x_GlobalVariableDefs.c"
#include "DSP280x_SysCtrl.c"
#include "DSP280x_Device.h"     // DSP280x Headerfile Include File
#include "DSP280x_Examples.h"   // DSP280x Examples Include File
#include "Init.h"


#define     BLINK_TIME  50000      // time in us



void setUp(void)
{
}

void tearDown(void)
{
}

void testInit(void)
{
  //InitSysCtrl();
  //InitPieVectTable();
  /*InitSysCtrl_Expect();
  InitPieCtrl_Expect();
  InitPieVectTable_Expect();
  InitCpuTimers_Expect();
  ConfigCpuTimer_Expect(&CpuTimer0, 100, BLINK_TIME);
  StartCpuTimer0_Expect();*/
  
  init();
}

