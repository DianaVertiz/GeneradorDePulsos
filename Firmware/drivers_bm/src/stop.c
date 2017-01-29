/*
 * stop.c
 *
 *  Created on: 10/12/2016
 *      Author: je_su
 */

#include "stop.h"


void InicializarStop()
{
	Chip_GPIO_Init(LPC_GPIO_PORT);
	Chip_SCU_PinMux(6,10,MD_PUP|MD_EZI|MD_ZI,FUNC0);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 3 ,1<<6,1);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 3,6); //por defecto está en bajo?? desactivado??
}

uint8_t ReadStop()
{
	//devuelve 0 si está en bajo o desactivado
	 if (Chip_GPIO_GetPinState(LPC_GPIO_PORT,3,6))
		 return 1;
	else
	     return 0;
}
void CambiarEstado()
{
	if(!(Chip_GPIO_GetPinState(LPC_GPIO_PORT,3,6)))
		{
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 3,6);
		}

	else if(Chip_GPIO_GetPinState(LPC_GPIO_PORT,3,6))
			{
				Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 3,6);
			}
}

void ActivarPin()
{
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 3,6);
}

void DesactivarPin()
{
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 3,6);
}
