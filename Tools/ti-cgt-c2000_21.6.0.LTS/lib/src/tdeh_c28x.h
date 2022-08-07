/*****************************************************************************/
/*  tdeh_c28x.h                                                              */
/*                                                                           */
/* Copyright (c) 2016 Texas Instruments Incorporated                         */
/* http://www.ti.com/                                                        */
/*                                                                           */
/*  Redistribution and  use in source  and binary forms, with  or without    */
/*  modification,  are permitted provided  that the  following conditions    */
/*  are met:                                                                 */
/*                                                                           */
/*     Redistributions  of source  code must  retain the  above copyright    */
/*     notice, this list of conditions and the following disclaimer.         */
/*                                                                           */
/*     Redistributions in binary form  must reproduce the above copyright    */
/*     notice, this  list of conditions  and the following  disclaimer in    */
/*     the  documentation  and/or   other  materials  provided  with  the    */
/*     distribution.                                                         */
/*                                                                           */
/*     Neither the  name of Texas Instruments Incorporated  nor the names    */
/*     of its  contributors may  be used to  endorse or  promote products    */
/*     derived  from   this  software  without   specific  prior  written    */
/*     permission.                                                           */
/*                                                                           */
/*  THIS SOFTWARE  IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS    */
/*  "AS IS"  AND ANY  EXPRESS OR IMPLIED  WARRANTIES, INCLUDING,  BUT NOT    */
/*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR    */
/*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT    */
/*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,    */
/*  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL  DAMAGES  (INCLUDING, BUT  NOT    */
/*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,    */
/*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY    */
/*  THEORY OF  LIABILITY, WHETHER IN CONTRACT, STRICT  LIABILITY, OR TORT    */
/*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE    */
/*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.     */
/*                                                                           */
/*                                                                           */
/*  Target-Specific header for Table-Driven Exception Handling               */
/*                                                                           */
/*****************************************************************************/
#ifndef _TDEH_C28X_H_
#define _TDEH_C28X_H_

#include "tdeh_common.h"

#ifdef __cplusplus
extern "C" {
#endif
    _Unwind_Reason_Code __c28xabi_unwind_cpp_pr0 (_Unwind_Phase      phase,
                                                  _Unwind_Exception *uexcep, 
                                                  _Unwind_Context   *context);
    _Unwind_Reason_Code __c28xabi_unwind_cpp_pr1 (_Unwind_Phase      phase,
                                                  _Unwind_Exception *uexcep, 
                                                  _Unwind_Context   *context);
    _Unwind_Reason_Code __c28xabi_unwind_cpp_pr2 (_Unwind_Phase      phase,
                                                  _Unwind_Exception *uexcep, 
                                                  _Unwind_Context   *context);
#ifdef __cplusplus
}
#endif

#define UWINS_FINISH	(0x00)

/*---------------------------------------------------------------------------*/
/* The registers that we will save in the register buffer.  The order here   */
/* is unrelated to the encoding in the unwinding instructions, but it must   */
/* remain consistent with the tables in tdeh_pr_c28x.cpp.                  */
/*---------------------------------------------------------------------------*/
typedef enum
{
    _UR_RETA,

    _UR_SP,
    _UR_PC,
    _UR_XAR1,
    _UR_XAR2,
    _UR_XAR3,
    _UR_XAR4,
    
#ifdef __TMS320C28XX_FPU32__
  #ifdef __TMS320C28XX_FPU64__
    _UR_R4L,
  #endif
    _UR_R4H,
  #ifdef __TMS320C28XX_FPU64__
    _UR_R5L,
  #endif
    _UR_R5H,
  #ifdef __TMS320C28XX_FPU64__
    _UR_R6L,
  #endif
    _UR_R6H,
  #ifdef __TMS320C28XX_FPU64__
    _UR_R7L,
  #endif
    _UR_R7H,

    _UR_REG_LAST = _UR_R7H,
#else
    _UR_REG_LAST = _UR_XAR4,
#endif

    _UR_ARG1 = _UR_XAR4
} _Unwind_Reg_Id;

/*---------------------------------------------------------------------------*/
/* Register Buffer - Used to store copy of the machine regs during unwinding */
/* _Unwind_Context is an opaque handle used to access the register           */
/* buffer. The unwinder passes _Unwind_Context* to the personality routine.  */
/*---------------------------------------------------------------------------*/
typedef _UINT32 _SAVED_REG_T;
#define _SAVED_REG_FMT "lx"

typedef struct
{
    _SAVED_REG_T core[_UR_REG_LAST+1]; /* core registers + PC */
} _Unwind_Register_Buffer;


#endif /* _TDEH_C28X_H_ */
