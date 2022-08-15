/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "MockIntrinsicsWrapper.h"

static const char* CMockString_Interrupt_Disable = "Interrupt_Disable";
static const char* CMockString_Interrupt_Enable = "Interrupt_Enable";

typedef struct _CMOCK_Interrupt_Enable_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;

} CMOCK_Interrupt_Enable_CALL_INSTANCE;

typedef struct _CMOCK_Interrupt_Disable_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;

} CMOCK_Interrupt_Disable_CALL_INSTANCE;

static struct MockIntrinsicsWrapperInstance
{
  char Interrupt_Enable_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE Interrupt_Enable_CallInstance;
  char Interrupt_Disable_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE Interrupt_Disable_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void MockIntrinsicsWrapper_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.Interrupt_Enable_CallInstance;
  if (Mock.Interrupt_Enable_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_Interrupt_Enable);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  call_instance = Mock.Interrupt_Disable_CallInstance;
  if (Mock.Interrupt_Disable_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_Interrupt_Disable);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
}

void MockIntrinsicsWrapper_Init(void)
{
  MockIntrinsicsWrapper_Destroy();
}

void MockIntrinsicsWrapper_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

void Interrupt_Enable(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Interrupt_Enable_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_Interrupt_Enable);
  cmock_call_instance = (CMOCK_Interrupt_Enable_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Interrupt_Enable_CallInstance);
  Mock.Interrupt_Enable_CallInstance = CMock_Guts_MemNext(Mock.Interrupt_Enable_CallInstance);
  if (Mock.Interrupt_Enable_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  UNITY_CLR_DETAILS();
}

void Interrupt_Enable_CMockIgnore(void)
{
  Mock.Interrupt_Enable_IgnoreBool = (char)1;
}

void Interrupt_Enable_CMockStopIgnore(void)
{
  Mock.Interrupt_Enable_IgnoreBool = (char)0;
}

void Interrupt_Enable_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Interrupt_Enable_CALL_INSTANCE));
  CMOCK_Interrupt_Enable_CALL_INSTANCE* cmock_call_instance = (CMOCK_Interrupt_Enable_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Interrupt_Enable_CallInstance = CMock_Guts_MemChain(Mock.Interrupt_Enable_CallInstance, cmock_guts_index);
  Mock.Interrupt_Enable_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
}

void Interrupt_Disable(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Interrupt_Disable_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_Interrupt_Disable);
  cmock_call_instance = (CMOCK_Interrupt_Disable_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Interrupt_Disable_CallInstance);
  Mock.Interrupt_Disable_CallInstance = CMock_Guts_MemNext(Mock.Interrupt_Disable_CallInstance);
  if (Mock.Interrupt_Disable_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  UNITY_CLR_DETAILS();
}

void Interrupt_Disable_CMockIgnore(void)
{
  Mock.Interrupt_Disable_IgnoreBool = (char)1;
}

void Interrupt_Disable_CMockStopIgnore(void)
{
  Mock.Interrupt_Disable_IgnoreBool = (char)0;
}

void Interrupt_Disable_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Interrupt_Disable_CALL_INSTANCE));
  CMOCK_Interrupt_Disable_CALL_INSTANCE* cmock_call_instance = (CMOCK_Interrupt_Disable_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Interrupt_Disable_CallInstance = CMock_Guts_MemChain(Mock.Interrupt_Disable_CallInstance, cmock_guts_index);
  Mock.Interrupt_Disable_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
}

