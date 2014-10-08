
/**************************************************************************/

void sum_steps(){
  if(outputDir) {netSteps = netSteps + i;}
    else{netSteps = netSteps - i;}
}

/**************************************************************************/

void center(unsigned long t){
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
  Serial.print("   count: "); Serial.println(count); Serial.println("");
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
  Serial.print("   count: "); Serial.println(count); Serial.println("");
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
    Serial.print("servo1 input: "); Serial.print(x_val); Serial.print(" degrees");
    Serial.print("servo1 feedback: "); Serial.print(feedback1); Serial.println(" degrees");
    Serial.print("servo2 input: "); Serial.print(y_val); Serial.print(" degrees");
    Serial.print("servo2 feedback: "); Serial.print(feedback2); Serial.println(" degrees");
  }

