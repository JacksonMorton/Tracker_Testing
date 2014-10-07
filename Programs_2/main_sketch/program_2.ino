
void program2() {
  Serial.println("Beginning program2...");
  
 entry(45,y_hold,0,standard); 
 center(standard); 
 entry(135,y_hold,0,standard); 
 center(standard);
 entry(x_hold,45,0,standard); 
 center(standard); 
 entry(x_hold,135,0,standard); 
 center(standard);
 
 entry(45,45,0,standard); 
 entry(135,135,0,standard); 
 center(standard); 
 entry(45,135,0,standard);
 entry(135,45,0,standard);
 center(standard); 
 
 entry(90,90,400,standard);
 entry(90,90,-400,standard);
 center(standard);
 
 entry(45,45,400,standard);
 entry(135,135,0,standard);
 entry(135,45,-400,standard);
 entry(45,135,0,standard);
 center(standard);
 
}
