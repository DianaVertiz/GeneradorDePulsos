
#ifndef TIMER_H
#define TIMER_H
#include "chip.h"
#include "core_cm4.h"


#define RITIMER_IRQn 11



/*==================[inclusions]=============================================*/
#include "stdint.h"

void InicializaTimer(void);
void Temporizador(uint32_t);
void LimpiarBandera(void);



#endif /* PROJECTS_DRIVERS_BM_INC_TECLAS_H_ */
