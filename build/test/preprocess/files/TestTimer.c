#include "Source/src/DSP280x_GlobalVariableDefs.c"
#include "Source/src/DSP280x_CpuTimers.c"
#include "Source/src/DSP280x_PieCtrl.c"
#include "Source/src/Timer.h"
#include "build/test/mocks/MockTaster.h"
#include "Source/src/DSP280x_Examples.h"
#include "Source/src/DSP280x_Device.h"
#include "test/support/UnityHelper.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"










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





int zuendung_aktiv;

int flag;

int richtungs_blinken_flag;



void testTimerIsr_when_ZuendungAndWarnblinkenAreNotActive()

{

 zuendung_aktiv = 0;

 flag = 0;



 zuendungstaster_CMockExpect(44);

    warntaster_CMockExpect(45);

    rechtsblinken_CMockExpect(46);

    linksblinken_CMockExpect(47);

 cpu_timer0_isr();



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((richtungs_blinken_flag)), (

((void *)0)

), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

 printf("Requirement F1006 tested!");

}





void testTimerIsr_when_warnblinkenIsActive()

{

 flag = 1;



 zuendungstaster_CMockExpect(59);

    warntaster_CMockExpect(60);

    rechtsblinken_CMockExpect(61);

    linksblinken_CMockExpect(62);

 cpu_timer0_isr();



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((richtungs_blinken_flag)), (

((void *)0)

), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_INT);

 printf("Requirement FXX tested!");

}



void testTimerIsr_when_rechtsblinken()

{

 flag = 0;

 zuendung_aktiv = 1;

 richtungs_blinken_flag = 1;

 blinkcounter = 0;



 zuendungstaster_CMockExpect(76);

    warntaster_CMockExpect(77);

    rechtsblinken_CMockExpect(78);

    linksblinken_CMockExpect(79);

 cpu_timer0_isr();





 printf("Requirement FXX tested!");

}



void testTimerIsr_when_linksblinken()

{

 flag = 0;

 zuendung_aktiv = 1;

 richtungs_blinken_flag = 2;

 blinkcounter = 0;



 zuendungstaster_CMockExpect(93);

    warntaster_CMockExpect(94);

    rechtsblinken_CMockExpect(95);

    linksblinken_CMockExpect(96);

 cpu_timer0_isr();





 printf("Requirement FXX tested!");

}



void testTimerIsr_blinkenLaengerAlsDreiSekunden()

{

 flag = 0;

 zuendung_aktiv = 1;

 links_blink_zustand = 3;

 blinkcounter = 60;



 zuendungstaster_CMockExpect(110);

    warntaster_CMockExpect(111);

    rechtsblinken_CMockExpect(112);

    linksblinken_CMockExpect(113);

 cpu_timer0_isr();





 printf("Requirement FXX tested!");

}



void testTimerIsr_blinkenKuerzerAlsDreiSekunden()

{

 flag = 0;

 zuendung_aktiv = 1;

 links_blink_zustand = 1;

 blinkcounter = 60;



 zuendungstaster_CMockExpect(127);

    warntaster_CMockExpect(128);

    rechtsblinken_CMockExpect(129);

    linksblinken_CMockExpect(130);

 cpu_timer0_isr();





 printf("Requirement FXX tested!");

}



void testBlinken_when_countIsZero()

{



 counter = 0;

 blinken(0x00180000);

}



void testBlinken_when_countIsGreaterTen()

{



 counter = 11;

 blinken(0x00180000);

}



void testBlinken_when_countIsTwentyOne()

{



 counter = 21;

 blinken(0x00180000);

}
