
#ifndef TIMER2_H
#define TIMER2_H


/*==================[inclusions]=============================================*/
#include "stdint.h"

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





#endif /* PROJECTS_DRIVERS_BM_INC_TECLAS_H_ */
