#include "Source/src/DSP280x_GlobalVariableDefs.c"
#include "Source/src/DSP280x_CpuTimers.c"
#include "Source/src/DSP280x_PieCtrl.c"
#include "Source/src/Timer.h"
#include "Source/src/Taster.h"
#include "Source/src/DSP280x_Examples.h"
#include "Source/src/DSP280x_Device.h"
#include "test/support/UnityHelper.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"








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



 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((zuendung_aktiv)), (

((void *)0)

), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT);

}



void testZuendungstaster_whenZuendungWasActive()

{

 zuendung_aktiv = 1;

 zuendung = 1;

 GpioDataRegs.GPADAT.bit.GPIO9 = 0;

 zuendungstaster();



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((zuendung_aktiv)), (

((void *)0)

), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);

}



void testZuendungstaster_State1TransitionTo2()

{

 zuendung = 1;

 GpioDataRegs.GPADAT.bit.GPIO9 = 0;

 zuendungstaster();



 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((zuendung)), (

((void *)0)

), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);

}



void testZuendungstaster_State2TransitionTo3()

{

 zuendung = 2;

 GpioDataRegs.GPADAT.bit.GPIO9 = 0;

 zuendungstaster();



 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((zuendung)), (

((void *)0)

), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_INT);

}



void testZuendungstaster_State3TransitionTo4()

{

 zuendung = 3;

 GpioDataRegs.GPADAT.bit.GPIO9 = 1;

 zuendungstaster();



 UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((zuendung)), (

((void *)0)

), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_INT);

}



void testZuendungstaster_State4TransitionTo1()

{

 zuendung = 4;

 GpioDataRegs.GPADAT.bit.GPIO9 = 1;

 zuendungstaster();



 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((zuendung)), (

((void *)0)

), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT);

}





void testWarntaster_whenWarnblinkenWasNotActive()

{

 flag = 0;

 warn_zustand = 1;

 GpioDataRegs.GPADAT.bit.GPIO26 = 0;

 warntaster();



 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((flag)), (

((void *)0)

), (UNITY_UINT)(94), UNITY_DISPLAY_STYLE_INT);

 printf("Requirement F1002.1 tested!");

}



void testWarntaster_whenWarnblinkenWasActive()

{

 flag = 1;

 warn_zustand = 1;

 GpioDataRegs.GPADAT.bit.GPIO26 = 0;

 warntaster();



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((flag)), (

((void *)0)

), (UNITY_UINT)(105), UNITY_DISPLAY_STYLE_INT);

 printf("Requirement F1002.2 tested!");

}



void testWarntaster_State1TransitionTo2()

{

 warn_zustand = 1;

 GpioDataRegs.GPADAT.bit.GPIO26 = 0;

 warntaster();



 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((warn_zustand)), (

((void *)0)

), (UNITY_UINT)(115), UNITY_DISPLAY_STYLE_INT);

 printf("Requirement F1001.3 tested!");

 printf("Requirement F1001.4 tested!");

}



void testWarntaster_State2TransitionTo3()

{

 warn_zustand = 2;

 GpioDataRegs.GPADAT.bit.GPIO26 = 0;

 warntaster();



 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((warn_zustand)), (

((void *)0)

), (UNITY_UINT)(126), UNITY_DISPLAY_STYLE_INT);

}



void testWarntaster_State3TransitionTo4()

{

 warn_zustand = 3;

 GpioDataRegs.GPADAT.bit.GPIO26 = 1;

 warntaster();



 UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((warn_zustand)), (

((void *)0)

), (UNITY_UINT)(135), UNITY_DISPLAY_STYLE_INT);

}



void testWarntaster_State4TransitionTo1()

{

 warn_zustand = 4;

 GpioDataRegs.GPADAT.bit.GPIO26 = 1;

 warntaster();



 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((warn_zustand)), (

((void *)0)

), (UNITY_UINT)(144), UNITY_DISPLAY_STYLE_INT);

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



 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((rechts_blink_zustand)), (

((void *)0)

), (UNITY_UINT)(181), UNITY_DISPLAY_STYLE_INT);



 printf("Requirement F1001.2 tested!");

 printf("Requirement F1001.4 tested!");

}



void testRechtsblinken_State2TransitionTo3()

{

 rechts_blink_zustand = 2;

 GpioDataRegs.GPADAT.bit.GPIO22 = 0;

 rechtsblinken();



 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((rechts_blink_zustand)), (

((void *)0)

), (UNITY_UINT)(193), UNITY_DISPLAY_STYLE_INT);

}



void testRechtsblinken_State3TransitionTo4()

{

 rechts_blink_zustand = 3;

 GpioDataRegs.GPADAT.bit.GPIO22 = 1;

 rechtsblinken();



 UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((rechts_blink_zustand)), (

((void *)0)

), (UNITY_UINT)(202), UNITY_DISPLAY_STYLE_INT);

}



void testRechtsblinken_State4TransitionTo1()

{

 rechts_blink_zustand = 4;

 GpioDataRegs.GPADAT.bit.GPIO22 = 1;

 rechtsblinken();



 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((rechts_blink_zustand)), (

((void *)0)

), (UNITY_UINT)(211), UNITY_DISPLAY_STYLE_INT);

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



 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((links_blink_zustand)), (

((void *)0)

), (UNITY_UINT)(246), UNITY_DISPLAY_STYLE_INT);



 printf("Requirement F1001.1 tested!");

 printf("Requirement F1001.4 tested!");

}



void testLinksblinken_State2TransitionTo3()

{

 links_blink_zustand = 2;

 GpioDataRegs.GPADAT.bit.GPIO17 = 0;

 linksblinken();



 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((links_blink_zustand)), (

((void *)0)

), (UNITY_UINT)(258), UNITY_DISPLAY_STYLE_INT);

}



void testLinksblinken_State3TransitionTo4()

{

 links_blink_zustand = 3;

 GpioDataRegs.GPADAT.bit.GPIO17 = 1;

 linksblinken();



 UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((links_blink_zustand)), (

((void *)0)

), (UNITY_UINT)(267), UNITY_DISPLAY_STYLE_INT);

}



void testLinksblinken_State4TransitionTo1()

{

 links_blink_zustand = 4;

 GpioDataRegs.GPADAT.bit.GPIO17 = 1;

 linksblinken();



 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((links_blink_zustand)), (

((void *)0)

), (UNITY_UINT)(276), UNITY_DISPLAY_STYLE_INT);

}
