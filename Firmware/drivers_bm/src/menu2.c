/*
 * menu2.c
 *
 *  Created on: 26/2/2017
 *      Author: je_su
 */

#include "menu2.h"
#include "GPIO.h"
#include "math.h"

void OpenMenu2()
{
	inicializarPulsadores();
	uint8_t i;
	uint8_t signo=1;
	uint8_t tipo=1;
	uint8_t aux=0;
	dato_guardado=0;
	flag1=0;
	flag2=0;
	flag3=0;
	flag4=0;


	ClearDisplay();

	while(!salir)
	{

		if(!(pulsado(BtnLeft)))
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				if(menuPosition-1> 0)
				{ menuPosition--;}
				else
				{ menuPosition=6;}

			}
		else if(!(pulsado(BtnRight)))
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				if(menuPosition <iMENU)
				{ menuPosition++;}
				else
				{ menuPosition=1;}

			}
		else if(!pulsado(BtnEnter))
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				salir=1;
			}

		else if(! (pulsado(BtnUp)) || !(pulsado(BtnDown)) )
		{
			TemporizadorTimer0(20);
			ResetTimer0();

			switch(menuPosition)
			     {
			         case 1: Conf_Amplitud2();
			         	 	 flag1=1; break;
			         case 2: Conf_Pulsos2();
			        	  	 flag2=1; break;
			         case 3: Conf_TUp2();
			         	 	 flag3=1; break;
			         case 4: Conf_Periodo2();
			         	 	 flag4=1; break;
			         case 5: ModoEstimulacion();
			         	 	 break;
			         case 6: Polaridad();
			         	 	 break;

			     }
		}

		if(!salir)
		{

			if(menuPosition==1)
				{
					uint16_t value, value_aux;
					value=DevolverValueUp();
					PosicionarCursor(1,1);
					printf_lcd("Amplitud:       ");
					PosicionarCursor(1,2);

					if(DevolverFlagPoN()==1)
					{
						if(DevolverFlagVoI()==1)
						{
							value_aux=(value*31)/1000;
						}
						if(DevolverFlagVoI()==0)
						{
							value_aux=(value*62)/1000;
						}
					}
					if(DevolverFlagPoN()==0)
					{

						if(DevolverFlagVoI()==1)
						{
							value_aux=(value*31)/1000;
						}
						if(DevolverFlagVoI()==0)
						{
							value_aux=(value*62)/1000;
						}
						printf_lcd("-");
					}

					lcd_putInt(value_aux);

					if(DevolverFlagVoI()==1)
						{
							printf_lcd(" mA             ");
						}
					if(DevolverFlagVoI()==0)
						{
							printf_lcd(" V              ");
						}


				}


			if(menuPosition==2)
				{
					PosicionarCursor(1, 1);
					printf_lcd("Nro de pulsos:  ");
					PosicionarCursor(1,2);
					lcd_putInt(DevolverNumPulsos());
					printf_lcd("                ");


				}



			if(menuPosition==3)
				{
					PosicionarCursor(1, 1);
					printf_lcd("Tiempo en alto: ");
					PosicionarCursor(1,2);
					lcd_putInt(DevolverTimeUp());
					printf_lcd(" ms             ");

				}
			if(menuPosition==4)
				{
					PosicionarCursor(1,1);
					printf_lcd("Periodo:        ");
					PosicionarCursor(1,2);
					lcd_putInt(DevolverPeriodo());
					printf_lcd(" ms             ");
				}

			if(menuPosition ==5)
			{
				if(DevolverFlagVoI()==1)
				{	tipo=1;
					PosicionarCursor(1,1);
					arrow();
					PosicionarCursor(2,1);
					printf_lcd("Pulsos en mA    ");
					PosicionarCursor(1,2);
					printf_lcd(" ");
					PosicionarCursor(2,2);
					printf_lcd("Pulsos en V     ");

				}
				else
				{
					tipo=0;
					PosicionarCursor(1,1);
					arrow();
					PosicionarCursor(2,1);
					printf_lcd("Pulsos en V     ");
					PosicionarCursor(1,2);
					printf_lcd(" ");
					PosicionarCursor(2,2);
					printf_lcd("Pulsos en mA    ");

				}

			}

			if(menuPosition==6)
			{
				if(DevolverFlagPoN()==1)
					{	signo=1;
						PosicionarCursor(1,1);
						arrow();
						PosicionarCursor(2,1);
						printf_lcd("P. positivos    ");
						PosicionarCursor(1,2);
						printf_lcd(" ");
						PosicionarCursor(2,2);
						printf_lcd("P. Negativos    ");

					}
					else
					{
						signo=0;
						PosicionarCursor(1,1);
						arrow();
						PosicionarCursor(2,1);
						printf_lcd("P. Negativos    ");
						PosicionarCursor(1,2);
						printf_lcd(" ");
						PosicionarCursor(2,2);
						printf_lcd("P. positivos    ");

					}
			}





		}

	}

	salir=0;
	menuPosition = 1;
	ClearDisplay();
}


