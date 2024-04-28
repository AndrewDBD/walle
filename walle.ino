#include "acceleration.h"
// String DIRECTION;
bool direction = true;

//входы драйвера моторов у валли
//orange - in2
//green - in1
//yellow - in4
//brown/gray - in3
//blue - step
//in1 + in2 = motor1
//in3 + in4 = motor2

int motor1_1 = 0;
int motor1_2 = 16;
int motor2_1 = 12;
int motor2_2 = 15;
int x = 1;  //переменная для приёма сообщений из порта String str;  //переменная для приёма строковых значений из порта


void setup() {
  Serial.begin(115200);
  pinMode(motor1_1, OUTPUT);
  pinMode(motor1_2, OUTPUT);
  pinMode(motor2_1, OUTPUT);
  pinMode(motor2_2, OUTPUT);
  Serial.print("setup");
}
int speed = 0;  //текущая скорость


void loop() {
  if (Serial.available() > 0) {
   
    x = Serial.parseInt();
    //x = constrain(x, 0, 180);
    Serial.println(x);

    //myservo.write(x);
  }
  direction = !direction;
  speed = 5;
  acceleration(direction, x, speed);
  delay(2000);
  //нужно реализовать логику торможения
}
