#include <stm32f10x_lib.h>
#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h" 
#include "key.h"	 	 
//Mini STM32开发板范例代码2
//按键输入实验
//正点原子@ALIENTEK
//技术论坛:www.openedv.com	  
int main(void)
{								  
	u8 t;	  
	Stm32_Clock_Init(9); //系统时钟设置
	delay_init(72);	     //延时初始化 
	LED_Init();		  	 //初始化与LED连接的硬件接口
	KEY_Init();          //初始化与按键连接的硬件接口
	while(1)
	{
		t=KEY_Scan();//得到键值
	   	if(t)
		{						   
			switch(t)
			{				 
				case 1:
					LED0=!LED0;
					break;
				case 2:
					LED1=!LED1;
					break;
				case 3:				
					LED0=!LED0;
					LED1=!LED1;
					break;
			}
		}else delay_ms(10); 
	}	 
}

























