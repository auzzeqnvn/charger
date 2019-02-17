#include "stm32f10x.h"
#include "config.h"
#include "app_middleware.h"

void    delay_ms(uint32_t   time)
{
    uint32_t    i;
    uint16_t    j;
    for(i=0;i<time;i++)
    {
        for(j=0;j<10000;j++);
    }
}

void main(void)
{
    APP_config();
    while(1)
    {
        APP_midd_charging_control(1,ON);
        APP_midd_led(ON);
        delay_ms(1000);
        APP_midd_charging_control(1,OFF);
        APP_midd_led(OFF);
        delay_ms(1000);
    }
}
