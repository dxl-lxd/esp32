#include <Arduino.h>

// 定义 LED 引脚数组
int ledPins[] = {19, 18, 5, 17, 16};
// 数组长度
int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  // 遍历每个 LED 引脚并将其设置为输出模式
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // 点亮每个 LED 并延迟一段时间
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(500);
    digitalWrite(ledPins[i], LOW);
  }
}