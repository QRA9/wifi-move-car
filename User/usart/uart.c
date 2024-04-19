#include "uart.h"

void usart2_init(void){
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//ʹ�ܶ˿�ʱ�� PA2 PA3
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	//ʹ�ܴ���2ʱ�� 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); 
	
	USART_DeInit(USART2); 
	
	// ����RXD PA3 �������� 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// ����TXD PA2 ����������� 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate = 115200; //������
  USART_InitStructure.USART_WordLength = USART_WordLength_8b; //����λ
  USART_InitStructure.USART_StopBits = USART_StopBits_1; //ֹͣλ
  USART_InitStructure.USART_Parity = USART_Parity_No; //��У��
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //����Ӳ������
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;;
	// ��ʼ�� USART2
  USART_Init(USART2, &USART_InitStructure);
	 
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�����ж��飬4λ��ռ���ȼ���4λ��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;//�жϺţ�
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//��ռ���ȼ�
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//��Ӧ���ȼ�
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);   
	
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
  // ʹ�ܴ��ڹ��� USART2
  USART_Cmd(USART2, ENABLE);
}

void usart3_init() {  
	GPIO_InitTypeDef GPIO_InitStructure;  
  USART_InitTypeDef USART_InitStructure;  
	NVIC_InitTypeDef NVIC_InitStructure; 

	
	
	//ʹ�ܶ˿�ʱ�� PB10
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	//ʹ�ܴ���3ʱ�� APB1
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	
	USART_DeInit(USART3); 
	
	/* USART3 GPIO config */
	// ����TXD PB10 ����������� 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);    
	
	// ����RXD PB11 ��������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/* USART3 mode config */
	USART_InitStructure.USART_BaudRate = 115200;//������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//����λ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No ;//��У��
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//����Ӳ������
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
	 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //UART4 TX��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //�������������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure); //�˿�C��
			
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11; //UART4 RX��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //�������룻
	GPIO_Init(GPIOC, &GPIO_InitStructure); //�˿�C��
	 
	USART_InitStructure.USART_BaudRate = 115200; //�����ʣ�
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //����λ8λ��
	USART_InitStructure.USART_StopBits = USART_StopBits_1; //ֹͣλ1λ��
	USART_InitStructure.USART_Parity = USART_Parity_No ; //��У��λ��
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	//��Ӳ�����أ�
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	//�շ�ģʽ��
	USART_Init(UART4, &USART_InitStructure);//���ô��ڲ�����
	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�����ж��飬4λ��ռ���ȼ���4λ��Ӧ���ȼ���
	 
	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn; //�жϺţ�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //��ռ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	 
	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
	USART_Cmd(UART4, ENABLE); //ʹ�ܴ��ڣ�
}

void uart5_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;        
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE );
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE );
	 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; //UART5 TX��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //�������������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure); //�˿�C��
			
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //UART5 RX��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //�������룻
	GPIO_Init(GPIOD, &GPIO_InitStructure); //�˿�D��
	 
	USART_InitStructure.USART_BaudRate = 115200; //�����ʣ�
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //����λ8λ��
	USART_InitStructure.USART_StopBits = USART_StopBits_1; //ֹͣλ1λ��
	USART_InitStructure.USART_Parity = USART_Parity_No ; //��У��λ��
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	//��Ӳ�����أ�
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	//�շ�ģʽ��
	USART_Init(UART5, &USART_InitStructure);//���ô��ڲ�����
	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�����ж��飬4λ��ռ���ȼ���4λ��Ӧ���ȼ���
	 
	NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn; //�жϺţ�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //��ռ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	 
	USART_ITConfig(UART5, USART_IT_RXNE, ENABLE);
	USART_Cmd(UART5, ENABLE); //ʹ�ܴ��ڣ�
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

void uart4_send_byte(u8 Data) //����һ���ֽڣ�
{
	USART_SendData(UART4,Data);
	while( USART_GetFlagStatus(UART4, USART_FLAG_TC) == RESET );
}
 
void uart4_send_str(u8 *Data) //�����ַ�����
{
	while(*Data){
		uart4_send_byte(*Data++);
	}
}
 
void uart5_send_byte(u8 Data) //����һ���ֽڣ�
{
	USART_SendData(UART5,Data);
	while( USART_GetFlagStatus(UART5, USART_FLAG_TC) == RESET );
}
 
void uart5_send_str(u8 *Data) //�����ַ�����
{
	while(*Data){
		uart5_send_byte(*Data++);
	}
}

void usart2_irqHandler(void) //�жϴ�������
{
	u8 res;    
	if(USART_GetITStatus(USART2, USART_IT_RXNE) == SET) //�ж��Ƿ����жϣ�
	{
		USART_ClearFlag(USART2, USART_IT_RXNE); //�����־λ��
		res=USART_ReceiveData(USART2); //�������ݣ�
		usart2_send_byte(res); //�û��Զ��壻
	}  
}

void usart3_irqHandler(void) //�жϴ�������
{
	u8 res;    
	if(USART_GetITStatus(USART3, USART_IT_RXNE) == SET) //�ж��Ƿ����жϣ�
	{
		USART_ClearFlag(USART3, USART_IT_RXNE); //�����־λ��
		res=USART_ReceiveData(USART3); //�������ݣ�
		usart3_send_byte(res); //�û��Զ��壻
	}  
}

void uart4_irqHandler(void) //�жϴ�������
{
	u8 res;    
	if(USART_GetITStatus(UART4, USART_IT_RXNE) == SET) //�ж��Ƿ����жϣ�
	{
		USART_ClearFlag(UART4, USART_IT_RXNE); //�����־λ��
		res=USART_ReceiveData(UART4); //�������ݣ�
		uart4_send_byte(res); //�û��Զ��壻
	}  
} 

void uart5_irqHandler(void) //�жϴ�������
{
	u8 res;    
	if(USART_GetITStatus(UART5, USART_IT_RXNE) == SET) //�ж��Ƿ����жϣ�
	{
		USART_ClearFlag(UART5, USART_IT_RXNE); //�����־λ��
		res=USART_ReceiveData(UART5); //�������ݣ�
		uart4_send_byte(res); //�û��Զ��壻
	}
} 


void all_send_str(u8 *Data){
	uart4_send_str(Data);
	uart5_send_str(Data);
}

