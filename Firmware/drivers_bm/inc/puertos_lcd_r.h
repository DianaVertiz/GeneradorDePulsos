/*================================================================
 * Dpto de Electrónica y Laboratorio de Sistemas Embebidos – UNCa
 * Nombre: puertos_lcd.h
 * Autor: Marcos Aranda
 * Descripción: Prototipos y definiciones para la configuración de
 * pines para el LCD
===============================================================*/
#include "chip.h"

#define ENTRADA 0
#define SALIDA 1
#define INIT_IN 0
#define INIT_OUT 1
#define ALTO 2
#define BAJO 3

#define STATE_IN 4
#define DISABLE 0

void Init_Port_Pin(uint8_t puerto,uint8_t pin,uint8_t config, uint8_t modo);//Inicializa un pin de un puerto.
void Port_Pin_Alto_Bajo(uint8_t puerto, uint8_t pin, uint8_t config ,uint8_t modo);
uint32_t Port_Pin_Estado(uint8_t puerto, uint8_t pin,uint8_t modo);
