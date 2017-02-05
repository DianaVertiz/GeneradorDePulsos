/*
 * teclas.h
 *
 *  Created on: 3/5/2016
 *      Author: root
 */

#ifndef TECLAS_H
#define TECLAS_H

#define TEC_4
/*==================[inclusions]=============================================*/
#include "stdint.h"


void InicializarTeclas(void);
uint8_t DetectarTecla(uint8_t);
uint8_t EscanearTeclado();


#endif /* PROJECTS_DRIVERS_BM_INC_TECLAS_H_ */
