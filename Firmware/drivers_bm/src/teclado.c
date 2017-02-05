/* Copyright 2016, XXXXXXXXX  
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Blinking Bare Metal driver led
 **
 **
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */

/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal LED Driver
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif
#include "teclado.h"
#include "timer2.h"



/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */

Inicializar_Teclas(void)
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

uint8_t Configurar_Puerto()
{
	uint8_t puerto_compuesto=0b00000000;

puerto_compuesto = puerto_compuesto & puerto_inicial;

if(Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,4)==0)
{
	puerto_compuesto=puerto_compuesto & 0b11111110;
}
if(Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,8)==0)
{
	puerto_compuesto=puerto_compuesto & 0b11111101;
}
if(Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,9)==0)
{
	puerto_compuesto=puerto_compuesto & 0b11111011;
}
if(Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,1,9)==0)
{
	puerto_compuesto=puerto_compuesto & 0b11110111;
}

	return puerto_compuesto;
}


uint8_t Escanear(uint8_t puerto)
{
	uint8_t tecla;


	if(puerto == TEC1){tecla=TEC1;}
	if(puerto == TEC2){tecla=TEC2;}
	if(puerto == TEC3){tecla=TEC3;}
	if(puerto == TEC4){tecla=TEC4;}
	return tecla;

}

DetectarPulsado(uint8_t aux)
{
	Temporizador(1);

	/*tecla_temp=aux;
	if(contador_1ms==veces_contador_1ms)
		{
		if(tecla_temp == EscanearTeclado())
			{tecla_pulsada=tecla_temp;}
		contador_1ms=0;

		}
	else
		{contador_1ms++;}*/
	//Esperar();
}
//DetectarPulsado2(uint8_t)
//DetectarPulsado3(uint8_t)


/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

