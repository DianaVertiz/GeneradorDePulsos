/*
 * pulsadores.c
 *
 *  Created on: 22/11/2016
 *      Author: je_su
 */
#include "led.h"
#include "GPIO.h"
#include "pulsadores.h"


void inicializarPulsadores()
{
	Init_GPIO();
	GPIO_Set_Dir( GPIO0 , INPUT);
	GPIO_Set_Dir( GPIO1 , INPUT);
	GPIO_Set_Dir( GPIO2 , INPUT);
	GPIO_Set_Dir( GPIO3 , INPUT);
	GPIO_Set_Dir( GPIO4 , INPUT);
	GPIO_Set_Dir( GPIO6 , INPUT);


}

uint8_t pulsado(uint8_t pulsador) //se fija si se pulsó o no un GPIO
								  //Devuelve falso si se pulsó
{
	return GPIO_Read(pulsador);
}

uint8_t ReadPulsador() //devuele la tecla pulsada
{
	uint8_t key;

	if (!(GPIO_Read(GPIO0)))
	{
		key=5;
		TemporizadorTimer0(300);
		ResetTimer0();
	}

	if (!(GPIO_Read(GPIO1)))
	{
		key=2;
		TemporizadorTimer0(300);
		ResetTimer0();
	}

	if (!(GPIO_Read(GPIO2)))
	{
		key=1;

		TemporizadorTimer0(300);
		ResetTimer0();

	}

	if (!(GPIO_Read(GPIO3)))
	{
		key=3;
		TemporizadorTimer0(300);
		ResetTimer0();
	}

	if (!(GPIO_Read(GPIO4)))
	{
		key=4;
		TemporizadorTimer0(300);
		ResetTimer0();
	}

	return key;
}

void DetenerEstimulador()
{
	GPIO_Write(GPIO6, 1);
}

void ReanudarEstimulador()
{
	GPIO_Write(GPIO6, 0);
}


