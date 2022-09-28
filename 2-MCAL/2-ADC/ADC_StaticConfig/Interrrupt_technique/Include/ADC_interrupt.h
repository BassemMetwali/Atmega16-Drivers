/*************************************************************************************************
 * [MODULE_NAME]:  ADC_interrupt.h
 *
 * [DATE CREATED]: Oct 3, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Header file for the ADC driver
 ************************************************************************************************/
#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern Public global variables to be used by other modules */
extern volatile uint16 g_adcResult;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_interrupt_init(void);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
void ADC_interrupt_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
