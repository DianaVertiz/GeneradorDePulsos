/*
 * pulsos.h
 *
 *  Created on: 24/9/2016
 *      Author: je_su
 */

#ifndef PULSOS_H
#define PULSOS_H

/*==================[inclusions]=============================================*/
#include "stdint.h"

//========================================================================
#define VALUE 1023
#define VCC 3300
#define delay_rele 10

uint16_t N_PULSOS=5; //n
uint16_t VALUE_UP=33;//u  voltaje o corriente
uint16_t  TIMER_UP=1; //t  tiempo en ms
uint16_t  PERIODO=5; //p
uint16_t VALUE_DOWN=0;
uint16_t TIMER_DOWN;
uint32_t value_down;
uint32_t value_up;
uint8_t flagVoI=1; //1 Modo corriente
uint8_t flagPoN=1; //1 Pulsos positivos

//const uint32_t value_down_d=(VALUE_DOWN_D*1023)/VCC;
//const uint32_t value_up_d=(VALUE_UP_D*1023)/VCC;
//const uint32_t TIMER_DOWN_D=PERIODO_D-TIMER_UP_D;

/*==================[macros]=================================================*/
#define lpc4337            1
#define mk60fx512vlq15     2


/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/
#if (CPU == mk60fx512vlq15)
/* Reset_Handler is defined in startup_MK60F15.S_CPP */
void Reset_Handler( void );

extern uint32_t __StackTop;
#elif (CPU == lpc4337)
/** \brief Reset ISR
 **
 ** ResetISR is defined in cr_startup_lpc43xx.c
 **
 ** \remark the definition is in
 **         externals/drivers/cortexM4/lpc43xx/src/cr_startup_lpc43xx.c
 **/
extern void ResetISR(void);

/** \brief Stack Top address
 **
 ** External declaration for the pointer to the stack top from the Linker Script
 **
 ** \remark only a declaration is needed, there is no definition, the address
 **         is set in the linker script:
 **         externals/base/cortexM4/lpc43xx/linker/ciaa_lpc4337.ld.
 **/
extern void _vStackTop(void);
uint16_t DevolverNumPulsos();
uint16_t DevolverValueUp();
uint16_t DevolverTimeUp();
uint16_t DevolverPeriodo();
uint8_t DevolverFlagVoI();
uint8_t DevolverFlagPoN();
void ModificarFlagVoI(uint8_t);
void ModificarFlagPoN(uint8_t);
void ModificarNumPulsos(uint16_t);
void ModificarTimeUp(uint16_t);
void ModificarPeriodo(uint16_t);
void ModificarValueUp(uint16_t);
void ResetValues();
void GenerarPulsos(void);

#else

#endif


#endif /* PULSOS_H_ */
