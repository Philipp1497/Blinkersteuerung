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

int flag;

int richtungs_blinken_flag;

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



void testTimerIsr_when_zuendungIsNotActive()

{

 zuendung_aktiv = 0;

 flag = 0;



 zuendungstaster_CMockExpect(41);

    warntaster_CMockExpect(42);

    rechtsblinken_CMockExpect(43);

    linksblinken_CMockExpect(44);

 cpu_timer0_isr();



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((richtungs_blinken_flag)), (

((void *)0)

), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);

 printf("Requirement F1006 tested!");

}





void testTimerIsr_when_warnblinkenIsActive()

{

 flag = 1;



 zuendungstaster_CMockExpect(56);

    warntaster_CMockExpect(57);

    rechtsblinken_CMockExpect(58);

    linksblinken_CMockExpect(59);

 cpu_timer0_isr();



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((richtungs_blinken_flag)), (

((void *)0)

), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_INT);

 printf("Requirement FXX tested!");

}



void testTimerIsr_when_rechtsblinken()

{

 flag = 0;

 zuendung_aktiv = 1;

 richtungs_blinken_flag = 1;

 blinkcounter = 0;



 zuendungstaster_CMockExpect(73);

    warntaster_CMockExpect(74);

    rechtsblinken_CMockExpect(75);

    linksblinken_CMockExpect(76);

 cpu_timer0_isr();





 printf("Requirement FXX tested!");

}



void testTimerIsr_when_linksblinken()

{

 flag = 0;

 zuendung_aktiv = 1;

 richtungs_blinken_flag = 2;

 blinkcounter = 0;



 zuendungstaster_CMockExpect(90);

    warntaster_CMockExpect(91);

    rechtsblinken_CMockExpect(92);

    linksblinken_CMockExpect(93);

 cpu_timer0_isr();





 printf("Requirement FXX tested!");

}



void testTimerIsr_blinkenLaengerAlsDreiSekunden()

{

 flag = 0;

 zuendung_aktiv = 1;

 links_blink_zustand = 3;

 blinkcounter = 60;



 zuendungstaster_CMockExpect(107);

    warntaster_CMockExpect(108);

    rechtsblinken_CMockExpect(109);

    linksblinken_CMockExpect(110);

 cpu_timer0_isr();





 printf("Requirement FXX tested!");

}



void testTimerIsr_blinkenKuerzerAlsDreiSekunden()

{

 flag = 0;

 zuendung_aktiv = 1;

 links_blink_zustand = 1;

 blinkcounter = 60;



 zuendungstaster_CMockExpect(124);

    warntaster_CMockExpect(125);

    rechtsblinken_CMockExpect(126);

    linksblinken_CMockExpect(127);

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
