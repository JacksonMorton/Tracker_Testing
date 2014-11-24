#include <Servo.h>

Servo servo1; 
Servo servo2; 

uint8_t x_out = A2;
uint8_t y_out = A3;
uint8_t a_out = A4;

int joystick_power = 5;
int potentiometer_power = 4;
int x_servo; int y_servo; int a_stepper;
int x_value; int y_value; int a_value;

void setup() {
 Serial.begin(9600);
 pinMode(joystick_power, OUTPUT);
 pinMode(potentiometer_power, OUTPUT);
 digitalWrite(joystick_power, HIGH);
 digitalWrite(potentiometer_power, HIGH);
 
 servo1.attach(10,1000,2000); servo2.attach(9,1000,2000);
 
}

void loop() {
 x_value = analogRead(x_out);
 y_value = analogRead(y_out);
 a_value = analogRead(a_out);
 
 x_servo = map(x_value,0,1016,135,45);
 y_servo = map(y_value,0,1016,135,45);
 a_stepper = map(a_value,0,1021,-400,400);
 
 servo1.write(x_servo); servo2.write(y_servo);
 
 Serial.print("x_value: "); Serial.println(x_servo);
 Serial.print("y_value: "); Serial.println(y_servo);
 Serial.print("a_value: "); Serial.println(a_stepper);
 Serial.print("millis() "); Serial.println(millis());
 Serial.println("");
 
 //delay(2000);
}

