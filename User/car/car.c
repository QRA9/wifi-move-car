#include "car.h"

//speed (-1000 ~~ +1000)
//前进（6，7，8，9 +）
//后退（6，7，8，9 -）
//左转（6-，7+，8-，9+)
//右转（6+，7-, 8+，9-)
//左平移（6-, 7+, 8+. 9-）
//右平移（6+, 7-. 8-, 9+）

void wait(int t){
	int n = t / 100;
	for(int i = 1; i <= n; i++)
	{
		delay_ms(100);
	}
}
void move_car(int speed7, /*左前轮*/ int speed6, /*右前轮*/ int speed8, /*左后轮*/ int speed9, /*右后轮*/ int time){
	u8 cmd_data[1024];
	speed7 = 1500 + speed7;
	speed6 = 1500 - speed6;
	speed8 = 1500 + speed8;
	speed9 = 1500 - speed9;
	sprintf((char *)cmd_data,  "{#006P%04dT0000!#007P%04dT0000!#008P%04dT0000!#009P%04dT0000!}", speed6, speed7, speed8, speed9);
//	usart2_send_str(cmd_data);
	uart5_send_str(cmd_data);
	uart4_send_str(cmd_data);
	wait(time);
}
void car_go(int speed, int time){//前进（6，7，8，9 +）
	LED_GREEN;
	move_car(speed, speed, speed, speed, time);
}

void car_back(int speed, int time){//后退（6，7，8，9 -）
	LED_PURPLE;
	move_car(0-speed, 0-speed, 0-speed, 0-speed, time);
}                                  

void car_turn_left(int speed, int time){//左转（6-，7+，8-，9+)
	LED_BLUE;
	move_car(0-speed, speed, 0-speed, speed, time);
}

void car_turn_right(int speed, int time){//右转（6+，7-, 8+，9-)
	LED_YELLOW;
	move_car(speed, 0-speed, speed, 0-speed, time);
}

void car_move_left(int speed, int time){//左平移（6-, 7+, 8+. 9-）
	LED_BLUE;
	move_car(0-speed, speed, speed, 0-speed, time);
}

void car_move_right(int speed, int time){//右平移（6+, 7-. 8-, 9+）
	LED_YELLOW;
	move_car(speed, 0-speed, 0-speed, speed, time);
}

void car_stop(int time){//停车
	LED_RED;
	move_car(0,0,0,0,time);
}


void car_start(char mode, int speed, int time)
{
	int new_speed = 0;
	switch(mode)
	{
		case 'g':
			while(speed > new_speed)
			{
				new_speed = new_speed + 50;
				car_back(new_speed, 100);
				time = time - 100;
			}
			car_back(speed, time);
			break;
		case 'b':
			while(speed > new_speed)
			{
				new_speed = new_speed + 50;
				car_go(new_speed, 100);
				time = time - 100;
			}
			car_go(speed, time);
			break;
		case 'l':
			while(speed > new_speed)
			{
				new_speed = new_speed + 50;
				car_move_left(new_speed, 100);
				time = time - 100;
			}
			car_move_left(speed, time);
			break;
		case 'r':
			while(speed > new_speed)
			{
				new_speed = new_speed + 50;
				car_move_right(new_speed, 100);
				time = time - 100;
			}
			car_move_right(speed, time);
			break;
		case 's':
			car_stop(time);
			break;
	}
}

void car_init(void){
	uart5_init();
	uart4_init();
	delay_init();
	LED_WHITE;
	wait(1000);
}