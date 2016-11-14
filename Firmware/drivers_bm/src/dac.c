
#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#include "core_cm4.h"
#include "dac.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif



uint8_t InicializarDAC(void)
{
	//Chip_SCU_DAC_Analog_Config();
	Chip_DAC_Init(LPC_DAC);
	Chip_DAC_SetBias(LPC_DAC, DAC_MAX_UPDATE_RATE_400kHz);
	Chip_DAC_SetDMATimeOut(LPC_DAC, 0xffff);
	Chip_DAC_ConfigDAConverterControl(LPC_DAC,DAC_CNT_ENA|DAC_DMA_ENA);
	LPC_SCU->ENAIO[2] =0;
	return TRUE;
	}

void Conversion(uint32_t dac_value)
{
	if( dac_value > 1023 ){
	        dac_value = 1023;
	      }
	Chip_DAC_UpdateValue(LPC_DAC, dac_value);

}

