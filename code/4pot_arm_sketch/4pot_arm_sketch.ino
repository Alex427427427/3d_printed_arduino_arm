#include <Servo.h>

// declare servos
Servo servo_base;
Servo servo_forward_drive;
Servo servo_vertical_drive;
Servo servo_claws;
int base_angle = 90;
int forward_angle = 90;
int vertical_angle = 90;
int claw_angle = 0;

// declare potentiometer pins
int base_pot = A0;
int forward_pot = A1;
int vertical_pot = A2;
int claw_pot = A3;
int V_base;
int V_forward;
int V_vertical;
int V_claw;

// conversion
float pin_to_angle = 180./1023.;


void setup() {
  // put your setup code here, to run once:
  // attach servos
  servo_base.attach(8);
  servo_forward_drive.attach(9);
  servo_vertical_drive.attach(10);
  servo_claws.attach(11);
  
  servo_base.write(base_angle);
  servo_forward_drive.write(forward_angle);
  servo_vertical_drive.write(vertical_angle);
  servo_claws.write(claw_angle);
  
 
  //setup pot pins
  pinMode(base_pot, INPUT);
  pinMode(forward_pot, INPUT);
  pinMode(vertical_pot, INPUT);
  pinMode(claw_pot, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // read input voltages, from 0 to 1023
  V_base = analogRead(base_pot);
  V_forward = analogRead(forward_pot);
  V_vertical = analogRead(vertical_pot);
  V_claw = analogRead(claw_pot);

  // convert voltage readings into angles
  
  base_angle = floor(V_base*pin_to_angle);
  forward_angle = floor(V_forward*pin_to_angle);
  vertical_angle = floor(V_vertical*pin_to_angle);
  claw_angle = floor(V_claw*pin_to_angle);

  //update servos
  servo_base.write(base_angle);
  servo_forward_drive.write(forward_angle);
  servo_vertical_drive.write(vertical_angle);
  servo_claws.write(claw_angle);
}
