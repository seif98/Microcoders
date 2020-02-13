#include "std_types.h"
#include "Register Map.h"
#include "utils.h"
#include "GPIO_Priv.h"
#include "GPIO_Config.h"
#include "GPIO_Init.h"

//#define SYSCTRL_RCC_OSCSRC
//
//#define RCC_OSCSRC_MOSC 0
//#define RCC_OSCSRC_MOSC 1


void GPIO_voidInit()
{
    SETBIT(SYSCTRL_RCC,PWRDN);
    SETBIT(SYSCTRL_RCC,BYBASS);
    CLRBIT(SYSCTRL_RCC,USESYSDIV);

    u8 i = 0;
    while(i<3)
        i++;


    #if (GPIODEN_F == ENABLE)
        SETBIT(RCGCGPIO,5);
        #if(PORTF_BUS == APB)
            SETBIT(GPIODEN_FP,7);
            SETBIT(GPIODEN_FP,6);
            SETBIT(GPIODEN_FP,5);
            SETBIT(GPIODEN_FP,4);
            SETBIT(GPIODEN_FP,3);
            SETBIT(GPIODEN_FP,2);
            SETBIT(GPIODEN_FP,1);
            SETBIT(GPIODEN_FP,0);
        #elif(PORTF_BUS == AHB)
            SETBIT(GPIODEN_FH,7);
            SETBIT(GPIODEN_FH,6);
            SETBIT(GPIODEN_FH,5);
            SETBIT(GPIODEN_FH,4);
            SETBIT(GPIODEN_FH,3);
            SETBIT(GPIODEN_FH,2);
            SETBIT(GPIODEN_FH,1);
            SETBIT(GPIODEN_FH,0);
        #endif
    #else
        CLRBIT(RCGCGPIO,5);
        #if(PORTF_BUS == APB)
            CLRBIT(GPIODEN_FP,7);
            CLRBIT(GPIODEN_FP,6);
            CLRBIT(GPIODEN_FP,5);
            CLRBIT(GPIODEN_FP,4);
            CLRBIT(GPIODEN_FP,3);
            CLRBIT(GPIODEN_FP,2);
            CLRBIT(GPIODEN_FP,1);
            CLRBIT(GPIODEN_FP,0);
        #elif(PORTF_BUS == AHB)
            CLRBIT(GPIODEN_FH,7);
            CLRBIT(GPIODEN_FH,6);
            CLRBIT(GPIODEN_FH,5);
            CLRBIT(GPIODEN_FH,4);
            CLRBIT(GPIODEN_FH,3);
            CLRBIT(GPIODEN_FH,2);
            CLRBIT(GPIODEN_FH,1);
            CLRBIT(GPIODEN_FH,0);
        #endif
    #endif

    #if (GPIODEN_E == ENABLE)
        SETBIT(RCGCGPIO,4);
        #if(PORTE_BUS == APB)
            SETBIT(GPIODEN_EP,7);
            SETBIT(GPIODEN_EP,6);
            SETBIT(GPIODEN_EP,5);
            SETBIT(GPIODEN_EP,4);
            SETBIT(GPIODEN_EP,3);
            SETBIT(GPIODEN_EP,2);
            SETBIT(GPIODEN_EP,1);
            SETBIT(GPIODEN_EP,0);
        #elif(PORTE_BUS == AHB)
            SETBIT(GPIODEN_EH,7);
            SETBIT(GPIODEN_EH,6);
            SETBIT(GPIODEN_EH,5);
            SETBIT(GPIODEN_EH,4);
            SETBIT(GPIODEN_EH,3);
            SETBIT(GPIODEN_EH,2);
            SETBIT(GPIODEN_EH,1);
            SETBIT(GPIODEN_EH,0);
        #endif
        
    #else
        CLRBIT(RCGCGPIO,4);
        #if(PORTE_BUS == APB)
            CLRBIT(GPIODEN_EP,7);
            CLRBIT(GPIODEN_EP,6);
            CLRBIT(GPIODEN_EP,5);
            CLRBIT(GPIODEN_EP,4);
            CLRBIT(GPIODEN_EP,3);
            CLRBIT(GPIODEN_EP,2);
            CLRBIT(GPIODEN_EP,1);
            CLRBIT(GPIODEN_EP,0);
        #elif(PORTE_BUS == AHB)
            CLRBIT(GPIODEN_EH,7);
            CLRBIT(GPIODEN_EH,6);
            CLRBIT(GPIODEN_EH,5);
            CLRBIT(GPIODEN_EH,4);
            CLRBIT(GPIODEN_EH,3);
            CLRBIT(GPIODEN_EH,2);
            CLRBIT(GPIODEN_EH,1);
            CLRBIT(GPIODEN_EH,0);
        #endif
    #endif
    #if (GPIODEN_D == ENABLE)
        SETBIT(RCGCGPIO,3);
        #if(PORTD_BUS == APB)
            SETBIT(GPIODEN_DP,7);
            SETBIT(GPIODEN_DP,6);
            SETBIT(GPIODEN_DP,5);
            SETBIT(GPIODEN_DP,4);
            SETBIT(GPIODEN_DP,3);
            SETBIT(GPIODEN_DP,2);
            SETBIT(GPIODEN_DP,1);
            SETBIT(GPIODEN_DP,0);
        #elif(PORTD_BUS == AHB)
            SETBIT(GPIODEN_DH,7);
            SETBIT(GPIODEN_DH,6);
            SETBIT(GPIODEN_DH,5);
            SETBIT(GPIODEN_DH,4);
            SETBIT(GPIODEN_DH,3);
            SETBIT(GPIODEN_DH,2);
            SETBIT(GPIODEN_DH,1);
            SETBIT(GPIODEN_DH,0);
        #endif
    #else
        CLRBIT(RCGCGPIO,3);
        #if(PORTD_BUS == APB)
            CLRBIT(GPIODEN_DP,7);
            CLRBIT(GPIODEN_DP,6);
            CLRBIT(GPIODEN_DP,5);
            CLRBIT(GPIODEN_DP,4);
            CLRBIT(GPIODEN_DP,3);
            CLRBIT(GPIODEN_DP,2);
            CLRBIT(GPIODEN_DP,1);
            CLRBIT(GPIODEN_DP,0);
        #elif(PORTD_BUS == AHB)
            CLRBIT(GPIODEN_DH,7);
            CLRBIT(GPIODEN_DH,6);
            CLRBIT(GPIODEN_DH,5);
            CLRBIT(GPIODEN_DH,4);
            CLRBIT(GPIODEN_DH,3);
            CLRBIT(GPIODEN_DH,2);
            CLRBIT(GPIODEN_DH,1);
            CLRBIT(GPIODEN_DH,0);
        #endif
    #endif

    #if (GPIODEN_C == ENABLE)
        SETBIT(RCGCGPIO,2);
        #if(PORTF_BUS == APB)
            SETBIT(GPIODEN_CP,7);
            SETBIT(GPIODEN_CP,6);
            SETBIT(GPIODEN_CP,5);
            SETBIT(GPIODEN_CP,4);
            SETBIT(GPIODEN_CP,3);
            SETBIT(GPIODEN_CP,2);
            SETBIT(GPIODEN_CP,1);
            SETBIT(GPIODEN_CP,0);
        #elif(PORTF_BUS == AHB)
            SETBIT(GPIODEN_CH,7);
            SETBIT(GPIODEN_CH,6);
            SETBIT(GPIODEN_CH,5);
            SETBIT(GPIODEN_CH,4);
            SETBIT(GPIODEN_CH,3);
            SETBIT(GPIODEN_CH,2);
            SETBIT(GPIODEN_CH,1);
            SETBIT(GPIODEN_CH,0);
        #endif
    #else
        CLRBIT(RCGCGPIO,2);
        #if(PORTC_BUS == APB)
            CLRBIT(GPIODEN_CP,7);
            CLRBIT(GPIODEN_CP,6);
            CLRBIT(GPIODEN_CP,5);
            CLRBIT(GPIODEN_CP,4);
            CLRBIT(GPIODEN_CP,3);
            CLRBIT(GPIODEN_CP,2);
            CLRBIT(GPIODEN_CP,1);
            CLRBIT(GPIODEN_CP,0);
        #elif(PORTC_BUS == AHB)
            CLRBIT(GPIODEN_CH,7);
            CLRBIT(GPIODEN_CH,6);
            CLRBIT(GPIODEN_CH,5);
            CLRBIT(GPIODEN_CH,4);
            CLRBIT(GPIODEN_CH,3);
            CLRBIT(GPIODEN_CH,2);
            CLRBIT(GPIODEN_CH,1);
            CLRBIT(GPIODEN_CH,0);
        #endif
    #endif

    #if (GPIODEN_B == ENABLE)
        SETBIT(RCGCGPIO,1);
        #if(PORTB_BUS == APB)
            SETBIT(GPIODEN_BP,7);
            SETBIT(GPIODEN_BP,6);
            SETBIT(GPIODEN_BP,5);
            SETBIT(GPIODEN_BP,4);
            SETBIT(GPIODEN_BP,3);
            SETBIT(GPIODEN_BP,2);
            SETBIT(GPIODEN_BP,1);
            SETBIT(GPIODEN_BP,0);
        #elif(PORTB_BUS == AHB)
            SETBIT(GPIODEN_BH,7);
            SETBIT(GPIODEN_BH,6);
            SETBIT(GPIODEN_BH,5);
            SETBIT(GPIODEN_BH,4);
            SETBIT(GPIODEN_BH,3);
            SETBIT(GPIODEN_BH,2);
            SETBIT(GPIODEN_BH,1);
            SETBIT(GPIODEN_BH,0);
        #endif
    #else
        CLRBIT(RCGCGPIO,1);
        #if(PORTB_BUS == APB)
            CLRBIT(GPIODEN_BP,7);
            CLRBIT(GPIODEN_BP,6);
            CLRBIT(GPIODEN_BP,5);
            CLRBIT(GPIODEN_BP,4);
            CLRBIT(GPIODEN_BP,3);
            CLRBIT(GPIODEN_BP,2);
            CLRBIT(GPIODEN_BP,1);
            CLRBIT(GPIODEN_BP,0);
        #elif(PORTB_BUS == AHB)
            CLRBIT(GPIODEN_BH,7);
            CLRBIT(GPIODEN_BH,6);
            CLRBIT(GPIODEN_BH,5);
            CLRBIT(GPIODEN_BH,4);
            CLRBIT(GPIODEN_BH,3);
            CLRBIT(GPIODEN_BH,2);
            CLRBIT(GPIODEN_BH,1);
            CLRBIT(GPIODEN_BH,0);
        #endif
    #endif

    #if (GPIODEN_A == ENABLE)
        SETBIT(RCGCGPIO,0);
        #if(PORTA_BUS == APB)
            SETBIT(GPIODEN_AP,7);
            SETBIT(GPIODEN_AP,6);
            SETBIT(GPIODEN_AP,5);
            SETBIT(GPIODEN_AP,4);
            SETBIT(GPIODEN_AP,3);
            SETBIT(GPIODEN_AP,2);
            SETBIT(GPIODEN_AP,1);
            SETBIT(GPIODEN_AP,0);
        #elif(PORTA_BUS == AHB)
            SETBIT(GPIODEN_AH,7);
            SETBIT(GPIODEN_AH,6);
            SETBIT(GPIODEN_AH,5);
            SETBIT(GPIODEN_AH,4);
            SETBIT(GPIODEN_AH,3);
            SETBIT(GPIODEN_AH,2);
            SETBIT(GPIODEN_AH,1);
            SETBIT(GPIODEN_AH,0);
        #endif
    #else
        CLRBIT(RCGCGPIO,0);
        #if(PORTA_BUS == APB)
            CLRBIT(GPIODEN_AP,7);
            CLRBIT(GPIODEN_AP,6);
            CLRBIT(GPIODEN_AP,5);
            CLRBIT(GPIODEN_AP,4);
            CLRBIT(GPIODEN_AP,3);
            CLRBIT(GPIODEN_AP,2);
            CLRBIT(GPIODEN_AP,1);
            CLRBIT(GPIODEN_AP,0);
        #elif(PORTA_BUS == AHB)
            CLRBIT(GPIODEN_AH,7);
            CLRBIT(GPIODEN_AH,6);
            CLRBIT(GPIODEN_AH,5);
            CLRBIT(GPIODEN_AH,4);
            CLRBIT(GPIODEN_AH,3);
            CLRBIT(GPIODEN_AH,2);
            CLRBIT(GPIODEN_AH,1);
            CLRBIT(GPIODEN_AH,0);
        #endif
    #endif

    #if (PORTF_BUS == APB)
        CLRBIT(GPIOHBCTL,5);
    #else
        SETBIT(GPIOHBCTL,5);
    #endif

    #if (PORTE_BUS == APB)
        CLRBIT(GPIOHBCTL,4);
    #else
        SETBIT(GPIOHBCTL,4);
    #endif

    #if (PORTD_BUS == APB)
        CLRBIT(GPIOHBCTL,3);
    #else
        SETBIT(GPIOHBCTL,3);
    #endif

    #if (PORTC_BUS == APB)
        CLRBIT(GPIOHBCTL,2);
    #else
        SETBIT(GPIOHBCTL,2);
    #endif

    #if (PORTB_BUS == APB)
        CLRBIT(GPIOHBCTL,1);
    #else
        SETBIT(GPIOHBCTL,1);
    #endif

    #if (PORTA_BUS == APB)
        CLRBIT(GPIOHBCTL,0);
    #else
        SETBIT(GPIOHBCTL,0);
    #endif
    
    // SETBIT(RCGCGPIO, 5);
    // CLRBIT(GPIOHBCTL, 5);

    // CLRBIT(GPIOAFSEL_FP, 7);
    // CLRBIT(GPIOAFSEL_FP, 6);
    // CLRBIT(GPIOAFSEL_FP, 5);
    // CLRBIT(GPIOAFSEL_FP, 4);
    // CLRBIT(GPIOAFSEL_FP, 3);
    // CLRBIT(GPIOAFSEL_FP, 2);
    // CLRBIT(GPIOAFSEL_FP, 1);
    // CLRBIT(GPIOAFSEL_FP, 0);

    // CLRBIT(GPIOPCTL_FP, 7);
    // CLRBIT(GPIOPCTL_FP, 6);
    // CLRBIT(GPIOPCTL_FP, 5);
    // CLRBIT(GPIOPCTL_FP, 4);
    // CLRBIT(GPIOPCTL_FP, 3);
    // CLRBIT(GPIOPCTL_FP, 2);
    // CLRBIT(GPIOPCTL_FP, 1);
    // CLRBIT(GPIOPCTL_FP, 0);



    /** PORTF MAX CURRENT **/
    #if (GPIOF_MAXPIN0 == GPIO_2m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR2R_FP,0);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR2R_FH,0);
        #endif
    #elif (GPIOF_MAXPIN0 == GPIO_4m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR4R_FP,0);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR4R_FH,0);
        #endif
    #elif (GPIOF_MAXPIN0 == GPIO_8m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR8R_FP,0);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR8R_FH,0);
        #endif
    #endif

    #if (GPIOF_MAXPIN1 == GPIO_2m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR2R_FP,1);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR2R_FH,1);
        #endif
    #elif (GPIOF_MAXPIN1 == GPIO_4m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR4R_FP,1);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR4R_FH,1);
        #endif
    #elif (GPIOF_MAXPIN1 == GPIO_8m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR8R_FP,1);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR8R_FH,1);
        #endif
    #endif

    #if (GPIOF_MAXPIN2 == GPIO_2m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR2R_FP,2);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR2R_FH,2);
        #endif
    #elif (GPIOF_MAXPIN2 == GPIO_4m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR4R_FP,2);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR4R_FH,2);
        #endif
    #elif (GPIOF_MAXPIN2 == GPIO_8m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR8R_FP,2);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR8R_FH,2);
        #endif
    #endif

    #if (GPIOF_MAXPIN3 == GPIO_2m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR2R_FP,3);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR2R_FH,3);
        #endif
    #elif (GPIOF_MAXPIN3 == GPIO_4m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR4R_FP,3);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR4R_FH,3);
        #endif
    #elif (GPIOF_MAXPIN3 == GPIO_8m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR8R_FP,3);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR8R_FH,3);
        #endif
    #endif

    #if (GPIOF_MAXPIN4 == GPIO_2m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR2R_FP,4);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR2R_FH,4);
        #endif
    #elif (GPIOF_MAXPIN4 == GPIO_4m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR4R_FP,4);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR4R_FH,4);
        #endif
    #elif (GPIOF_MAXPIN4 == GPIO_8m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR8R_FP,4);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR8R_FH,4);
        #endif
    #endif

    #if (GPIOF_MAXPIN5 == GPIO_2m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR2R_FP,5);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR2R_FH,5);
        #endif
    #elif (GPIOF_MAXPIN5 == GPIO_4m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR4R_FP,5);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR4R_FH,5);
        #endif
    #elif (GPIOF_MAXPIN5 == GPIO_8m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR8R_FP,5);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR8R_FH,5);
        #endif
    #endif

    #if (GPIOF_MAXPIN6 == GPIO_2m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR2R_FP,6);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR2R_FH,6);
        #endif
    #elif (GPIOF_MAXPIN6 == GPIO_4m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR4R_FP,6);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR4R_FH,6);
        #endif
    #elif (GPIOF_MAXPIN6 == GPIO_8m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR8R_FP,6);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR8R_FH,6);
        #endif
    #endif

    #if (GPIOF_MAXPIN7 == GPIO_2m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR2R_FP,7);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR2R_FH,7);
        #endif
    #elif (GPIOF_MAXPIN7 == GPIO_4m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR4R_FP,7);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR4R_FH,7);
        #endif
    #elif (GPIOF_MAXPIN7 == GPIO_8m)
        #if (PORTF_BUS == APB)
            SETBIT(GPIODR8R_FP,7);
        #elif (PORTF_BUS == AHB)
            SETBIT(GPIODR8R_FH,7);
        #endif
    #endif

    /*********************************************/

    /** PORTE MAX CURRENT **/
    #if (GPIOE_MAXPIN0 == GPIO_2m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR2R_EP,0);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR2R_EH,0);
        #endif
    #elif (GPIOE_MAXPIN0 == GPIO_4m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR4R_EP,0);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR4R_EH,0);
        #endif
    #elif (GPIOE_MAXPIN0 == GPIO_8m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR8R_EP,0);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR8R_EH,0);
        #endif
    #endif

    #if (GPIOE_MAXPIN1 == GPIO_2m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR2R_EP,1);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR2R_EH,1);
        #endif
    #elif (GPIOE_MAXPIN1 == GPIO_4m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR4R_EP,1);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR4R_EH,1);
        #endif
    #elif (GPIOE_MAXPIN1 == GPIO_8m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR8R_EP,1);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR8R_EH,1);
        #endif
    #endif

    #if (GPIOE_MAXPIN2 == GPIO_2m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR2R_EP,2);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR2R_EH,2);
        #endif
    #elif (GPIOE_MAXPIN2 == GPIO_4m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR4R_EP,2);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR4R_EH,2);
        #endif
    #elif (GPIOE_MAXPIN2 == GPIO_8m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR8R_EP,2);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR8R_EH,2);
        #endif
    #endif

    #if (GPIOE_MAXPIN3 == GPIO_2m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR2R_EP,3);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR2R_EH,3);
        #endif
    #elif (GPIOE_MAXPIN3 == GPIO_4m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR4R_EP,3);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR4R_EH,3);
        #endif
    #elif (GPIOE_MAXPIN3 == GPIO_8m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR8R_EP,3);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR8R_EH,3);
        #endif
    #endif

    #if (GPIOE_MAXPIN4 == GPIO_2m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR2R_EP,4);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR2R_EH,4);
        #endif
    #elif (GPIOE_MAXPIN4 == GPIO_4m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR4R_EP,4);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR4R_EH,4);
        #endif
    #elif (GPIOE_MAXPIN4 == GPIO_8m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR8R_EP,4);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR8R_EH,4);
        #endif
    #endif

    #if (GPIOE_MAXPIN5 == GPIO_2m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR2R_EP,5);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR2R_EH,5);
        #endif
    #elif (GPIOE_MAXPIN5 == GPIO_4m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR4R_EP,5);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR4R_EH,5);
        #endif
    #elif (GPIOE_MAXPIN5 == GPIO_8m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR8R_EP,5);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR8R_EH,5);
        #endif
    #endif

    #if (GPIOE_MAXPIN6 == GPIO_2m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR2R_EP,6);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR2R_EH,6);
        #endif
    #elif (GPIOE_MAXPIN6 == GPIO_4m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR4R_EP,6);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR4R_EH,6);
        #endif
    #elif (GPIOE_MAXPIN6 == GPIO_8m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR8R_EP,6);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR8R_EH,6);
        #endif
    #endif

    #if (GPIOE_MAXPIN7 == GPIO_2m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR2R_EP,7);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR2R_EH,7);
        #endif
    #elif (GPIOE_MAXPIN7 == GPIO_4m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR4R_EP,7);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR4R_EH,7);
        #endif
    #elif (GPIOE_MAXPIN7 == GPIO_8m)
        #if (PORTE_BUS == APB)
            SETBIT(GPIODR8R_EP,7);
        #elif (PORTE_BUS == AHB)
            SETBIT(GPIODR8R_EH,7);
        #endif
    #endif

    /*********************************************/

    /** PORTD MAX CURRENT **/
    #if (GPIOD_MAXPIN0 == GPIO_2m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR2R_DP,0);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR2R_DH,0);
        #endif
    #elif (GPIOD_MAXPIN0 == GPIO_4m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR4R_DP,0);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR4R_DH,0);
        #endif
    #elif (GPIOD_MAXPIN0 == GPIO_8m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR8R_DP,0);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR8R_DH,0);
        #endif
    #endif

    #if (GPIOD_MAXPIN1 == GPIO_2m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR2R_DP,1);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR2R_DH,1);
        #endif
    #elif (GPIOD_MAXPIN1 == GPIO_4m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR4R_DP,1);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR4R_DH,1);
        #endif
    #elif (GPIOD_MAXPIN1 == GPIO_8m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR8R_DP,1);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR8R_DH,1);
        #endif
    #endif

    #if (GPIOD_MAXPIN2 == GPIO_2m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR2R_DP,2);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR2R_DH,2);
        #endif
    #elif (GPIOD_MAXPIN2 == GPIO_4m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR4R_DP,2);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR4R_DH,2);
        #endif
    #elif (GPIOD_MAXPIN2 == GPIO_8m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR8R_DP,2);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR8R_DH,2);
        #endif
    #endif

    #if (GPIOD_MAXPIN3 == GPIO_2m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR2R_DP,3);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR2R_DH,3);
        #endif
    #elif (GPIOD_MAXPIN3 == GPIO_4m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR4R_DP,3);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR4R_DH,3);
        #endif
    #elif (GPIOD_MAXPIN3 == GPIO_8m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR8R_DP,3);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR8R_DH,3);
        #endif
    #endif

    #if (GPIOD_MAXPIN4 == GPIO_2m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR2R_DP,4);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR2R_DH,4);
        #endif
    #elif (GPIOD_MAXPIN4 == GPIO_4m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR4R_DP,4);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR4R_DH,4);
        #endif
    #elif (GPIOD_MAXPIN4 == GPIO_8m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR8R_DP,4);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR8R_DH,4);
        #endif
    #endif

    #if (GPIOD_MAXPIN5 == GPIO_2m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR2R_DP,5);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR2R_DH,5);
        #endif
    #elif (GPIOD_MAXPIN5 == GPIO_4m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR4R_DP,5);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR4R_DH,5);
        #endif
    #elif (GPIOD_MAXPIN5 == GPIO_8m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR8R_DP,5);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR8R_DH,5);
        #endif
    #endif

    #if (GPIOD_MAXPIN6 == GPIO_2m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR2R_DP,6);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR2R_DH,6);
        #endif
    #elif (GPIOD_MAXPIN6 == GPIO_4m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR4R_DP,6);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR4R_DH,6);
        #endif
    #elif (GPIOD_MAXPIN6 == GPIO_8m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR8R_DP,6);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR8R_DH,6);
        #endif
    #endif

    #if (GPIOD_MAXPIN7 == GPIO_2m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR2R_DP,7);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR2R_DH,7);
        #endif
    #elif (GPIOD_MAXPIN7 == GPIO_4m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR4R_DP,7);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR4R_DH,7);
        #endif
    #elif (GPIOD_MAXPIN7 == GPIO_8m)
        #if (PORTD_BUS == APB)
            SETBIT(GPIODR8R_DP,7);
        #elif (PORTD_BUS == AHB)
            SETBIT(GPIODR8R_DH,7);
        #endif
    #endif

    /*********************************************/

    /** PORTC MAX CURRENT **/
    #if (GPIOC_MAXPIN0 == GPIO_2m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR2R_CP,0);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR2R_CH,0);
        #endif
    #elif (GPIOC_MAXPIN0 == GPIO_4m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR4R_CP,0);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR4R_CH,0);
        #endif
    #elif (GPIOC_MAXPIN0 == GPIO_8m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR8R_CP,0);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR8R_CH,0);
        #endif
    #endif

    #if (GPIOC_MAXPIN1 == GPIO_2m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR2R_CP,1);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR2R_CH,1);
        #endif
    #elif (GPIOC_MAXPIN1 == GPIO_4m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR4R_CP,1);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR4R_CH,1);
        #endif
    #elif (GPIOC_MAXPIN1 == GPIO_8m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR8R_CP,1);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR8R_CH,1);
        #endif
    #endif

    #if (GPIOC_MAXPIN2 == GPIO_2m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR2R_CP,2);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR2R_CH,2);
            #endif
    #elif (GPIOC_MAXPIN2 == GPIO_4m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR4R_CP,2);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR4R_CH,2);
            #endif
    #elif (GPIOC_MAXPIN2 == GPIO_8m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR8R_CP,2);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR8R_CH,2);
            #endif
    #endif

    #if (GPIOC_MAXPIN3 == GPIO_2m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR2R_CP,3);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR2R_CH,3);
        #endif
    #elif (GPIOC_MAXPIN3 == GPIO_4m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR4R_CP,3);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR4R_CH,3);
        #endif
    #elif (GPIOC_MAXPIN3 == GPIO_8m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR8R_CP,3);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR8R_CH,3);
        #endif
    #endif

    #if (GPIOC_MAXPIN4 == GPIO_2m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR2R_CP,4);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR2R_CH,4);
        #endif
    #elif (GPIOC_MAXPIN4 == GPIO_4m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR4R_CP,4);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR4R_CH,4);
        #endif
    #elif (GPIOC_MAXPIN4 == GPIO_8m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR8R_CP,4);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR8R_CH,4);
        #endif
    #endif

    #if (GPIOC_MAXPIN5 == GPIO_2m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR2R_CP,5);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR2R_CH,5);
        #endif
    #elif (GPIOC_MAXPIN5 == GPIO_4m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR4R_CP,5);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR4R_CH,5);
        #endif
    #elif (GPIOC_MAXPIN5 == GPIO_8m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR8R_CP,5);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR8R_CH,5);
        #endif
    #endif

    #if (GPIOC_MAXPIN6 == GPIO_2m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR2R_CP,6);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR2R_CH,6);
        #endif
    #elif (GPIOC_MAXPIN6 == GPIO_4m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR4R_CP,6);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR4R_CH,6);
        #endif
    #elif (GPIOC_MAXPIN6 == GPIO_8m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR8R_CP,6);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR8R_CH,6);
        #endif
    #endif

    #if (GPIOC_MAXPIN7 == GPIO_2m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR2R_CP,7);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR2R_CH,7);
        #endif
    #elif (GPIOC_MAXPIN7 == GPIO_4m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR4R_CP,7);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR4R_CH,7);
        #endif
    #elif (GPIOC_MAXPIN7 == GPIO_8m)
        #if (PORTC_BUS == APB)
            SETBIT(GPIODR8R_CP,7);
        #elif (PORTC_BUS == AHB)
            SETBIT(GPIODR8R_CH,7);
        #endif
    #endif

    /*********************************************/

    /** PORTB MAX CURRENT **/
    #if (GPIOB_MAXPIN0 == GPIO_2m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR2R_BP,0);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR2R_BH,0);
        #endif
    #elif (GPIOB_MAXPIN0 == GPIO_4m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR4R_BP,0);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR4R_BH,0);
        #endif
    #elif (GPIOB_MAXPIN0 == GPIO_8m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR8R_BP,0);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR8R_BH,0);
        #endif
    #endif

    #if (GPIOB_MAXPIN1 == GPIO_2m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR2R_BP,1);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR2R_BH,1);
        #endif
    #elif (GPIOB_MAXPIN1 == GPIO_4m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR4R_BP,1);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR4R_BH,1);
        #endif
    #elif (GPIOB_MAXPIN1 == GPIO_8m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR8R_BP,1);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR8R_BH,1);
        #endif
    #endif

    #if (GPIOB_MAXPIN2 == GPIO_2m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR2R_BP,2);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR2R_BH,2);
        #endif
    #elif (GPIOB_MAXPIN2 == GPIO_4m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR4R_BP,2);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR4R_BH,2);
        #endif
    #elif (GPIOB_MAXPIN2 == GPIO_8m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR8R_BP,2);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR8R_BH,2);
        #endif
    #endif

    #if (GPIOB_MAXPIN3 == GPIO_2m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR2R_BP,3);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR2R_BH,3);
        #endif
    #elif (GPIOB_MAXPIN3 == GPIO_4m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR4R_BP,3);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR4R_BH,3);
        #endif
    #elif (GPIOB_MAXPIN3 == GPIO_8m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR8R_BP,3);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR8R_BH,3);
        #endif
    #endif

    #if (GPIOB_MAXPIN4 == GPIO_2m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR2R_BP,4);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR2R_BH,4);
        #endif
    #elif (GPIOB_MAXPIN4 == GPIO_4m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR4R_BP,4);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR4R_BH,4);
        #endif
    #elif (GPIOB_MAXPIN4 == GPIO_8m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR8R_BP,4);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR8R_BH,4);
        #endif
    #endif

    #if (GPIOB_MAXPIN5 == GPIO_2m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR2R_BP,5);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR2R_BH,5);
        #endif
    #elif (GPIOB_MAXPIN5 == GPIO_4m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR4R_BP,5);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR4R_BH,5);
        #endif
    #elif (GPIOB_MAXPIN5 == GPIO_8m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR8R_BP,5);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR8R_BH,5);
        #endif
    #endif

    #if (GPIOB_MAXPIN6 == GPIO_2m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR2R_BP,6);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR2R_BH,6);
        #endif
    #elif (GPIOB_MAXPIN6 == GPIO_4m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR4R_BP,6);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR4R_BH,6);
        #endif
    #elif (GPIOB_MAXPIN6 == GPIO_8m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR8R_BP,6);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR8R_BH,6);
        #endif
    #endif

    #if (GPIOB_MAXPIN7 == GPIO_2m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR2R_BP,7);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR2R_BH,7);
        #endif
    #elif (GPIOB_MAXPIN7 == GPIO_4m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR4R_BP,7);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR4R_BH,7);
        #endif
    #elif (GPIOB_MAXPIN7 == GPIO_8m)
        #if (PORTB_BUS == APB)
            SETBIT(GPIODR8R_BP,7);
        #elif (PORTB_BUS == AHB)
            SETBIT(GPIODR8R_BH,7);
        #endif
    #endif

    /*********************************************/

    /** PORTA MAX CURRENT **/
    #if (GPIOA_MAXPIN0 == GPIO_2m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR2R_AP,0);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR2R_AH,0);
        #endif
    #elif (GPIOA_MAXPIN0 == GPIO_4m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR4R_AP,0);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR4R_AH,0);
        #endif
    #elif (GPIOA_MAXPIN0 == GPIO_8m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR8R_AP,0);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR8R_AH,0);
        #endif
    #endif

    #if (GPIOA_MAXPIN1 == GPIO_2m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR2R_AP,1);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR2R_AH,1);
        #endif
    #elif (GPIOA_MAXPIN1 == GPIO_4m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR4R_AP,1);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR4R_AH,1);
        #endif
    #elif (GPIOA_MAXPIN1 == GPIO_8m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR8R_AP,1);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR8R_AH,1);
        #endif
    #endif

    #if (GPIOA_MAXPIN2 == GPIO_2m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR2R_AP,2);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR2R_AH,2);
        #endif
    #elif (GPIOA_MAXPIN2 == GPIO_4m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR4R_AP,2);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR4R_AH,2);
        #endif
    #elif (GPIOA_MAXPIN2 == GPIO_8m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR8R_AP,2);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR8R_AH,2);
        #endif
    #endif

    #if (GPIOA_MAXPIN3 == GPIO_2m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR2R_AP,3);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR2R_AH,3);
        #endif
    #elif (GPIOA_MAXPIN3 == GPIO_4m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR4R_AP,3);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR4R_AH,3);
        #endif
    #elif (GPIOA_MAXPIN3 == GPIO_8m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR8R_AP,3);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR8R_AH,3);
        #endif
    #endif

    #if (GPIOA_MAXPIN4 == GPIO_2m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR2R_AP,4);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR2R_AH,4);
        #endif
    #elif (GPIOA_MAXPIN4 == GPIO_4m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR4R_AP,4);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR4R_AH,4);
        #endif
    #elif (GPIOA_MAXPIN4 == GPIO_8m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR8R_AP,4);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR8R_AH,4);
        #endif
    #endif

    #if (GPIOA_MAXPIN5 == GPIO_2m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR2R_AP,5);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR2R_AH,5);
        #endif
    #elif (GPIOA_MAXPIN5 == GPIO_4m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR4R_AP,5);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR4R_AH,5);
        #endif
    #elif (GPIOA_MAXPIN5 == GPIO_8m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR8R_AP,5);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR8R_AH,5);
        #endif
    #endif

    #if (GPIOA_MAXPIN6 == GPIO_2m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR2R_AP,6);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR2R_AH,6);
        #endif
    #elif (GPIOA_MAXPIN6 == GPIO_4m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR4R_AP,6);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR4R_AH,6);
        #endif
    #elif (GPIOA_MAXPIN6 == GPIO_8m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR8R_AP,6);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR8R_AH,6);
        #endif
    #endif

    #if (GPIOA_MAXPIN7 == GPIO_2m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR2R_AP,7);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR2R_AH,7);
        #endif
    #elif (GPIOA_MAXPIN7 == GPIO_4m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR4R_AP,7);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR4R_AH,7);
        #endif
    #elif (GPIOA_MAXPIN7 == GPIO_8m)
        #if (PORTA_BUS == APB)
            SETBIT(GPIODR8R_AP,7);
        #elif (PORTA_BUS == AHB)
            SETBIT(GPIODR8R_AH,7);
        #endif
    #endif

    /*********************************************/


    // SETBIT(GPIODR8R_FP,1);
    // SETBIT(GPIODR8R_FP,2);
    // SETBIT(GPIODR8R_FP,3);

    // SETBIT(GPIOPUR_FP, 7);
    // SETBIT(GPIOPUR_FP, 6);
    // SETBIT(GPIOPUR_FP, 5);
    // SETBIT(GPIOPUR_FP, 4);
    // SETBIT(GPIOPUR_FP, 3);
    // SETBIT(GPIOPUR_FP, 2);
    // SETBIT(GPIOPUR_FP, 1);
    // SETBIT(GPIOPUR_FP, 0);

    // SETBIT(GPIODEN_FP, 7);
    // SETBIT(GPIODEN_FP, 6);
    // SETBIT(GPIODEN_FP, 5);
    // SETBIT(GPIODEN_FP, 4);
    // SETBIT(GPIODEN_FP, 3);
    // SETBIT(GPIODEN_FP, 2);
    // SETBIT(GPIODEN_FP, 1);
    // SETBIT(GPIODEN_FP, 0);


}

