/* Copyright 2016, XXXXXX
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


/*==================[inclusions]=============================================*/

#include "GenPulsosV2.h"
#include "led.h"
#include "teclas.h"
#include "dac.h"
#include "timer.h"
#include "timer2.h"

//=========================================================================

uint8_t BAND=1;
uint8_t FLAG=1;
uint8_t caracter=0;
char aux[3]={0} ;
uint8_t valor =0;

void SetBanderaRT()
{
	FLAG=0;
}
uint8_t GetBanderaRT(){return FLAG;}

void Interrupcion(){
	SetBanderaRT();
	LimpiarBandera();
}
void Esperar()
{

	while(GetBanderaRT()==1);
	FLAG=1;

}


void UART2_IRQHandler()
{

	FinInt();

}

int main(void)

{
	uint16_t dato[2] ={0};
	uint16_t dat;
	uint8_t i=0;

	InicializarLeds();
	InicializarDAC();
	InicializaTimer0();
	InicializaTimer1();
	IniciarUart();
	lcd_init_port();
	lcd_init();
	InicializarGpio();
	//PulsosNegativos();
	MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo());

	while(1)
	{
		caracter=Leer_intUART();

		switch(caracter)
		{

    		case 'e':
    				GenerarPulsos();break;
    	    case 'n':
    	    		ReadModifyN();break;
    	    case 't':
    	    		ReadModifyT();break;
    	    case 'p':
    	    		ReadModifyP();break;
    	    case 'v':
    	    		ReadModifyV();break;
    	    case 'q':
    	    		ResetValues();break;
    	    case 'r':
    	    		MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo());

    	}

	}

}



/*==================[end of file]============================================*/

