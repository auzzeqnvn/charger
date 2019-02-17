#include "config.h"

GPIO_InitTypeDef GPIO_InitStructure;
ADC_InitTypeDef ADC_InitStructure;
DMA_InitTypeDef DMA_InitStructure;

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
}

void APP_config_adc(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_ADC2, ENABLE);

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
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 1;
    ADC_Init(ADC1, &ADC_InitStructure);
    /* ADC1 regular channels configuration */ 
    ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_28Cycles5);  
    ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, ADC_SampleTime_28Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 3, ADC_SampleTime_28Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 4, ADC_SampleTime_28Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 5, ADC_SampleTime_28Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 6, ADC_SampleTime_28Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 7, ADC_SampleTime_28Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 8, ADC_SampleTime_28Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 9, ADC_SampleTime_28Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 10, ADC_SampleTime_28Cycles5);


    /* Enable ADC1 */
    ADC_Cmd(ADC1, ENABLE);
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
}

void APP_config(void)
{
    //APP_config_clock();
    APP_config_io();
    APP_config_adc();
    APP_config_usart();
}
