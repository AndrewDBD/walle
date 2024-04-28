
#include "Arduino.h"


void acceleration(bool direction, int acc = 1, int speed = 5, int motor1_1 = 0, int motor1_2 = 16, int motor2_1 = 12, int motor2_2 = 15) {
  //туду исправить ошибки
  //для замедления параметр acc должен быть меньше 0
  //acc = constrain(acc, 1, 10);
  //ниже обрабатываем исключения - выход за границы допустимого диапозона
  //проверить как отрабатывает код при вводе -1 -2 и т.д туду
  acc = -10 > acc ? -10 : acc;
  acc = 0 == acc ? 1 : acc;
  acc = acc > 10 ? 10 : acc;
  String DIRECTION = "";
  DIRECTION = direction == false ? "вперёд" : "назад";
  Serial.printf("идём %s\n", DIRECTION);
  for (int i = speed; 0 <= i && i < 11; i += acc) {
    Serial.printf("i = %d\n", i);
    digitalWrite(motor1_1, direction == false ? LOW : HIGH);
    digitalWrite(motor1_2, direction == false ? HIGH : LOW);
    digitalWrite(motor2_1, direction == false ? LOW : HIGH);
    digitalWrite(motor2_2, direction == false ? HIGH : LOW);
    delay(4 * i);
    digitalWrite(motor1_1, LOW);
    digitalWrite(motor1_2, LOW);
    digitalWrite(motor2_1, LOW);
    digitalWrite(motor2_2, LOW);
    delay(4 * (10 - i));
  }
  //ниже должны быть вращения
  Serial.println("вращения");

  for (int i = speed; 0 <= i && i < 11; i += acc) {
    Serial.printf("i = %d\n", i);
    digitalWrite(motor1_1, direction == false ? LOW : HIGH);
    digitalWrite(motor1_2, direction == false ? HIGH : LOW);
    digitalWrite(motor2_1, direction == false ? HIGH : LOW);
    digitalWrite(motor2_2, direction == false ? LOW : HIGH);
    delay(4 * i);
    digitalWrite(motor1_1, LOW);
    digitalWrite(motor1_2, LOW);
    digitalWrite(motor2_1, LOW);
    digitalWrite(motor2_2, LOW);
    delay(4 * (10 - i));
  }
  for (int i = speed; 0 <= i && i < 11; i += acc) {
    Serial.printf("i = %d\n", i);
    digitalWrite(motor1_1, direction == false ? HIGH : LOW);
    digitalWrite(motor1_2, direction == false ? LOW : HIGH);
    digitalWrite(motor2_1, direction == false ? LOW : HIGH);
    digitalWrite(motor2_2, direction == false ? HIGH : LOW);
    delay(4 * i);
    digitalWrite(motor1_1, LOW);
    digitalWrite(motor1_2, LOW);
    digitalWrite(motor2_1, LOW);
    digitalWrite(motor2_2, LOW);
    delay(4 * (10 - i));
  }
}
