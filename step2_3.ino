// TODO: fill in the RA4M1 pin name below, based on Arduino datasheet
// (Just like you did for Prelab Q1, except for digital pin 13)
const unsigned int D13_PORT = ;
const unsigned int D13_PIN = ;

// TODO for step 3: (use Prelab Q1)
//const unsigned int D3_PORT = ;
//const unsigned int D3_PIN = ;

void setup() {
   // Set the direction of D13 to output
   // TODO: Prelab Q2.1 for the field name, Q2.3 for the value
   R_PFS->PORT[D13_PORT].PIN[D13_PIN].PmnPFS_b.___ = ; 

   // TODO for step 3: configure D3 as an input
   // R_PFS->PORT[D3_PORT].PIN[D3_PIN].PmnPFS_b.___ = ;
}

void loop() {
   step2();
   // step3();
}

void step2() {
   // Drive D13 low
   // TODO: Prelab Q2.3 for the field name, Q2.4 for the value
   R_PFS->PORT[D13_PORT].PIN[D13_PIN].PmnPFS_b.___ = ;
   delay(1000);

   // Drive D13 high
   // TODO: Prelab Q2.3 for the field name, Q2.5 for the value
   R_PFS->PORT[D13_PORT].PIN[D13_PIN].PmnPFS_b.___ = ;
   delay(1000);
}

void step3() {
   // TODO for step 3: drive D13 high iff D3 is pressed
}

