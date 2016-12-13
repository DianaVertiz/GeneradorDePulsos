/*
 * comQT.h
 *
 *  Created on: 6/10/2016
 *      Author: je_su
 */

#ifndef COMQT_H
#define COMQT_H

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif
#include "led.h"

void ReadModifyN(void);
void ReadModifyT(void);
void ReadModifyP(void);
void ReadModifyV(void);
void WriteN(void);
void WriteV(void);
void WriteT(void);
void WriteP(void);


#endif /* COMQT_H_ */
