#include "build/test/mocks/MockTaskScheduler.h"
#include "src/TimerModel.h"
#include "src/Types.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void testUpdateTimeShouldDelegateToTaskScheduler(void)

{

  TaskScheduler_Update_CMockExpect(16, 19387L);

  TimerModel_UpdateTime(19387L);

}
