/*================================================================
Dpto de Electrónica y Laboratorio de Sistemas Embebidos – UNCa
Nombre: lcd.c Autor: Matias L. Ferraro
Descripción: Driver del display LCD de 2 lineas por 16 columnas
para la EDU-CIAA
===============================================================*/
#include "lcd_r.h"
#include "puertos_lcd_r.h"


LCD_DATA_Type data;

//Inicializa los puertos del LCD
void lcd_init_port(void)
{
	Init_Port_Pin(LCD_PORT,LCD_RS,MD_PLN,INIT_OUT);
	Init_Port_Pin(LCD_PORT,LCD_EN,MD_PLN,INIT_OUT);
	Init_Port_Pin(LCD_PORT,LCD4,MD_PLN,INIT_OUT);
	Init_Port_Pin(LCD_PORT,LCD3,MD_PLN,INIT_OUT);
	Init_Port_Pin(LCD_PORT,LCD2,MD_PLN,INIT_OUT);
	Init_Port_Pin(LCD_PORT,LCD1,MD_PLN,INIT_OUT);
}

//Inicializa el LCD según el manual del dispositivo
void lcd_init(void)
{
//	Paso 1)--------Enviar: D7,D6,D5,D4=0011---- RS=0 ----------
	delay();
	data.D1=1;
	data.D2=1;
	data.D3=0;
	data.D4=0;
	data.RS=0;
	enviar_lcd(data);
	delay();

//	Paso 2)--------Enviar: D7,D6,D5,D4=0011---- RS=0 ----------
	delay();
	data.D1=1;
	data.D2=1;
	data.D3=0;
	data.D4=0;
	data.RS=0;
	enviar_lcd(data);
	delay();

//	Paso 3)--------- Enviar: D7,D6,D5,D4=0011---- RS=0 ----------
	delay();
	//. . . . . .*/ /* Asignar valores a los bits
	data.D1=1;
	data.D2=1;
	data.D3=0;
	data.D4=0;
	data.RS=0;

	enviar_lcd(data);
	delay();

//	Paso 4)--------- Enviar: D7,D6,D5,D4=0010----- RS=0 ----------
	data.D1=0;
	data.D2=1;
	data.D3=0;
	data.D4=0;
	data.RS=0;
	delay();
	//. . . . . .*/ /* Asignar valores a los bits

	enviar_lcd(data);
	delay();
	//Paso 5)---PRIMERO---- Enviar: D7,D6,D5,D4=0010----- RS=0 -----
	//---DESPUES---- Enviar: D7,D6,D5,D4=1111------ RS=0 ----
	delay();
	//. . . . . .*/ /* Asignar valores a los bits
	data.D1=0;
	data.D2=1;
	data.D3=0;
	data.D4=0;
	data.RS=0;
	enviar_lcd(data);
	delay();
	//. . . . . .*/ /* Asignar valores a los bits*
	data.D1=1;
	data.D2=1;
	data.D3=1;
	data.D4=1;
	data.RS=0;///???
	enviar_lcd(data);

	//Paso 6)---PRIMERO----- Enviar: ---D7,D6,D5,D4=0000------ RS=0 --
	//---DESPUES----- Enviar: ---D7,D6,D5,D4=1000------ RS=0 --
	delay();
	//. . . . . .*/ /* Asignar valores a los bits
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
	data.D4=1;
	data.RS=0;
	enviar_lcd(data);
	delay();

	//Paso 7)---PRIMERO--------D7,D6,D5,D4=0000------------------
	//---DESPUES--------D7,D6,D5,D4=0001------------------

	delay();
	//. . . . . .*/ /* Asignar valores a los bits
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

	//Paso 8)---PRIMERO--------D7,D6,D5,D4=0000------------------
	//---DESPUES--------D7,D6,D5,D4=0110------------------
	delay();
	//. . . . . .*/ /* Asignar valores a los bits
	data.D1=0;
	data.D2=0;
	data.D3=0;
	data.D4=0;
	data.RS=0;
	enviar_lcd(data);
	delay();
	// . . . . .*/ /* Asignar valores a los bits
	data.D1=0;
	data.D2=1;
	data.D3=1;
	data.D4=0;
	data.RS=0;
	enviar_lcd(data);
	delay();

	// FIN INICIALIZACION

	//DISPLAY ON/OFF
	///---PRIMERO--------D7,D6,D5,D4=0000---- RS = 0 --------
	///----DESPUES-------D7,D6,D5,D4=1100---- RS = 0 --------

	delay(); //. . . . . .*/ /* Asignar valores a los bits
	data.D1=0;
	data.D2=0;
	data.D3=0;
	data.D4=0;
	data.RS=0;
	enviar_lcd(data);
	delay();
	//. . . . . .*/ /* Asignar valores a los bits
	data.D1=0;
	data.D2=0;
	data.D3=1;
	data.D4=1;
	data.RS=0;
	enviar_lcd(data);
	delay();
}


