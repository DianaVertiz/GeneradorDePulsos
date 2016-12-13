/*
 * menu.h
 *
 *  Created on: 6/12/2016
 *      Author: je_su
 */

#ifndef MENU_H
#define MENU_H
#include "stdint.h"



/* CONSTANTES Y VARIABLES */
#define MOD_NUM_PULSOS       1
#define MOD_AMPLITUD       	 2
#define MOD_TaLTO        	 3
#define MOD_PERIODO          4

uint8_t salir=0;
uint8_t salir2=0;
uint8_t menuPosition       = 1;
const uint8_t rowsLCD      = 2;     // Numero de filas del LCD
const uint8_t columnsLCD   = 16;    // Numero de columnas del LCD
uint8_t x=1;
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
    "Guardar y salir",
    "Salir          "
};

/* TEXTOS SUBMENU */
const char *txSUBMENU[] = {
    "Nro de Pulsos:  ",
    "Amplitud:       ",
    "Tiempo en alto: ",
    "Periodo:        ",
};


void OpenMenu(void);
void Conf_Pulsos(uint8_t);
void Guardar_Pulsos(void);
void Conf_previa(void);
void Conf_Amplitud(uint8_t);
void Guardar_Amplitud(void);
void Conf_TUp(uint8_t);
void Guardar_TUp(void);
void Conf_Periodo(uint8_t);
void Guardar_Periodo(void);
uint16_t GuardarDato(uint8_t*, uint8_t);




#endif /* MENU_H_ */
