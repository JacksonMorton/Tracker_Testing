
 #include <Servo.h>
 
 Servo servo3; Servo servo4;
 int feedback3 = 0; int feedback4 = 0;
 uint8_t feedbackPin3 = A0;
 uint8_t feedbackPin4 = A1;
 int n = 0;
 int i = 0;
 
 void setup() {
   servo3.attach(11,1000,2000);
   servo4.attach(5,1000,2000);
   Serial.begin(9600);
 }
 
 void loop() {
   delay(2000);
   
   for(i=1; i<40; i++){
   servo3.write(n); feedback3 = analogRead(feedbackPin3);
   servo4.write(n); feedback4 = analogRead(feedbackPin4);
   Serial.print("Angle: "); Serial.print(n); Serial.print("   ");
   Serial.print("servo3 Input: "); Serial.print(feedback3); Serial.print("     ");
   Serial.print("servo4 Input: "); Serial.println(feedback4);
   n = 5*i;
   delay(2000);
   }
   
 }
