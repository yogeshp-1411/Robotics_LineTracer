#include <Servo.h>
#define WHITE_VAL  250
#define BLACK_VAL  150

Servo MyservoLeft;  // create servo object for Left Motor
Servo MyservoRight; // create servo object for Right Motor

int Analog1 = A3;
int Analog2 = A4;
int Analog3 = A5;

int middle_sensor      = 0;
int left_sensor        = 0;
//int most_left_sensor   = 0;
int right_sensor       = 0;
//int most_right_sensor  = 0;

void setup() 
{
  Serial.begin(9600);
  MyservoLeft.attach(12);  // attaches the servo on pin 9 to the servo object
  MyservoRight.attach(13);
}
void loop() 
{
  
  //most_left_sensor  = analogRead(Analog1);
  
  left_sensor       = analogRead(Analog1);
  
  middle_sensor     = analogRead(Analog2);
  
  right_sensor      = analogRead(Analog3);
  
  //most_right_sensor = analogRead(Analog5);
//  Serial.print("Sensor 1:");
//  Serial.println(most_left_sensor);
//  Serial.print("Sensor 2:");
//  Serial.println(left_sensor);
//  Serial.print("Sensor 3:");
//  Serial.println(middle_sensor);
//  Serial.print("Sensor 4:");
//  Serial.println(right_sensor);  
//  Serial.print("Sensor 5:");
//  Serial.println(most_right_sensor);
  //move_reverse();
  if((left_sensor > WHITE_VAL)&&(middle_sensor < BLACK_VAL) && (right_sensor > WHITE_VAL))
  {
    Serial.println("F");
    move_forward();
  }
  else if((left_sensor > WHITE_VAL)&&(middle_sensor > WHITE_VAL) && ((right_sensor < BLACK_VAL)))
  {
   Serial.println("L");
    move_left();
  }
  else if((left_sensor > WHITE_VAL)&&(middle_sensor < BLACK_VAL) && (right_sensor < BLACK_VAL))
  {
    Serial.println("SL");
    move_left();
  }
  else if(((left_sensor < BLACK_VAL))&&(middle_sensor > WHITE_VAL) && (right_sensor > WHITE_VAL))
  {
    Serial.println("R");
    move_right();
  }
  else if((left_sensor < BLACK_VAL)&&(middle_sensor < BLACK_VAL) && (right_sensor > WHITE_VAL))
  {
    Serial.println("SR");
    move_right();
  }
  else if((left_sensor > WHITE_VAL)&&(middle_sensor > WHITE_VAL) && (right_sensor > WHITE_VAL))
  {
    Serial.println("rev");
    move_reverse();
    MyservoRight.writeMicroseconds(1700);
  }
  else
  {
    Serial.println("Def");
    move_forward();
  }
  delay(10);
}
void move_forward()
{
  MyservoRight.writeMicroseconds(1700);
  MyservoLeft.writeMicroseconds(1300);
  delay(10);
}
void move_left()
{
  MyservoRight.writeMicroseconds(1700);
  MyservoLeft.writeMicroseconds(1500);
  delay(10);
}
void move_right()
{
  MyservoRight.writeMicroseconds(1500);
  MyservoLeft.writeMicroseconds(1300);
  delay(10);
}
void move_reverse()
{
  MyservoRight.writeMicroseconds(1300);
  MyservoLeft.writeMicroseconds(1700);
  delay(10);
}
