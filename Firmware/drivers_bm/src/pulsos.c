/*
 * pulsos.c
 *
 *  Created on: 24/9/2016
 *      Author: je_su
 */

#include "pulsos.h"

uint16_t DevolverNumPulsos()
{
	return N_PULSOS;
}
uint16_t DevolverValueUp()
{
	return VALUE_UP;
}
uint16_t DevolverTimeUp()
{
	return TIMER_UP;
}
uint16_t DevolverPeriodo()
{
	return PERIODO;
}

uint8_t DevolverFlagVoI()
{
	return flagVoI;
}
uint8_t DevolverFlagPoN()
{
	return flagPoN;
}

void ModificarFlagVoI(uint8_t valor)
{
	flagVoI=valor;
}
void ModificarFlagPoN(uint8_t valor)
{
	flagPoN=valor;
}

void ModificarNumPulsos(uint16_t pulsos)
{
	N_PULSOS = pulsos;
}

void ModificarTimeUp(uint16_t tiempo)
{
	TIMER_UP = tiempo;
}

void ModificarPeriodo(uint16_t periodo)
{
	PERIODO = periodo;
}

void ModificarValueUp(uint16_t v_up)
{
	VALUE_UP = v_up;
}

void ResetValues()
{
	//N_PULSOS = 5;
	TIMER_UP = 1;
	PERIODO = 5;
	//VALUE_UP = 2000;
}


void GenerarPulsos()
{
	uint16_t pulsos =0;
	uint16_t valor;
	//if(VALUE_UP<=5){valor=0;}
	//else{valor=VALUE_UP-5;}
	//value_up=(valor*1023)/VCC;
	value_up=(VALUE_UP*1023)/VCC;
	value_down=(VALUE_DOWN*1023)/VCC;
	TIMER_DOWN=PERIODO-TIMER_UP;

	while(pulsos < N_PULSOS)
	   {
	    	EncenderLeds(5);
	    	Conversion(value_up);
	    	TemporizadorTimer0(TIMER_UP-1);
	    	ApagarLeds(5);
	    	Conversion(value_down);
	    	ResetTimer0();
	    	ResetTimer1();
	    	TemporizadorTimer1(TIMER_DOWN-1);

	    	pulsos++;
	    }
}


