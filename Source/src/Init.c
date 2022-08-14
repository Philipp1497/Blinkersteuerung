#include "Init.h"

#define     BLINK_TIME  50000      // time in us


volatile unsigned int IFR;
volatile unsigned int IER;

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

void InitSysCtrl(void)
{

   // Disable the watchdog
   DisableDog();
	
   // Initialize the PLL control: PLLCR and CLKINDIV
   // DSP28_PLLCR and DSP28_CLKINDIV are defined in DSP280x_Examples.h
   //InitPll(DSP28_PLLCR,DSP28_CLKINDIV);

   // Initialize the peripheral clocks
   InitPeripheralClocks();
}

void DisableDog(void)
{
    EALLOW;
    SysCtrlRegs.WDCR= 0x0068;
    EDIS;
}
/*
void InitPll(Uint16 val, Uint16 clkindiv)
{
   volatile Uint16 iVol;

   // Make sure the PLL is not running in limp mode
   if (SysCtrlRegs.PLLSTS.bit.MCLKSTS != 0)
   {
      // Missing external clock has been detected
      // Replace this line with a call to an appropriate
      // SystemShutdown(); function.
      asm("        ESTOP0");
   }

   // CLKINDIV MUST be 0 before PLLCR can be changed from
   // 0x0000. It is set to 0 by an external reset XRSn
   if (SysCtrlRegs.PLLSTS.bit.CLKINDIV != 0)
   {
       SysCtrlRegs.PLLSTS.bit.CLKINDIV = 0;
   }

   // Change the PLLCR
   if (SysCtrlRegs.PLLCR.bit.DIV != val)
   {

      EALLOW;
      // Before setting PLLCR turn off missing clock detect logic
      SysCtrlRegs.PLLSTS.bit.MCLKOFF = 1;
      SysCtrlRegs.PLLCR.bit.DIV = val;
      EDIS;

      // Optional: Wait for PLL to lock.
      // During this time the CPU will switch to OSCCLK/2 until
      // the PLL is stable.  Once the PLL is stable the CPU will
      // switch to the new PLL value.
      //
      // This time-to-lock is monitored by a PLL lock counter.
      //
      // Code is not required to sit and wait for the PLL to lock.
      // However, if the code does anything that is timing critical,
      // and requires the correct clock be locked, then it is best to
      // wait until this switching has completed.

      // Wait for the PLL lock bit to be set.
      // Note this bit is not available on 281x devices.  For those devices
      // use a software loop to perform the required count.

      // The watchdog should be disabled before this loop, or fed within
      // the loop via ServiceDog().

	  // Uncomment to disable the watchdog
      DisableDog();

      while(SysCtrlRegs.PLLSTS.bit.PLLLOCKS != 1)
      {
	      // Uncomment to service the watchdog
          // ServiceDog();
      }

      EALLOW;
      SysCtrlRegs.PLLSTS.bit.MCLKOFF = 0;
      SysCtrlRegs.PLLSTS.bit.CLKINDIV != clkindiv;
      EDIS;
    }
}*/

void InitPeripheralClocks(void)
{
   EALLOW;

// HISPCP/LOSPCP prescale register settings, normally it will be set to default values
   SysCtrlRegs.HISPCP.all = 0x0001;
   SysCtrlRegs.LOSPCP.all = 0x0002;

// XCLKOUT to SYSCLKOUT ratio.  By default XCLKOUT = 1/4 SYSCLKOUT
//   SysCtrlRegs.XCLK.bit.XCLKOUTDIV=2;	//XCLKOUT is sistem clock
   SysCtrlRegs.XCLK.bit.XCLKOUTDIV=3;   //XCLKOUT is off


// Peripheral clock enables set for the selected peripherals.
// If you are not using a peripheral leave the clock off
// to save on power.
//
// Note: not all peripherals are available on all 280x derivates.
// Refer to the datasheet for your particular device.
//
// This function is not written to be an example of efficient code.

   SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;    // ADC
   SysCtrlRegs.PCLKCR0.bit.I2CAENCLK = 1;   // I2C
   SysCtrlRegs.PCLKCR1.bit.ECAP1ENCLK = 1;  // eCAP1
   SysCtrlRegs.PCLKCR1.bit.ECAP2ENCLK = 1;  // eCAP2
   SysCtrlRegs.PCLKCR1.bit.EPWM1ENCLK = 1;  // ePWM1
   SysCtrlRegs.PCLKCR1.bit.EPWM2ENCLK = 1;  // ePWM2
   SysCtrlRegs.PCLKCR1.bit.EPWM3ENCLK = 1;  // ePWM3
   SysCtrlRegs.PCLKCR0.bit.SCIAENCLK = 1;   // SCI-A
   SysCtrlRegs.PCLKCR0.bit.SPIAENCLK = 1;   // SPI-A

   if(DevEmuRegs.PARTID.bit.PARTNO != PARTNO_28015 &&
      DevEmuRegs.PARTID.bit.PARTNO != PARTNO_28016)
   {
      SysCtrlRegs.PCLKCR1.bit.EQEP1ENCLK = 1;  // eQEP1
      SysCtrlRegs.PCLKCR0.bit.SPIBENCLK = 1;   // SPI-B
   }

   if(DevEmuRegs.PARTID.bit.PARTNO != PARTNO_2801 &&
      DevEmuRegs.PARTID.bit.PARTNO != PARTNO_2802)
   {
	   SysCtrlRegs.PCLKCR1.bit.EPWM4ENCLK = 1;  // ePWM4
   }

   if(DevEmuRegs.PARTID.bit.PARTNO != PARTNO_28015)
   {
      SysCtrlRegs.PCLKCR0.bit.ECANAENCLK=1;    // eCAN-A
   }

   if(DevEmuRegs.PARTID.bit.PARTNO == PARTNO_2809 ||
      DevEmuRegs.PARTID.bit.PARTNO == PARTNO_2808 ||
      DevEmuRegs.PARTID.bit.PARTNO == PARTNO_2806 )
   {
	   SysCtrlRegs.PCLKCR1.bit.ECAP3ENCLK = 1;  // eCAP3
	   SysCtrlRegs.PCLKCR1.bit.ECAP4ENCLK = 1;  // eCAP4
	   SysCtrlRegs.PCLKCR1.bit.EPWM5ENCLK = 1;  // ePWM5
	   SysCtrlRegs.PCLKCR1.bit.EPWM6ENCLK = 1;  // ePWM6
	   SysCtrlRegs.PCLKCR0.bit.SCIBENCLK = 1;   // SCI-B
	   SysCtrlRegs.PCLKCR0.bit.SPICENCLK = 1;   // SPI-C
	   SysCtrlRegs.PCLKCR0.bit.SPIDENCLK = 1;   // SPI-D
	   SysCtrlRegs.PCLKCR1.bit.EQEP2ENCLK = 1;  // eQEP2

   }
   if(DevEmuRegs.PARTID.bit.PARTNO == PARTNO_2808 ||
      DevEmuRegs.PARTID.bit.PARTNO == PARTNO_2809)
   {
	   SysCtrlRegs.PCLKCR0.bit.ECANBENCLK=1;    // eCAN-B
   }

   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;       // Enable TBCLK within the ePWM

   EDIS;
}