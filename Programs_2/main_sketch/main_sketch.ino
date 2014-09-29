 #include <Servo.h>

 int dir = 2; // The Arduino pin controlling stepper (alpha) direction.
 int steps = 3; // The Arduino pin controlling the # of steps taken by the stepper motor.
 int netSteps;  /* The direction specific sum of the number of steps the stepper has taken.
                      Steps when dir = HIGH are positive; steps when dir = LOW are negative. */

 Servo servo1;
 Servo servo2;
 int i;
 int n = 1000; // Set the speed of the stepper motor (microsecond delay between each step).
 bool outputDir = false;
 int initial_delay = 2000; // Initial delay time after program is initialized (milliseconds).
 int count = 0;
 int pause = 1000; 
 unsigned long time = millis();
 unsigned int move_on; unsigned int standard;

 int x_current = 90;
 int y_current = 90;
 int a_current = 0;

 void setup() {
  servo1.attach(9,1000,2000);
  servo2.attach(10,1000,2000);
  pinMode(dir, OUTPUT);
  pinMode(steps, OUTPUT);
 
  digitalWrite(dir, LOW); // Set the original stepper direction.
  servo1.write(90);
  servo2.write(90);
  netSteps = 0;
  move_on = pause*count + initial_delay;
  standard = move_on;
  Serial.begin(9600);
  delay(initial_delay);
 }
 
 void loop() {
   
   program2();
  
 }
