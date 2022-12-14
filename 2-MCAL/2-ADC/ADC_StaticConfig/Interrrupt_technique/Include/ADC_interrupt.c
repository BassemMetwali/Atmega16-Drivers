/*************************************************************************************************
 * [MODULE_NAME]:  ADC_interrupt.c
 *
 * [DATE CREATED]: Oct 3, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Source file for the ADC driver
 ************************************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc_interrupt.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/

volatile uint16 g_adcResult = 0;

/*******************************************************************************
 *                          ISR's Definitions                                  *
 *******************************************************************************/

ISR(ADC_vect)
{
	/* Read ADC Data after conversion complete */
	g_adcResult = ADC;
}


void ADC_interrupt_init(void)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 00 to choose to connect external reference voltage by input this voltage through AREF pin
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = 0;

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 1 Enable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 011 to choose ADC_Clock=F_CPU/8=1Mhz/8=125Khz --> ADC must operate in range 50-200Khz
	 */
	ADCSRA = (1<<ADEN) | (1<<ADIE) | (1<<ADPS1) | (1<<ADPS0);
}

void ADC_interrupt_readChannel(uint8 channel_num)
{

	ADMUX = (ADMUX & 0xE0) | (channel_num & 0x07); /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */

}


