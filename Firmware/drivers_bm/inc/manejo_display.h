/*
 * manejo_display.h
 *
 *  Created on: 17/10/2016
 *      Author: je_su
 */

#ifndef MANEJO_DISPLAY_H
#define MANEJO_DISPLAY_H



void MostrarPulsos(uint16_t,uint16_t,uint16_t,uint16_t,uint8_t,uint8_t);
void MostrarNumPulsos(uint16_t);
void MostrarAmplitud(uint16_t,uint8_t,uint8_t);
void MostrarTUp(uint16_t);
void MostrarPeriodo(uint16_t);

void DesactivarCursor(void);
void ActivarCursor(void);
void Cursor_sinBlink(void);
void DesplazarCursorDerecha(void);
void DesplazarDisplay(void);
void ClearDisplayDerecha(void);
void lcd_putInt(uint16_t);
void DesplazarDisplayIzquierda(void);
void PosicionarCursor(uint8_t, uint8_t);
void arrow(void);
void arriba(void);
void MensajeScroll(void);
#endif /* MANEJO_DISPLAY_H_ */

