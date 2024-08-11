
#ifndef CR_SPI_INTERNAL_H
#define CR_SPI_INTERNAL_H

#include <stdint.h>



typedef struct
{
    volatile uint8_t  SPIxRXB;
    volatile uint8_t  SPIxTXB;
    volatile uint16_t SPIxTCNT;
    volatile uint8_t  SPIxCON0;
    volatile uint8_t  SPIxCON1;
    volatile uint8_t  SPIxCON2;
    volatile uint8_t  SPIxSTATUS;
    volatile uint8_t  SPIxTWIDTH;
    volatile uint8_t  SPIxBAUD;
    volatile uint8_t  SPIxINTF;
    volatile uint8_t  SPIxINTE;
    volatile uint8_t  SPIxCLK;
    
} sSPI_Handler_t;

#define SPI1_StartAddr          (0x00000080)
#define pSPI1                   ((sSPI_Handler_t* const) SPI1_StartAddr)

#define SPI2_StartAddr          (0x0000008D)
#define pSPI2                   ((sSPI_Handler_t* const) SPI2_StartAddr)

/* -------------------------------------------------------------------------- */
// SPIxRXB Register

#define SPIxRXB_RXB_Pos         (0U)
#define SPIxRXB_RXB_Mask        (0xFF << SPIxRXB_RXB_Pos)

/* -------------------------------------------------------------------------- */
// SPIxTXB Register

#define SPIxTXB_TXB_Pos         (0U)
#define SPIxTXB_TXB_Mask        (0xFF << SPIxTXB_TXB_Pos)

/* -------------------------------------------------------------------------- */
// SPIxTCNT Register

#define SPIxTCNT_TCNTH_Pos      (0U)
#define SPIxTCNT_TCNTH_Mask     (0x07FF << SPIxTCNT_TCNTH_Pos)

/* -------------------------------------------------------------------------- */
// SPIxCON0 Register

#define SPIxCON0_EN_Pos         (7U)
#define SPIxCON0_EN_Mask        (1U << SPIxCON0_EN_Pos)

#define SPIxCON0_LSBF_Pos       (2U)
#define SPIxCON0_LSBF_Mask      (1U << SPIxCON0_LSBF_Pos)

#define SPIxCON0_MST_Pos        (1U)
#define SPIxCON0_MST_Mask       (1U << SPIxCON0_MST_Pos)

#define SPIxCON0_BMODE_Pos      (0U)
#define SPIxCON0_BMODE_Mask     (1U << SPIxCON0_BMODE_Pos)

/* -------------------------------------------------------------------------- */
// SPIxCON1 Register

#define SPIxCON1_SMP_Pos        (7U)
#define SPIxCON1_SMP_Mask       (1U << SPIxCON1_SMP_Pos)

#define SPIxCON1_CKE_Pos        (6U)
#define SPIxCON1_CKE_Mask       (1U << SPIxCON1_CKE_Pos)

#define SPIxCON1_CKP_Pos        (5U)
#define SPIxCON1_CKP_Mask       (1U << SPIxCON1_CKP_Pos)

#define SPIxCON1_FST_Pos        (4U)
#define SPIxCON1_FST_Mask       (1U << SPIxCON1_FST_Pos)

#define SPIxCON1_SSP_Pos        (2U)
#define SPIxCON1_SSP_Mask       (1U << SPIxCON1_SSP_Pos)

#define SPIxCON1_SDIP_Pos       (1U)
#define SPIxCON1_SDIP_Mask      (1U << SPIxCON1_SDIP_Pos)

#define SPIxCON1_SDOP_Pos       (0U)
#define SPIxCON1_SDOP_Mask      (1U << SPIxCON1_SDOP_Pos)

/* -------------------------------------------------------------------------- */
// SPIxCON2 Register

#define SPIxCON2_BUSY_Pos       (7U)
#define SPIxCON2_BUSY_Mask      (1U << SPIxCON2_BUSY_Pos)

#define SPIxCON2_SSFLT_Pos      (6U)
#define SPIxCON2_SSFLT_Mask     (1U << SPIxCON2_SSFLT_Pos)

#define SPIxCON2_SSET_Pos       (2U)
#define SPIxCON2_SSET_Mask      (1U << SPIxCON2_SSET_Pos)

