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


// ADC1ת���ĵ�ѹֵͨ��MDA��ʽ����SRAM
//extern __IO uint16_t ADC_ConvertedValue;

// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
//float ADC_Vol; 

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
	init();
	Usart_SendString( DEBUG_USART,"���������ģ�����\n");
	printf("�̵�����������ݲ���\n");
	
    while (1)
    {
			RELAY1_ON; 
			SysTick_Delay_Ms( 5000 );
		  RELAY1_OFF;
			SysTick_Delay_Ms( 5000 );
    }
}



/*********************************************END OF FILE**********************/

