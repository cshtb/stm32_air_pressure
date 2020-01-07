#include "stm32f4xx.h"
#include "./usart/bsp_debug_usart.h"
#include "./adc/bsp_adc.h"
#include "./relay/bsp_relay.h"
#include "./systick/bsp_SysTick.h"
#include "./tim/bsp_advance_tim.h"
#include "./all_init/init.h"

void init(void)
{
  Debug_USART_Config();//����ͨ�ų�ʼ��
	RELAY_GPIO_Config();//�̵����ӿڳ�ʼ��
	Rheostat_Init();//AD��ʼ��	
	TIMx_Configuration(); // ��ʼ���߼����ƶ�ʱ����ʱ��1s����һ���ж�
}
