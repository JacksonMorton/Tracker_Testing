#include <Servo.h>

int dir = 2;
bool outputDir = false;
int steps = 3;
int i; int n;
Servo servo1;
Servo servo2;
int netSteps;

void setup() {
  servo1.attach(9);
  servo2.attach(10);
  pinMode(dir, OUTPUT);
  pinMode(steps, OUTPUT);
  n = 1000; netSteps = 0;
 // digitalWrite(dir, LOW);
  Serial.begin(9600);
}
  
void loop() {
  digitalWrite(dir, LOW); outputDir = false;
  for(i=0;i<3200;i++) {
    digitalWrite(steps, LOW);
    digitalWrite(steps, HIGH);
    delayMicroseconds(n);
  }
  if(outputDir) {netSteps = netSteps + i;}
    else{netSteps = netSteps - i;}
  servo1.write(90); servo2.write(90);
  Serial.print("dir (90): "); Serial.println(dir);
  Serial.print("value of netStep (90): "); Serial.println(netSteps);
  Serial.println("");
  delay(2000);
  
  digitalWrite(dir, HIGH); outputDir = true;
  for(i=0;i<3200;i++) {
   digitalWrite(steps, LOW);
   digitalWrite(steps, HIGH);
  delayMicroseconds(n); 
  }
  if(outputDir) {netSteps = netSteps + i;}
    else{netSteps = netSteps - i;}
  servo1.write(110); servo2.write(110);
  Serial.print("dir (110): "); Serial.println(dir);
  Serial.print("value of netStep (110): "); Serial.println(netSteps);
  Serial.println("");
  delay(2000);

}
