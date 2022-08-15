#include "Source/src/DSP280x_GlobalVariableDefs.c"
#include "Source/src/DSP280x_CpuTimers.c"
#include "Source/src/DSP280x_PieCtrl.c"
#include "Source/src/Timer.h"
#include "build/test/mocks/MockTaster.h"
#include "Source/src/DSP280x_Examples.h"
#include "Source/src/DSP280x_Device.h"
#include "test/support/UnityHelper.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"












int zuendung_aktiv;

int flag;

int richtungs_blinken_flag;

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



 zuendungstaster_CMockExpect(38);

    warntaster_CMockExpect(39);

    rechtsblinken_CMockExpect(40);

    linksblinken_CMockExpect(41);

 cpu_timer0_isr();



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((richtungs_blinken_flag)), (

((void *)0)

), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_INT);

}



void testBlinken()

{

 blinken(0x00180000);

}
