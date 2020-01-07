/**
  ******************************************************************************
  * @file    bsp_SysTick.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   SysTick ϵͳ�δ�ʱ��10us�жϺ�����,�ж�ʱ����������ã�
  *          ���õ��� 1us 10us 1ms �жϡ�     
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:����  STM32 F429 ������
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "./systick/bsp_SysTick.h"

static __IO u32 TimingDelay;
 
/**
  * @brief  ����ϵͳ�δ�ʱ�� SysTick
  * @param  ��
  * @retval ��
  */
void SysTick_Init(void)
{
	/* SystemFrequency / 1000    1ms�ж�һ��
	 * SystemFrequency / 100000	 10us�ж�һ��
	 * SystemFrequency / 1000000 1us�ж�һ��
	 */
	if (SysTick_Config(SystemCoreClock / 100000))
	{ 
		/* Capture error */ 
		while (1);
	}
}

/**
  * @brief   us��ʱ����,10usΪһ����λ
  * @param  
  *		@arg nTime: Delay_us( 1 ) ��ʵ�ֵ���ʱΪ 1 * 10us = 10us
  * @retval  ��
  */
void Delay_us(__IO u32 nTime)
{ 
	TimingDelay = nTime;	

	while(TimingDelay != 0);
}

/**
  * @brief  ��ȡ���ĳ���
  * @param  ��
  * @retval ��
  * @attention  �� SysTick �жϺ��� SysTick_Handler()����
  */
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{ 
		TimingDelay--;
	}
}


/* ����������ʱ���õ��ǲ�ѯ�ķ�����������ʹ���жϣ����Ӽ�� */

void SysTick_Delay_Us( __IO uint32_t us)
{
	 uint32_t i;
	 SysTick_Config(SystemCoreClock/1000000);

	 for (i=0; i<us; i++) {
			 // ����������ֵ��С��0��ʱ��CRTL�Ĵ�����λ16����1
			 while ( !((SysTick->CTRL)&(1<<16)) );
	 }
	 // �ر�SysTick��ʱ��
	 SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
}


void SysTick_Delay_Ms( __IO uint32_t ms)
{
	 uint32_t i;
	 SysTick_Config(SystemCoreClock/1000);

	 for (i=0; i<ms; i++) {
			 // ����������ֵ��С��0��ʱ��CRTL�Ĵ�����λ16����1
			 // ����1ʱ����ȡ��λ����0
			 while ( !((SysTick->CTRL)&(1<<16)) );
	 }
	 // �ر�SysTick��ʱ��
	 SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;
}

/*********************************************END OF FILE**********************/