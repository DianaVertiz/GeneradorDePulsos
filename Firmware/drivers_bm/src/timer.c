
#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#include "core_cm4.h"
#include "timer.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif



void InicializaTimer(){
	Chip_RIT_Init(LPC_RITIMER);
	NVIC_EnableIRQ(RITIMER_IRQn);

}

void Temporizador(uint32_t intervalo)
{

	Chip_RIT_SetTimerInterval(LPC_RITIMER, intervalo);

}
void LimpiarBandera(){
Chip_RIT_ClearInt(LPC_RITIMER);
}





