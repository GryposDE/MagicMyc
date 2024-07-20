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

/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();
    
    DAC1_Initialize();
    
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

    TRISB &= ~(1U << 7U); // pin7 is an
    TRISB &= ~(1U << 6U); // pin6 is an
    TRISB &= ~(1U << 5U); // pin6 is an
    WPUB = 0;
    ODCONB = 0; // push-pull
    
    uint8_t bShow = 0;
    uint32_t xxx = 0;
    uint32_t yyy = 0;
    int8_t light = 0;
    uint32_t counter = 0;
    while(1)
    {
        
        // PWM LED
        if(counter < light)
        {
            PORTB |=  (1U << 7U);
            PORTB |=  (1U << 5U);
            PORTB &= ~(1U << 6U);
        }
        else
        {
            PORTB &= ~(1U << 7U);
            PORTB &=  (1U << 5U);
            PORTB |=  (1U << 6U);
        }
        
        if(++counter > 10)
        {
            counter = 0;
            if(++yyy > 0x2000)
            {
                yyy = 0;
            
                if(bShow == 0)
                {
                    if(++light > 10)
                    {
                        bShow = 1;
                    }
                }
                else
                {
                    if(--light <= 0)
                    {
                        bShow = 0;
                    }
                }
            }
        }
        
        // DAC
        //DAC1_SetOutput(rawData[xxx]);
        //if(++xxx > 0x600)
        {
            xxx = 0;
        }
        
        // SPI
        
        //DELAY_milliseconds(1000);
    }    
    
    
    
    return 0;
}