void GPIO_voidSetPINDir(u8 GPIO_PORT,u8 GPIO_PIN,u8 PINDIR)
{
    if(GPIO_PORT == PORTA)
    {
        if(PORTA_BUS == APB)
        {
            if(PINDIR == IN)
            {
                CLRBIT(GPIODIR_AP, GPIO_PIN);
            }
            else
            {
                SETBIT(GPIODIR_AP, GPIO_PIN);
            }
        }

        else
        {
            if(PINDIR == IN)
            {
                CLRBIT(GPIODIR_AH, GPIO_PIN);
            }
            else
            {
                SETBIT(GPIODIR_AH, GPIO_PIN);
            }
        }
    }
        
    else if(GPIO_PORT == PORTB)
    {
        if(PORTB_BUS == APB)
        {
            if(PINDIR == IN)
                CLRBIT(GPIODIR_BP, GPIO_PIN);
            else
                SETBIT(GPIODIR_BP, GPIO_PIN);
        }

        else
        {
            if(PINDIR == IN)
                CLRBIT(GPIODIR_BH, GPIO_PIN);
            else
                SETBIT(GPIODIR_BH, GPIO_PIN);
        }
    }

    else if(GPIO_PORT == PORTC)
    {
        if(PORTC_BUS == APB)
        {
            if(PINDIR == IN)
                CLRBIT(GPIODIR_CP, GPIO_PIN);
            else
                SETBIT(GPIODIR_CP, GPIO_PIN);
        }

        else
        {
            if(PINDIR == IN)
                CLRBIT(GPIODIR_CH, GPIO_PIN);
            else
                SETBIT(GPIODIR_CH, GPIO_PIN);
        }
    }

    else if(GPIO_PORT == PORTD)
    {
        if(PORTD_BUS == APB)
        {
            if(PINDIR == IN)
                CLRBIT(GPIODIR_DP, GPIO_PIN);
            else
                SETBIT(GPIODIR_DP, GPIO_PIN);
        }

        else
        {
            if(PINDIR == IN)
                CLRBIT(GPIODIR_DH, GPIO_PIN);
            else
                SETBIT(GPIODIR_DH, GPIO_PIN);
        }
    }

    else if(GPIO_PORT == PORTE)
    {
        if(PORTE_BUS == APB)
        {
            if(PINDIR == IN)
                CLRBIT(GPIODIR_EP, GPIO_PIN);
            else
                SETBIT(GPIODIR_EP, GPIO_PIN);
        }

        else
        {
            if(PINDIR == IN)
                CLRBIT(GPIODIR_EH, GPIO_PIN);
            else
                SETBIT(GPIODIR_EH, GPIO_PIN);
        }
    }

    else if(GPIO_PORT == PORTF)
    {
        if(PORTF_BUS == APB)
        {
            if(PINDIR == IN)
                CLRBIT(GPIODIR_FP, GPIO_PIN);
            else
                SETBIT(GPIODIR_FP, GPIO_PIN);
        }

        else
        {
            if(PINDIR == IN)
                CLRBIT(GPIODIR_FH, GPIO_PIN);
            else
                SETBIT(GPIODIR_FH, GPIO_PIN);
        }
    }
}

