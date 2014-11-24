
void program3() {
 
 Serial.println("Beginning program3...");
 randomNumbers(); 
 
 if(initialCheck) {check_mode();}
 initialCheck = false;
 
 for (u=0; u<2; u++) {
 entry(rand_x,rand_y,rand_a,standard);}
 center(standard);
}
