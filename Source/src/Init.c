#include "Init.h"

#define     BLINK_TIME  50000      // time in us

#ifdef CEEDLING
cregister volatile unsigned int IFR;
cregister volatile unsigned int IER;
#endif

void init()
{
    // Step 1. Initialize System Control:
    // PLL, WatchDog, enable Peripheral Clocks
    // This example function is found in the DSP280x_SysCtrl.c file.
       InitSysCtrl();
	
    // Step 2. Initalize GPIO:
    // This example function is found in the DSP280x_Gpio.c file and
    // illustrates how to set the GPIO to it's default state.
    // InitGpio();  // Skipped for this example


    // Step 3. Clear all interrupts and initialize PIE vector table:
    // Disable CPU interrupts
       DINT;
    // Initialize the PIE control registers to their default state.
    // The default state is all PIE interrupts disabled and flags
    // are cleared.
    // This function is found in the DSP280x_PieCtrl.c file.
       InitPieCtrl();

    // Disable CPU interrupts and clear all CPU interrupt flags:
       IER = 0x0000;
       IFR = 0x0000;

    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    // This will populate the entire table, even if the interrupt
    // is not used in this example.  This is useful for debug purposes.
    // The shell ISR routines are found in DSP280x_DefaultIsr.c.
    // This function is found in DSP280x_PieVect.c.
	#ifndef CEEDLING
       InitPieVectTable();
	#endif
    // Interrupts that are used in this example are re-mapped to
    // ISR functions found within this file.
       EALLOW;  // This is needed to write to EALLOW protected registers
       //PieVectTable.TINT0 = &cpu_timer0_isr;
      EDIS;    // This is needed to disable write to EALLOW protected registers

    // Step 4. Initialize all the Device Peripherals:
    // This function is found in DSP280x_InitPeripherals.c
      InitCpuTimers();   // For this example, only initialize the Cpu Timers

    // Configure CPU-Timer 0 to interrupt every second:
    // 100MHz CPU Freq, 1 second Period (in uSeconds)
      ConfigCpuTimer(&CpuTimer0, 100, BLINK_TIME);
      StartCpuTimer0();

    // Step 5. User specific code, enable interrupts:


    // Enable CPU INT1 which is connected to CPU-Timer 0:
      IER |= M_INT1;

    // Enable TINT0 in the PIE: Group 1 interrupt 7
      PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
      //PieCtrlRegs.PIEIER1.bit.INTx4 = 1;

    // Enable global Interrupts and higher priority real-time debug events:
      EINT;   // Enable Global interrupt INTM
      ERTM;   // Enable Global realtime interrupt DBGM
    // Step 6. IDLE loop. Just sit and loop forever (optional):
}