void GPIO_voidSetPortDir(u8 GPIO_PORT,u8 Value)
{
    if (GPIO_PORT == PORTA)
    {
        if(PORTA_BUS == APB)
        {
            if(((Value >> 0) & 1) == 1)
                SETBIT(GPIODIR_AP, 0);
            else
                CLRBIT(GPIODIR_AP, 0);
            
            if(((Value >> 1) & 1) == 1)
                SETBIT(GPIODIR_AP, 1);
            else
                CLRBIT(GPIODIR_AP, 1);

            if(((Value >> 2) & 1) == 1)
                SETBIT(GPIODIR_AP, 2);
            else
                CLRBIT(GPIODIR_AP, 2);

            if(((Value >> 3) & 1) == 1)
                SETBIT(GPIODIR_AP, 3);
            else
                CLRBIT(GPIODIR_AP, 3);

            if(((Value >> 4) & 1) == 1)
                SETBIT(GPIODIR_AP, 4);
            else
                CLRBIT(GPIODIR_AP, 4);
            if(((Value >> 5) & 1) == 1)
                SETBIT(GPIODIR_AP, 5);
            else
                CLRBIT(GPIODIR_AP, 5);

            if(((Value >> 6) & 1) == 1)
                SETBIT(GPIODIR_AP, 6);
            else
                CLRBIT(GPIODIR_AP, 6);

            if(((Value >> 7) & 1) == 1)
                SETBIT(GPIODIR_AP, 7);
            else
                CLRBIT(GPIODIR_AP, 7);
        }

        else if(PORTA_BUS == AHB)
            if(((Value >> 0) & 1) == 1)
                SETBIT(GPIODIR_AP, 0);
            else
                CLRBIT(GPIODIR_AP, 0);
            
            if(((Value >> 1) & 1) == 1)
                SETBIT(GPIODIR_AP, 1);
            else
                CLRBIT(GPIODIR_AP, 1);

            if(((Value >> 2) & 1) == 1)
                SETBIT(GPIODIR_AP, 2);
            else
                CLRBIT(GPIODIR_AP, 2);

            if(((Value >> 3) & 1) == 1)
                SETBIT(GPIODIR_AP, 3);
            else
                CLRBIT(GPIODIR_AP, 3);

            if(((Value >> 4) & 1) == 1)
                SETBIT(GPIODIR_AP, 4);
            else
                CLRBIT(GPIODIR_AP, 4);
            if(((Value >> 5) & 1) == 1)
                SETBIT(GPIODIR_AP, 5);
            else
                CLRBIT(GPIODIR_AP, 5);

            if(((Value >> 6) & 1) == 1)
                SETBIT(GPIODIR_AP, 6);
            else
                CLRBIT(GPIODIR_AP, 6);

            if(((Value >> 7) & 1) == 1)
                SETBIT(GPIODIR_AP, 7);
            else
                CLRBIT(GPIODIR_AP, 7); 
    }

    else if (GPIO_PORT == PORTB)
    {
        if(PORTB_BUS == APB)
        {
            if(((Value >> 0) & 1) == 1)
                SETBIT(GPIODIR_BP, 0);
            else
                CLRBIT(GPIODIR_BP, 0);
            
            if(((Value >> 1) & 1) == 1)
                SETBIT(GPIODIR_BP, 1);
            else
                CLRBIT(GPIODIR_BP, 1);

            if(((Value >> 2) & 1) == 1)
                SETBIT(GPIODIR_BP, 2);
            else
                CLRBIT(GPIODIR_BP, 2);

            if(((Value >> 3) & 1) == 1)
                SETBIT(GPIODIR_BP, 3);
            else
                CLRBIT(GPIODIR_BP, 3);

            if(((Value >> 4) & 1) == 1)
                SETBIT(GPIODIR_BP, 4);
            else
                CLRBIT(GPIODIR_BP, 4);
            if(((Value >> 5) & 1) == 1)
                SETBIT(GPIODIR_BP, 5);
            else
                CLRBIT(GPIODIR_BP, 5);

            if(((Value >> 6) & 1) == 1)
                SETBIT(GPIODIR_BP, 6);
            else
                CLRBIT(GPIODIR_BP, 6);

            if(((Value >> 7) & 1) == 1)
                SETBIT(GPIODIR_BP, 7);
            else
                CLRBIT(GPIODIR_BP, 7);
        }

        else if(PORTB_BUS == AHB)
            if(((Value >> 0) & 1) == 1)
                SETBIT(GPIODIR_BP, 0);
            else
                CLRBIT(GPIODIR_BP, 0);
            
            if(((Value >> 1) & 1) == 1)
                SETBIT(GPIODIR_BP, 1);
            else
                CLRBIT(GPIODIR_BP, 1);

            if(((Value >> 2) & 1) == 1)
                SETBIT(GPIODIR_BP, 2);
            else
                CLRBIT(GPIODIR_BP, 2);

            if(((Value >> 3) & 1) == 1)
                SETBIT(GPIODIR_BP, 3);
            else
                CLRBIT(GPIODIR_BP, 3);

            if(((Value >> 4) & 1) == 1)
                SETBIT(GPIODIR_BP, 4);
            else
                CLRBIT(GPIODIR_BP, 4);
            if(((Value >> 5) & 1) == 1)
                SETBIT(GPIODIR_BP, 5);
            else
                CLRBIT(GPIODIR_BP, 5);

            if(((Value >> 6) & 1) == 1)
                SETBIT(GPIODIR_BP, 6);
            else
                CLRBIT(GPIODIR_BP, 6);

            if(((Value >> 7) & 1) == 1)
                SETBIT(GPIODIR_BP, 7);
            else
                CLRBIT(GPIODIR_BP, 7); 
    }

    else if (GPIO_PORT == PORTC)
    {
        if(PORTC_BUS == APB)
        {
            if(((Value >> 0) & 1) == 1)
                SETBIT(GPIODIR_CP, 0);
            else
                CLRBIT(GPIODIR_CP, 0);
            
            if(((Value >> 1) & 1) == 1)
                SETBIT(GPIODIR_CP, 1);
            else
                CLRBIT(GPIODIR_CP, 1);

            if(((Value >> 2) & 1) == 1)
                SETBIT(GPIODIR_CP, 2);
            else
                CLRBIT(GPIODIR_CP, 2);

            if(((Value >> 3) & 1) == 1)
                SETBIT(GPIODIR_CP, 3);
            else
                CLRBIT(GPIODIR_CP, 3);

            if(((Value >> 4) & 1) == 1)
                SETBIT(GPIODIR_CP, 4);
            else
                CLRBIT(GPIODIR_CP, 4);
            if(((Value >> 5) & 1) == 1)
                SETBIT(GPIODIR_CP, 5);
            else
                CLRBIT(GPIODIR_CP, 5);

            if(((Value >> 6) & 1) == 1)
                SETBIT(GPIODIR_CP, 6);
            else
                CLRBIT(GPIODIR_CP, 6);

            if(((Value >> 7) & 1) == 1)
                SETBIT(GPIODIR_CP, 7);
            else
                CLRBIT(GPIODIR_CP, 7);
        }

        else if(PORTC_BUS == AHB)
            if(((Value >> 0) & 1) == 1)
                SETBIT(GPIODIR_CP, 0);
            else
                CLRBIT(GPIODIR_CP, 0);
            
            if(((Value >> 1) & 1) == 1)
                SETBIT(GPIODIR_CP, 1);
            else
                CLRBIT(GPIODIR_CP, 1);

            if(((Value >> 2) & 1) == 1)
                SETBIT(GPIODIR_CP, 2);
            else
                CLRBIT(GPIODIR_CP, 2);

            if(((Value >> 3) & 1) == 1)
                SETBIT(GPIODIR_CP, 3);
            else
                CLRBIT(GPIODIR_CP, 3);

            if(((Value >> 4) & 1) == 1)
                SETBIT(GPIODIR_CP, 4);
            else
                CLRBIT(GPIODIR_CP, 4);
            if(((Value >> 5) & 1) == 1)
                SETBIT(GPIODIR_CP, 5);
            else
                CLRBIT(GPIODIR_CP, 5);

            if(((Value >> 6) & 1) == 1)
                SETBIT(GPIODIR_CP, 6);
            else
                CLRBIT(GPIODIR_CP, 6);

            if(((Value >> 7) & 1) == 1)
                SETBIT(GPIODIR_CP, 7);
            else
                CLRBIT(GPIODIR_CP, 7); 
    }

    else if (GPIO_PORT == PORTD)
    {
        if(PORTD_BUS == APB)
        {
            if(((Value >> 0) & 1) == 1)
                SETBIT(GPIODIR_DP, 0);
            else
                CLRBIT(GPIODIR_DP, 0);
            
            if(((Value >> 1) & 1) == 1)
                SETBIT(GPIODIR_DP, 1);
            else
                CLRBIT(GPIODIR_DP, 1);

            if(((Value >> 2) & 1) == 1)
                SETBIT(GPIODIR_DP, 2);
            else
                CLRBIT(GPIODIR_DP, 2);

            if(((Value >> 3) & 1) == 1)
                SETBIT(GPIODIR_DP, 3);
            else
                CLRBIT(GPIODIR_DP, 3);

            if(((Value >> 4) & 1) == 1)
                SETBIT(GPIODIR_DP, 4);
            else
                CLRBIT(GPIODIR_DP, 4);
            if(((Value >> 5) & 1) == 1)
                SETBIT(GPIODIR_DP, 5);
            else
                CLRBIT(GPIODIR_DP, 5);

            if(((Value >> 6) & 1) == 1)
                SETBIT(GPIODIR_DP, 6);
            else
                CLRBIT(GPIODIR_DP, 6);

            if(((Value >> 7) & 1) == 1)
                SETBIT(GPIODIR_DP, 7);
            else
                CLRBIT(GPIODIR_DP, 7);
        }

        else if(PORTD_BUS == AHB)
            if(((Value >> 0) & 1) == 1)
                SETBIT(GPIODIR_DP, 0);
            else
                CLRBIT(GPIODIR_DP, 0);
            
            if(((Value >> 1) & 1) == 1)
                SETBIT(GPIODIR_DP, 1);
            else
                CLRBIT(GPIODIR_DP, 1);

            if(((Value >> 2) & 1) == 1)
                SETBIT(GPIODIR_DP, 2);
            else
                CLRBIT(GPIODIR_DP, 2);

            if(((Value >> 3) & 1) == 1)
                SETBIT(GPIODIR_DP, 3);
            else
                CLRBIT(GPIODIR_DP, 3);

            if(((Value >> 4) & 1) == 1)
                SETBIT(GPIODIR_DP, 4);
            else
                CLRBIT(GPIODIR_DP, 4);
            if(((Value >> 5) & 1) == 1)
                SETBIT(GPIODIR_DP, 5);
            else
                CLRBIT(GPIODIR_DP, 5);

            if(((Value >> 6) & 1) == 1)
                SETBIT(GPIODIR_DP, 6);
            else
                CLRBIT(GPIODIR_DP, 6);

            if(((Value >> 7) & 1) == 1)
                SETBIT(GPIODIR_DP, 7);
            else
                CLRBIT(GPIODIR_DP, 7); 
    }

    else if (GPIO_PORT == PORTE)
    {
        if(PORTE_BUS == APB)
        {
            if(((Value >> 0) & 1) == 1)
                SETBIT(GPIODIR_EP, 0);
            else
                CLRBIT(GPIODIR_EP, 0);
            
            if(((Value >> 1) & 1) == 1)
                SETBIT(GPIODIR_EP, 1);
            else
                CLRBIT(GPIODIR_EP, 1);

            if(((Value >> 2) & 1) == 1)
                SETBIT(GPIODIR_EP, 2);
            else
                CLRBIT(GPIODIR_EP, 2);

            if(((Value >> 3) & 1) == 1)
                SETBIT(GPIODIR_EP, 3);
            else
                CLRBIT(GPIODIR_EP, 3);

            if(((Value >> 4) & 1) == 1)
                SETBIT(GPIODIR_EP, 4);
            else
                CLRBIT(GPIODIR_EP, 4);
            if(((Value >> 5) & 1) == 1)
                SETBIT(GPIODIR_EP, 5);
            else
                CLRBIT(GPIODIR_EP, 5);

            if(((Value >> 6) & 1) == 1)
                SETBIT(GPIODIR_EP, 6);
            else
                CLRBIT(GPIODIR_EP, 6);

            if(((Value >> 7) & 1) == 1)
                SETBIT(GPIODIR_EP, 7);
            else
                CLRBIT(GPIODIR_EP, 7);
        }

        else if(PORTE_BUS == AHB)
            if(((Value >> 0) & 1) == 1)
                SETBIT(GPIODIR_EP, 0);
            else
                CLRBIT(GPIODIR_EP, 0);
            
            if(((Value >> 1) & 1) == 1)
                SETBIT(GPIODIR_EP, 1);
            else
                CLRBIT(GPIODIR_EP, 1);

            if(((Value >> 2) & 1) == 1)
                SETBIT(GPIODIR_EP, 2);
            else
                CLRBIT(GPIODIR_EP, 2);

            if(((Value >> 3) & 1) == 1)
                SETBIT(GPIODIR_EP, 3);
            else
                CLRBIT(GPIODIR_EP, 3);

            if(((Value >> 4) & 1) == 1)
                SETBIT(GPIODIR_EP, 4);
            else
                CLRBIT(GPIODIR_EP, 4);
            if(((Value >> 5) & 1) == 1)
                SETBIT(GPIODIR_EP, 5);
            else
                CLRBIT(GPIODIR_EP, 5);

            if(((Value >> 6) & 1) == 1)
                SETBIT(GPIODIR_EP, 6);
            else
                CLRBIT(GPIODIR_EP, 6);

            if(((Value >> 7) & 1) == 1)
                SETBIT(GPIODIR_EP, 7);
            else
                CLRBIT(GPIODIR_EP, 7); 
    }

    else if (GPIO_PORT == PORTF)
    {
        if(PORTF_BUS == APB)
        {
            if(((Value >> 0) & 1) == 1)
                SETBIT(GPIODIR_FP, 0);
            else
                CLRBIT(GPIODIR_FP, 0);
            
            if(((Value >> 1) & 1) == 1)
                SETBIT(GPIODIR_FP, 1);
            else
                CLRBIT(GPIODIR_FP, 1);

            if(((Value >> 2) & 1) == 1)
                SETBIT(GPIODIR_FP, 2);
            else
                CLRBIT(GPIODIR_FP, 2);

            if(((Value >> 3) & 1) == 1)
                SETBIT(GPIODIR_FP, 3);
            else
                CLRBIT(GPIODIR_FP, 3);

            if(((Value >> 4) & 1) == 1)
                SETBIT(GPIODIR_FP, 4);
            else
                CLRBIT(GPIODIR_FP, 4);
            if(((Value >> 5) & 1) == 1)
                SETBIT(GPIODIR_FP, 5);
            else
                CLRBIT(GPIODIR_FP, 5);

            if(((Value >> 6) & 1) == 1)
                SETBIT(GPIODIR_FP, 6);
            else
                CLRBIT(GPIODIR_FP, 6);

            if(((Value >> 7) & 1) == 1)
                SETBIT(GPIODIR_FP, 7);
            else
                CLRBIT(GPIODIR_FP, 7);
        }

        else if(PORTF_BUS == AHB)
            if(((Value >> 0) & 1) == 1)
                SETBIT(GPIODIR_FP, 0);
            else
                CLRBIT(GPIODIR_FP, 0);
            
            if(((Value >> 1) & 1) == 1)
                SETBIT(GPIODIR_FP, 1);
            else
                CLRBIT(GPIODIR_FP, 1);

            if(((Value >> 2) & 1) == 1)
                SETBIT(GPIODIR_FP, 2);
            else
                CLRBIT(GPIODIR_FP, 2);

            if(((Value >> 3) & 1) == 1)
                SETBIT(GPIODIR_FP, 3);
            else
                CLRBIT(GPIODIR_FP, 3);

            if(((Value >> 4) & 1) == 1)
                SETBIT(GPIODIR_FP, 4);
            else
                CLRBIT(GPIODIR_FP, 4);
            if(((Value >> 5) & 1) == 1)
                SETBIT(GPIODIR_FP, 5);
            else
                CLRBIT(GPIODIR_FP, 5);

            if(((Value >> 6) & 1) == 1)
                SETBIT(GPIODIR_FP, 6);
            else
                CLRBIT(GPIODIR_FP, 6);

            if(((Value >> 7) & 1) == 1)
                SETBIT(GPIODIR_FP, 7);
            else
                CLRBIT(GPIODIR_FP, 7); 
    }
}

