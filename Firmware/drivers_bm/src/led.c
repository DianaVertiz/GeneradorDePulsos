/*==================[inclusions]=============================================*/

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif
#include "led.h"


/* driver para encender y apagar el led en el gabinete */

void InicializarLed(){

Chip_GPIO_Init(LPC_GPIO_PORT);

Chip_SCU_PinMux(6,12,MD_PUP,FUNC0);

Chip_GPIO_SetDir(LPC_GPIO_PORT,2,(1 << 8),1);//Led


Chip_GPIO_ClearValue(LPC_GPIO_PORT, 2,(1<<8));


}

void EncenderLed(){

Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,2,8);

 }

void ApagarLed()
{

Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,2,8);


}


/*==================[end of file]============================================*/

