#ifndef _UART_H_
#define _UART_H_

#include "stm32f10x.h"

void usart2_init(void);
void usart3_init(void);
void uart4_init(void);
void uart5_init(void);

void usart2_irqHandler(void);
void usart3_irqHandler(void);
void uart4_irqHandler(void);
void uart5_irqHandler(void);

void usart2_send_byte(u8 Data);
void usart3_send_byte(u8 Data);
void uart4_send_byte(u8 Data);
void uart5_send_byte(u8 Data);
void usart2_send_str(u8 *Data);
void usart3_send_str(u8 *Data);
void uart4_send_str(u8 *Data);
void uart5_send_str(u8 *Data);

void all_send_str(u8 *Data);

#endif