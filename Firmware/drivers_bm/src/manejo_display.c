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
#include "lcd_r.h"
#include "puertos_lcd_r.h"

#elif (mk60fx512vlq15 == CPU)
#else
#endif

LCD_DATA_Type data;

void MostrarPulsos(uint16_t N,uint16_t V,uint16_t Tup,uint16_t P,uint8_t flagVoI,uint8_t flagPoN)
{
	static char auxN[10];
	static char auxV[10];
	static char auxT[10];
	static char auxP[10];
	uint16_t Vaux;
	//uint16_t Iaux;

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

	lcd_gotoxy(6,1);

if(flagPoN==1)
{
	if(flagVoI==1)
	{
		printf_lcd("I:");
		Vaux=(V*31)/1000;
	}
	if(flagVoI==0)
	{
		printf_lcd("V:");
		Vaux=(V*62)/1000;
	}
}
if(flagPoN==0)
{

	if(flagVoI==1)
	{
		printf_lcd("I:");
		Vaux=(V*31)/1000;
	}
	if(flagVoI==0)
	{
		printf_lcd("V:");
		Vaux=(V*62)/1000;
	}
	printf_lcd("-");
}


	itoa(Vaux,auxV,10);
		char* strV=auxV;
		while(*strV != 0)
		{
			  lcd_putc(*strV);
			  strV++;
		}

		lcd_gotoxy(10,1);

	if(flagVoI==1)
	{
		printf_lcd("mA");
	}
	if(flagVoI==0)
	{
		printf_lcd("V");
	}


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
	lcd_gotoxy(8,2);
	printf_lcd("P:");

				itoa(P,auxP,10);
				char* strP=auxP;
				while(*strP != 0)
				{
					  lcd_putc(*strP);
					  strP++;
				}
	printf_lcd("ms");



}

void ActivarCursor()
{
	delay(); //. . . . . .*/ /* Asignar valores a los bits
	data.D1=0;
	data.D2=0;
	data.D3=0;
	data.D4=0;
	data.RS=0;
	enviar_lcd(data);
	delay();

	data.D1=1; //habilita parpadeo
	data.D2=1; //habilita cursor
	data.D3=1;
	data.D4=1;
	data.RS=0;
	enviar_lcd(data);
	delay();

}

void DesplazarCursorDerecha()
{

//desplazamiento del cursor a la derecha
		delay(); //. . . . . .*/ /* Asignar valores a los bits
		data.D1=1;
		data.D2=0;
		data.D3=0;
		data.D4=0;
		data.RS=0;
		enviar_lcd(data);
		delay();

		//data.D1=0; //
		//data.D2=1; //
		data.D3=1;
		data.D4=0;
		data.RS=0;
		enviar_lcd(data);
		delay();

}

void RetornoCasa()
{

	//Retorno a casa

	delay(); //. . . . . .*/ /* Asignar valores a los bits
			data.D1=0;
			data.D2=0;
			data.D3=0;
			data.D4=0;
			data.RS=0;
			enviar_lcd(data);
			delay();

			//data.D1=0; //
			data.D2=1; //
			data.D3=0;
			data.D4=0;
			data.RS=0;
			enviar_lcd(data);
			delay();
//----------------------------

}

void DesplazarDisplay()
{
	//desplazamiento de toda la pantalla a la derecha
			delay(); //. . . . . .*/ /* Asignar valores a los bits
			data.D1=1;
			data.D2=0;
			data.D3=0;
			data.D4=0;
			data.RS=0;
			enviar_lcd(data);
			delay();

			//data.D1=0; //
			//data.D2=1; //
			data.D3=1;
			data.D4=1;
			data.RS=0;
			enviar_lcd(data);
			delay();

}




