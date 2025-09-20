   int global1 = 1;
   int global2 = 4;

   int* addr;
   int* addrStatic;

   void setup() {
      int local1 = 5;
      char local2 = 'b';
      unsigned long local3 = 0xdecafbad;

      Serial.begin(9600);
      while(!Serial);

      Serial.print("global1 addr: ");
      Serial.println((unsigned int) &global1, HEX);
      Serial.print("global2 addr: ");
      Serial.println((unsigned int) &global2, HEX);
      Serial.print("local1 addr: ");
      Serial.println((unsigned int) &local1, HEX);
      Serial.print("local2 addr: ");
      Serial.println((unsigned int) &local2, HEX);
      Serial.print("local3 addr: ");
      Serial.println((unsigned int) &local3, HEX);

      Serial.print("loop addr: ");
      Serial.println((unsigned int) &loop, HEX);
      Serial.print("helper addr: ");
      Serial.println((unsigned int) &helper, HEX);

      // TODO: print out the address of a peripheral register
      //Serial.print("register addr: ");
      //Serial.println((unsigned int) &(R_PERIPHERAL->REG), HEX); // TODO

      helper();
      Serial.println("**BACK IN SETUP**");
      Serial.print("addr value: ");
      Serial.println((unsigned int) addr, HEX);
      Serial.print("addr dereference: ");
      Serial.println((unsigned int) *addr);

      Serial.print("addrStatic value: ");
      Serial.println((unsigned int) addrStatic, HEX);
      Serial.print("addrStatic dereference: ");
      Serial.println((unsigned int) *addrStatic);
   }

   void helper() {
      int helperLocal = 1600;
      static int helperStatic = 40;
      addr = &helperLocal;
      addrStatic = &helperStatic;
      Serial.println("**INSIDE HELPER**");
      Serial.print("helperLocal addr: ");
      Serial.println((unsigned int) &helperLocal, HEX);
      Serial.print("helperLocal value: ");
      Serial.println(helperLocal);
      Serial.print("helperStatic addr: ");
      Serial.println((unsigned int) &helperStatic, HEX);
      Serial.print("helperStatic value: ");
      Serial.println(helperStatic);
   }


   void loop() {
      Serial.println("A print in the loop");
      while(true); // don't loop again
   }
