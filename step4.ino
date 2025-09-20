// TODO:
const unsigned int D2_PORT = ;
const unsigned int D2_PIN = ;
// TODO: (Prelab step 4.5)
const unsigned int D2_IRQ = ; 

// The MCU gives us 32 possible CPU interrupt channels to connect to
// The Arduino IRQ manager starts allocating them sequentially from 0, so we'll start at 31
// WARNING: this is dangerous in the general case, since the IRQ manager hasn't been told that
// we used up channel 31 (but it's OK in this lab because we're not asking the Arduino libraries/
// IRQ manager to initialize any interrupts beyond the one(s) needed by Serial) 
const unsigned int CPU_INT = 31;

void setup() {
   Serial.begin(9600);
   while(!Serial);

   // TODO: Configure D2 as an input AND to be used as an IRQ input pin
   // Note: read the PmnPFS register description to find the name of the field that
   // configures a pin for IRQ (or reread prelab Q4.4)
   // Both fields should be set in one write, using the bitfield macro style you saw
   // in lecture/prelab Q3. All other bitfields should be 0, so you don't have to worry
   // about leaving them unchanged -- just overwrite the whole register
   // The macro(s) you want to use will start with R_PFS_PORT_PIN_PmnPFS
   R_PFS->PORT[D2_PORT].PIN[D2_PIN].PmnPFS = 

   // TODO: Trigger an interrupt when D2 goes from LOW to HIGH (prelab Q4.6)
   // Again, do not use the _b notation. We can just overwrite the register and make the
   // values of the other fields 0.
   R_ICU->IRQCR[D2_IRQ] = ;
   // Configure the ICU to connect the Port IRQ to the CPU (NVIC) IRQ (prelab Q4.7)
   R_ICU->IELSR[CPU_INT] = ;
   
   // Use the Arm CMSIS API to enable *CPU* interrupts
   NVIC_SetVector((IRQn_Type) CPU_INT, (uint32_t) &ourISR); // set vector entry to our handler
   NVIC_SetPriority((IRQn_Type) CPU_INT, 14); // Priority lower than Serial (12)
   NVIC_EnableIRQ((IRQn_Type) CPU_INT);
}

void ourISR() {
   static int timesPushed = 0; // static means value persists between function calls
   Serial.println(timesPushed++);

   // TODO: Clear the pending interrupt flag (Prelab Q4.8) on the MCU side
   R_ICU->IELSR_b[CPU_INT].___ = ;
   // Clear the pending interrupt on the CPU side
   NVIC_ClearPendingIRQ((IRQn_Type) CPU_INT);
}

void loop() {
   delay(100000); // IRQ should be able to interrupt this delay no matter when it happens
}
