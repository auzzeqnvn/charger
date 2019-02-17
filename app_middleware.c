#include "app_middleware.h"
#include "config.h"

/*
Lua chon va dieu khien cong sac
Cong sac 1-5
state : ON/OFF
*/
void    APP_midd_charging_control(uint8_t  Charger,uint8_t  state)
{
    switch(Charger)
    {
        case    1:
        {
            GPIO_WriteBit(GPIOA,IO_NAP1,state);
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
    GPIO_WriteBit(GPIOB,IO_LED,state);
}


