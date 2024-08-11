#ifndef GENERIC_GPIO_PIC_GPIO_H
#define GENERIC_GPIO_PIC_GPIO_H

#include "Generic_GPIO.h"


typedef struct
{
    uint8_t GPIO_Pin;
    uint8_t GPIO_Port;
    
    uint8_t bPullUp    : 1;
    uint8_t bIsInput   : 1;
    uint8_t bOpenDrain : 1;
    
} sPIC_GPIO_Config_t;

typedef struct
{
    sGeneric_GPIO_t base;

} sPIC_GPIO_t;


void vPIC_GPIO_Init(sPIC_GPIO_t* pPIC_GPIO_Handler, sPIC_GPIO_Config_t* psConfig);

void vPIC_GPIO_Set(sPIC_GPIO_t* pPIC_GPIO_Handler);

void vPIC_GPIO_Reset(sPIC_GPIO_t* pPIC_GPIO_Handler);


#endif /* GENERIC_GPIO_PIC_GPIO_H */