void GPIO_voidSetAFunc(u8 GPIO_PIN, u8 TYPE)
{
    if(GPIO_PIN < 8)
    {
       if(PORTA_BUS == APB)
       {
           if(TYPE == GPIO)
                CLRBIT(GPIOAFSEL_AP,GPIO_PIN);
       }
       else if(PORTA_BUS == AHB)
       {
           if(TYPE == GPIO)
                CLRBIT(GPIOAFSEL_AH,GPIO_PIN);
       }
    }
    else if(GPIO_PIN < 16)
    {
        GPIO_PIN -= 8;
       if(PORTB_BUS == APB)
       {
           if(TYPE == GPIO)
                CLRBIT(GPIOAFSEL_BP,GPIO_PIN);
       }
       else if(PORTB_BUS == AHB)
       {
           if(TYPE == GPIO)
                CLRBIT(GPIOAFSEL_BH,GPIO_PIN);
       }
    }
    else if(GPIO_PIN < 24)
    {
        GPIO_PIN -= 16;
       if(PORTC_BUS == APB)
       {
           if(TYPE == GPIO)
                CLRBIT(GPIOAFSEL_CP,GPIO_PIN);
       }
       else if(PORTC_BUS == AHB)
       {
           if(TYPE == GPIO)
                CLRBIT(GPIOAFSEL_CH,GPIO_PIN);
       }
    }
    else if(GPIO_PIN < 32)
    {
        GPIO_PIN -=24;
       if(PORTD_BUS == APB)
       {
           if(TYPE == GPIO)
                CLRBIT(GPIOAFSEL_DP,GPIO_PIN);
       }
       else if(PORTD_BUS == AHB)
       {
           if(TYPE == GPIO)
                SETBIT(GPIOAFSEL_DH,GPIO_PIN);
       }
    }
    else if(GPIO_PIN < 40)
    {
        GPIO_PIN -=32;
       if(PORTE_BUS == APB)
       {
           if(TYPE == GPIO)
                SETBIT(GPIOAFSEL_EP,GPIO_PIN);
       }
       else if(PORTE_BUS == AHB)
       {
           if(TYPE == GPIO)
                SETBIT(GPIOAFSEL_EH,GPIO_PIN);
       }
    }
    else if(GPIO_PIN < 48)
    {
        GPIO_PIN -= 40;
       if(PORTF_BUS == APB)
       {
           if(TYPE == GPIO)
                SETBIT(GPIOAFSEL_FP,GPIO_PIN);
       }
       else if(PORTF_BUS == AHB)
       {
           if(TYPE == GPIO)
                SETBIT(GPIOAFSEL_FH,GPIO_PIN);
       }
    }
}

