#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#define IOD_IN1  GPIO_Pin_13
#define IOD_IN1_PORT    GPIOC
#define IOD_IN2  GPIO_Pin_14
#define IOD_IN2_PORT    GPIOC
#define IOD_IN3  GPIO_Pin_15
#define IOD_IN3_PORT    GPIOC

#define IOD_NAP1 GPIO_Pin_1
#define IOD_NAP1_PORT   GPIOB
#define IOD_XA1  GPIO_Pin_12
#define IOD_XA1_PORT    GPIOB
#define IOA_CURRENT1 GPIO_Pin_0
#define IOA_CURRENT1_PORT   GPIOA
#define IOA_VOL1 GPIO_Pin_5
#define IOA_VOL1_PORT   GPIOA


#define IOD_NAP2 GPIO_Pin_13
#define IOD_NAP2_PORT   GPIOB
#define IOD_XA2  GPIO_Pin_14
#define IOD_XA2_PORT    GPIOB
#define IOA_CURRENT2 GPIO_Pin_1
#define IOA_CURRENT2_PORT   GPIOA
#define IOA_VOL2 GPIO_Pin_6
#define IOA_VOL2_PORT   GPIOA

#define IOD_NAP3 GPIO_Pin_15
#define IOD_NAP3_PORT   GPIOB
#define IOD_XA3  GPIO_Pin_12
#define IOD_XA3_PORT    GPIOB
#define IOA_CURRENT3 GPIO_Pin_2
#define IOA_CURRENT3_PORT   GPIOA
#define IOA_VOL3 GPIO_Pin_7
#define IOA_VOL3_PORT   GPIOA

#define IOD_NAP4 GPIO_Pin_11
#define IOD_NAP4_PORT   GPIOA
#define IOD_XA4  GPIO_Pin_12
#define IOD_XA4_PORT    GPIOB
#define IOA_CURRENT4 GPIO_Pin_3
#define IOA_CURRENT4_PORT   GPIOA
#define IOA_VOL4 GPIO_Pin_0
#define IOA_VOL4_PORT   GPIOB

#define IOD_NAP5 GPIO_Pin_8
#define IOD_NAP5_PORT   GPIOB
#define IOD_XA5  GPIO_Pin_12
#define IOD_XA5_PORT    GPIOB
#define IOA_CURRENT5 GPIO_Pin_4
#define IOA_CURRENT5_PORT   GPIOA
#define IOA_VOL5 GPIO_Pin_1
#define IOA_VOL5_PORT   GPIOB

#define IOD_LED  GPIO_Pin_5
#define IOD_LED_PORT    GPIOB

#define ON 1
#define OFF 0



void APP_config(void);

