
/**************************************************************************/

 void sum_steps(){
   if(outputDir) {netSteps = netSteps + i;}
     else{netSteps = netSteps - i;}
 }
 
 /**************************************************************************/
 
 void center(unsigned long t){
   
   check_mode(); motors_on_off();
   
   Serial.print("millis(): "); Serial.print((millis()/1000)/60); Serial.print(":"); 
   if ((millis()/1000)%60 < 10) {Serial.print("0");}; Serial.print((millis()/1000)%60);
   Serial.print("   t: "); Serial.print((t/1000)/60); Serial.print(":"); 
   if ((t/1000)%60 < 10) {Serial.print((t/1000)%60); Serial.println("0");} else {Serial.println((t/1000)%60);}
   if(millis() < t) {delay(t - millis());}
   servo1.write(90); servo2.write(90);
   if(netSteps > 0) {digitalWrite(dir,LOW); outputDir = false;}
     else {digitalWrite(dir,HIGH); outputDir = true;}
   for(i=0; i < abs(netSteps); i++){
     digitalWrite(steps,LOW);
     digitalWrite(steps,HIGH);
     delayMicroseconds(n);
   }
   sum_steps();
   count = count + 1;
   standard = pause*count + initial_delay;
   x_hold = 90; y_hold = 90; a_hold = 0;
   randomNumbers();
   
   Serial.print("x: "); Serial.print(x_hold); 
   Serial.print("   y: "); Serial.print(y_hold); 
   Serial.print("   a: "); Serial.println(a_hold); 
   Serial.print("   count: "); Serial.println(count); 
   if (feedback_on) {feedback();}
   //delay(2000); if (feedback_on) {feedback();}
   Serial.println("");
   
 }

 /**************************************************************************/

 void stepper_position(int a) {
  
   if(a < netSteps) {digitalWrite(dir,LOW); outputDir = false;}
     else {digitalWrite(dir, HIGH); outputDir = true;}
    
   for(i=0; i < abs(netSteps-a); i++) {
     digitalWrite(steps,LOW);
     digitalWrite(steps,HIGH);
     delayMicroseconds(n);
   }
   sum_steps();
 }

 /**************************************************************************/

 void entry(int x, int y, int a, unsigned long t) {
   
   check_mode(); motors_on_off(); //Serial.print("lastMotorsOn: "); Serial.print(lastMotorsOn); Serial.print("   motorsOn: "); Serial.println(motorsOn);
  
   Serial.print("millis(): "); Serial.print((millis()/1000)/60); Serial.print(":"); 
   if ((millis()/1000)%60 < 10) {Serial.print("0");}; Serial.print((millis()/1000)%60);
   Serial.print("   t: "); Serial.print((t/1000)/60); Serial.print(":");
   if ((t/1000)%60 < 10) {Serial.print("0");}; {Serial.println((t/1000)%60);}
   if(millis() < t) {delay(t - millis());}
  
   stepper_position(a);
  
   x_val = x; y_val = y;
   if (stutter_on) {stutter();}
   servo1.write(x);
   servo2.write(y);

   count = count + 1;
   standard = pause*count + initial_delay;
   x_hold = x; y_hold = y; a_hold = a;
   randomNumbers();
  
   Serial.print("x: "); Serial.print(x_hold); 
   Serial.print("   y: "); Serial.print(y_hold); 
   Serial.print("   a: "); Serial.println(a_hold); 
   Serial.print("   count: "); Serial.println(count); 
   if (feedback_on) {feedback();}
   //delay(2000); if (feedback_on) {feedback();}
   Serial.println("");
   
 }  
 
 /**************************************************************************/ 
  
   void randomNumbers() {
     rand_x = random(45,135);
     rand_y = random(45,135);
     rand_a = random(-400,400);
   }

 /**************************************************************************/ 
  
   void stutter() {
   
     stutters_x = abs(x_val-x_hold)/10; stutters_y = abs(y_val-y_hold)/10;
    
     if (stutters_x - stutters_y >= 0) {max_stutters = stutters_x;}
       else {max_stutters = stutters_y;}
    
       for (z=0; z < max_stutters; z++) {
         if (stutters_x >= z) {servo1.write(x_hold+z*((x_val-x_hold)/stutters_x)); }
         if (stutters_y >= z) {servo2.write(y_hold+z*((y_val-y_hold)/stutters_y)); }
         delay(150);}
   }
  
 /**************************************************************************/

  void feedback() {
    feedback1 = analogRead(feedbackPin1); feedback2 = analogRead(feedbackPin2);
    feedback1_map = map(feedback1, 259, 356, 45, 135); feedback2_map = map(feedback2, 245, 340, 45, 135);
    Serial.print("servo1 feedback: "); Serial.print(feedback1); Serial.println(" (This number is between 259 and 356.)");
    Serial.print("servo1 mapped feedback: "); Serial.print(feedback1_map); Serial.println(" degrees");
    Serial.print("servo2 feedback: "); Serial.print(feedback2); Serial.println(" (This number is between 245 and 340.)");
    Serial.print("servo2 mapped feedback: "); Serial.print(feedback2_map); Serial.println(" degrees");
   
  }

 /**************************************************************************/

 void check_mode() {
   manual = digitalRead(mode_switch);
  
   if (lastMode != manual) {
    
     servo1.write(90); servo2.write(90);
     if(netSteps > 0) {digitalWrite(dir,LOW); outputDir = false;}
       else {digitalWrite(dir,HIGH); outputDir = true;}
     for(i=0; i < abs(netSteps); i++){
       digitalWrite(steps,LOW);
       digitalWrite(steps,HIGH);
       delayMicroseconds(n);
     }
     sum_steps();
     lastMode = manual; n = 500;
   }
  
   Serial.print("mode: "); Serial.println(manual);
  
   while (manual) {
   joystick();}
  
   if (lastMode != manual) { 
     servo1.write(90); servo2.write(90);
     if(netSteps > 0) {digitalWrite(dir,LOW); outputDir = false;}
       else {digitalWrite(dir,HIGH); outputDir = true;}
     for(i=0; i < abs(netSteps); i++){
       digitalWrite(steps,LOW);
       digitalWrite(steps,HIGH);
       delayMicroseconds(n); }
     sum_steps();
     lastMode = manual; n = 1000;
    }
    Serial.print("netSteps: "); Serial.println(netSteps);
  }

 /**************************************************************************/

 void joystick() {
  
    x_value = analogRead(x_out);
    y_value = analogRead(y_out);
    a_value = analogRead(a_out);
   
    x_servo = map(x_value,0,1016,135,45);
    y_servo = map(y_value,0,1016,135,45);
    a_stepper = map(a_value,0,1021,400,-400);
    
    servo1.write(x_servo); servo2.write(y_servo);
    //extraSteps = a_stepper % smoothingConstant;
    //stepper_position(a_stepper - extraSteps); 
    stepper_position(a_stepper);
   
    Serial.print("x_value: "); Serial.println(x_servo);
    Serial.print("y_value: "); Serial.println(y_servo);
    Serial.print("a_value: "); Serial.println(a_stepper);
    Serial.print("millis() "); Serial.println(millis());
    Serial.println("");
   
    manual = digitalRead(mode_switch);
    Serial.print("mode: "); Serial.print(manual); Serial.print("     netSteps: "); Serial.println(netSteps);
   
    //delay(2000);
   }
  
 /**************************************************************************/

 void motors_on_off () {
   
   motorsOn = digitalRead(powerToMotors);
   Serial.print("Motor check!");
   Serial.print(" last: " + lastMotorsOn);
   Serial.println(" current: " + motorsOn);
   boolean isChanged = (lastMotorsOn != motorsOn);
   if(isChanged) {
     if (!motorsOn) {
       // If the power supply to the motors has just been switched off
       // save the netSteps value at the instant the switch is pressed.
       saveNetSteps = netSteps;
       lastMotorsOn = motorsOn;
       Serial.print("The switch has flipped, netSteps is saved as: "); Serial.print(netSteps);
     }
     else {
       // If the power supply to the motors has just been switched on, 
       // set netSteps equal to the value it had when the power was turned off.
       netSteps = saveNetSteps;
       lastMotorsOn = motorsOn;
       Serial.print("The switch has flipped, netSteps has been restored to: "); Serial.print(netSteps);
     }
   }
   
   }
 
