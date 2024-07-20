# 1 "SPI/SPI_Master.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "S:\\XC8C\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "SPI/SPI_Master.c" 2

# 1 "SPI/SPI_Master.h" 1
# 11 "SPI/SPI_Master.h"
# 1 "SPI/SPI_Internal.h" 1




# 1 "S:\\XC8C\\pic\\include\\c99\\stdint.h" 1 3



# 1 "S:\\XC8C\\pic\\include\\c99\\musl_xc8.h" 1 3
# 5 "S:\\XC8C\\pic\\include\\c99\\stdint.h" 2 3
# 26 "S:\\XC8C\\pic\\include\\c99\\stdint.h" 3
# 1 "S:\\XC8C\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 133 "S:\\XC8C\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned __int24 uintptr_t;
# 148 "S:\\XC8C\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __int24 intptr_t;
# 164 "S:\\XC8C\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 194 "S:\\XC8C\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 235 "S:\\XC8C\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 27 "S:\\XC8C\\pic\\include\\c99\\stdint.h" 2 3

typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 148 "S:\\XC8C\\pic\\include\\c99\\stdint.h" 3
# 1 "S:\\XC8C\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 149 "S:\\XC8C\\pic\\include\\c99\\stdint.h" 2 3
# 5 "SPI/SPI_Internal.h" 2




typedef struct
{
    volatile uint8_t SPIxRXB;
    volatile uint8_t SPIxTXB;
    volatile uint16_t SPIxTCNT;
    volatile uint8_t SPIxCON0;
    volatile uint8_t SPIxCON1;
    volatile uint8_t SPIxCON2;
    volatile uint8_t SPIxSTATUS;
    volatile uint8_t SPIxTWIDTH;
    volatile uint8_t SPIxBAUD;
    volatile uint8_t SPIxINTF;
    volatile uint8_t SPIxINTE;
    volatile uint8_t SPIxCLK;

} sSPI_Handler_t;
# 11 "SPI/SPI_Master.h" 2


typedef enum
{
    SPI_CLKSEL_SYSCLK = (0b0000 << (0U)),
    SPI_CLKSEL_HFINTOSC = (0b0001 << (0U)),
    SPI_CLKSEL_MFINTOSC = (0b0010 << (0U)),
    SPI_CLKSEL_EXTOSC = (0b0011 << (0U)),
    SPI_CLKSEL_ClockRefOutput = (0b0100 << (0U)),
    SPI_CLKSEL_TMR0_OUT = (0b0101 << (0U)),
    SPI_CLKSEL_TMR2_Postscaler_OUT = (0b0110 << (0U)),
    SPI_CLKSEL_TMR4_Postscaler_OUT = (0b0111 << (0U)),
    SPI_CLKSEL_SMT1_OUT = (0b1000 << (0U)),
    SPI_CLKSEL_CLC1_OUT = (0b1001 << (0U)),
    SPI_CLKSEL_CLC2_OUT = (0b1010 << (0U)),
    SPI_CLKSEL_CLC3_OUT = (0b1011 << (0U)),
    SPI_CLKSEL_CLC4_OUT = (0b1100 << (0U)),

} eSPI_CLKSEL_t;

typedef enum
{
    SPI_MODE_0 = 0,
    SPI_MODE_1 = 1,
    SPI_MODE_2 = 2,
    SPI_MODE_3 = 3,
} eSPI_Mode_t;

typedef struct
{
    eSPI_Mode_t eSPI_Mode;
    eSPI_CLKSEL_t eSPI_CLKSEL;
    uint8_t u8SPI_Baud;

    uint8_t bMSB_First;

} sSPI_Config;




int8_t s8SPI_Master_Init(sSPI_Handler_t* const psSPI_Handler, sSPI_Config const* const psConfig);

int8_t s8SPI_Master_TransmitData(sSPI_Handler_t* const psSPI_Handler, uint8_t const* const pu8Data, uint32_t u32DataLength);

int8_t s8SPI_Master_ReceiveData(sSPI_Handler_t* const psSPI_Handler, uint8_t* const pu8Data, uint32_t u32DataLength);

int8_t s8SPI_Master_TransmitReceiveData(sSPI_Handler_t* const psSPI_Handler, uint8_t const* const pu8TxData, uint8_t* const pu8RxData, uint32_t u32DataLength);
# 2 "SPI/SPI_Master.c" 2


# 1 "S:\\XC8C\\pic\\include\\c99\\assert.h" 1 3
# 12 "S:\\XC8C\\pic\\include\\c99\\assert.h" 3
# 1 "S:\\XC8C\\pic\\include\\c99\\bits/assert.h" 1 3
# 1 "S:\\XC8C\\pic\\include\\c99\\features.h" 1 3
# 2 "S:\\XC8C\\pic\\include\\c99\\bits/assert.h" 2 3
# 19 "S:\\XC8C\\pic\\include\\c99\\bits/assert.h" 3
          void __assert_fail (const char *, const char *, int, const char *);
# 13 "S:\\XC8C\\pic\\include\\c99\\assert.h" 2 3

#pragma intrinsic(__builtin_software_breakpoint)
extern void __builtin_software_breakpoint(void);
# 4 "SPI/SPI_Master.c" 2
# 14 "SPI/SPI_Master.c"
static void vSPI_Enable(sSPI_Handler_t* const psSPI_Handler);
static void vSPI_Disable(sSPI_Handler_t* const psSPI_Handler);
static void vSPI_ClearFIFOs(sSPI_Handler_t* const psSPI_Handler);



