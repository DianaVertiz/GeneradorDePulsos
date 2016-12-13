
#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#include "core_cm4.h"
#include "timer2.h"
#include "string.h"

#elif (mk60fx512vlq15 == CPU)
#else
#endif

/*

void InicializaRitTimer(){
	Chip_RIT_Init(LPC_RITIMER);*
	NVIC_EnableIRQ(RITIMER_IRQn);

}

void TemporizadorRT(uint32_t intervalo)
{

	Chip_RIT_SetTimerInterval(LPC_RITIMER, intervalo);


}
void LimpiarBanderaRT(){
Chip_RIT_ClearInt(LPC_RITIMER);
}
*/
void InicializaTimer1()
{
		uint32_t timerFreq;


		timerFreq = Chip_Clock_GetRate(CLK_MX_TIMER1);
		SystemCoreClockUpdate();

		/* Enable timer 1 clock and reset it */
		Chip_TIMER_Init(LPC_TIMER1);
		Chip_TIMER_Reset(LPC_TIMER1);

		//PR=204000000/1000=204000
		//TC aumenta cada PR+1 ciclos de reloj, como cada ciclo se realiza en 1/204MHz
		//TC cuenta cada 204001*1/204MHz = 1ms
		//10 seg seran 10/(1000000*1/204MHz)
		Chip_TIMER_PrescaleSet(LPC_TIMER1, (timerFreq / TICKRATE_HZ));
		//Chip_TIMER_Enable(LPC_TIMER1);


}


void TemporizadorTimer1(uint32_t tim)
{
	Chip_TIMER_Enable(LPC_TIMER1);
	while(Chip_TIMER_ReadCount(LPC_TIMER1)<= tim){}
	Chip_TIMER_Disable(LPC_TIMER1);

}

void ResetTimer1()
{
	Chip_TIMER_Reset(LPC_TIMER1);
	//Chip_TIMER_Enable(LPC_TIMER1);
}


void InicializaTimer0()
{
		uint32_t timerFreq2;


		timerFreq2 = Chip_Clock_GetRate(CLK_MX_TIMER0);
		SystemCoreClockUpdate();

		/* Enable timer 2 clock and reset it */
		Chip_TIMER_Init(LPC_TIMER0);
		Chip_TIMER_Reset(LPC_TIMER0);

		//PR=204000000/204=1000000
		//TC aumenta cada PR+1 ciclos de reloj, como cada ciclo se realiza en 1/204MHz
		//TC cuenta cada 1000000*1/204MHz +1
		//10 seg seran 10/(1000000*1/204MHz)
		Chip_TIMER_PrescaleSet(LPC_TIMER0, (timerFreq2 / TICKRATE_HZ));
		//Chip_TIMER_Enable(LPC_TIMER1);


}


void TemporizadorTimer0(uint32_t tim2)
{
	Chip_TIMER_Enable(LPC_TIMER0);
	while(Chip_TIMER_ReadCount(LPC_TIMER0)<= tim2){}
	Chip_TIMER_Disable(LPC_TIMER0);

}

void ResetTimer0()
{
	Chip_TIMER_Reset(LPC_TIMER0);

}

//timer2 común
void InicializaTimer2()
{
	uint32_t timerFreq2;

	timerFreq2 = Chip_Clock_GetRate(CLK_MX_TIMER2);
			SystemCoreClockUpdate();

	/* Enable timer 2 clock and reset it */
	Chip_TIMER_Init(LPC_TIMER2);
	Chip_TIMER_Reset(LPC_TIMER2);

	//PR=204000000/204 = 1000000
	//TC aumenta cada PR+1 ciclos de reloj, como cada ciclo se realiza en 1/204MHz
	//TC cuenta cada 1000000*1/204MHz +1
	//10 seg seran 10/(1000000*1/204MHz)
	Chip_TIMER_PrescaleSet(LPC_TIMER2, (timerFreq2 / TICKRATE_HZ));
	//Chip_TIMER_Enable(LPC_TIMER2);
}

void TemporizadorTimer2(uint32_t tim)
{
	Chip_TIMER_Enable(LPC_TIMER2);
	while(Chip_TIMER_ReadCount(LPC_TIMER2)<= tim){}
	Chip_TIMER_Disable(LPC_TIMER2);
}
void ResetTimer2()
{
	Chip_TIMER_Reset(LPC_TIMER2);

}

//usar el timer2 para interrupción por match

void InitTimer2_MatchInterrupt(uint32_t tim)
{

	//uint32_t timerFreq2;

	//timerFreq2 = Chip_Clock_GetRate(CLK_MX_TIMER2);
	//SystemCoreClockUpdate();

	Chip_TIMER_Init(LPC_TIMER2);
	Chip_TIMER_Reset(LPC_TIMER2);
	Chip_TIMER_MatchEnableInt(LPC_TIMER2, 2);
	Chip_TIMER_PrescaleSet(LPC_TIMER2,204000);


	Chip_TIMER_SetMatch(LPC_TIMER2, 2, tim);

	Chip_TIMER_ResetOnMatchEnable(LPC_TIMER2, 2);

	Chip_TIMER_Enable(LPC_TIMER2);

	NVIC_ClearPendingIRQ(TIMER2_IRQn);

	NVIC_EnableIRQ(TIMER2_IRQn);

}

void FinTimer2_MatchInt()
{
	ResetTimer2();
	//NVIC_DisableIRQ(TIMER2_IRQn);

}

void InitInterrupt2()
{
	NVIC_EnableIRQ(TIMER2_IRQn);
}
void FinInterrupt2()
{
	//ResetTimer2();
	//NVIC_ClearPendingIRQ(TIMER2_IRQn);
	NVIC_DisableIRQ(TIMER2_IRQn);

}






