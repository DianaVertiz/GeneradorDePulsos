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

    //if(dato[0]==120){dato[0]=0;}

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
	//uint8_t dato  = 0;
	//while(!(dato=uartReadByte())){}
	ModificarValueUp(dat);
}

void WriteN()
{

	uartWriteByte(DevolverNumPulsos());
}
void WriteV()
{

}
void WriteT()
{

}
void WriteP()
{

}




