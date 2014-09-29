
/**************************************************************************/

void sum_steps(){
  if(outputDir) {netSteps = netSteps + i;}
    else{netSteps = netSteps - i;}
}

/**************************************************************************/
void center(unsigned int t){
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
  x_current = 0; y_current = 0; a_current = 0;
  
  Serial.print("x: "); Serial.print(x_current); 
  Serial.print("   y: "); Serial.print(y_current); 
  Serial.print("   a: "); Serial.println(a_current); 
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

void entry(int x, int y, int a, unsigned int t) {
  Serial.print("millis(): "); Serial.print(millis()); 
  Serial.print("   t: "); Serial.println(t);
  if(millis() < t) {delay(t - millis());}
  servo1.write(x);
  servo2.write(y);
  stepper_position(a);
  count = count + 1;
  standard = pause*count + initial_delay;
  x_current = x; y_current = y; a_current = a;
  
  Serial.print("x: "); Serial.print(x_current); 
  Serial.print("   y: "); Serial.print(y_current); 
  Serial.print("   a: "); Serial.println(a_current); 
  Serial.print("   count: "); Serial.println(count); Serial.println("");
  
}
