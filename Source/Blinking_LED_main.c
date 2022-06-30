//###########################################################################
//
// FILE:    Blinking_LED.c
//
// TITLE:   DSP280x Device Getting Started Program.
//
// ASSUMPTIONS:
//
//    This program requires the DSP280x header files.  
//
//    Other then boot mode configuration, no other hardware configuration
//    is required.   
//
//
//    As supplied, this project is configured for "boot to SARAM" 
//    operation.  The 280x Boot Mode table is shown below.  
//    For information on configuring the boot mode of an eZdsp, 
//    please refer to the documentation included with the eZdsp,  
//
//       Boot      GPIO18     GPIO29    GPIO34
//       Mode      SPICLKA    SCITXDA
//                 SCITXB
//       -------------------------------------
//       Flash       1          1        1
//       SCI-A       1          1        0
//       SPI-A       1          0        1
//       I2C-A       1          0        0
//       ECAN-A      0          1        1        
//       SARAM       0          1        0  <- "boot to SARAM"
//       OTP         0          0        1
//       I/0         0          0        0 
//
//
// DESCRIPTION:
//
//    This example configures CPU Timer0 and Toggle LED(GPIO11)
//    each time the timer asserts an interrupt.
//      
//

#include "DSP280x_Device.h"     // DSP280x Headerfile Include File
#include "DSP280x_Examples.h"   // DSP280x Examples Include File

#define     BUT     GpioDataRegs.GPADAT.bit.GPIO9
#define     LED_ON  GpioDataRegs.GPASET.bit.GPIO20
#define     LED_OFF GpioDataRegs.GPASET.all |= BIT11

#define     BLINK_TIME  1000000      // time in us


// Prototype statements for functions found within this file.
interrupt void cpu_timer0_isr(void);
void Gpio_select(void);

void main(void)
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
   InitPieVectTable();

// Interrupts that are used in this example are re-mapped to
// ISR functions found within this file.
   EALLOW;  // This is needed to write to EALLOW protected registers
   PieVectTable.TINT0 = &cpu_timer0_isr;
   EDIS;    // This is needed to disable write to EALLOW protected registers

// Step 4. Initialize all the Device Peripherals:
// This function is found in DSP280x_InitPeripherals.c
// InitPeripherals(); // Not required for this example
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

// Enable global Interrupts and higher priority real-time debug events:
   EINT;   // Enable Global interrupt INTM
   ERTM;   // Enable Global realtime interrupt DBGM

// Step 6. IDLE loop. Just sit and loop forever (optional):

   Gpio_select();

   for(;;)
   {
       //LED_ON;
   }

} 

void Gpio_select(void)
{

   
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all = 0x00000000;  // All GPIO
    GpioCtrlRegs.GPAMUX2.all = 0x00000000;  // All GPIO
    GpioCtrlRegs.GPAMUX1.all = 0x00000000;  // All GPIO
    //GpioDataRegs.GPASET.all = 0x00100000;   //output letch is set
    GpioCtrlRegs.GPADIR.all = 0x00100000;   // GIOA20 is output

    GpioCtrlRegs.GPACTRL.all = 0x0000ff00;  //input qualification 510xTsysclkout for GPIO8-15
    GpioCtrlRegs.GPAQSEL1.bit.GPIO9 = 2;    //6 samples


    EDIS;
     
} 


interrupt void cpu_timer0_isr(void)
{
   CpuTimer0.InterruptCount++;

   GpioDataRegs.GPATOGGLE.bit.GPIO20 = 1;   //toggle led

   // Acknowledge this interrupt to receive more interrupts from group 1
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

//===========================================================================
// No more.
//===========================================================================
