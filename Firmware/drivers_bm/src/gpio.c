


/*==================[inclusions]=============================================*/

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif
#include "gpio.h"




void InicializarGpio()
{

Chip_GPIO_Init(LPC_GPIO_PORT);
Chip_SCU_PinMux(6,9,MD_PUP,FUNC0); //PinNamePort ,PinNamePin

Chip_GPIO_SetDir(LPC_GPIO_PORT,3,(1 <<5),1);//GpioPortNum=3

Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 3,5); // En 1 por defecto la salida es positiva

}

void PulsosNegativos()
{
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 3,5);
}

void PulsosPositivos()
{
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 3,5);
}


/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