int8_t s8SPI_Master_Init(sSPI_Handler_t* const psSPI_Handler, sSPI_Config const* const psConfig)
{
    ((void)((psSPI_Handler) || (__assert_fail("psSPI_Handler", "SPI/SPI_Master.c", 22, __func__),0)));
    ((void)((psConfig) || (__assert_fail("psConfig", "SPI/SPI_Master.c", 23, __func__),0)));




    vSPI_Disable(psSPI_Handler);






    psSPI_Handler->SPIxCON0 = ( (psSPI_Handler->SPIxCON0 & (~((1U << (2U)) | (1U << (1U))))) |
                                (((1U << (1U))) | ((1U << (0U))) | !psConfig->bMSB_First) );




    psSPI_Handler->SPIxTWIDTH = (psSPI_Handler->SPIxTWIDTH & ~(7U << (0U)));







    psSPI_Handler->SPIxCON1 = ( (psSPI_Handler->SPIxCON1 & (~((((1U << (6U)) | (1U << (5U)))) | (1U << (1U)) | (1U << (0U))))) |
                                (((uint8_t)(psConfig->eSPI_Mode << ((5U)))) | ((1U << (2U)))) );




    psSPI_Handler->SPIxCLK = ( (psSPI_Handler->SPIxCLK & (~(0x0F << (0U)))) |
                                ((uint8_t)(psConfig->eSPI_CLKSEL << (0U))) );




    psSPI_Handler->SPIxBAUD = ( (psSPI_Handler->SPIxBAUD & (0xFF << (0U))) |
                                 ((uint8_t)(psConfig->u8SPI_Baud << (0U))) );

    vSPI_ClearFIFOs(psSPI_Handler);
    vSPI_Enable(psSPI_Handler);

    return 0;
}

int8_t s8SPI_Master_TransmitData(sSPI_Handler_t* const psSPI_Handler, uint8_t const* const pu8Data, uint32_t u32DataLength)
{
    ((void)((psSPI_Handler) || (__assert_fail("psSPI_Handler", "SPI/SPI_Master.c", 72, __func__),0)));
    ((void)((pu8Data) || (__assert_fail("pu8Data", "SPI/SPI_Master.c", 73, __func__),0)));

    vSPI_ClearFIFOs(psSPI_Handler);

    while(!(psSPI_Handler->SPIxSTATUS & (1U << (5U))));
    for(uint32_t i=0; i<u32DataLength; ++i)
    {
        psSPI_Handler->SPIxTXB = pu8Data[i];
        while(!(psSPI_Handler->SPIxSTATUS & (1U << (5U))));
    }

    while(!(psSPI_Handler->SPIxSTATUS & (1U << (5U))));
    while(psSPI_Handler->SPIxCON2 & (1U << (7U)));

    return 0;
}

int8_t s8SPI_Master_ReceiveData(sSPI_Handler_t* const psSPI_Handler, uint8_t* const pu8Data, uint32_t u32DataLength)
{
    ((void)((psSPI_Handler) || (__assert_fail("psSPI_Handler", "SPI/SPI_Master.c", 92, __func__),0)));
    ((void)((pu8Data) || (__assert_fail("pu8Data", "SPI/SPI_Master.c", 93, __func__),0)));

    vSPI_ClearFIFOs(psSPI_Handler);

    for(uint32_t i=0; i<u32DataLength; ++i)
    {


    }



    return -1;
}

int8_t s8SPI_Master_TransmitReceiveData(sSPI_Handler_t* const psSPI_Handler, uint8_t const* const pu8TxData, uint8_t* const pu8RxData, uint32_t u32DataLength)
{
    ((void)((psSPI_Handler) || (__assert_fail("psSPI_Handler", "SPI/SPI_Master.c", 110, __func__),0)));
    ((void)((pu8TxData) || (__assert_fail("pu8TxData", "SPI/SPI_Master.c", 111, __func__),0)));
    ((void)((pu8RxData) || (__assert_fail("pu8RxData", "SPI/SPI_Master.c", 112, __func__),0)));

    vSPI_ClearFIFOs(psSPI_Handler);

    for(uint32_t i=0; i<u32DataLength; ++i)
    {
        psSPI_Handler->SPIxTXB = pu8TxData[i];
        while(!(psSPI_Handler->SPIxSTATUS & (1U << (5U))));
        pu8RxData[i] = psSPI_Handler->SPIxRXB;
    }

    while(!(psSPI_Handler->SPIxSTATUS & (1U << (5U))));
    while(psSPI_Handler->SPIxCON2 & (1U << (7U)));

    return 0;
}




__inline static void vSPI_Enable(sSPI_Handler_t* const psSPI_Handler)
{
    psSPI_Handler->SPIxCON0 |= (1U << (7U));
}

__inline static void vSPI_Disable(sSPI_Handler_t* const psSPI_Handler)
{
    psSPI_Handler->SPIxCON0 &= (1U << (7U));
}

__inline static void vSPI_ClearFIFOs(sSPI_Handler_t* const psSPI_Handler)
{
    psSPI_Handler->SPIxSTATUS |= (1U << (2U));
}
