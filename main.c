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

#include "mario.h"

/*
    Main application
*/

#define PI 3.14159265
#define SAMPLES 100  // Number of samples in the wave
#define AMPLITUDE 2047  // Amplitude of the sine wave (for a 12-bit DAC, half of 4096)
#define OFFSET 2048     // Offset for the sine wave (for a 12-bit DAC, middle of 0-4095)

uint8_t sine_wave[SAMPLES];

void generate_sine_wave(void) {
    for (int i = 0; i < SAMPLES; i++) {
        sine_wave[i] = (uint8_t)(AMPLITUDE * (1 + sin(2 * PI * i / SAMPLES)) + OFFSET);
    }
}

int main(void)
{
    SYSTEM_Initialize();
    
    DAC1_Initialize();
    generate_sine_wave();

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
        DAC1_SetOutput(rawData[xxx]);
        if(++xxx > 0x600)
        {
            xxx = 0;
        }
        
        //DELAY_milliseconds(1000);
    }    
    
    
    
    return 0;
}