#define SPIxCON2_TXR_Pos        (1U)
#define SPIxCON2_TXR_Mask       (1U << SPIxCON2_TXR_Pos)

#define SPIxCON2_RXR_Pos        (0U)
#define SPIxCON2_RXR_Mask       (1U << SPIxCON2_RXR_Pos)

/* -------------------------------------------------------------------------- */
// SPIxSTATUS Register

#define SPIxSTATUS_TXWE_Pos     (7U)
#define SPIxSTATUS_TXWE_Mask    (1U << SPIxSTATUS_TXWE_Pos)

#define SPIxSTATUS_TXBE_Pos     (5U)
#define SPIxSTATUS_TXBE_Mask    (1U << SPIxSTATUS_TXBE_Pos)

#define SPIxSTATUS_RXRE_Pos     (3U)
#define SPIxSTATUS_RXRE_Mask    (1U << SPIxSTATUS_RXRE_Pos)

#define SPIxSTATUS_CLB_Pos      (2U)
#define SPIxSTATUS_CLB_Mask     (1U << SPIxSTATUS_CLB_Pos)

#define SPIxSTATUS_RXBF_Pos     (0U)
#define SPIxSTATUS_RXBF_Mask    (1U << SPIxSTATUS_RXBF_Pos)

/* -------------------------------------------------------------------------- */
// SPIxTWIDTH Register

#define SPIxTWIDTH_TWIDTH_Pos   (0U)
#define SPIxTWIDTH_TWIDTH_Mask  (7U << SPIxTWIDTH_TWIDTH_Pos)

/* -------------------------------------------------------------------------- */
// SPIxBAUD Register

#define SPIxBAUD_BAUD_Pos       (0U)
#define SPIxBAUD_BAUD_Mask      (0xFF << SPIxBAUD_BAUD_Pos)

/* -------------------------------------------------------------------------- */
// SPIxINTF Register

#define SPIxINTF_SRMTIF_Pos     (7U)
#define SPIxINTF_SRMTIF_Mask    (1U << SPIxINTF_SRMTIF_Pos)

#define SPIxINTF_TCZIF_Pos      (6U)
#define SPIxINTF_TCZIF_Mask     (1U << SPIxINTF_TCZIF_Pos)

#define SPIxINTF_SOSIF_Pos      (5U)
#define SPIxINTF_SOSIF_Mask     (1U << SPIxINTF_SOSIF_Pos)

#define SPIxINTF_EOSIF_Pos      (4U)
#define SPIxINTF_EOSIF_Mask     (1U << SPIxINTF_EOSIF_Pos)

#define SPIxINTF_RXOIF_Pos      (2U)
#define SPIxINTF_RXOIF_Mask     (1U << SPIxINTF_RXOIF_Pos)

#define SPIxINTF_TXUIF_Pos      (1U)
#define SPIxINTF_TXUIF_Mask     (1U << SPIxINTF_TXUIF_Pos)

/* -------------------------------------------------------------------------- */
// SPIxINTE Register

#define SPIxINTE_SRMTIE_Pos     (7U)
#define SPIxINTE_SRMTIE_Mask    (1U << SPIxINTE_SRMTIE_Pos)

#define SPIxINTE_TCZIE_Pos      (6U)
#define SPIxINTE_TCZIE_Mask     (1U << SPIxINTE_TCZIE_Pos)

#define SPIxINTE_SOSIE_Pos      (5U)
#define SPIxINTE_SOSIE_Mask     (1U << SPIxINTE_SOSIE_Pos)

#define SPIxINTE_EOSIE_Pos      (4U)
#define SPIxINTE_EOSIE_Mask     (1U << SPIxINTE_EOSIE_Pos)

#define SPIxINTE_RXOIE_Pos      (2U)
#define SPIxINTE_RXOIE_Mask     (1U << SPIxINTE_RXOIE_Pos)

#define SPIxINTE_TXUIE_Pos      (1U)
#define SPIxINTE_TXUIE_Mask     (1U << SPIxINTE_TXUIE_Pos)

/* -------------------------------------------------------------------------- */
// SPIxCLK Register

#define SPIxCLK_CLKSEL_Pos      (0U)
#define SPIxCLK_CLKSEL_Mask     (0x0F << SPIxCLK_CLKSEL_Pos)



#endif