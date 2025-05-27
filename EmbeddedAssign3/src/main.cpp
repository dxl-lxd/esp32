#include <Arduino.h>
#include <Wire.h>                  // I2C 通信库
#include <Adafruit_GFX.h>          // 图形库
#include <Adafruit_SSD1306.h>      // SSD1306 驱动库

// 定义 OLED 分辨率（0.96 寸常见为 128x64）
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// 定义 I2C 地址（默认 0x3C，若屏幕无显示可尝试 0x3D）
#define OLED_ADDR 0x3C

// 初始化 OLED 对象（参数：宽度、高度、I2C 接口、重置引脚（无则设 -1））
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
    // 初始化 I2C 引脚（SDA=GPIO18，SCL=GPIO19）
    Wire.begin(18, 19);  // 关键修改：指定 SDA=18，SCL=19
    
    // 初始化 OLED 屏幕
    if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println(F("OLED 初始化失败！请检查接线或地址"));
        for(;;);  // 死循环，停止执行
    }

    display.clearDisplay();         // 清屏
    display.setTextColor(SSD1306_WHITE);  // 设置文字颜色（白色）
}

void loop() {
    display.clearDisplay();  // 清空缓冲区（避免残留内容）

    // 设置文字大小（2=12x16 像素，适合小屏幕）
    display.setTextSize(2);
    // 设置文字居中显示（计算 x 坐标：(屏幕宽度 - 文字宽度)/2）
    // "hello . world" 长度：12 字符（含空格和点），每个字符宽 12px（文字大小 2）
    int text_width = 12 * 12;  // 12px/字符 × 12字符
    int x = (SCREEN_WIDTH - text_width) / 2;  // 居中坐标

    display.setCursor(x, 20);  // 文字起始坐标（x, y）
    display.print("    hello     world!");  // 目标显示内容

    display.display();  // 刷新屏幕（将缓冲区内容写入 OLED）
    delay(1000);        // 延迟 1 秒（可根据需求调整）
}
    