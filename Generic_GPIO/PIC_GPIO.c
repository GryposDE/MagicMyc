
#include <xc.h>

#include "PIC_GPIO.h"


static void vGeneric_GPIO_Set(sGeneric_GPIO_t* const psGPIO);
static void vGeneric_GPIO_Reset(sGeneric_GPIO_t* const psGPIO);

typedef struct
{
    volatile uint8_t ANSELx;   // analog select
    volatile uint8_t WPUx;     // pull-up enable
    volatile uint8_t ODCONx;   // open-drain enable
    volatile uint8_t SLRCONx;  // slew rate control
    volatile uint8_t INLVLx;   // input level select
    
} sInternal_GPIO_Config_t;

#define GPIOA_CONFIG    ((sInternal_GPIO_Config_t*)&ANSELA)
#define GPIOB_CONFIG    ((sInternal_GPIO_Config_t*)&ANSELB)
#define GPIOC_CONFIG    ((sInternal_GPIO_Config_t*)&ANSELC)

static sInternal_GPIO_Config_t* const apsGPIO_Configs[] = {
    GPIOA_CONFIG,
    GPIOB_CONFIG,
    GPIOC_CONFIG,
};

#define TRISx(port)     (port-8)

void vPIC_GPIO_Init(sPIC_GPIO_t* pPIC_GPIO_Handler, sPIC_GPIO_Config_t* psConfig)
{
    pPIC_GPIO_Handler->base.GPIO_Pin  = (uint32_t)psConfig->GPIO_Pin;
    pPIC_GPIO_Handler->base.GPIO_Port = (uint32_t)&psConfig->GPIO_Port;
    
    // Configure Pin as input or output
    *(uint8_t*)TRISx(pPIC_GPIO_Handler->base.GPIO_Port) &= (1 << pPIC_GPIO_Handler->base.GPIO_Pin);
    *(uint8_t*)TRISx(pPIC_GPIO_Handler->base.GPIO_Port) |= (psConfig->bIsInput << pPIC_GPIO_Handler->base.GPIO_Pin);
    
    // Configure the use of an internal pull-up
    apsGPIO_Configs[( ((uint8_t)&PORTA) - ((uint8_t)pPIC_GPIO_Handler->base.GPIO_Port) )]->WPUx &= (1 << pPIC_GPIO_Handler->base.GPIO_Pin);
    apsGPIO_Configs[( ((uint8_t)&PORTA) - ((uint8_t)pPIC_GPIO_Handler->base.GPIO_Port) )]->WPUx |= (psConfig->bPullUp << pPIC_GPIO_Handler->base.GPIO_Pin);
    
    // Configure the use of open-drain or push-pull
    apsGPIO_Configs[( ((uint8_t)&PORTA) - ((uint8_t)pPIC_GPIO_Handler->base.GPIO_Port) )]->ODCONx &= (1 << pPIC_GPIO_Handler->base.GPIO_Pin);
    apsGPIO_Configs[( ((uint8_t)&PORTA) - ((uint8_t)pPIC_GPIO_Handler->base.GPIO_Port) )]->ODCONx |= (psConfig->bOpenDrain << pPIC_GPIO_Handler->base.GPIO_Pin);
    
}

void vPIC_GPIO_Set(sPIC_GPIO_t* pPIC_GPIO_Handler)
{
    *((uint8_t*)pPIC_GPIO_Handler->base.GPIO_Port) |= (1 << pPIC_GPIO_Handler->base.GPIO_Pin);
}

void vPIC_GPIO_Reset(sPIC_GPIO_t* pPIC_GPIO_Handler)
{
    *((uint8_t*)pPIC_GPIO_Handler->base.GPIO_Port) &= ~( 1 << pPIC_GPIO_Handler->base.GPIO_Pin);
}


/* private functions */

static void vGeneric_GPIO_Set(sGeneric_GPIO_t* const psGPIO)
{
    vPIC_GPIO_Set((sPIC_GPIO_t*)psGPIO);
}

static void vGeneric_GPIO_Reset(sGeneric_GPIO_t* const psGPIO)
{
    vPIC_GPIO_Reset((sPIC_GPIO_t*)psGPIO);
}

