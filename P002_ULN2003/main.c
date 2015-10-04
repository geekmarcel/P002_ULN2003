/*--------------------------------------------------------------------------------------------------------------------------------------------------------
 * Project: 		Post 2 ULN2003
 * Hardware:		Arduino UNO
 * Micro:			ATMEGA328P
 * IDE:			Atmel Studio 6.2
 *
 * Name:    		main.c
 * Purpose: 		ULN example, using IC ULN2003 and 2 relays
 * Date:			27-09-2015
 *
 * Hardware setup:	
 *				Pin 2 of PORTD connected to pin 1 of ULN, 
 *				Pin 3 of PORTS connected to pin 2 of ULN.
 *
 * Note(s):
 *--------------------------------------------------------------------------------------------------------------------------------------------------------*/

  
/************************************************************************/
/* Includes				                                                                  */
/************************************************************************/
#include <avr/io.h>
#include "util/delay.h"

/************************************************************************/
/* Defines				                                                                  */
/************************************************************************/
#define	BYTE	unsigned char
#define	BOOL	unsigned char


/***************************************************************************
*  Function:		Setup(int number)
*  Description:		Setup PORTD and the timer, this function need to be called at
*				the beginning of main.
*  Receives:		Nothing
*  Returns:		Nothing
***************************************************************************/
void Setup()
{
	/* Setup PORTD */
	/* Set pins 2 and 3 as output , and pins 0,1 and 4 to 7 as input*/
	/* We skip pin 0 and 1 because these pins are needed for programming the chip */
	DDRD = 0b00001100;
}

/***************************************************************************
*  Function:		Main(void)
*  Description:		Main function of the program.
*  Receives:		Nothing
*  Returns:		Optionally the exit code.
***************************************************************************/
int main(void)
{
	/* Variable initialization */
	unsigned char led = 1;
	
	/* Setup PORT D */
	Setup();
	
	/* Test the code toggling the relays */
	while(1)
	{
		PORTD = (PIND & 0xF3) | (led++ << 2);

		/* Start over if we at the end */
		if(led == 3)
			led = 1;
			
		/* Delay for 500 milliseconds */
		_delay_ms(500);
	}
}