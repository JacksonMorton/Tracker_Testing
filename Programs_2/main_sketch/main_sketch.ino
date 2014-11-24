 #include <Servo.h>
 
 /******* User Defined Values  *******/
 
  bool stutter_on = true;  /* Choose whether the servo motors move directly to the desired position or
                              move there in several discrete steps. */
  bool feedback_on = true; // Choose to show or hide feedback data from the servo motors on the serial monitor.
  int n = 1000; // Set the speed of the stepper motor (microsecond delay between each step).
  unsigned long initial_delay = 2000; // Initial delay time after program is initialized (milliseconds).
  unsigned long pause = 2000; // The amount of time (milliseconds) between each eye movement.
  int smoothingConstant = 10; // As smoothingConstant increases, joystick control of the a-direction becomes 
                              // smoother but less precise.
  
 /************************************/ 

 int dir = 2; // The Arduino pin controlling stepper (alpha) direction.
 int steps = 3; // The Arduino pin controlling the # of steps taken by the stepper motor.
 int netSteps;  /* The direction specific sum of the number of steps the stepper has taken.
                      Steps when dir = HIGH are positive; steps when dir = LOW are negative. */
 bool outputDir = false;
 
 Servo servo1; 
 Servo servo2;
 
 int i; int z; int u;

 unsigned long count = 0;
 unsigned long time = millis();
 unsigned long move_on; unsigned long standard;
 
 int feedback1 = 0; int feedback1_map;
 int feedback2 = 0; int feedback2_map;
 uint8_t feedbackPin1 = A0; 
 uint8_t feedbackPin2 = A1;
 
 int x_hold = 90; 
 int y_hold = 90; 
 int a_hold = 0;
 
 int rand_x; 
 int rand_y; 
 int rand_a;

 int x_val; int y_val;
 int stutters_x = 0; int stutters_y = 0; int max_stutters = 0;

 uint8_t x_out = A2;
 uint8_t y_out = A3;
 uint8_t a_out = A4;
 
 int joystick_power = 5;
 int potentiometer_power = 4;
 int x_servo; int y_servo; int a_stepper;
 int x_value; int y_value; int a_value;
 int mode_switch = 12; boolean manual; boolean lastMode;
 boolean initialCheck = true;
 int extraSteps;

 /************************************/ 

 void setup() {
  randomSeed(analogRead(5));
   
  servo1.attach(10,1000,2000);
  servo2.attach(9,1000,2000);
  pinMode(dir, OUTPUT);
  pinMode(steps, OUTPUT);
  
  pinMode(joystick_power, OUTPUT);
  pinMode(potentiometer_power, OUTPUT);
  pinMode(mode_switch, INPUT);
  digitalWrite(joystick_power, HIGH);
  digitalWrite(potentiometer_power, HIGH);
  lastMode = digitalRead(mode_switch);
 
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
