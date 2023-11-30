#include "globals.h"

LiquidCrystal_I2C lcd (0x27, 20, 4, p9, p10);
mRotaryEncoder rotaryEncoder (p21, p22, p23, PullUp, 1000);

Serial pc (USBTX, USBRX);
CAN can (p30, p29);

DigitalOut led1 (LED1);
DigitalOut led2 (LED2);
DigitalOut led3 (LED3);
DigitalOut led4 (LED4);