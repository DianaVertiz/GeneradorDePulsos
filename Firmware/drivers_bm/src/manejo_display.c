/*
 * manejo_display.c
 *
 *  Created on: 17/10/2016
 *      Author: je_su
 */

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#include "core_cm4.h"
#include "manejo_display.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif

void MostrarPulsos(uint16_t N,uint16_t V,uint16_t Tup,uint16_t P)
{
	static char auxN[10];
	static char auxV[10];
	static char auxT[10];
	static char auxP[10];

	lcd_init_port();
	lcd_init();
	lcd_gotoxy(1,1);
	printf_lcd("N:");

	itoa(N,auxN,10);
	char* strN=auxN;
	while(*strN != 0)
	{
		  lcd_putc(*strN);
		  strN++;
	}

	printf_lcd(" V:");

	itoa(V,auxV,10);
		char* strV=auxV;
		while(*strV != 0)
		{
			  lcd_putc(*strV);
			  strV++;
		}
	printf_lcd("mV");


	lcd_gotoxy(1,2);
	printf_lcd("T:");

		itoa(Tup,auxT,10);
		char* strT=auxT;
		while(*strT != 0)
		{
			  lcd_putc(*strT);
			  strT++;
		}
	//printf_lcd("ms");
	printf_lcd(" P:");

				itoa(P,auxP,10);
				char* strP=auxP;
				while(*strP != 0)
				{
					  lcd_putc(*strP);
					  strP++;
				}
	printf_lcd("ms");



}



