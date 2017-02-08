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
#include "dac.h"
#include "timer.h"
#include "timer2.h"
#include "GPIO.h"


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

void TIMER2_IRQHandler()
{
	uint8_t var=0;
	MensajeScroll();
	while (Chip_TIMER_MatchPending(LPC_TIMER2, 2))
		{
			var=Leer_intUART();
			EncenderLeds(4);
			if(!(pulsado(BtnRight)) || var=='r') //STOP

			{
				TemporizadorTimer0(500);
				ResetTimer0();

				Chip_TIMER_ClearMatch(LPC_TIMER2, 2);
				FinInterrupt2();

			}


		}
	DesactivarPin();
	var=0;
	MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo(),DevolverFlagVoI(),DevolverFlagPoN());
	ApagarLeds(4);
}


int main(void)

{
 	uint8_t aux=0;
	uint8_t	aux2=1;


	inicializarPulsadores();
	InicializarTeclas();

	InicializarLeds();
	InicializarDAC();
	InicializaTimer0();
	InicializaTimer1();

	IniciarUart();
	lcd_init_port();
	lcd_init();

	arriba();
	MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo(),DevolverFlagVoI(),DevolverFlagPoN());
	InicializarSigno();
	InicializarStop();
	//PulsosNegativos();

	WriteN();


	while(1)
	{

		caracter=Leer_intUART();
		if(EscanearTeclado()==1)
		{
			TemporizadorTimer0(500);
			ResetTimer0();
			GenerarPulsos();
		}

		if(!(pulsado(BtnRight))) //STOP

		{
			TemporizadorTimer0(500);
			ResetTimer0();
			ActivarPin();
			InitTimer2_MatchInterrupt(10);

		}

		if(!(pulsado(BtnEnter))) //Abre el menu
		{
			TemporizadorTimer0(500);
			ResetTimer0();
			OpenMenu();

			MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo(),DevolverFlagVoI(),DevolverFlagPoN());
			WriteN();
		}

		if(!(pulsado(BtnLeft))) //Envía tren de pulsos
		{	TemporizadorTimer0(500);
			ResetTimer0();
			GenerarPulsos();
		}

		if(!(pulsado(BtnUp)) || !(pulsado(BtnDown))) //configuración rápida de la amplitud
		{
			TemporizadorTimer0(500);
			ResetTimer0();
			VariarAmplitud();
			MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo(),DevolverFlagVoI(),DevolverFlagPoN());
			WriteN();
		}



		switch(caracter)
		{

    		case 'e': FinInterrupt2();
    				  GenerarPulsos();
    				  InitInterrupt2();break;

    	    case 'n':
    	    		ReadModifyN();
    	    		MostrarNumPulsos(DevolverNumPulsos());
    	    		//MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo(),DevolverFlagVoI(),DevolverFlagPoN());
    	    		break;
    	    case 't':
    	    		ReadModifyT();
    	    		MostrarTUp(DevolverTimeUp());
    	    		//MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo(),DevolverFlagVoI(),DevolverFlagPoN());
    	    		break;
    	    case 'p':
    	    		ReadModifyP();
    	    		MostrarPeriodo(DevolverPeriodo());
    	    		//MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo(),DevolverFlagVoI(),DevolverFlagPoN());
    	    		break;
    	    case 'v':
    	    		ReadModifyV();
    	    		MostrarAmplitud(DevolverValueUp(),DevolverFlagVoI(),DevolverFlagPoN());
    	    		//MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo(),DevolverFlagVoI(),DevolverFlagPoN());
    	    		break;
    	    case 'q':
    	    		ResetValues();break;
    	    case 'u':
    	    		ModificarFlagVoI(aux2);
    	    		MostrarAmplitud(DevolverValueUp(),DevolverFlagVoI(),DevolverFlagPoN());
    	    		//MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo(),DevolverFlagVoI(),DevolverFlagPoN());
    	    		break;
    	    case 'w':
    	       	    ModificarFlagVoI(aux);
    	       	    MostrarAmplitud(DevolverValueUp(),DevolverFlagVoI(),DevolverFlagPoN());
    	    		//MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo(),DevolverFlagVoI(),DevolverFlagPoN());
    	       	    break;
    	    case 'o':
    	        	ModificarFlagPoN(aux2);
    	        	PulsosPositivos();
    	        	MostrarAmplitud(DevolverValueUp(),DevolverFlagVoI(),DevolverFlagPoN());
    	        	//MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo(),DevolverFlagVoI(),DevolverFlagPoN());
    	        	break;
    	    case 's':
    	        	ModificarFlagPoN(aux);
    	        	PulsosNegativos();
    	        	MostrarAmplitud(DevolverValueUp(),DevolverFlagVoI(),DevolverFlagPoN());
    	        	//MostrarPulsos(DevolverNumPulsos(),DevolverValueUp(),DevolverTimeUp(),DevolverPeriodo(),DevolverFlagVoI(),DevolverFlagPoN());
    	        	break;

    	    case 'r':
    	    		ActivarPin();
    	    		InitTimer2_MatchInterrupt(10);
    	    		break;
    	}

	}

}



/*==================[end of file]============================================*/

