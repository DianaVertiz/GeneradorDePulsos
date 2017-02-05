/*

 * teclas.c
 *
 *  Created on: 3/5/2016
 *      Author: root
 */
#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif
#include "teclas.h"



void InicializarTeclas(void)
{
Chip_SCU_PinMux(1,0,MD_PUP|MD_EZI|MD_ZI,FUNC0);
Chip_SCU_PinMux(1,1,MD_PUP|MD_EZI|MD_ZI,FUNC0);
Chip_SCU_PinMux(1,2,MD_PUP|MD_EZI|MD_ZI,FUNC0);
Chip_SCU_PinMux(1,6,MD_PUP|MD_EZI|MD_ZI,FUNC0);

Chip_GPIO_SetDir(LPC_GPIO_PORT,0,(1 << 4),0);//setear estos pines como entrada
Chip_GPIO_SetDir(LPC_GPIO_PORT,0,(1 << 8),0);
Chip_GPIO_SetDir(LPC_GPIO_PORT,0,(1 << 9),0);
Chip_GPIO_SetDir(LPC_GPIO_PORT,1,(1 << 9),0);

}

uint8_t DetectarTecla(uint8_t tecla)
{
switch (tecla){

case 1:return 3;break;
case 2:return 4;break;
case 3:return 5;break;
case 4:return 6;break;

}
}

uint8_t EscanearTeclado()
{
	if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,4)){//TEC_1
		return 1;}
	else { if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,8)) //TEC_2
			{return 2;}
			else{ if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,9))//TEC_3
					{return 3;}
				 	else{if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,1,9)) //TEC_4
							{return 4; }
					      else {return 0;}
							}
				}


			}

}



