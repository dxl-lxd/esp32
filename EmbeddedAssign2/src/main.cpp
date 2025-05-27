#include <Arduino.h>

// 定义 LED 引脚数组
int ledPins[] = {19, 18, 5, 17, 16};
// 数组长度
int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

// 用于存储每个 LED 的状态，初始为 LOW（灭）
bool ledStates[5] = {LOW, LOW, LOW, LOW, LOW};

void setup() {
    // 初始化串口通信，波特率为 9600
    Serial.begin(9600);

    // 遍历每个 LED 引脚并将其设置为输出模式
    for (int i = 0; i < numLeds; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
}

void loop() {
    // 检查串口是否有数据可读
    if (Serial.available() > 0) {
        // 读取串口接收到的字符串
        String command = Serial.readStringUntil('\n');

        // 解析接收到的指令
        if (command.length() == 1) {
            int ledIndex = command.toInt() - 1;

            // 检查指令是否有效
            if (ledIndex >= 0 && ledIndex < numLeds) {
                // 切换 LED 状态
                ledStates[ledIndex] = !ledStates[ledIndex];
                digitalWrite(ledPins[ledIndex], ledStates[ledIndex]);

                // 发送反馈信息
                if (ledStates[ledIndex]) {
                    Serial.print("LED");
                    Serial.print(ledIndex + 1);
                    Serial.println("ON");
                } else {
                    Serial.print("LED");
                    Serial.print(ledIndex + 1);
                    Serial.println("OFF");
                }
            }
        }
    }
}