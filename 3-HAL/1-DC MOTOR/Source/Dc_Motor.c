 /*************************************************************************************************
 * [MODULE_NAME]:  DC_MOTOR.c
 *
 * [DATE CREATED]: Oct 3, 2021
 *
 * [Author]:       Bassem Metwali
 *
 * [DESCRIPTION]:  Source File for DC motor driver of AVR
 ************************************************************************************************/

#include "Dc_Motor.h"
#include "gpio.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void DcMotor_Init(void)
{
	/* configure pin PB0 & PB1 and PB2 as output pins */
	GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_INPUT1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_INPUT2_PIN_ID, PIN_OUTPUT);

	/* Motor is stopped at the beginning */
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_INPUT1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_INPUT2_PIN_ID, LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state)
{

	/* check the state of the motor */
	if(state == CLOCKWISE)
	{
		/* Rotate the motor --> clock wise */
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_INPUT1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_INPUT2_PIN_ID, LOGIC_LOW);
	}
	else if(state == ANTI_CLOCKWISE)
	{
		/* Rotate the motor --> anti-clock wise */
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_INPUT1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_INPUT2_PIN_ID, LOGIC_HIGH);

	}

	else if(state == STOP)
	{
		/* Stop the motor */
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_INPUT1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_INPUT2_PIN_ID, LOGIC_LOW);
	}

}