Conf_Amplitud2()
{
	uint16_t value, value_aux;
	value=DevolverValueUp();

	uint32_t aux1=0;
	uint32_t aux2=0;
	uint16_t dat=0;
	uint8_t exit=0;

	PosicionarCursor(1,2);


	if(DevolverFlagPoN()==1)
	{
		if(DevolverFlagVoI()==1)
		{
			value_aux=(value*31)/1000;
		}
		if(DevolverFlagVoI()==0)
		{
			value_aux=(value*62)/1000;
		}
	}
	if(DevolverFlagPoN()==0)
	{

		if(DevolverFlagVoI()==1)
		{
			value_aux=(value*31)/1000;
		}
		if(DevolverFlagVoI()==0)
		{
			value_aux=(value*62)/1000;
		}
		printf_lcd("-");
	}

	lcd_putInt(value_aux);

	if(DevolverFlagVoI()==1)
		{
			printf_lcd(" mA             ");
		}
	if(DevolverFlagVoI()==0)
		{
			printf_lcd(" V              ");
		}


	while(!exit)
	{
		if(!(pulsado(BtnUp)))
		{
			TemporizadorTimer0(300);
			ResetTimer0();
			value_aux++;
			if(DevolverFlagVoI()==1 && value_aux>85)
			{
				value_aux=1;
			}
			if(DevolverFlagVoI()==0 && value_aux>170)
			{
				value_aux=1;
			}
		}


		if(!(pulsado(BtnDown)))
		{
			TemporizadorTimer0(300);
			ResetTimer0();

			if(DevolverFlagVoI()==1 && value_aux==1)
			{
				value_aux=86; //después se le resta 1
			}
			if(DevolverFlagVoI()==0 && value_aux==1)
			{
				value_aux=171;
			}
			value_aux--;
		}


		if(!(pulsado(BtnLeft)))
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				if(menuPosition-1> 0)
				{ menuPosition--;}
				else
				{ menuPosition=6;}
				exit=1;

			}
		else if(!(pulsado(BtnRight)))
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				if(menuPosition <iMENU)
				{ menuPosition++;}
				else
				{ menuPosition=1;}
				exit=1;
			}

		if(!(pulsado(BtnEnter)))
		{
			TemporizadorTimer0(300);
			ResetTimer0();
			exit=1;
			salir=1;
			//salir_menu=1;
		}

		PosicionarCursor(1,2);

		lcd_putInt(value_aux);


		if(DevolverFlagVoI()==1)
				{
					printf_lcd(" mA             ");
				}
			if(DevolverFlagVoI()==0)
				{
					printf_lcd(" V              ");
				}


	}

//---------------------------------------------------------------------
	if(DevolverFlagVoI()==1)
		{
			// For upper value of x/y, use this ( x + y - 1 ) / y

			if(value_aux>= 85)	{value_aux=85;}
			aux1=value_aux*1000; //value x
			aux2= aux1 + 31; //x+y
			dat= (aux2-1)/31;
		}
		if(DevolverFlagVoI()==0)
		{
			if(value_aux>= 170)	{value_aux=170;}
			aux1=value_aux*1000; //value x
			aux2= aux1 + 62; //x+y
			dat=(aux2-1)/62;

		}
//------------------------------------------------------------------

	ModificarValueUp(dat);

	ClearDisplay();


}

Conf_Pulsos2()
{
	uint16_t puls, puls_aux;
		puls=DevolverNumPulsos();
		puls_aux=puls;

		uint8_t exit=0;

		PosicionarCursor(1,2);


		lcd_putInt(puls);
		printf_lcd("                ");



		while(!exit)
		{
			if(!(pulsado(BtnUp)))
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				puls_aux++;
				if(puls_aux>100)
				{
					puls_aux=1;
				}

			}


			if(!(pulsado(BtnDown)))
			{
				TemporizadorTimer0(300);
				ResetTimer0();

				if(puls_aux==1)
				{
					puls_aux=101; //después se le resta 1
				}

				puls_aux--;
			}

			if(!(pulsado(BtnLeft)))
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				if(menuPosition-1> 0)
				{ menuPosition--;}
				else
				{ menuPosition=6;}
				exit=1;

			}
		else if(!(pulsado(BtnRight)))
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				if(menuPosition <iMENU)
				{ menuPosition++;}
				else
				{ menuPosition=1;}
				exit=1;
			}

			if(!(pulsado(BtnEnter)))
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				exit=1;
				salir=1;
			}

			PosicionarCursor(1,2);

			lcd_putInt(puls_aux);

			printf_lcd("    ");



		}


		ModificarNumPulsos(puls_aux);

		ClearDisplay();

	}

