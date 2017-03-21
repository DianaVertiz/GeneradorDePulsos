
#ifndef TIMER2_H
#define TIMER2_H


/*==================[inclusions]=============================================*/
#include "chip.h"
#include "core_cm4.h"
#include "stdint.h"

#define TIMER2_IRQn 14

#define TICKRATE_HZ 1000

//void InicializaRitTimer(void);
//void TemporizadorRT(uint32_t);
//void LimpiarBanderaRT(void);
void InicializaTimer1(void);
void TemporizadorTimer1(uint32_t);
void ResetTimer1(void);
void InicializaTimer0(void);
void TemporizadorTimer0(uint32_t);
void ResetTimer0(void);
void InicializaTimer2(void);
void TemporizadorTimer2(uint32_t);
void ResetTimer2(void);
void InitTimer2_MatchInterrupt(uint32_t);
void FinTimer2_MatchInt(void);
void InitInterrupt2();
void FinInterrupt2();




#endif /* PROJECTS_DRIVERS_BM_INC_TECLAS_H_ */
