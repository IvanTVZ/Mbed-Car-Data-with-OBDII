#ifndef GLOBALS_H
#define GLOBALS_H

#include "mbed.h"
#include "LiquidCrystal_I2C.h"
#include "mRotaryEncoder.h"

extern LiquidCrystal_I2C lcd;
extern mRotaryEncoder rotaryEncoder;

extern Serial pc;
extern CAN can;

extern DigitalOut led1;
extern DigitalOut led2;
extern DigitalOut led3;
extern DigitalOut led4;

#endif