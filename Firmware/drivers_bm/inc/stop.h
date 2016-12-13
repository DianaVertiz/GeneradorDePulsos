/*
 * stop.h
 *
 *  Created on: 10/12/2016
 *      Author: je_su
 */

#ifndef STOP_H
#define STOP_H

/*==================[inclusions]=============================================*/
#include "stdint.h"
#include "chip.h"

/*==================[macros]=================================================*/
#define lpc4337            1
#define mk60fx512vlq15     2

/*==================[typedef]================================================*/


void InicializarStop(void);
uint8_t ReadStop(void);
void CambiarEstado(void);



#endif /* STOP_H_ */