Conf_TUp2()
{
			uint16_t tup, tup_aux;
			tup=DevolverTimeUp();
			tup_aux=tup;

			uint8_t exit=0;

			PosicionarCursor(1,2);


			lcd_putInt(tup);
			printf_lcd(" ms             ");



			while(!exit)
			{
				if(!(pulsado(BtnUp)))
				{
					TemporizadorTimer0(300);
					ResetTimer0();
					tup_aux++;
					if(tup_aux>9999)
					{
						tup_aux=1;
					}

				}


				if(!(pulsado(BtnDown)))
				{
					TemporizadorTimer0(300);
					ResetTimer0();

					if(tup_aux==1)
					{
						tup_aux=10000; //después se le resta 1
					}

					tup_aux--;

				}

				if(!(pulsado(BtnLeft)))
				{
					TemporizadorTimer0(300);
					ResetTimer0();
					if(menuPosition-1> 0)
					{ menuPosition--;}
					else
					{ menuPosition=6;}
					exit=1;

				}
			else if(!(pulsado(BtnRight)))
				{
					TemporizadorTimer0(300);
					ResetTimer0();
					if(menuPosition <iMENU)
					{ menuPosition++;}
					else
					{ menuPosition=1;}
					exit=1;
				}

				if(!(pulsado(BtnEnter)))
				{
					TemporizadorTimer0(300);
					ResetTimer0();
					exit=1;
					salir=1;
				}

				PosicionarCursor(1,2);

				lcd_putInt(tup_aux);

				printf_lcd(" ms             ");



			}


			ModificarTimeUp(tup_aux);
			if( DevolverTimeUp()==DevolverPeriodo() || DevolverPeriodo()< DevolverTimeUp() )
			{ ModificarPeriodo(DevolverTimeUp()+1);}

			ClearDisplay();
}

Conf_Periodo2()
{
	uint16_t P, P_aux;
	P=DevolverPeriodo();
	P_aux=P;

	uint8_t exit=0;

	PosicionarCursor(1,2);


	lcd_putInt(P);
	printf_lcd(" ms             ");



	while(!exit)
	{
	if(!(pulsado(BtnUp)))
	{
		TemporizadorTimer0(300);
		ResetTimer0();
		P_aux++;
		if(P_aux>9999)
		{
			P_aux=1;
		}

	}


	if(!(pulsado(BtnDown)))
	{
		TemporizadorTimer0(300);
		ResetTimer0();

		if(P_aux==1)
		{
			P_aux=10000; //después se le resta 1
		}

		P_aux--;


	}


	if(!(pulsado(BtnLeft)))
	{
		TemporizadorTimer0(300);
		ResetTimer0();
		if(menuPosition-1> 0)
		{ menuPosition--;}
		else
		{ menuPosition=6;}
		exit=1;

	}
	else if(!(pulsado(BtnRight)))
	{
		TemporizadorTimer0(300);
		ResetTimer0();
		if(menuPosition <iMENU)
		{ menuPosition++;}
		else
		{ menuPosition=1;}
		exit=1;
	}

	if(!(pulsado(BtnEnter)))
	{
		TemporizadorTimer0(300);
		ResetTimer0();
		exit=1;
		salir=1;
	}

	PosicionarCursor(1,2);

	lcd_putInt(P_aux);
	if( DevolverTimeUp()==DevolverPeriodo() || DevolverPeriodo()< DevolverTimeUp() )
	{ P_aux = DevolverTimeUp()+1;}

	printf_lcd(" ms             ");



	}


	ModificarPeriodo(P_aux);
	if( DevolverTimeUp()==DevolverPeriodo() || DevolverPeriodo()< DevolverTimeUp() )
	{ ModificarPeriodo(DevolverTimeUp()+1);}

	ClearDisplay();
}


