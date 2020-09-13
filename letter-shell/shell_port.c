/**
 * @brief   shell��ֲ��STM32F767ʱ�Ľӿ�ʵ��
 * @author	mculover666
 * @date    2020/09/13 
*/

#include "shell.h"
#include "stm32h7xx_hal.h"
#include "usart.h"
#include "shell_port.h"

/* 1. ����shell���󣬿���shell������ */
Shell shell;
char shell_buffer[512];


/* 2. �Լ�ʵ��shellд���� */

//shellд����ԭ�ͣ�typedef void (*shellWrite)(const char);
void User_Shell_Write(const char ch)
{
	//����STM32 HAL�� API ʹ�ò�ѯ��ʽ����
	HAL_UART_Transmit(&huart1, (uint8_t*)&ch, 1, 0xFFFF);
}

/* 3. ��д��ʼ������ */
void User_Shell_Init(void)
{
		//ע���Լ�ʵ�ֵ�д����
    shell.write = User_Shell_Write;
	
		//����shell��ʼ������
    shellInit(&shell, shell_buffer, 512);
}
