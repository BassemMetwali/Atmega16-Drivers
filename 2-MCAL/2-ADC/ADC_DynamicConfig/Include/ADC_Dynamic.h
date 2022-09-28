/*************************************************************************************************
 * [MODULE_NAME]:  ADC_Dyanmic.h
 *
 * [DATE CREATED]: Oct 3, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Header file for the ADC driver
 ************************************************************************************************/

#ifndef ADC_DYNAMIC_H_
#define ADC_DYNAMIC_H_


#include "std_types.h"


/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern volatile uint16 g_adc_result;
/*******************************************************************************
 *                        Types Declarations                                    *
 *******************************************************************************/

typedef enum {
	AREF,AVCC,Reserved,Internal
}ADC_Referace;

typedef enum {
	ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7
}ADC_Channel;

typedef enum {
	POLLING,INTERRUPT
}ADC_Mode;

typedef enum {
	NO_prescaler,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Presclar;

typedef struct {

	ADC_Referace Referance;
	ADC_Channel  Channel;
	ADC_Mode     Mode;
	ADC_Presclar Presclar;
}ADC_Configtype;


/*****************************************************************
 *                  Functions Prototype
 *****************************************************************/


/* Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_Init(const ADC_Configtype * Config_Ptr);

/* Description
 * Function is responsible for read analog data from certain  ADC channel
 * then convert it to digital using ADC driver .
 */
uint16 ADC_ReadChannel(const ADC_Configtype * Config_Ptr);

#endif /* ADC_DYNAMIC_H_ */