void Polaridad()
{

	uint8_t variable=1;
	uint8_t signo=1;//pulsos positivos
	uint8_t exit=0;


	if(DevolverFlagPoN()==1)
	{
		signo=1;
	}
	else
	{
		signo=0;
	}


	while(!exit)
		{
			if(!(pulsado(BtnDown)))
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				if(variable==2){variable=1;}
				variable++;

			}
			if(!(pulsado(BtnUp)))
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				if(variable==2)
				{variable--;}
			}

			if(!(pulsado(BtnLeft)))
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				if(menuPosition-1> 0)
				{ menuPosition--;}
				else
				{ menuPosition=6;}
				exit=1;

			}
			else if(!(pulsado(BtnRight)))
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				if(menuPosition <iMENU)
				{ menuPosition++;}
				else
				{ menuPosition=1;}
				exit=1;
			}

			if(!(pulsado(BtnEnter)))
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				exit=1;
				salir=1;
			}


			if(variable==1)
			{
				//TemporizadorTimer0(500);
				//ResetTimer0();


				PosicionarCursor(2,1);
				if(signo==1) {//printf_lcd("P. Positivos    ");
								ModificarFlagPoN(1);
								PulsosPositivos();
							  }
				if(signo==0) {//printf_lcd("P. Negativos    ");
								ModificarFlagPoN(0);
								PulsosNegativos();
							 }

			}

			if(variable==2)
			{
				//TemporizadorTimer0(500);
				//ResetTimer0();


				PosicionarCursor(2,2);
				if(signo==1) {//printf_lcd("P. Negativos    ");
								ModificarFlagPoN(0);
								PulsosNegativos();
							 }
				if(signo==0) {
								//printf_lcd("P. Positivos    ");
								ModificarFlagPoN(1);
								PulsosPositivos();
							 }

			}


			if(variable==1)
			{
				PosicionarCursor(1,1);
				arrow();
				PosicionarCursor(1,2);
				printf_lcd(" ");
			}


			if(variable==2)
			{
				PosicionarCursor(1,1);
				printf_lcd(" ");
				PosicionarCursor(1,2);
				arrow();
			}

		}


}


void ModoEstimulacion()
{

	uint8_t variable=1;
	uint8_t tipo=1;//modo corriente
	uint8_t exit=0;
	uint32_t aux1=0;
	uint32_t aux2=0;
	uint16_t dat=0;


//---------------------------------------------------------
	uint16_t value, value_aux;
	value=DevolverValueUp();


	if(DevolverFlagVoI()==1)
	{
		value_aux=(value*31)/1000;
		tipo=1;
	}
	if(DevolverFlagVoI()==0)
	{
		value_aux=(value*62)/1000;
		tipo=0;
	}








/*
		if(DevolverFlagVoI()==1)
		{
			tipo=1;
		}
		else
		{
			tipo=0;
		}
*/

		while(!exit)
			{
				if(!(pulsado(BtnDown)))
				{
					TemporizadorTimer0(300);
					ResetTimer0();
					if(variable==2){variable=1;}
					variable++;

				}
				if(!(pulsado(BtnUp)))
				{
					TemporizadorTimer0(300);
					ResetTimer0();
					if(variable==2)
					{variable--;}
				}
				if(!(pulsado(BtnLeft)))
				{
					TemporizadorTimer0(300);
					ResetTimer0();
					if(menuPosition-1> 0)
					{ menuPosition--;}
					else
					{ menuPosition=6;}
					exit=1;

				}
				else if(!(pulsado(BtnRight)))
				{
					TemporizadorTimer0(300);
					ResetTimer0();
					if(menuPosition <iMENU)
					{ menuPosition++;}
					else
					{ menuPosition=1;}
					exit=1;
				}

				if(!(pulsado(BtnEnter)))
				{
					TemporizadorTimer0(300);
					ResetTimer0();
					exit=1;
					salir=1;
				}


				if(variable==1)
				{
					//TemporizadorTimer0(300);
					//ResetTimer0();


					PosicionarCursor(2,1);
					if(tipo==1) {
									ModificarFlagVoI(1);

								  }
					if(tipo==0) {
									ModificarFlagVoI(0);

								 }

				}

				if(variable==2)
				{


					PosicionarCursor(2,2);
					if(tipo==1) {
									ModificarFlagVoI(0);
									//ModificarValueUp(dat);

								 }
					if(tipo==0) {
									ModificarFlagVoI(1);
									//ModificarValueUp(dat);

								 }

				}


				if(variable==1)
				{
					PosicionarCursor(1,1);
					arrow();
					PosicionarCursor(1,2);
					printf_lcd(" ");
				}


				if(variable==2)
				{
					PosicionarCursor(1,1);
					printf_lcd(" ");
					PosicionarCursor(1,2);
					arrow();
				}

			}


		if(DevolverFlagVoI()==1)
			{
						// For upper value of x/y, use this ( x + y - 1 ) / y

				if(value_aux>= 85)	{value_aux=85;}
				aux1=value_aux*1000; //value x
				aux2= aux1 + 31; //x+y
				dat= (aux2-1)/31;
			}
			if(DevolverFlagVoI()==0)
			{
				if(value_aux>= 170)	{value_aux=170;}
				aux1=value_aux*1000; //value x
				aux2= aux1 + 62; //x+y
				dat=(aux2-1)/62;

			}
			ModificarValueUp(dat);

}


