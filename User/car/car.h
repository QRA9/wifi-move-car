#ifndef _CAR_H_
#define _CAR_H_

#include "stm32f10x.h"
#include "uart.h"
#include "delay.h"
#include <stdio.h>
#include "bsp_led.h"

void wait(int t);
void move_car(int speed6, /*��ǰ��*/ int speed7, /*��ǰ��*/ int speed8, /*�����*/ int speed9, /*�Һ���*/ int time);
void car_go(int speed, int time);
void car_back(int speed, int time);
void car_turn_left(int speed, int time);
void car_turn_right(int speed, int time);
void car_move_left(int speed, int time);
void car_move_right(int speed, int time);
void car_stop(int time);
void car_start(char mode, int speed, int time);
void car_init(void);

#endif