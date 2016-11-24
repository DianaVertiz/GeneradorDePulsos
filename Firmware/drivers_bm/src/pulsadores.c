/*
 * pulsadores.c
 *
 *  Created on: 22/11/2016
 *      Author: je_su
 */
#include "led.h"
#include "GPIO.h"


void inicializarPulsadores()
{
	Init_GPIO();
	GPIO_Set_Dir( GPIO0 , INPUT);
	GPIO_Set_Dir( GPIO1 , INPUT);
	GPIO_Set_Dir( GPIO2 , INPUT);
	GPIO_Set_Dir( GPIO3 , INPUT);
	GPIO_Set_Dir( GPIO4 , INPUT);
}

uint8_t pulsado(uint8_t pulsador)
{
	return GPIO_Read(pulsador);
}

void probarPulsadores()
{
	if (!(GPIO_Read(GPIO0)))
	{EncenderLeds(LED0_R);}
	else {ApagarLeds(LED0_R);}

	if (!(GPIO_Read(GPIO1)))
	{EncenderLeds(LED0_R);}
	else {ApagarLeds(LED0_R);}

	if (!(GPIO_Read(GPIO2)))
	{EncenderLeds(LED0_R);}
	else {ApagarLeds(LED0_R);}

	if (!(GPIO_Read(GPIO3)))
	{EncenderLeds(LED0_R);}
	else {ApagarLeds(LED0_R);}

	if (!(GPIO_Read(GPIO4)))
	{EncenderLeds(LED0_R);}
	else {ApagarLeds(LED0_R);}
}



