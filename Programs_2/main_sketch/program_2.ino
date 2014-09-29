
void program2() {
  Serial.println("Beginning program2...");
  
 entry(45,y_current,0,standard); 
 center(standard); 
 entry(135,90,0,standard); 
 center(standard);
 entry(90,45,0,standard); 
 center(standard); 
 entry(90,135,0,standard); 
 center(standard);
 
 entry(45,45,0,standard); 
 entry(135,135,0,standard); 
 center(standard); 
 entry(45,135,0,standard);
 entry(135,45,0,standard);
 center(standard); 
 
 entry(90,90,320,standard);
 entry(90,90,-320,standard);
 center(standard);
 
 entry(45,45,320,standard);
 entry(135,135,0,standard);
 entry(135,45,-320,standard);
 entry(45,135,0,standard);
 center(standard);
 
}
