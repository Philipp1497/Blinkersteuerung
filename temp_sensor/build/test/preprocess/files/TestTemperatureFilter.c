#include "src/TemperatureFilter.h"
#include "src/Types.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




void setUp(void)

{

  TemperatureFilter_Init();

}



void tearDown(void)

{

}



void testShouldInitializeTemeratureToInvalidValue(void)

{

  TemperatureFilter_Init();

  UnityAssertFloatSpecial((UNITY_FLOAT)((TemperatureFilter_GetTemperatureInCelcius())), (

 ((void *)0)

 ), (UNITY_UINT)(18), UNITY_FLOAT_IS_NEG_INF);

}



void testShouldInitializeTemperatureAfterCallToInit(void)

{

  TemperatureFilter_Init();

  TemperatureFilter_ProcessInput(17.8f);

  UnityAssertFloatsWithin((UNITY_FLOAT)((0.0001f)), (UNITY_FLOAT)((17.8f)), (UNITY_FLOAT)((TemperatureFilter_GetTemperatureInCelcius())), (

 ((void *)0)

 ), (UNITY_UINT)(25));



  TemperatureFilter_Init();

  TemperatureFilter_ProcessInput(32.6f);

  UnityAssertFloatsWithin((UNITY_FLOAT)((0.0001f)), (UNITY_FLOAT)((32.6f)), (UNITY_FLOAT)((TemperatureFilter_GetTemperatureInCelcius())), (

 ((void *)0)

 ), (UNITY_UINT)(29));

}



void setValueAndVerifyResponse(float input, float response)

{

  float actual;

  TemperatureFilter_ProcessInput(input);

  actual = TemperatureFilter_GetTemperatureInCelcius();



  if (input == +

               __builtin_inf() 

                        ||

      input == -

               __builtin_inf() 

                        ||

      

     (sizeof (

     input

     ) == sizeof (float) ? __isnanf (

     input

     ) : sizeof (

     input

     ) == sizeof (double) ? __isnan (

     input

     ) : __isnanl (

     input

     ))

                 )

  {

    UnityAssertFloatSpecial((UNITY_FLOAT)((actual)), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_FLOAT_IS_NEG_INF);

  }

  else

  {

    UnityAssertFloatsWithin((UNITY_FLOAT)((0.0001f)), (UNITY_FLOAT)((response)), (UNITY_FLOAT)((actual)), (

   ((void *)0)

   ), (UNITY_UINT)(46));

  }

}



void testShouldWeightEachSubsequentValueBy25PercentAfterInitialValue(void)

{

  TemperatureFilter_Init();

  setValueAndVerifyResponse(0.0f, 0.0f);

  setValueAndVerifyResponse(10.0f, 2.5f);

  setValueAndVerifyResponse(10.0f, 4.375f);

  setValueAndVerifyResponse(10.0f, 5.78125f);



  TemperatureFilter_Init();

  setValueAndVerifyResponse(100.0f, 100.0f);

  setValueAndVerifyResponse(0.0f, 75.0f);

  setValueAndVerifyResponse(0.0f, 56.25f);

  setValueAndVerifyResponse(0.0f, 42.1875f);

}



void setInvalidTemperatureAndVerifyReinitialized(float invalidTemperature)

{

  TemperatureFilter_Init();

  setValueAndVerifyResponse(100.0f, 100.0f);

  setValueAndVerifyResponse(invalidTemperature, -

                                                __builtin_inf()

                                                        );

  setValueAndVerifyResponse(14.3f, 14.3f);

}



void testShouldResetAverageIfPassedInfinityOrInvalidValue(void)

{

  setInvalidTemperatureAndVerifyReinitialized(-

                                              __builtin_inf()

                                                      );

  setInvalidTemperatureAndVerifyReinitialized(+

                                              __builtin_inf()

                                                      );

  setInvalidTemperatureAndVerifyReinitialized(+

                                              __builtin_nan("")

                                                 );

  setInvalidTemperatureAndVerifyReinitialized(-

                                              __builtin_nan("")

                                                 );

}
