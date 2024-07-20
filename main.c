 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"

#include "mcc_generated_files/timer/delay.h"
#include "math.h"

#include "mcc_generated_files/dac/dac1.h"
//#include "mcc_generated_files/spi/spi1.h"

#include "SPI/SPI_Master.h"


#define SAMPLES 100     // Number of samples in the wave
#define AMPLITUDE 2047  // Amplitude of the sine wave (for a 12-bit DAC, half of 4096)
#define OFFSET 2048     // Offset for the sine wave (for a 12-bit DAC, middle of 0-4095)


static void vRGB_GPIO_Init(void);

static void vGPIO_Set(volatile uint8_t* const pu8GPIO_Port, uint8_t u8GPIO_Pin);
static void vGPIO_Reset(volatile uint8_t* const pu8GPIO_Port, uint8_t u8GPIO_Pin);


static void vGenerateSinus(uint8_t* const pu8OutputArray, uint32_t u32Samples, uint32_t u32Amplitude, uint32_t u32Offset);

/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();
    
    static uint8_t au8SinusWave[SAMPLES];
    vGenerateSinus((uint8_t*)au8SinusWave, SAMPLES, AMPLITUDE, OFFSET);
    DAC1_Initialize();
    
    vRGB_GPIO_Init();
    
    sSPI_Config const sConfig = {
        .eSPI_Mode = SPI_MODE_0,
        .eSPI_CLKSEL = SPI_CLKSEL_MFINTOSC,
        .u8SPI_Baud = 1U,    
        .bMSB_First = 1U,
    };

    s8SPI_Master_Init(pSPI1, &sConfig);

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    //INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    uint32_t u32CurrentSample = 0;
    
    uint8_t  u8Light = 0;
    uint8_t  u8Direction = 0;
    uint32_t u32CounterA = 0;
    uint32_t u32CounterB = 0;
    while(1)
    {
        // PWM RGB LED:
        if(u32CounterA < u8Light)
        {
            vGPIO_Set(&PORTB, 7U);
            vGPIO_Reset(&PORTB, 6U);
        }
        else
        {
            vGPIO_Reset(&PORTB, 7U);
            vGPIO_Set(&PORTB, 6U);
        }
        
        // Super smart and for sure not brutforce-tested timing for RGB animation
        if(++u32CounterA > 10)
        {
            u32CounterA = 0;
            if(++u32CounterB > 0x2000)
            {
                u32CounterB = 0;                
                if(u8Direction == 0)
                {
                    if(++u8Light > 10)
                    {
                        u8Direction = !u8Direction;
                    }
                }
                else
                {
                    if(--u8Light == 0)
                    {
                        u8Direction = !u8Direction;
                    }
                }
            }
        }
        
        // DAC
        DAC1_SetOutput(au8SinusWave[u32CurrentSample]);
        if(++u32CurrentSample > SAMPLES)
        {
            u32CurrentSample = 0;
        }
        
        // SPI
        
        //DELAY_milliseconds(1000);
    }    
    
    
    
    return 0;
}


static void vRGB_GPIO_Init(void)
{
    TRISB &= ~(1U << 7U);   // pin7 is an output
    TRISB &= ~(1U << 6U);   // pin6 is an output
    TRISB &= ~(1U << 5U);   // pin5 is an output
    WPUB   = 0;             // pullup disable
    ODCONB = 0;             // push-pull
}

static void vGPIO_Set(volatile uint8_t* const pu8GPIO_Port, uint8_t u8GPIO_Pin)
{
    *pu8GPIO_Port |= (1U << u8GPIO_Pin);
}

static void vGPIO_Reset(volatile uint8_t* const pu8GPIO_Port, uint8_t u8GPIO_Pin)
{
    *pu8GPIO_Port &= ~(1U << u8GPIO_Pin);
}


static void vGenerateSinus(uint8_t* const pu8OutputArray, uint32_t u32Samples, uint32_t u32Amplitude, uint32_t u32Offset)
{
    static double const PI = 3.14159265;
    for (int i = 0; i < u32Samples; ++i) 
    {
        pu8OutputArray[i] = (uint8_t)(u32Amplitude * (1 + sin(2 * PI * i / u32Samples)) + u32Offset);
    }
}