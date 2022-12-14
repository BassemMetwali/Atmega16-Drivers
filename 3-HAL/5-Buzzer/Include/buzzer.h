/*************************************************************************************************
 * [MODULE_NAME]:  BUZZER.h
 *
 * [DATE CREATED]: Oct 3, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Header File for Buzzer driver of AVR
 ************************************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define BUZZER_PORT                PORTC_ID
#define BUZZER_PIN                  PIN4_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function that initials the buzzer to be ready to work
 */
void BUZZER_init(void);


/*
 * Description :
 * Function that Fires the buzzer ON
 */
void BUZZER_on(void);


/*
 * Description :
 * Function that Turns the buzzer OFF
 */
void BUZZER_off(void);

#endif /* BUZZER_H_ */
