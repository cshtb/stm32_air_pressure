#include "stm32f4xx.h"
#include "./usart/bsp_debug_usart.h"
#include "./adc/bsp_adc.h"
#include "./relay/bsp_relay.h"
#include "./systick/bsp_SysTick.h"
#include "./tim/bsp_advance_tim.h"
#include "./all_init/init.h"

void init(void)
{
  Debug_USART_Config();//串口通信初始化
	RELAY_GPIO_Config();//继电器接口初始化
	Rheostat_Init();//AD初始化	
	TIMx_Configuration(); // 初始化高级控制定时器定时，1s产生一次中断
}
