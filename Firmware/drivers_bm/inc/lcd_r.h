/*================================================================
Dpto de Electrónica y Laboratorio de Sistemas Embebidos – UNCa
Nombre: lcd.h Autor: Matias L. Ferraro
Descripción: Driver del display LCD de 2 lineas por 16 columnas
para la EDU-CIAA
===============================================================*/

#include "lpc_types.h"
typedef struct __LCD_DATA_Type
{
	Bool D4;
	Bool D3;
	Bool D2;
	Bool D1;
	Bool RS;
	Bool EN;
} LCD_DATA_Type;

/*Donde esta el LCD*/
#define LCD_PORT 4

/*Pines del puerto*/

/* conector EDU-CIAA P2-22 (port 4 pin 10)*/
#define LCD4 10
/* conector EDU-CIAA P2-26 (port 4 pin 6)*/
#define LCD3 6
/* conector EDU-CIAA P2-28 (port 4 pin 5)*/
#define LCD2 5
/* conector EDU-CIAA P2-30 (port 4 pin 4)*/
#define LCD1 4
/* conector EDU-CIAA P2-24 (port 4 pin 8)*/
#define LCD_RS 8
/* conector EDU-CIAA P2-23 (port 4 pin 9)*/
#define LCD_EN 9


/* Funciones necesarias para manejar el display */
void lcd_init_port(void);
void lcd_init(void);
void lcd_gotoxy(int x, int y);
void lcd_putc(char c);
void enviar_lcd (LCD_DATA_Type data);
void printf_lcd(char * string);
void delay(void);
