/*************************************************************************
 *  � 2012 Microchip Technology Inc.                                       
 *  
 *  Project Name:    mTouch Framework v2.3
 *  FileName:        mTouch_HardwareProfile_12F61x.h
 *  Dependencies:    mTouch.h
 *  Processor:       See documentation for supported PIC� microcontrollers 
 *  Compiler:        HI-TECH Ver. 9.81 or later
 *  IDE:             MPLAB� IDE v8.50 (or later) or MPLAB� X                        
 *  Hardware:         
 *  Company:         
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *  Description:     mTouch CVD Framework Hardware Profile Header File
 *                   - Provides information about correct SFR addresses,
 *                     pin assignments, module availability, and any other
 *                     part-specific data.
 *                   - See the documentation for more information.
 *************************************************************************/
 /**************************************************************************
 * MICROCHIP SOFTWARE NOTICE AND DISCLAIMER: You may use this software, and 
 * any derivatives created by any person or entity by or on your behalf, 
 * exclusively with Microchip's products in accordance with applicable
 * software license terms and conditions, a copy of which is provided for
 * your referencein accompanying documentation. Microchip and its licensors 
 * retain all ownership and intellectual property rights in the 
 * accompanying software and in all derivatives hereto. 
 * 
 * This software and any accompanying information is for suggestion only. 
 * It does not modify Microchip's standard warranty for its products. You 
 * agree that you are solely responsible for testing the software and 
 * determining its suitability. Microchip has no obligation to modify, 
 * test, certify, or support the software. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE, ITS INTERACTION WITH 
 * MICROCHIP'S PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY 
 * APPLICATION. 
 * 
 * IN NO EVENT, WILL MICROCHIP BE LIABLE, WHETHER IN CONTRACT, WARRANTY, 
 * TORT (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), STRICT 
 * LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, 
 * SPECIAL, PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, 
 * FOR COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, 
 * HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY 
 * OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT ALLOWABLE BY LAW, 
 * MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS 
 * SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID 
 * DIRECTLY TO MICROCHIP FOR THIS SOFTWARE. 
 * 
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF 
 * THESE TERMS. 
 *************************************************************************/
/** @file mTouch_HardwareProfile_12F61x.h
* @brief Support for: PIC12F615, PIC12HV615, PIC12F617
*/
/// @cond
#if !defined(__MTOUCH_HARDWARE_12F61X_H)
#define __MTOUCH_HARDWARE_12F61X_H

#if !defined(_12F615) && !defined(_12HV615)
#if !defined(_12F617) 
    #error The current mTouch hardware include file does not support this PIC microcontroller.
#endif
#endif

#if defined(_12F615) || defined(_12HV615)
    #if MTOUCH_NUMBER_SENSORS > 2
        #error The PIC12F/HV615 is not able to support more than 2 sensors on the mTouch Framework due to memory limitations.
    #endif
    #if MTOUCH_NUMBER_OF_SLEEP_SENSORS > 2
        #error The PIC12F/HV615 is not able to support more than 2 sleep-mode sensors on the mTouch Framework due to memory limitations.
    #endif
#endif
#if defined(_12F617)
    #if MTOUCH_NUMBER_SENSORS > 4
        #error The PIC12F617 is not able to support more than 4 sensors due to pinout limitations.
    #endif
    #if MTOUCH_NUMBER_OF_SLEEP_SENSORS > 4
        #error The PIC12F617 is not able to support more than 4 sleep-mode sensors due to pinout limitations.
    #endif
#endif

//===========================================================
//  Device Configuration
//===========================================================
#define MTOUCH_USE_GPIO

//===========================================================
//  Communications Configuration
//===========================================================
// NO UART AVAILABLE

#define PIC_TIMER0_AVAILABLE
#define PIC_TIMER1_AVAILABLE
#define PIC_TIMER2_AVAILABLE

//===========================================================
//  ADC Configuration
//===========================================================
#define PIC_ADC_BITS                10
#define PIC_ADC_UNIMP_AVAILABLE

#define PIC_ADC_ADCS                ANSELbits.ADCS
#define PIC_ADC_ADFM                ADCON0bits.ADFM
#define PIC_ADC_ADON                ADCON0bits.ADON

#define PIC_ADC_ADCS_FOSC2          0b000
#define PIC_ADC_ADCS_FOSC4          0b100
#define PIC_ADC_ADCS_FOSC8          0b001
#define PIC_ADC_ADCS_FOSC16         0b101
#define PIC_ADC_ADCS_FOSC32         0b010
#define PIC_ADC_ADCS_FOSC64         0b110
#define PIC_ADC_ADCS_FRC            0b111

#define PIC_ADC_ADFM_RIGHT          1
#define PIC_ADC_ADFM_LEFT           0

#if     _XTAL_FREQ == 8000000 
    #define PIC_ADC_SETCLK()    PIC_ADC_ADCS = PIC_ADC_ADCS_FOSC16
    #define PIC_ADC_TAD         2 
#elif   _XTAL_FREQ == 4000000 
    #define PIC_ADC_SETCLK()    PIC_ADC_ADCS = PIC_ADC_ADCS_FOSC8
    #define PIC_ADC_TAD         2 
#elif   _XTAL_FREQ == 1000000 
    #define PIC_ADC_SETCLK()    PIC_ADC_ADCS = PIC_ADC_ADCS_FOSC2
    #define PIC_ADC_TAD         2 
#else
    #error No predefined ADC clock values for the chosen _XTAL_FREQ.
#endif

//===========================================================
//  DAC Configuration
//===========================================================
#define PIC_VRCON_AVAILABLE

#define PIC_VRCON_BANK                  0
#define PIC_VRCON_MAX                   0x8F
#define PIC_VRCON_MIN                   0xA0
    

//===========================================================
//  Software-enabled Watchdog Timer Configuration
//===========================================================
// NOT AVAILABLE



//===========================================================
//  Analog Port Mapping
//  - Right Justification
//  - VDD/VSS Reference
//  - GO/DONE cleared
//  - ADON enabled
//===========================================================
#define MTOUCH_AD_AN0           0x81
#define MTOUCH_AD_AN1           0x85
#define MTOUCH_AD_AN2           0x89
#define MTOUCH_AD_AN3           0x8D

#define MTOUCH_AD_DAC_NOGO      0x91
#define MTOUCH_AD_DAC_AND_GO    0x93
#define MTOUCH_AD_ISO_AND_GO    0x9F
#define MTOUCH_AD_ISO_NOGO      0x9D

#define MTOUCH_PIN_AN0          0
#define MTOUCH_PIN_AN1          1
#define MTOUCH_PIN_AN2          2
#define MTOUCH_PIN_AN3          4



#endif
/// @endcond
