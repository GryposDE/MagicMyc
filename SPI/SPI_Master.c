
#include "SPI_Master.h"

#include <assert.h>

#ifndef assert
#define assert(x)       (!(!x))
#endif

#define SPI_MODE_Pos    (SPIxCON1_CKP_Pos)
#define SPI_MODE_Mask   ((SPIxCON1_CKE_Mask | SPIxCON1_CKP_Mask))


static void vSPI_Enable(sSPI_Handler_t* const psSPI_Handler);
static void vSPI_Disable(sSPI_Handler_t* const psSPI_Handler);
static void vSPI_ClearFIFOs(sSPI_Handler_t* const psSPI_Handler);

/* public functions */
    
int8_t s8SPI_Master_Init(sSPI_Handler_t* const psSPI_Handler, sSPI_Config const* const psConfig)
{
    assert(psSPI_Handler);
    assert(psConfig);
    
    /**
     *  Disable SPI to change configuration.
     */
    vSPI_Disable(psSPI_Handler);
    
    /**
     *  Set SPI as master,
     *   set BMODE (only 8bit data),
     *   configure MSB/LSB-first from user.
     */
    psSPI_Handler->SPIxCON0 = ( (psSPI_Handler->SPIxCON0 & (~(SPIxCON0_LSBF_Mask | SPIxCON0_MST_Mask))) |
                                ((SPIxCON0_MST_Mask) | (SPIxCON0_BMODE_Mask) | !psConfig->bMSB_First) );
    
    /**
     *  Set data_size to 8 bit.
     */
    psSPI_Handler->SPIxTWIDTH = (psSPI_Handler->SPIxTWIDTH & ~SPIxTWIDTH_TWIDTH_Mask);
    
    /**
     *  Configure SPI-Mode from user, 
     *   set CS to active low,
     *   set MISO active high,
     *   set MOSI active high.
     */
    psSPI_Handler->SPIxCON1 = ( (psSPI_Handler->SPIxCON1 & (~(SPI_MODE_Mask | SPIxCON1_SDIP_Mask | SPIxCON1_SDOP_Mask))) |
                                (((uint8_t)(psConfig->eSPI_Mode << SPI_MODE_Pos)) | (SPIxCON1_SSP_Mask)) );
    
    /**
     *  Configure SPI Clock Source from user.
     */
    psSPI_Handler->SPIxCLK = ( (psSPI_Handler->SPIxCLK & (~SPIxCLK_CLKSEL_Mask)) |
                                ((uint8_t)(psConfig->eSPI_CLKSEL << SPIxCLK_CLKSEL_Pos)) );
    
    /**
     *  Configure SPI Baudrate from user.
     */
    psSPI_Handler->SPIxBAUD = ( (psSPI_Handler->SPIxBAUD & SPIxBAUD_BAUD_Mask) |
                                 ((uint8_t)(psConfig->u8SPI_Baud << SPIxBAUD_BAUD_Pos)) );
    
    vSPI_ClearFIFOs(psSPI_Handler);
    vSPI_Enable(psSPI_Handler);
    
    return 0;
}

int8_t s8SPI_Master_TransmitData(sSPI_Handler_t* const psSPI_Handler, uint8_t const* const pu8Data, uint32_t u32DataLength)
{
    assert(psSPI_Handler);
    assert(pu8Data);
    
    vSPI_ClearFIFOs(psSPI_Handler);
    
    while(!(psSPI_Handler->SPIxSTATUS & SPIxSTATUS_TXBE_Mask));
    for(uint32_t i=0; i<u32DataLength; ++i)
    {
        psSPI_Handler->SPIxTXB = pu8Data[i];
        while(!(psSPI_Handler->SPIxSTATUS & SPIxSTATUS_TXBE_Mask));
    }
    
    while(!(psSPI_Handler->SPIxSTATUS & SPIxSTATUS_TXBE_Mask));
    while(psSPI_Handler->SPIxCON2 & SPIxCON2_BUSY_Mask);
    
    return 0;
}

int8_t s8SPI_Master_ReceiveData(sSPI_Handler_t* const psSPI_Handler, uint8_t* const pu8Data, uint32_t u32DataLength)
{
    assert(psSPI_Handler);
    assert(pu8Data);
    
    vSPI_ClearFIFOs(psSPI_Handler);
    
    for(uint32_t i=0; i<u32DataLength; ++i)
    {
        //while(!psSPI_Handler->SPIxSTATUS & SPIxSTATUS_TXBE_Mask);
        //psSPI_Handler->SPIxTXB = pu8Data[i];
    }
    
    //while(!psSPI_Handler->SPIxSTATUS & SPIxSTATUS_TXBE_Mask);
    //while(psSPI_Handler->SPIxCON2 & SPIxCON2_BUSY_Mask)
    return -1;
}

int8_t s8SPI_Master_TransmitReceiveData(sSPI_Handler_t* const psSPI_Handler, uint8_t const* const pu8TxData, uint8_t* const pu8RxData, uint32_t u32DataLength)
{
    assert(psSPI_Handler);
    assert(pu8TxData);
    assert(pu8RxData);
    
    vSPI_ClearFIFOs(psSPI_Handler);
    
    for(uint32_t i=0; i<u32DataLength; ++i)
    {
        psSPI_Handler->SPIxTXB = pu8TxData[i];
        while(!(psSPI_Handler->SPIxSTATUS & SPIxSTATUS_TXBE_Mask));
        pu8RxData[i] = psSPI_Handler->SPIxRXB;
    }
    
    while(!(psSPI_Handler->SPIxSTATUS & SPIxSTATUS_TXBE_Mask));
    while(psSPI_Handler->SPIxCON2 & SPIxCON2_BUSY_Mask);
    
    return 0;
}


/* private functions */

__inline static void vSPI_Enable(sSPI_Handler_t* const psSPI_Handler)
{
    psSPI_Handler->SPIxCON0 |= SPIxCON0_EN_Mask;
}

__inline static void vSPI_Disable(sSPI_Handler_t* const psSPI_Handler)
{
    psSPI_Handler->SPIxCON0 &= SPIxCON0_EN_Mask;
}

__inline static void vSPI_ClearFIFOs(sSPI_Handler_t* const psSPI_Handler)
{
    psSPI_Handler->SPIxSTATUS |= SPIxSTATUS_CLB_Mask;
}
