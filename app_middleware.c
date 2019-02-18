#include "app_middleware.h"
#include "config.h"

uint8_t	app_charging_time = 0;
uint16_t	ADC_BUFF[10][20];
/*
Lua chon va dieu khien cong sac
Cong sac 1-5
state : ON/OFF
*/
void    APP_midd_charging_control(uint8_t  Charger,uint8_t  state)
{
    if(state == OFF)	state = Bit_RESET;
	else	state = Bit_SET;
	switch(Charger)
    {
        case    1:
        {
            GPIO_WriteBit(IOD_NAP1_PORT,IOD_NAP1,state);
            break;
        }
    }
}

/*
Dieu khien led
state : ON/OFF
*/
void    APP_midd_led(uint8_t    state)
{
    GPIO_WriteBit(GPIOB,IOD_LED,state);
}

/*
Dieu khien chon huong du lieu 485
state : OUT/IN
*/
void    APP_midd_485_dir(uint8_t  state)
{
    if(state == OUT)	state = Bit_RESET;
	else	state = Bit_SET;
	GPIO_WriteBit(IOD_485_DIR_PORT,IOD_485_DIR,state);
}
/**
 * @fn		void USART_PrChar(USART_TypeDef* USARTx, uint16_t data)
 * @brief	send one character though USARTx
 * @param	USARTx	USART Instance
 * @param	data	character to be sent
 */
void USART_PrChar(USART_TypeDef* USARTx, uint8_t data)
{
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE)==RESET);
	USART_SendData(USARTx, data);
}
void USART_Prdata(USART_TypeDef* USARTx, uint8_t* str)
{
	while(*str)
	{
		USART_PrChar(USARTx, *str++);
	}
}
void USART_Prdata_2(USART_TypeDef* USARTx, uint8_t* str,uint8_t	num)
{
	while(num--)
	{
		USART_PrChar(USARTx, *str++);
	}
}

