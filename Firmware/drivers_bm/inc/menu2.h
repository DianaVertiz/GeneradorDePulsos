/*
 * menu2.h
 *
 *  Created on: 26/2/2017
 *      Author: je_su
 */

#ifndef MENU2_H
#define MENU2_H
#include "stdint.h"

/* CONSTANTES Y VARIABLES */
#define MOD_NUM_PULSOS       1
#define MOD_AMPLITUD       	 2
#define MOD_TaLTO        	 3
#define MOD_PERIODO          4


uint8_t salir=0;
uint8_t salir_menu=0;
uint8_t menuPosition       = 1;
const uint8_t rowsLCD      = 2;     // Numero de filas del LCD
const uint8_t columnsLCD   = 16;    // Numero de columnas del LCD
uint8_t x=1;
uint8_t unidad1=0;
uint8_t unidad2=0;
uint8_t unidad3=0;
uint8_t unidad4=0;
uint8_t unidad=0;
uint8_t flag1=0;
uint8_t flag2=0;
uint8_t flag3=0;
uint8_t flag4=0;

uint8_t dato_pulsos[2] ={15,15};
uint8_t dato_amplitud[3]={15,15,15};
uint8_t dato_talto[4]={15,15,15,15};
uint8_t dato_periodo[4]={15,15,15,15};
uint16_t dato_guardado=0;
/* TEXTOS MENUS */
const uint8_t iMENU = 6;
const char *txMENU[] = {
    "Nro de pulsos  ",
    "Amplitud       ",
    "Tiempo en alto ",
    "Periodo        ",
};
void OpenMenu2(void);
void Conf_Amplitud2(void);
void Conf_Pulsos2(void);
void Conf_TUp2(void);
void Conf_Periodo2(void);
void ModoEstimulacion(void);
void Polaridad();


#endif /* MENU2_H_ */
