#include "DSP280x_Device.h"     // DSP280x Headerfile Include File
#include "DSP280x_Examples.h"   // DSP280x Examples Include File

#define     BUT     GpioDataRegs.GPADAT.bit.GPIO9
#define     LED_ON  GpioDataRegs.GPASET.bit.GPIO20
#define     LED_OFF GpioDataRegs.GPASET.all |= BIT11

#define     BLINK_TIME  50000      // time in us


// Prototype statements for functions found within this file.
interrupt void cpu_timer0_isr(void);
interrupt void pin_26_isr(void);
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
   PieVectTable.XINT1 = &pin_26_isr;
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
   PieCtrlRegs.PIEIER1.bit.INTx4 = 1;

// Enable global Interrupts and higher priority real-time debug events:
   EINT;   // Enable Global interrupt INTM
   ERTM;   // Enable Global realtime interrupt DBGM

// Step 6. IDLE loop. Just sit and loop forever (optional):

   Gpio_select();

   for(;;)
   {

   }

} 

void Gpio_select(void)
{

   
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all = 0x00000000;  // All GPIO
    GpioCtrlRegs.GPAMUX2.all = 0x00000000;  // All GPIO
    GpioCtrlRegs.GPAMUX1.all = 0x00000000;  // All GPIO
    GpioDataRegs.GPASET.bit.GPIO23;   //output letch is set
    GpioCtrlRegs.GPADIR.all = 0x00980000;   //  GPIO19, GPIO20 and GPIO23 are outputs

    GpioCtrlRegs.GPACTRL.all = 0x0000ff00;  //input qualification 510xTsysclkout for GPIO8-15
    GpioCtrlRegs.GPAQSEL1.bit.GPIO9 = 2;    //6 samples
    GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL |= 0x1A; //Enable GPIO26 as Interrupt Source
    XIntruptRegs.XINT1CR.bit.ENABLE |= 0x01;
    XIntruptRegs.XINT1CR.bit.POLARITY |= 0x00;


    EDIS;
     
} 

int flag = 0;
int counter = 0;
int entprellt = 0;

interrupt void cpu_timer0_isr(void)
{
    entprellt = 1;
//    if(PieCtrlRegs.PIEIER1.bit.INTx4 == 0)
//    {
//        PieCtrlRegs.PIEIER1.bit.INTx4 = 1;
//    }
    CpuTimer0.InterruptCount++;
    if(flag == 0)
    {
       GpioDataRegs.GPACLEAR.all = 0x00180000;
       counter = 0;
    //       GpioDataRegs.GPADAT.bit.GPIO19 = 0;
    //       GpioDataRegs.GPADAT.bit.GPIO20 = 0;
    }
    if(flag == 1 && counter < 10)
    {
       GpioDataRegs.GPADAT.all = 0x00180000;
    //       GpioDataRegs.GPADAT.bit.GPIO19 = 1;
    //       GpioDataRegs.GPADAT.bit.GPIO20 = 1;
       counter++;
    }
    if(flag == 1 && counter >= 10)
    {
       GpioDataRegs.GPACLEAR.all = 0x00180000;
    //       GpioDataRegs.GPADAT.bit.GPIO19 = 0;
    //       GpioDataRegs.GPADAT.bit.GPIO20 = 0;
       counter++;
       if(counter == 20)
       {
           counter = 0;
       }
    }


   // Acknowledge this interrupt to receive more interrupts from group 1
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}



interrupt void pin_26_isr(void)
{
    if(flag == 0 && entprellt == 1)
    {
        flag = 1;
        counter = 0;
    }
    else if(flag == 1 && entprellt == 1)
    {
        flag = 0;
        counter = 0;
        GpioDataRegs.GPACLEAR.all = 0x00180000;
    }

    // Acknowledge this interrupt to receive more interrupts from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
//    PieCtrlRegs.PIEIER1.bit.INTx4 = 0;
}
//===========================================================================
// No more.
//===========================================================================
