 /*************************************************************************************************
 * [MODULE_NAME]:  BUZZER.c
 *
 * [DATE CREATED]: Oct 3, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Source File for Buzzer driver of AVR
 ************************************************************************************************/

#include "gpio.h"
#include "buzzer.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function the initiates the buzzer
 */
void BUZZER_init(void)
{
	GPIO_setupPinDirection( BUZZER_PORT ,BUZZER_PIN,PIN_OUTPUT);
}

/*
 * Description :
 * Fires the buzzer on
 */
void BUZZER_on(void)
{
	GPIO_writePin( BUZZER_PORT , BUZZER_PIN ,LOGIC_HIGH);
}

/*
 * Description :
 * Turns the buzzer off
 */
void BUZZER_off(void)
{
	GPIO_writePin( BUZZER_PORT , BUZZER_PIN , LOGIC_LOW);


}
