
#ifndef ADC_H
#define ADC_H


/*==================[inclusions]=============================================*/
#include "stdint.h"

uint16_t adc_value;


void InicializarADC(void);
void EsperarConversion(void);
void Leer_valor_adc(void);

#endif /* PROJECTS_DRIVERS_BM_INC_TECLAS_H_ */
