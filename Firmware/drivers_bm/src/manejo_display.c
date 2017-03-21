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
#include "GPIO.h"

#elif (mk60fx512vlq15 == CPU)
#else
#endif

LCD_DATA_Type data;

void MostrarPulsos(uint16_t N,uint16_t V,uint16_t Tup,uint16_t P,uint8_t flagVoI,uint8_t flagPoN)
{
	ClearDisplay();

	uint16_t Vaux;

	lcd_gotoxy(1,1);
	printf_lcd("N:");

	lcd_putInt(N);

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


	lcd_putInt(Vaux);

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

	lcd_putInt(Tup);

	lcd_gotoxy(8,2);
	printf_lcd("P:");

	lcd_putInt(P);
	printf_lcd("ms");

	//RetornoCasa();

}


void MostrarNumPulsos(uint16_t N)
{
	lcd_gotoxy(1,1);
	printf_lcd("     ");
	lcd_gotoxy(1,1);
	printf_lcd("N:");

	lcd_putInt(N);
}
void MostrarAmplitud(uint16_t V,uint8_t flagVoI,uint8_t flagPoN)
{
	static char auxV[10];
	uint16_t Vaux;
	lcd_gotoxy(6,1);
	printf_lcd("           ");
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


		lcd_putInt(Vaux);



		if(flagVoI==1)
		{
			printf_lcd("mA");
		}
		if(flagVoI==0)
		{
			printf_lcd("V");
		}

}

void MostrarTUp(uint16_t Tup)
{
	static char auxT[10];
	lcd_gotoxy(1,2);
	printf_lcd("       ");
	lcd_gotoxy(1,2);
	printf_lcd("T:");

	lcd_putInt(Tup);
}
void MostrarPeriodo(uint16_t P)
{
	static char auxP[10];
	lcd_gotoxy(8,2);
	printf_lcd("         ");
	lcd_gotoxy(8,2);
	printf_lcd("P:");

	lcd_putInt(P);
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

void Cursor_sinBlink()
{
	delay(); //. . . . . .*/ /* Asignar valores a los bits
	data.D1=0;
	data.D2=0;
	data.D3=0;
	data.D4=0;
	data.RS=0;
	enviar_lcd(data);
	delay();

	data.D1=0; //deshabilita parpadeo
	data.D2=1; //habilita cursor
	data.D3=1;
	data.D4=1;
	data.RS=0;
	enviar_lcd(data);
	delay();

}

void DesactivarCursor()
{
	delay(); //. . . . . .*/ /* Asignar valores a los bits
	data.D1=0;
	data.D2=0;
	data.D3=0;
	data.D4=0;
	data.RS=0;
	enviar_lcd(data);
	delay();

	data.D1=0;
	data.D2=0;
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

void PosicionarCursor(uint8_t x, uint8_t y)
{
	//x columna
	//y fila
	lcd_gotoxy(x,y);
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

void DesplazarDisplayDerecha()
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

void DesplazarDisplayIzquierda()
{
	//desplazamiento de toda la pantalla a la Izquierda
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
			data.D3=0;
			data.D4=1;
			data.RS=0;
			enviar_lcd(data);
			delay();

}

void ClearDisplay()
{
		data.D1=0;
		data.D2=0;
		data.D3=0;
		data.D4=0;
		data.RS=0;
		enviar_lcd(data);
		delay();
		//. . . . . .*/ /* Asignar valores a los bits
		data.D1=1;
		data.D2=0;
		data.D3=0;
		data.D4=0;
		data.RS=0;
		enviar_lcd(data);
		delay();
}


//Función que sirve para escribir un entero en el display

void lcd_putInt(uint16_t i)
{
	static char N[10];
	itoa(i,N,10);
	char* aux=N;
	while(*aux!=0)
	{
		lcd_putc(*aux);
		aux++;
	}
}

void arrow()
{
	//PosicionarCursor(1,1);
	//high order
			data.D1=1;
			data.D2=1;
			data.D3=1;
			data.D4=0;
			data.RS=1;
			enviar_lcd(data);
			delay();
			//low order
			data.D1=0;
			data.D2=1;
			data.D3=1;
			data.D4=1;
			data.RS=1;
			enviar_lcd(data);

}

void arriba()
{
	PosicionarCursor(1,1);
				data.D1=1;
				data.D2=0;
				data.D3=1;
				data.D4=0;
				data.RS=1;
				enviar_lcd(data);
				delay();

				data.D1=0;
				data.D2=1;
				data.D3=1;
				data.D4=1;
				data.RS=1;
				enviar_lcd(data);
}

void MensajeScroll()
{

	uint8_t salir=0;
	uint8_t posicion=0;

	TemporizadorTimer0(300);
	ResetTimer0();
	ClearDisplay();
	printf_lcd(" CONECTADO      ");


		  for (posicion = 0; posicion <5 ; posicion++) {
		  	// scroll 1 posicion a la Derecha
			  DesplazarDisplayDerecha();
			  TemporizadorTimer0(300);
			  ResetTimer0();
		  		  }
		  for (posicion = 0; posicion < 5; posicion++) {
		  // scroll 1 posicion a la izquierda
			  DesplazarDisplayIzquierda();
			  TemporizadorTimer0(300);
			  ResetTimer0();
		  		  }

	ClearDisplay();
}

void MensajeStop()
{
	ClearDisplay();
	printf_lcd(" STOP!    STOP! ");
	lcd_gotoxy(1, 2);
	printf_lcd("SIN ESTIMULACION");
}