void lcd_gotoxy(int x, int y)
{
	int address;
	LCD_DATA_Type data;
	int nibble;

	switch(y)
	{
		case 1: address = 0;
		break;
		case 2: address = 64;
		break;
	}
	//Primero envio tres bits de direccion y d7=1, luego cuatro bits más de dirección
	address =(address+(x-1));
	delay();
	data.D1=(!!(address & 16));
	data.D2=(!!(address & 32));
	data.D3=(!!(address & 64));
	data.D4=1; data.RS=0;
	enviar_lcd(data);
	delay();

	data.D1=(!!(address & 1));
	data.D2=(!!(address & 2));
	data.D3=(!!(address & 4));
	data.D4=(!!(address & 8));
	data.RS=0;
	enviar_lcd(data);
}

void lcd_putc(char C) {
	LCD_DATA_Type data;
	int nibble;
	switch(C)
	{
		case '\f':
			break;
		case '\n':
			break;
		case '\b':	//Borra pantalla
			delay();
			data.D1=0;
			data.D2=0;
			data.D3=0;
			data.D4=0;
			data.RS=0;
			enviar_lcd(data);
			delay();

			data.D1=1;
			data.D2=0;
			data.D3=0;
			data.D4=0;
			data.RS=0;
			enviar_lcd(data);
			delay();
			break;
		default:
			nibble= (int) C;
			data.D1=(!!(nibble & 16));
			data.D2=(!!(nibble & 32));
			data.D3=(!!(nibble & 64));
			data.D4=(!!(nibble & 128));
			data.RS=1;
			enviar_lcd(data);
			delay();

			data.D1=(!!(nibble & 1));
			data.D2=(!!(nibble & 2));
			data.D3=(!!(nibble & 4));
			data.D4=(!!(nibble & 8));
			data.RS=1;
			enviar_lcd(data);
			delay();
			break;
	}
}

void enviar_lcd (LCD_DATA_Type data)
{
	if (data.D1==1)
		Port_Pin_Alto_Bajo(LCD_PORT,LCD1,DISABLE, ALTO);
	else
		Port_Pin_Alto_Bajo(LCD_PORT,LCD1,DISABLE, BAJO);

	if (data.D2==1)
		Port_Pin_Alto_Bajo(LCD_PORT,LCD2,DISABLE,ALTO);
	else
		Port_Pin_Alto_Bajo(LCD_PORT,LCD2,DISABLE, BAJO);

	if (data.D3==1)
		Port_Pin_Alto_Bajo(LCD_PORT,LCD3,DISABLE, ALTO);
	else
		Port_Pin_Alto_Bajo(LCD_PORT,LCD3, DISABLE, BAJO);

	if (data.D4==1)
		Port_Pin_Alto_Bajo(LCD_PORT,LCD4,DISABLE, ALTO);
	else
		Port_Pin_Alto_Bajo(LCD_PORT,LCD4, DISABLE, BAJO);

	if(data.RS==1)
		Port_Pin_Alto_Bajo(LCD_PORT,LCD_RS,DISABLE,ALTO);
	else
		Port_Pin_Alto_Bajo(LCD_PORT,LCD_RS,DISABLE,BAJO);

	delay();
	Port_Pin_Alto_Bajo(LCD_PORT,LCD_EN, DISABLE, ALTO); delay();
	Port_Pin_Alto_Bajo(LCD_PORT,LCD_EN, DISABLE, BAJO); delay();
}

void printf_lcd(char * string)
{
	int c=0;
	while (string[c]!='\0')
	{
		lcd_putc(string[c]); c++;
	}
}

void delay(void)
{
	long int i=0,x=0;
	for(i=0; i<9999; i++){x++;}
}
