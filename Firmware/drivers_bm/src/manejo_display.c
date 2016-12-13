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
	static char auxN[10];
	static char auxV[10];
	static char auxT[10];
	static char auxP[10];
	uint16_t Vaux;
	//uint16_t Iaux;

	//lcd_init_port();
	//lcd_init();
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

		//lcd_gotoxy(10,1);

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

	//RetornoCasa();

}


void MostrarNumPulsos(uint16_t N)
{
	static char auxN[10];
	lcd_gotoxy(1,1);
	printf_lcd("     ");
	lcd_gotoxy(1,1);
	printf_lcd("N:");

	itoa(N,auxN,10);
	char* strN=auxN;
	while(*strN != 0)
	{
		  lcd_putc(*strN);
		  strN++;
	}
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


		itoa(Vaux,auxV,10);
			char* strV=auxV;
			while(*strV != 0)
			{
				  lcd_putc(*strV);
				  strV++;
			}

			//lcd_gotoxy(10,1);

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

	itoa(Tup,auxT,10);
	char* strT=auxT;
	while(*strT != 0)
	{
	  lcd_putc(*strT);
	  strT++;
	}
	//printf_lcd("ms");
}
void MostrarPeriodo(uint16_t P)
{
	static char auxP[10];
	lcd_gotoxy(8,2);
	printf_lcd("         ");
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

void ModificarParametro(uint8_t flagVoI,uint8_t flagPoN)
{
	uint8_t parametro= ProbarPulsadores();

	switch(parametro)
		{
		case 1:	ClearDisplay();
				PosicionarCursor(1,1);
				ActivarCursor();
				printf_lcd("Nro de Pulsos:");
				PosicionarCursor(1,2);
				break;
		case 2:	ClearDisplay();
				PosicionarCursor(1,1);
				ActivarCursor();
					if(flagVoI==1)
					{
						printf_lcd("Amplitud_I:");
					}
					if(flagVoI==0)
					{
						printf_lcd("Amplitud_V:");
					}
				PosicionarCursor(1,2);
				if(flagPoN==0){	printf_lcd("-");}
				if(flagPoN==1){ printf_lcd("");}
				break;
		case 3: ClearDisplay();
				PosicionarCursor(1,1);
				ActivarCursor();
				printf_lcd("Tiempo en alto:");
				PosicionarCursor(1,2);
				break;
		case 4: ClearDisplay();
				PosicionarCursor(1,1);
				ActivarCursor();
				printf_lcd("Periodo:");
				PosicionarCursor(1,2);
				break;
		}


}

//permite enviar un dígito entero al display
void lcd_putInt(uint8_t i)
{
	static char N[2];
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
	ClearDisplay();
	uint8_t salir=0;
	//uint8_t posicion=0;
	printf_lcd(" STOP!    STOP! ");
	lcd_gotoxy(1, 2);
	printf_lcd("SIN ESTIMULACION");
	/*TemporizadorTimer0(1000);
	ResetTimer0();
	ClearDisplay();
	printf_lcd(" STOP!    STOP! ");*/

			/*ClearDisplay();
			printf_lcd(" STOP!    STOP! ");
		 // scroll 9 posiciones a la izquierda

		  for (posicion = 0; posicion < 8; posicion++) {
		    // scroll 1 posicion a la izquierda
		    DesplazarDisplayIzquierda();
		    TemporizadorTimer0(300);
		    ResetTimer0();
		  }

		  for (posicion = 0; posicion < 16 ; posicion++) {
		  	// scroll 1 posicion a la Derecha
			  DesplazarDisplayDerecha();
			  TemporizadorTimer0(300);
			  ResetTimer0();
		  		  }
		  for (posicion = 0; posicion < 8; posicion++) {
		  // scroll 1 posicion a la izquierda
			  DesplazarDisplayIzquierda();
			  TemporizadorTimer0(300);
			  ResetTimer0();
		  		  }
		  ClearDisplay();
		  printf_lcd(" STOP!    STOP! ");
		  lcd_gotoxy(1, 2);
		  printf_lcd("SIN ESTIMULACION");*/


		 //TemporizadorTimer0(500);
		 //ResetTimer0();

	//ClearDisplay();
}


