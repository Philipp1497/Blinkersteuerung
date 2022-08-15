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
#include "Main.c"
#include "MockInit.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void testAppMain(void)
{
  init_Expect();
  //Gpio_select();
  
  AppMain();
}

void testGpioSelect(void)
{
  Gpio_select();
}