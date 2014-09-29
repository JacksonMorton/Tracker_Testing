
void program1(){
  Serial.println("Beginning program1...");
 
  servo1.write(45); 
  count = count + 1; move_on = pause*count + initial_delay;
  
  while(millis() < move_on){
    Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
    Serial.print(count); Serial.print("   "); Serial.println(millis());}
  
  center(standard); 
  
  while(millis() < move_on){
    Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
    Serial.print(count); Serial.print("   "); Serial.println(millis());}
  
  servo1.write(135); 
  count = count + 1; move_on = pause*count + initial_delay;
  
  while(millis() < move_on){
   Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
    Serial.print(count); Serial.print("   "); Serial.println(millis());}
    
  center(standard); 
  
  while(millis() < move_on){
    Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
    Serial.print(count); Serial.print("   "); Serial.println(millis());}
    
  servo2.write(45); 
  count = count + 1; move_on = pause*count + initial_delay;
  
  while(millis() < move_on){
  Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
    Serial.print(count); Serial.print("   "); Serial.println(millis());}
  
  center(standard); 
  
  while(millis() < move_on){
   Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
    Serial.print(count); Serial.print("   "); Serial.println(millis());}
    
  servo2.write(135); 
  count = count + 1; move_on = pause*count + initial_delay;
  
  while(millis() < move_on){
    Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
    Serial.print(count); Serial.print("   "); Serial.println(millis());}
    
  center(standard); 
  
  while(millis() < move_on){
    Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
    Serial.print(count); Serial.print("   "); Serial.println(millis());}

  servo1.write(45); servo2.write(45);
  count = count + 1; move_on = pause*count + initial_delay;
  
  while(millis() < move_on){
    Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
    Serial.print(count); Serial.print("   "); Serial.println(millis());}
    
  servo1.write(135); servo2.write(135);
  count = count + 1; move_on = pause*count + initial_delay;
  
  while(millis() < move_on){
    Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
    Serial.print(count); Serial.print("   "); Serial.println(millis());}  
    
  center(standard);
  
  while(millis() < move_on){
    Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
    Serial.print(count); Serial.print("   "); Serial.println(millis());}
    
  servo1.write(45); servo2.write(135);
  count = count + 1; move_on = pause*count + initial_delay;
  
  while(millis() < move_on){
    Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
    Serial.print(count); Serial.print("   "); Serial.println(millis());}
    
  servo1.write(135); servo2.write(45);
  count = count + 1; move_on = pause*count + initial_delay;
  
  while(millis() < move_on){
    Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
    Serial.print(count); Serial.print("   "); Serial.println(millis());}
    
  center(standard);
  
  while(millis() < move_on){
    Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
    Serial.print(count); Serial.print("   "); Serial.println(millis());}

  digitalWrite(dir,LOW); outputDir = false;
  for(i=0;i<160;i++) {
    digitalWrite(steps, LOW);
    digitalWrite(steps, HIGH);
    delayMicroseconds(n); }
  sum_steps();
  count = count + 1; move_on = pause*count + initial_delay;
 
  while(millis() < move_on){
     Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
     Serial.print(count); Serial.print("   "); Serial.println(millis());}
     
  digitalWrite(dir,HIGH); outputDir = true;
  for(i=0;i<320;i++) {
    digitalWrite(steps, LOW);
    digitalWrite(steps, HIGH);
    delayMicroseconds(n); }
  sum_steps();
  count = count + 1; move_on = pause*count + initial_delay;
 
  while(millis() < move_on){
     Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
     Serial.print(count); Serial.print("   "); Serial.println(millis());}
     
 center(standard);
 
  while(millis() < move_on){
     Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
     Serial.print(count); Serial.print("   "); Serial.println(millis());}
  
  servo1.write(45); servo2.write(45);   
  digitalWrite(dir,LOW); outputDir = false;
  for(i=0;i<160;i++) {
    digitalWrite(steps, LOW);
    digitalWrite(steps, HIGH);
    delayMicroseconds(n); }
  sum_steps();
  count = count + 1; move_on = pause*count + initial_delay;
  while(millis() < move_on){
     Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
     Serial.print(count); Serial.print("   "); Serial.println(millis());}
     
  servo1.write(135); servo2.write(135);   
  digitalWrite(dir,HIGH); outputDir = true;
  for(i=0;i<160;i++) {
    digitalWrite(steps, LOW);
    digitalWrite(steps, HIGH);
    delayMicroseconds(n); }
  sum_steps();
  count = count + 1; move_on = pause*count + initial_delay;
  while(millis() < move_on){
     Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
     Serial.print(count); Serial.print("   "); Serial.println(millis());}
     
  servo1.write(135); servo2.write(45);   
  digitalWrite(dir,HIGH); outputDir = true;
  for(i=0;i<160;i++) {
    digitalWrite(steps, LOW);
    digitalWrite(steps, HIGH);
    delayMicroseconds(n); }
  sum_steps();
  count = count + 1; move_on = pause*count + initial_delay;
  while(millis() < move_on){
     Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
     Serial.print(count); Serial.print("   "); Serial.println(millis());}
     
  servo1.write(45); servo2.write(135);   
  digitalWrite(dir,LOW); outputDir = false;
  for(i=0;i<160;i++) {
    digitalWrite(steps, LOW);
    digitalWrite(steps, HIGH);
    delayMicroseconds(n); }
  sum_steps();
  count = count + 1; move_on = pause*count + initial_delay;
  while(millis() < move_on){
     Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
     Serial.print(count); Serial.print("   "); Serial.println(millis());}
     
  center(standard);
  while(millis() < move_on){
     Serial.print("Waiting...  "); Serial.print(move_on); Serial.print("  "); 
     Serial.print(count); Serial.print("   "); Serial.println(millis());}
}
