#include "Source/src/Main.c"
#include "Source/src/DSP280x_GlobalVariableDefs.c"
#include "Source/src/DSP280x_CpuTimers.c"
#include "Source/src/DSP280x_PieCtrl.c"
#include "build/test/mocks/MockInit.h"
#include "Source/src/Timer.h"
#include "Source/src/Taster.h"
#include "Source/src/DSP280x_Examples.h"
#include "Source/src/DSP280x_Device.h"
#include "Source/test/support/UnityHelper.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






void setUp(void)

{

}



void tearDown(void)

{

}



void testAppMain(void)

{

  init_CMockExpect(25);





  AppMain();

}



void testGpioSelect(void)

{

  Gpio_select();

}
