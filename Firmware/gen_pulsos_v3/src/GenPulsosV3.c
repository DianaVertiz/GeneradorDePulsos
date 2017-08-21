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

#include "GenPulsosV3.h"
#include "leds.h"
#include "dac.h"
#include "timer2.h"
#include "GPIO.h"


//=========================================================================



uint8_t caracter=0;


void UART2_IRQHandler()
{

	FinInt();

}

void TIMER2_IRQHandler()
{
	uint8_t var=0;
	MensajeStop();
	while (Chip_TIMER_MatchPending(LPC_TIMER2, 2))
		{
			var=Leer_intUART();

			if(!(pulsado(BtnRight)) || var=='r') //STOP

			{
				TemporizadorTimer0(500);
				ResetTimer0();

				Chip_TIMER_ClearMatch(LPC_TIMER2, 2);
				FinInterrupt2();

			}


		}

	var=0;
	MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo(),DevolverFlagVoI(),DevolverFlagPoN());

}


int main(void)

{
 	uint8_t aux=0;
	uint8_t	aux2=1;


	inicializarPulsadores();


	InicializarLed();
	InicializarDAC();
	InicializaTimer0();
	InicializaTimer1();

	InicializarLeds();//no debería estar

	IniciarUart();
	lcd_init_port();
	lcd_init();

	MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo(),DevolverFlagVoI(),DevolverFlagPoN());
	InicializarSigno();
	DetenerEstimulador();


	while(1)
	{

		caracter=Leer_intUART();

		if(!(pulsado(BtnEnter))) //Abre el menu
		{
			TemporizadorTimer0(300);
			ResetTimer0();
			OpenMenu2();

			MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo(),DevolverFlagVoI(),DevolverFlagPoN());
			WriteN();
		}

		if(!(pulsado(BtnLeft))) //Envía tren de pulsos
		{	TemporizadorTimer0(300);
			ResetTimer0();
			GenerarPulsos();
		}


		switch(caracter)
		{

    		case 'e': FinInterrupt2();
    				  GenerarPulsos();
    				  InitInterrupt2();break;

    	    case 'n':
    	    		ReadModifyN();
    	    		MostrarNumPulsos(DevolverNumPulsos());
    	    		break;
    	    case 't':
    	    		ReadModifyT();
    	    		MostrarTUp(DevolverTimeUp());
    	    		break;
    	    case 'p':
    	    		ReadModifyP();
    	    		MostrarPeriodo(DevolverPeriodo());
    	    		break;
    	    case 'v':
    	    		ReadModifyV();
    	    		MostrarAmplitud(DevolverValueUp(),DevolverFlagVoI(),DevolverFlagPoN());
    	    		break;
    	    case 'q':
    	    		ResetValues();break;
    	    case 'u':
    	    		ModificarFlagVoI(aux2);
    	    		MostrarAmplitud(DevolverValueUp(),DevolverFlagVoI(),DevolverFlagPoN());
    	    		break;
    	    case 'w':
    	       	    ModificarFlagVoI(aux);
    	       	    MostrarAmplitud(DevolverValueUp(),DevolverFlagVoI(),DevolverFlagPoN());
    	    		break;
    	    case 'o':
    	        	ModificarFlagPoN(aux2);
    	        	PulsosPositivos();
    	        	MostrarAmplitud(DevolverValueUp(),DevolverFlagVoI(),DevolverFlagPoN());
    	        	break;
    	    case 's':
    	        	ModificarFlagPoN(aux);
    	        	PulsosNegativos();
    	        	MostrarAmplitud(DevolverValueUp(),DevolverFlagVoI(),DevolverFlagPoN());
    	        	break;

    	    case 'r':
    	    		InitTimer2_MatchInterrupt(10);
    	    		break;

    	    case 'x':
    	    		MensajeScroll();
    	    		break;

    	    case 'z':
    	        	WriteN();
    	        	break;

    	}

	}

}



/*==================[end of file]============================================*/

