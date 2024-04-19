#include "uart.h"

void usart2_init(void){
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//使能端口时钟 PA2 PA3
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	//使能串口2时钟 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); 
	
	USART_DeInit(USART2); 
	
	// 配置RXD PA3 浮空输入 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// 配置TXD PA2 复用推挽输出 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate = 115200; //波特率
  USART_InitStructure.USART_WordLength = USART_WordLength_8b; //数据位
  USART_InitStructure.USART_StopBits = USART_StopBits_1; //停止位
  USART_InitStructure.USART_Parity = USART_Parity_No; //无校验
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //无需硬件流控
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;;
	// 初始化 USART2
  USART_Init(USART2, &USART_InitStructure);
	 
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置中断组，4位抢占优先级，4位响应优先级；
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;//中断号；
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//抢占优先级
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//响应优先级
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);   
	
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
  // 使能串口工作 USART2
  USART_Cmd(USART2, ENABLE);
}

void usart3_init() {  
	GPIO_InitTypeDef GPIO_InitStructure;  
  USART_InitTypeDef USART_InitStructure;  
	NVIC_InitTypeDef NVIC_InitStructure; 

	
	
	//使能端口时钟 PB10
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	//使能串口3时钟 APB1
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	
	USART_DeInit(USART3); 
	
	/* USART3 GPIO config */
	// 配置TXD PB10 复用推挽输出 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);    
	
	// 配置RXD PB11 浮空输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/* USART3 mode config */
	USART_InitStructure.USART_BaudRate = 115200;//波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//数据位
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//停止位
	USART_InitStructure.USART_Parity = USART_Parity_No ;//无校验
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无需硬件流控
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);   
	
	USART_Init(USART3, &USART_InitStructure);
		

	
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
  //USART_ITConfig(USART3, USART_IT_TXE, ENABLE);
	
	//USART_HalfDuplexCmd(USART3,ENABLE);
		
	USART_Cmd(USART3, ENABLE); 
}

void uart4_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;        
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE );
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE );
	 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //UART4 TX；
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //复用推挽输出；
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure); //端口C；
			
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11; //UART4 RX；
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //浮空输入；
	GPIO_Init(GPIOC, &GPIO_InitStructure); //端口C；
	 
	USART_InitStructure.USART_BaudRate = 115200; //波特率；
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //数据位8位；
	USART_InitStructure.USART_StopBits = USART_StopBits_1; //停止位1位；
	USART_InitStructure.USART_Parity = USART_Parity_No ; //无校验位；
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	//无硬件流控；
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	//收发模式；
	USART_Init(UART4, &USART_InitStructure);//配置串口参数；
	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置中断组，4位抢占优先级，4位响应优先级；
	 
	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn; //中断号；
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //抢占优先级；
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //响应优先级；
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	 
	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
	USART_Cmd(UART4, ENABLE); //使能串口；
}

void uart5_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;        
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE );
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE );
	 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; //UART5 TX；
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //复用推挽输出；
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure); //端口C；
			
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //UART5 RX；
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //浮空输入；
	GPIO_Init(GPIOD, &GPIO_InitStructure); //端口D；
	 
	USART_InitStructure.USART_BaudRate = 115200; //波特率；
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //数据位8位；
	USART_InitStructure.USART_StopBits = USART_StopBits_1; //停止位1位；
	USART_InitStructure.USART_Parity = USART_Parity_No ; //无校验位；
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	//无硬件流控；
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	//收发模式；
	USART_Init(UART5, &USART_InitStructure);//配置串口参数；
	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置中断组，4位抢占优先级，4位响应优先级；
	 
	NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn; //中断号；
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //抢占优先级；
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //响应优先级；
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	 
	USART_ITConfig(UART5, USART_IT_RXNE, ENABLE);
	USART_Cmd(UART5, ENABLE); //使能串口；
}

void usart2_send_byte(u8 Data){
	USART_SendData(USART2, Data);
	while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET); 
}

void usart2_send_str(u8 *Data){
	while(*Data) {
		usart2_send_byte(*Data++);
	}
}

void usart3_send_byte(u8 Data){
	USART_SendData(USART3, Data);
	while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET); 
}

void usart3_send_str(u8 *Data){
	while(*Data) {
		usart3_send_byte(*Data++);
	}
}

void uart4_send_byte(u8 Data) //发送一个字节；
{
	USART_SendData(UART4,Data);
	while( USART_GetFlagStatus(UART4, USART_FLAG_TC) == RESET );
}
 
void uart4_send_str(u8 *Data) //发送字符串；
{
	while(*Data){
		uart4_send_byte(*Data++);
	}
}
 
void uart5_send_byte(u8 Data) //发送一个字节；
{
	USART_SendData(UART5,Data);
	while( USART_GetFlagStatus(UART5, USART_FLAG_TC) == RESET );
}
 
void uart5_send_str(u8 *Data) //发送字符串；
{
	while(*Data){
		uart5_send_byte(*Data++);
	}
}

void usart2_irqHandler(void) //中断处理函数；
{
	u8 res;    
	if(USART_GetITStatus(USART2, USART_IT_RXNE) == SET) //判断是否发生中断；
	{
		USART_ClearFlag(USART2, USART_IT_RXNE); //清除标志位；
		res=USART_ReceiveData(USART2); //接收数据；
		usart2_send_byte(res); //用户自定义；
	}  
}

void usart3_irqHandler(void) //中断处理函数；
{
	u8 res;    
	if(USART_GetITStatus(USART3, USART_IT_RXNE) == SET) //判断是否发生中断；
	{
		USART_ClearFlag(USART3, USART_IT_RXNE); //清除标志位；
		res=USART_ReceiveData(USART3); //接收数据；
		usart3_send_byte(res); //用户自定义；
	}  
}

void uart4_irqHandler(void) //中断处理函数；
{
	u8 res;    
	if(USART_GetITStatus(UART4, USART_IT_RXNE) == SET) //判断是否发生中断；
	{
		USART_ClearFlag(UART4, USART_IT_RXNE); //清除标志位；
		res=USART_ReceiveData(UART4); //接收数据；
		uart4_send_byte(res); //用户自定义；
	}  
} 

void uart5_irqHandler(void) //中断处理函数；
{
	u8 res;    
	if(USART_GetITStatus(UART5, USART_IT_RXNE) == SET) //判断是否发生中断；
	{
		USART_ClearFlag(UART5, USART_IT_RXNE); //清除标志位；
		res=USART_ReceiveData(UART5); //接收数据；
		uart4_send_byte(res); //用户自定义；
	}
} 


void all_send_str(u8 *Data){
	uart4_send_str(Data);
	uart5_send_str(Data);
}

