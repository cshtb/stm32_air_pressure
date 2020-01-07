/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2019-xx-xx
  ******************************************************************************
  * @attention
  *	https://github.com/cshtb/stm32_air_pressure.git
  *
  ******************************************************************************
  */
  
#include "include.h"


// ADC1转换的电压值通过MDA方式传到SRAM
//extern __IO uint16_t ADC_ConvertedValue;

// 局部变量，用于保存转换计算后的电压值 	 
//float ADC_Vol; 

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
	init();
	Usart_SendString( DEBUG_USART,"软体机器人模块测试\n");
	printf("继电器与接收数据测试\n");
	
    while (1)
    {
			RELAY1_ON; 
			SysTick_Delay_Ms( 5000 );
		  RELAY1_OFF;
			SysTick_Delay_Ms( 5000 );
    }
}



/*********************************************END OF FILE**********************/