void GPIO_voidSetPinState(u8 GPIO_PIN,u8 PINSTATE)
{
    if(GPIO_PIN < 8)
    {
        if(PORTA_BUS == APB)
        {
            if(PINSTATE == PUP)
                SETBIT(GPIOPUR_AP, GPIO_PIN);
            else if(PINSTATE == PDN)
                SETBIT(GPIOPDR_AP, GPIO_PIN);
            else
                SETBIT(GPIOODR_AP, GPIO_PIN);
        }
        else if(PORTA_BUS == AHB)
        {
            if(PINSTATE == PUP)
                SETBIT(GPIOPUR_AH, GPIO_PIN);
            else if(PINSTATE == PDN)
                SETBIT(GPIOPDR_AH, GPIO_PIN);
            else if(PINSTATE == ODR)
                SETBIT(GPIOODR_AH, GPIO_PIN);
        }
    }

    else if(GPIO_PIN < 16)
    {
        GPIO_PIN -= 8;
        if(PORTB_BUS == APB)
        {
            if(PINSTATE == PUP)
                SETBIT(GPIOPUR_BP, GPIO_PIN);
            else if(PINSTATE == PDN)
                SETBIT(GPIOPDR_BP, GPIO_PIN);
            else if(PINSTATE == ODR)
                SETBIT(GPIOODR_BP, GPIO_PIN);
        }
        else if(PORTB_BUS == AHB)
        {
            if(PINSTATE == PUP)
                SETBIT(GPIOPUR_BH, GPIO_PIN);
            else if(PINSTATE == PDN)
                SETBIT(GPIOPDR_BH, GPIO_PIN);
            else if(PINSTATE == ODR)
                SETBIT(GPIOODR_BH, GPIO_PIN);
        }
    }

    else if(GPIO_PIN < 24)
    {
        GPIO_PIN -= 16;
        if(PORTC_BUS == APB)
        {
            if(PINSTATE == PUP)
                SETBIT(GPIOPUR_CP, GPIO_PIN);
            else if(PINSTATE == PDN)
                SETBIT(GPIOPDR_CP, GPIO_PIN);
            else if(PINSTATE == ODR)
                SETBIT(GPIOODR_CP, GPIO_PIN);
        }
        else if(PORTC_BUS == AHB)
        {
            if(PINSTATE == PUP)
                SETBIT(GPIOPUR_CH, GPIO_PIN);
            else if(PINSTATE == PDN)
                SETBIT(GPIOPDR_CH, GPIO_PIN);
            else if(PINSTATE == ODR)
                SETBIT(GPIOODR_CH, GPIO_PIN);
        }
    }

    else if(GPIO_PIN < 32)
    {
        GPIO_PIN -= 24;
        if(PORTD_BUS == APB)
        {
            if(PINSTATE == PUP)
                SETBIT(GPIOPUR_DP, GPIO_PIN);
            else if(PINSTATE == PDN)
                SETBIT(GPIOPDR_DP, GPIO_PIN);
            else if(PINSTATE == ODR)
                SETBIT(GPIOODR_DP, GPIO_PIN);
        }
        else if(PORTD_BUS == AHB)
        {
            if(PINSTATE == PUP)
                SETBIT(GPIOPUR_DH, GPIO_PIN);
            else if(PINSTATE == PDN)
                SETBIT(GPIOPDR_DH, GPIO_PIN);
            else if(PINSTATE == ODR)
                SETBIT(GPIOODR_DH, GPIO_PIN);
        }
    }

    else if(GPIO_PIN < 40)
    {
        GPIO_PIN -= 32;
        if(PORTE_BUS == APB)
        {
            if(PINSTATE == PUP)
                SETBIT(GPIOPUR_EP, GPIO_PIN);
            else if(PINSTATE == PDN)
                SETBIT(GPIOPDR_EP, GPIO_PIN);
            else if(PINSTATE == ODR)
                SETBIT(GPIOODR_EP, GPIO_PIN);
        }
        else if(PORTE_BUS == AHB)
        {
            if(PINSTATE == PUP)
                SETBIT(GPIOPUR_EH, GPIO_PIN);
            else if(PINSTATE == PDN)
                SETBIT(GPIOPDR_EH, GPIO_PIN);
            else if(PINSTATE == ODR)
                SETBIT(GPIOODR_EH, GPIO_PIN);
        }
    }

    else if(GPIO_PIN < 48)
    {
        GPIO_PIN -= 40;
        if(PORTF_BUS == APB)
        {
            if(PINSTATE == PUP)
                SETBIT(GPIOPUR_FP, GPIO_PIN);
            else if(PINSTATE == PDN)
                SETBIT(GPIOPDR_FP, GPIO_PIN);
            else if(PINSTATE == ODR)
                SETBIT(GPIOODR_FP, GPIO_PIN);
        }
        else if(PORTF_BUS == AHB)
        {
            if(PINSTATE == PUP)
                SETBIT(GPIOPUR_FH, GPIO_PIN);
            else if(PINSTATE == PDN)
                SETBIT(GPIOPDR_FH, GPIO_PIN);
            else if(PINSTATE == ODR)
                SETBIT(GPIOODR_FH, GPIO_PIN);
        }
    }
}

// u8 GPIO_u8GetPIN(u8 GPIO_PIN)
// {
//     return GPIO_PIN;
// }

//void GPIO_voidSetPinCurMax(u8 GPIO_PORT, u8 Pin, u8 curr_max)

// void GPIO_voidSetPin(u32* GPIO_PIN,u8 Value)
// {
//     if(Value == GPIO_HIGH)
//     {
//         SETBIT(GPIO_PIN,2);
//         SETBIT(GPIO_PIN,3);
//         SETBIT(GPIO_PIN,4);
//         SETBIT(GPIO_PIN,5);
//         SETBIT(GPIO_PIN,6);
//         SETBIT(GPIO_PIN,7);
//         SETBIT(GPIO_PIN,8);
//         SETBIT(GPIO_PIN,9);
//     }
//     else
//     {
//         CLRBIT(GPIO_PIN,2);
//         CLRBIT(GPIO_PIN,3);
//         CLRBIT(GPIO_PIN,4);
//         CLRBIT(GPIO_PIN,5);
//         CLRBIT(GPIO_PIN,6);
//         CLRBIT(GPIO_PIN,7);
//         CLRBIT(GPIO_PIN,8);
//         CLRBIT(GPIO_PIN,9);
//     }
// }
