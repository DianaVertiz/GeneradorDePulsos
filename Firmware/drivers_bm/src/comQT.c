/* comQT.c
 *
 *  Created on: 6/10/2016
 *      Author: je_su
 */
#include "comQT.h"

void ReadModifyN()
{
	uint8_t dato  = 0;
	while(!(dato=uartReadByte())){}
	ModificarNumPulsos(dato);
}
void ReadModifyT()
{
	uint16_t dato[2] ={0};
	uint16_t dat;
	uint8_t aux;
	uint8_t aux2;

	while(!(ReadByte(&aux))){}
	dato[0]=aux;
	TemporizadorTimer1(10);
	ResetTimer1();
	ReadByte(&aux2);
    dato[1]=aux2;

	dat=(dato[0]*100)+dato[1];
	ModificarTimeUp(dat);
}
void ReadModifyP()
{
	uint16_t dato[2] ={0};
	uint16_t dat;
	uint8_t aux;
	uint8_t aux2;

	while(!(ReadByte(&aux))){}
	dato[0]=aux;
	TemporizadorTimer1(10);
	ResetTimer1();
	ReadByte(&aux2);
	dato[1]=aux2;


	dat=(dato[0]*100)+dato[1];
	ModificarPeriodo(dat);
}
void ReadModifyV()
{
	uint16_t dato[2] ={0};
	uint16_t dat;
	uint8_t aux;
	uint8_t aux2;

	while(!(ReadByte(&aux))){}
	dato[0]=aux;
	TemporizadorTimer1(10);
	ResetTimer1();
	ReadByte(&aux2);
	dato[1]=aux2;

	dat=(dato[0]*100)+dato[1];
	ModificarValueUp(dat);
}

void WriteN()
{
	uint8_t aux1,aux2_1,aux2_2,aux3_1,aux3_2,aux4_1,aux4_2;

	aux1=DevolverNumPulsos();
	aux2_1=DevolverValueUp()/100;
	aux2_2=DevolverValueUp()%100;
	aux3_1=DevolverTimeUp()/100;
	aux3_2=DevolverTimeUp()%100;
	aux4_1=DevolverPeriodo()/100;
	aux4_2=DevolverPeriodo()%100;

	WriteInt(aux1);
	uartWriteByte(',');
	WriteInt(aux2_1);
	uartWriteByte(',');
	WriteInt(aux2_2);
	uartWriteByte(',');
	WriteInt(aux3_1);
	uartWriteByte(',');
	WriteInt(aux3_2);
	uartWriteByte(',');
	WriteInt(aux4_1);
	uartWriteByte(',');
	WriteInt(aux4_2);
	uartWriteByte(',');

	if(DevolverFlagVoI() ==1)
	{uartWriteByte('1');}
	else
	{uartWriteByte('0');}

	uartWriteByte(',');
	if(DevolverFlagPoN() ==1)
	{uartWriteByte('1');}
	else
	{uartWriteByte('0');}


}



