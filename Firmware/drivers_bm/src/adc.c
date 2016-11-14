
#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#include "core_cm4.h"
#include "adc.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif

ADC_CLOCK_SETUP_T conversor;
bool end_Flag = false;
uint32_t _bitRate = 400000;
ADC_RESOLUTION_T _bitAccuracy = ADC_10BITS;
uint8_t Burst_Mode_Flag = 1;
uint8_t ADC_Interrupt_Done_Flag =1;
uint8_t Interrupt_Continue_Flag =1;



void InicializarADC(void)
{
	Chip_SCU_ADC_Channel_Config(0, ADC_CH1);
	_bitAccuracy -= _bitAccuracy > 0 ? 1 : 0;
	Chip_ADC_SetResolution(LPC_ADC0, &conversor, _bitAccuracy);
	//Chip_ADC_SampleRate
	Chip_ADC_Init(LPC_ADC0, &conversor);

	Chip_ADC_EnableChannel(LPC_ADC0, ADC_CH1, ENABLE);


	}

void EsperarConversion(void)
{
	//Chip_ADC_SetStartMode(LPC_ADC0, ADC_START_NOW, ADC_TRIGGERMODE_RISING);

	if (Burst_Mode_Flag) {
			Chip_ADC_SetBurstCmd(LPC_ADC0, ENABLE);
		}
		else {
			Chip_ADC_SetBurstCmd(LPC_ADC0, DISABLE);
		}

	if (!Burst_Mode_Flag) {
				Chip_ADC_SetStartMode(LPC_ADC0, ADC_START_NOW, ADC_TRIGGERMODE_RISING);
			}

	/*while (Interrupt_Continue_Flag) {
			if (!Burst_Mode_Flag && ADC_Interrupt_Done_Flag) {
				ADC_Interrupt_Done_Flag = 0;
				Chip_ADC_SetStartMode(LPC_ADC0, ADC_START_NOW, ADC_TRIGGERMODE_RISING);
			}

	}*/

	while(Chip_ADC_ReadStatus(LPC_ADC0, ADC_CH1, ADC_DR_DONE_STAT)== RESET){};
	//ADC_DR_DONE_STAT = 0;
}

void Leer_valor_adc(void)
{
	Chip_ADC_ReadValue(LPC_ADC0, ADC_CH1, &adc_value);
	//Chip_ADC_ReadByte(LPC_ADC0, ADC_CH1, adc_value);

}

/*void interrupcionADC0(void)
{
	uint16_t dataADC;
	/* Interrupt mode: Call the stream interrupt handler
	NVIC_DisableIRQ(_LPC_ADC_IRQ);
	Chip_ADC_Int_SetChannelCmd(LPC_ADC0, ADC_CH1, DISABLE);
	Chip_ADC_ReadValue(LPC_ADC0, ADC_CH1, &dataADC);
	ADC_Interrupt_Done_Flag = 1;
	App_print_ADC_value(dataADC);

	if (DEBUGIN() != 'x') {
		NVIC_EnableIRQ(_LPC_ADC_IRQ);
		Chip_ADC_Int_SetChannelCmd(LPC_ADC0, ADC_CH1, ENABLE);
	}
	else {Interrupt_Continue_Flag = 0; }
}*/

/*

// Polling routine for ADC example
static void App_Polling_Test(void)
{
	uint16_t dataADC;

	// Select using burst mode or not
	if (Burst_Mode_Flag) {
		Chip_ADC_SetBurstCmd(_LPC_ADC_ID, ENABLE);
	}
	else {
		Chip_ADC_SetBurstCmd(_LPC_ADC_ID, DISABLE);
	}

	// Get  adc value until get 'x' character
	while (DEBUGIN() != 'x') {
		// Start A/D conversion if not using burst mode
		if (!Burst_Mode_Flag) {
			Chip_ADC_SetStartMode(_LPC_ADC_ID, ADC_START_NOW, ADC_TRIGGERMODE_RISING);
		}
		// Waiting for A/D conversion complete
		while (Chip_ADC_ReadStatus(_LPC_ADC_ID, _ADC_CHANNLE, ADC_DR_DONE_STAT) != SET) {}
		/* Read ADC value
		Chip_ADC_ReadValue(_LPC_ADC_ID, _ADC_CHANNLE, &dataADC);
		/* Print ADC value
		App_print_ADC_value(dataADC);
	}

	/* Disable burst mode, if any
	if (Burst_Mode_Flag) {
		Chip_ADC_SetBurstCmd(_LPC_ADC_ID, DISABLE);
	}
}
}*/


