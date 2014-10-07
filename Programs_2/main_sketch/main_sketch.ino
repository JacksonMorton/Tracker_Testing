 #include <Servo.h>

 int dir = 2; // The Arduino pin controlling stepper (alpha) direction.
 int steps = 3; // The Arduino pin controlling the # of steps taken by the stepper motor.
 int netSteps;  /* The direction specific sum of the number of steps the stepper has taken.
                      Steps when dir = HIGH are positive; steps when dir = LOW are negative. */

 Servo servo1;
 Servo servo2;
 bool stutter_on = true;
 int i; int z; int u;
 int n = 1000; // Set the speed of the stepper motor (microsecond delay between each step).
 bool outputDir = false;
 unsigned long initial_delay = 2000; // Initial delay time after program is initialized (milliseconds).
 unsigned long count = 0;
 unsigned long pause = 2000; 
 unsigned long time = millis();
 unsigned long move_on; unsigned long standard;
 //unsigned long minutes = 0; int seconds = 0;
 uint8_t feedbackPin1 = A0;
 uint8_t feedbackPin2 = A1;

 int x_hold = 90;
 int y_hold = 90;
 int a_hold = 0;
 int rand_x; int rand_y; int rand_a;

 int x_val; int y_val;
 int stutters_x = 0; int stutters_y = 0; int max_stutters = 0;

 void setup() {
  randomSeed(analogRead(5));
   
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
   
   program3();
  
 }
