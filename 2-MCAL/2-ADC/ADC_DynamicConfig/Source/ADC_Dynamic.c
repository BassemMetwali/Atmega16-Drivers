/*************************************************************************************************
 * [MODULE_NAME]:  ADC_Dynamic.c
 *
 * [DATE CREATED]: Oct 3, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Source file for the ADC driver
 ************************************************************************************************/

#include "ADC_Dynamic.h"
#include "avr/io.h" /* To use the ADC Registers */
#include "common_macros.h" /* To use the macros like SET_BIT */

volatile uint16 g_adc_result=0;

ISR(ADC_vect)
{
	g_adc_result=ADC;
}

void ADC_Init(const ADC_Configtype *Config_Ptr)
{
	ADMUX=( ( Config_Ptr -> Referance ) << 6);

	SET_BIT(ADCSRA,ADEN);

	ADCSRA|=( (Config_Ptr -> Mode) << ADIE);

	ADCSRA=(ADCSRA & 0xF8) | ( (Config_Ptr -> Presclar) & 0x07);
}
uint16 ADC_ReadChannel(const ADC_Configtype *Config_Ptr)
{
	ADMUX=(( Config_Ptr->Channel));

	SET_BIT(ADCSRA,ADSC);

	if((Config_Ptr -> Mode) == POLLING)
	{
		while(BIT_IS_CLEAR(ADCSRA,ADIF))
		{
			SET_BIT(ADCSRA ,ADIF);
		}
	}

	else
	{
	}

	return ADC;
}
