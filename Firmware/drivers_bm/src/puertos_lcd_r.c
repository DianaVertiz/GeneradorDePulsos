/*================================================================
 * Dpto de Electrónica y Laboratorio de Sistemas Embebidos – UNCa
 * Nombre: puertos_lcd.c
 * Autor: Marcos Aranda
===============================================================*/
#include "puertos_lcd_r.h"

void Init_Port_Pin(uint8_t puerto, uint8_t pin, uint8_t config ,uint8_t modo)
{
	/*El puerto 4 es utilizado por el LCD*/
	if( puerto == 4)
	{
		if ((pin>=0)&&(pin<=6))
		{
			Chip_SCU_PinMux(4,pin,config,FUNC0);
			if (modo == 0)
			{
				/*Inicializo el GPIO como entrada*/
				Chip_GPIO_SetPinDIR(LPC_GPIO_PORT,2,pin, INIT_IN);
			}
			else
			{
				/*Inicializo el GPIO como salida*/
				Chip_GPIO_SetPinDIR(LPC_GPIO_PORT,2,pin, INIT_OUT);
			}
		}
		if ((pin>=8)&&(pin<=10))
		{
			Chip_SCU_PinMux(4,pin,config,FUNC4);
			if (modo == 0)
			{
				Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 5,pin+4, INIT_IN);
			}
			else
			{
				Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 5,pin+4, INIT_OUT);
			}
		}
	}
}

void Port_Pin_Alto_Bajo (uint8_t puerto, uint8_t pin, uint8_t config ,uint8_t modo)
{
	if (puerto == 4)
	{
		if ((pin>=0)&&(pin<=6))
		{
			switch(modo)
			{
				case ALTO:
					Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 2, pin);
					break;
				case BAJO:
					Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 2, pin);
					break;
				default:
					break;
			}
		}
	}

	if ((pin>=8)&&(pin<=10))
	{
		switch(modo)
		{
			case ALTO:
				Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, pin+4);
				break;
			case BAJO:
				Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, pin+4);
				break;
			default:
				break;
		}
	}
}

uint32_t Port_Pin_Estado (uint8_t puerto, uint8_t pin,uint8_t modo)
{
	if (puerto == 4)
	{
		if ((pin>=0)&&(pin<=6))
		{
			return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 2, pin);
		}
		if ((pin>=8)&&(pin<=10))
		{
			return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 5, pin+4);
		}
	}
}
