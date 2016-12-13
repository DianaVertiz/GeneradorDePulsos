/*
 * pulsadores.h
 *
 *  Created on: 22/11/2016
 *      Author: je_su
 */



#ifndef PULSADORES_H
#define PULSADORES_H



uint8_t parametro_modificar=0;

void inicializarPulsadores(void);
uint8_t pulsado(uint8_t);
uint8_t ReadPulsador(void);
void DetenerEstimulador(void);
void ReanudarEstimulador(void);

#endif /* PULSADORES_H */
