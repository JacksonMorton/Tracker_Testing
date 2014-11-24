
void program4() {
  
  Serial.println("Beginning program4...");
  
  if(initialCheck) {check_mode();}
   initialCheck = false;
 
  motorsOn = digitalRead(powerToMotors);
  Serial.print("The value being read from pin 8 is: "); Serial.println(motorsOn); Serial.println("");
  
  delay(500);
  
}
