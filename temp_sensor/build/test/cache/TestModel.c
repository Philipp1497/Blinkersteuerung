#include "build/test/mocks/MockTemperatureFilter.h"
#include "build/test/mocks/MockTaskScheduler.h"
#include "src/Model.h"
#include "src/Types.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void testInitShouldCallSchedulerAndTemperatureFilterInit(void)

{

  TaskScheduler_Init_CMockExpect(17);

  TemperatureFilter_Init_CMockExpect(18);

  Model_Init();

}
