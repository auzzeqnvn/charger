#include "stm32f10x.h"
#include "config.h"
#include "app_middleware.h"

uint8_t	printf_buff[200];
void    delay_ms(uint32_t   time)
{
    uint32_t    i;
    uint16_t    j;
    for(i=0;i<time;i++)
    {
        for(j=0;j<100;j++);
    }
}

void main(void)
{
    APP_config();
	APP_midd_485_dir(IN);
	USART_Prdata_2(USART1,"Hello",5);
	app_charging_time = 30;
	int i = 0;
	uint32_t	buff[10];
    while(1)
    {
		
		buff[0] = 0;
		buff[5] = 0;
		for(i=0;i<20;i++)
		{
			buff[0] += ADC_BUFF[0][i];
			buff[5] += ADC_BUFF[5][i];
		}
		buff[0] = buff[0] / 20;
		buff[5] = buff[5] / 20;
		memset(printf_buff,0,sizeof(printf_buff));
		sprintf(printf_buff,"ADC1 : %dmV ADC6 : %dmV \r\n",buff[0]*3300/4096,(buff[5]*3300/4096)*2);
		USART_Prdata(USART1,printf_buff);
        delay_ms(20000);
    }
}
