#include "config.h"

GPIO_InitTypeDef GPIO_InitStructure;
ADC_InitTypeDef ADC_InitStructure;
DMA_InitTypeDef DMA_InitStructure;
USART_InitTypeDef USART_InitStructure;
TIM_TimeBaseInitTypeDef timBaseStruct;
NVIC_InitTypeDef	NVIC_InitStructure;

uint8_t	APP_USART_BUFF[APP_USART_BUFF_LEN];
uint8_t v_usart_buff_count = 0;

uint16_t	ADCBuffer[10];


void APP_config_clock(void)
{
    RCC_DeInit();
    RCC_HSEConfig(RCC_HSE_ON);
    while(RCC_WaitForHSEStartUp() != SUCCESS);
    RCC_PLLConfig(RCC_PLLSource_HSE_Div1,9);
    RCC_PLLCmd(ENABLE);
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
    RCC_HCLKConfig(RCC_SYSCLK_Div1);
    RCC_PCLK1Config(RCC_HCLK_Div2);
    RCC_PCLK2Config(RCC_HCLK_Div1);
    RCC_ITConfig(RCC_IT_PLLRDY,DISABLE);
    RCC_ADCCLKConfig(RCC_PCLK2_Div2);
}
void APP_config_io(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC,ENABLE);

    /* Khoi tao input tao dia chi */
    GPIO_InitStructure.GPIO_Pin = IOD_IN1;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(IOD_IN1_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = IOD_IN2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(IOD_IN2_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = IOD_IN3;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(IOD_IN3_PORT, &GPIO_InitStructure);

    /* Khoi tao IO nap xa 1 */
    GPIO_InitStructure.GPIO_Pin = IOD_XA1;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(IOD_XA1_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = IOD_NAP1;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(IOD_NAP1_PORT, &GPIO_InitStructure);

    /* Khoi tao IO nap xa 2 */
    GPIO_InitStructure.GPIO_Pin = IOD_XA2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(IOD_XA2_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = IOD_NAP2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(IOD_NAP2_PORT, &GPIO_InitStructure);

    /* Khoi tao IO nap xa 3 */
    GPIO_InitStructure.GPIO_Pin = IOD_XA3;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(IOD_XA3_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = IOD_NAP3;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(IOD_NAP3_PORT, &GPIO_InitStructure);

    /* Khoi tao IO nap xa 4 */
    GPIO_InitStructure.GPIO_Pin = IOD_XA4;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(IOD_XA4_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = IOD_NAP4;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(IOD_NAP4_PORT, &GPIO_InitStructure);

    /* Khoi tao IO nap xa 5 */
    GPIO_InitStructure.GPIO_Pin = IOD_XA5;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(IOD_XA1_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = IOD_NAP5;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(IOD_NAP1_PORT, &GPIO_InitStructure);
    
    /* Khoi tao led */
    GPIO_InitStructure.GPIO_Pin = IOD_LED;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(IOD_LED_PORT, &GPIO_InitStructure);
	
	/* khoi tao chan dieu khien huong du lieu 485 */
	GPIO_InitStructure.GPIO_Pin = IOD_485_DIR;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(IOD_485_DIR_PORT, &GPIO_InitStructure);
}

void APP_config_adc(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

    /* khoi tao cac chan nhan gia tri dong dien */
    GPIO_InitStructure.GPIO_Pin = IOA_CURRENT1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(IOA_CURRENT1_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = IOA_CURRENT2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(IOA_CURRENT2_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = IOA_CURRENT3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(IOA_CURRENT3_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = IOA_CURRENT4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(IOA_CURRENT4_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = IOA_CURRENT5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(IOA_CURRENT5_PORT, &GPIO_InitStructure);

    /* khoi tao cac chan nhan gia tri dien ap */
    GPIO_InitStructure.GPIO_Pin = IOA_VOL1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(IOA_VOL1_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = IOA_VOL2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(IOA_VOL2_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = IOA_VOL3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(IOA_VOL3_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = IOA_VOL4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(IOA_VOL4_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = IOA_VOL5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(IOA_VOL5_PORT, &GPIO_InitStructure);
    
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = ENABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 10;
    ADC_Init(ADC1, &ADC_InitStructure);
    /* ADC1 regular channels configuration */ 
    ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_239Cycles5);  
    ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, ADC_SampleTime_239Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 3, ADC_SampleTime_239Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 4, ADC_SampleTime_239Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 5, ADC_SampleTime_239Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 6, ADC_SampleTime_239Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 7, ADC_SampleTime_239Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 8, ADC_SampleTime_239Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 9, ADC_SampleTime_239Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 10, ADC_SampleTime_239Cycles5);


	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
	DMA_InitStructure.DMA_BufferSize = 10;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ADCBuffer;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);

	DMA_Cmd(DMA1_Channel1, ENABLE);

    /* Enable ADC1 */
    ADC_Cmd(ADC1, ENABLE);
	ADC_DMACmd(ADC1, ENABLE);
    /* Enable ADC1 reset calibration register */   
    ADC_ResetCalibration(ADC1);
    /* Check the end of ADC1 reset calibration register */
    while(ADC_GetResetCalibrationStatus(ADC1));

    /* Start ADC1 calibration */
    ADC_StartCalibration(ADC1);
    /* Check the end of ADC1 calibration */
    while(ADC_GetCalibrationStatus(ADC1));

    /* Start ADC1 Software Conversion */ 
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

void APP_config_usart(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	/* Configure PA9 and PA10 as USART1 TX/RX */
    
    /* PA9 = alternate function push/pull output */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    /* PA10 = floating input */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    /* Configure and initialize usart... */
    USART_InitStructure.USART_BaudRate = 9600;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
        
    USART_Init(USART1, &USART_InitStructure);
    
    /* Enable USART1 */
    USART_Cmd(USART1, ENABLE);   
}

void	APP_config_timer2(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	timBaseStruct.TIM_Prescaler = 360-1;
	timBaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	timBaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
	timBaseStruct.TIM_Period = 10-1;
	timBaseStruct.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM2, &timBaseStruct);
	TIM_Cmd(TIM2, ENABLE);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE );
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_EnableIRQ(TIM2_IRQn);
}

void APP_config(void)
{
    APP_config_clock();
    APP_config_io();
    APP_config_adc();
	APP_config_timer2();
    APP_config_usart();
}
