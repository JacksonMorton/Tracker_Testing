
/**************************************************************************/

void sum_steps(){
  if(outputDir) {netSteps = netSteps + i;}
    else{netSteps = netSteps - i;}
}

/**************************************************************************/

void center(unsigned long t){
  Serial.print("millis(): "); Serial.print(millis()); 
  Serial.print("    t: "); Serial.println(t);
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
  Serial.print("millis(): "); Serial.print(millis()); 
  Serial.print("   t: "); Serial.println(t);
  if(millis() < t) {delay(t - millis());}
  servo1.write(x);
  servo2.write(y);
  stepper_position(a);
  count = count + 1;
  standard = pause*count + initial_delay;
  x_hold = x; y_hold = y; a_hold = a;
  
  Serial.print("x: "); Serial.print(x_hold); 
  Serial.print("   y: "); Serial.print(y_hold); 
  Serial.print("   a: "); Serial.println(a_hold); 
  Serial.print("   count: "); Serial.println(count); Serial.println("");
}
