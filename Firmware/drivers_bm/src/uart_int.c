
#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#include "core_cm4.h"
#include "uart_int.h"
#include "string.h"
#include "sAPI_DataTypes.h"



#elif (mk60fx512vlq15 == CPU)
#else
#endif

#define UART2_PIN_PKG 7
#define UART2_PIN_TXD 1
#define UART2_PIN_RXD 2





void IniciarUart()
{
	Chip_SCU_PinMux(UART2_PIN_PKG, UART2_PIN_TXD, MD_PDN, FUNC6);
	Chip_SCU_PinMux(UART2_PIN_PKG, UART2_PIN_RXD, MD_PLN | MD_EZI | MD_ZI, FUNC6);
	Chip_UART_Init(LPC_USART2);
	Chip_UART_SetBaud(LPC_USART2, BaudRate);
	Chip_UART_ConfigData(LPC_USART2, (UART_LCR_WLEN8 | UART_LCR_SBS_1BIT));

	//Chip_UART_SetupFIFOS(LPC_USART2, UART_FCR_FIFO_EN | UART_FCR_TRG_LEV0);
	Chip_UART_SetupFIFOS(LPC_USART2, (UART_FCR_FIFO_EN | UART_FCR_TRG_LEV2));

	//Chip_UART_SetupFIFOS(LPC_USART2, (UART_FCR_FIFO_EN | UART_FCR_RX_RS |UART_FCR_TX_RS | UART_FCR_TRG_LEV3));
	Chip_UART_TXEnable(LPC_USART2);
	Chip_UART_SetupFIFOS(LPC_USART2, (UART_FCR_FIFO_EN | UART_FCR_RX_RS |UART_FCR_TX_RS | UART_FCR_TRG_LEV3));

}

void FinUart()
{
	Chip_UART_DeInit(LPC_USART2);
}


void IniciarInt()
{
	Chip_UART_IntEnable(LPC_USART2, (UART_IER_RBRINT | UART_IER_RLSINT | UART_IER_THREINT | UART2_IER_BITMASK));
	//NVIC_SetPriority(UART2_IRQn, 1);
	NVIC_EnableIRQ(UART2_IRQn);
}


void EnviarMensaje(char* mensaje, uint8_t size)//size es número de bytes
{

	uint8_t *pdat;

	pdat = (uint8_t *) &mensaje[0];

	Chip_UART_Send(LPC_USART2, pdat, size);



}

uint8_t Leer_intUART(void)
{
	uint8_t byte;
	//while( (Chip_UART_ReadLineStatus(LPC_USART2) & UART_LSR_RDR)!=1){}

	byte=Chip_UART_ReadByte(LPC_USART2);

	return byte;
}

uint16_t Escalado(uint16_t valor)
{
	valor=(valor*1023)/255;
	return valor;
}

void LeerArray(char* array)
{
	uint8_t char_puls=0;
	uint8_t i_N=0;
	while (i_N<4 && char_puls!='\rn')
		{
			char_puls=0;
			while(char_puls==0)
			{char_puls=Leer_intUART(); }
			array[i_N]=(char)char_puls;
			TemporizadorTimer0(5);
			ResetTimer0();

			i_N++;

		}

		char_puls=0;


	/*uint8_t *pdat;

	pdat = (uint8_t *) &array[0];

	Chip_UART_Read(LPC_USART2, pdat, size);*/

}


uint8_t uartReadByte(){

   uint8_t receivedByte = 0;

      if (Chip_UART_ReadLineStatus(LPC_USART2) & UART_LSR_RDR) {
         receivedByte = Chip_UART_ReadByte(LPC_USART2);
      }

   return receivedByte;

}


void uartWriteByte(uint8_t byte){


      while ((Chip_UART_ReadLineStatus(LPC_USART2) & UART_LSR_THRE) == 0) {}   // Wait for space in FIFO
      Chip_UART_SendByte(LPC_USART2, byte);

}




void Escribir_dato(uint8_t dato)
{
	Chip_UART_SendByte(LPC_USART2, dato);
}


void FinInt()
{
		NVIC_DisableIRQ(UART2_IRQn);
		Chip_UART_IntDisable(LPC_USART2, (UART_IER_RBRINT | UART_IER_RLSINT));
}


uint16_t CharToInt(char* vector,uint8_t size)
{


		uint8_t *pdato;
		pdato = (uint8_t *) &vector[0];

		uint8_t b0= pdato[0] - 48;
		uint8_t b1= pdato[1];
		uint8_t b2= pdato[2];
		uint8_t b3= pdato[3];
		uint8_t b4= pdato[4];
		uint16_t var;

			if(b1 =='\r')
				{
					var= (uint16_t)b0;
				}
			else
				{
					b1= b1 - 48;
					if(b2 == '\r')
						{
							var= (uint16_t)(10*b0 + b1);
						}
					else
						{
							b2= b2 - 48;
							if(b3 == '\r')
								{
									var= 100*b0 + 10*b1 + b2;
								}
							else
								{
									b3= b3 - 48;
									if(b4 == '\r')
										{
											var= 1000*b0 + 100*b1 + 10*b2 + b3;
										}
								}

						}


				}

	return var;

}





bool_t ReadByte(uint8_t* receivedByte){

   bool_t retVal = TRUE;

      if ( Chip_UART_ReadLineStatus(LPC_USART2) & UART_LSR_RDR ) {
         *receivedByte = Chip_UART_ReadByte(LPC_USART2);
      } else{
         retVal = FALSE;
      }

    return retVal;
}

/**
 * C++ version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.
 */
char* itoa(uint16_t value, char* result, uint16_t base) {
   // check that the base is valid
   if (base < 2 || base > 36) { *result = '\0'; return result; }

   char* ptr = result, *ptr1 = result, tmp_char;
   uint16_t tmp_value;

   do {
      tmp_value = value;
      value /= base;
      *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
   } while ( value );

   // Apply negative sign
   if (tmp_value < 0) *ptr++ = '-';
   *ptr-- = '\0';
   while(ptr1 < ptr) {
      tmp_char = *ptr;
      *ptr--= *ptr1;
      *ptr1++ = tmp_char;
   }
   return result;
}

char* itoa2(uint32_t val, uint8_t base){

	static char buf[32] = {0};

	uint32_t i = 30;

	for(; val && i ; --i, val /= base)

		buf[i] = "0123456789abcdef"[val % base];

	return &buf[i+1];

}


