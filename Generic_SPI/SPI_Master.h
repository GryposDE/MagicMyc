/* 
 * File:   SPI.h
 * Author: Christian Roth
 *
 * Created on 20. Juli 2024, 14:24
 */

#ifndef CR_SPI_MASTER_H
#define	CR_SPI_MASTER_H

#include "SPI_Internal.h"
    
typedef enum
{
    SPI_CLKSEL_SYSCLK                 =  (0b0000 << SPIxCLK_CLKSEL_Pos),
    SPI_CLKSEL_HFINTOSC               =  (0b0001 << SPIxCLK_CLKSEL_Pos),
    SPI_CLKSEL_MFINTOSC               =  (0b0010 << SPIxCLK_CLKSEL_Pos), /* 500 kHz */
    SPI_CLKSEL_EXTOSC                 =  (0b0011 << SPIxCLK_CLKSEL_Pos),
    SPI_CLKSEL_ClockRefOutput         =  (0b0100 << SPIxCLK_CLKSEL_Pos),
    SPI_CLKSEL_TMR0_OUT               =  (0b0101 << SPIxCLK_CLKSEL_Pos),
    SPI_CLKSEL_TMR2_Postscaler_OUT    =  (0b0110 << SPIxCLK_CLKSEL_Pos),
    SPI_CLKSEL_TMR4_Postscaler_OUT    =  (0b0111 << SPIxCLK_CLKSEL_Pos),
    SPI_CLKSEL_SMT1_OUT               =  (0b1000 << SPIxCLK_CLKSEL_Pos),
    SPI_CLKSEL_CLC1_OUT               =  (0b1001 << SPIxCLK_CLKSEL_Pos),
    SPI_CLKSEL_CLC2_OUT               =  (0b1010 << SPIxCLK_CLKSEL_Pos),
    SPI_CLKSEL_CLC3_OUT               =  (0b1011 << SPIxCLK_CLKSEL_Pos),
    SPI_CLKSEL_CLC4_OUT               =  (0b1100 << SPIxCLK_CLKSEL_Pos),
            
} eSPI_CLKSEL_t;

typedef enum
{
    SPI_MODE_0  = 0,
    SPI_MODE_1  = 1,
    SPI_MODE_2  = 2,
    SPI_MODE_3  = 3,
} eSPI_Mode_t;
    
typedef struct
{
    eSPI_Mode_t eSPI_Mode;
    eSPI_CLKSEL_t eSPI_CLKSEL;
    uint8_t u8SPI_Baud;
    
    uint8_t bMSB_First;     /* default: true */
    
} sSPI_Config;
    

/* public functions */
    
int8_t s8SPI_Master_Init(sSPI_Handler_t* const psSPI_Handler, sSPI_Config const* const psConfig);

int8_t s8SPI_Master_TransmitData(sSPI_Handler_t* const psSPI_Handler, uint8_t const* const pu8Data, uint32_t u32DataLength);

int8_t s8SPI_Master_ReceiveData(sSPI_Handler_t* const psSPI_Handler, uint8_t* const pu8Data, uint32_t u32DataLength);

int8_t s8SPI_Master_TransmitReceiveData(sSPI_Handler_t* const psSPI_Handler, uint8_t const* const pu8TxData, uint8_t* const pu8RxData, uint32_t u32DataLength);


#endif	/* SPI_H */

