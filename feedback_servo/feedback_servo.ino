
 #include <Servo.h>
 
 Servo servo1; Servo servo2;
 int feedback1 = 0; int feedback2 = 0;
 uint8_t feedbackPin1 = A0;
 uint8_t feedbackPin2 = A1;
 int n = 0;
 int i = 0;
 
 void setup() {
   servo1.attach(9,1000,2000);
   servo2.attach(10,1000,2000);
   Serial.begin(9600);
 }
 
 void loop() {
   delay(2000);
   
   servo1.write(90); servo2.write(90);
   
   delay(60000);
   
   for(i=9; i<28; i++){
   n = 5*i;
   servo1.write(n); servo2.write(n); 
   
   delay(2000);
   
   feedback1 = analogRead(feedbackPin1); 
   feedback2 = analogRead(feedbackPin2);
   Serial.print("Angle: "); Serial.print(n); Serial.print("   ");
   Serial.print("servo1 Input: "); Serial.print(feedback1); Serial.print("     ");
   Serial.print("servo2 Input: "); Serial.println(feedback2);
   }
   Serial.println(""); 
 }
