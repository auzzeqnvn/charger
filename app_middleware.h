#include "stm32f10x.h"

#define	CHARGING_TIME_FULL 100

extern uint8_t	app_charging_time;
extern uint16_t	ADC_BUFF[10][20];

void    APP_midd_charging_control(uint8_t  Charger,uint8_t  state);
void    APP_midd_led(uint8_t    state);
void USART_Prdata_2(USART_TypeDef* USARTx, uint8_t* str,uint8_t	num);
void USART_Prdata(USART_TypeDef* USARTx, uint8_t* str);
