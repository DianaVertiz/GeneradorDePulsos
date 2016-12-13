/*
 * menu.c
 *
 *  Created on: 6/12/2016
 *      Author: je_su
 */
#include "menu.h"
#include "GPIO.h"
#include "math.h"

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

uint16_t GuardarDato(uint8_t* variable, uint8_t tamanio)
{
	uint8_t i,j;
	uint16_t aux=0;
	uint16_t aux2=0;
	dato_guardado=0;
	uint8_t flag=0;


	for(j=0; j<tamanio; j++)
	{
		if(variable[j]==15)
		{
			aux2++;
			flag=1;
		}
	}

	if(flag==1)
	{
		for(i=tamanio; i>0; i--)
			{
				if(variable[i-1]!=15)
					{
						aux = variable[i-1]*(pow(10,((i-1)-aux2)));
						dato_guardado=dato_guardado + aux;
					}

			}
	}

	else
	{
		for(i=tamanio; i>0; i--)
		{
			if(variable[i-1]!=15)
				{
				    aux = variable[i-1]*(pow(10,(i-1)));
				    dato_guardado=dato_guardado + aux;
				}

		}
	}

return dato_guardado;


}

void Conf_previa()
{
	//ClearDisplay();
	uint8_t variable=1;
	uint8_t signo=1;//pulsos positivos
	uint8_t tipo=1;//modo corriente
	PosicionarCursor(1,1);
	arrow();
	PosicionarCursor(2,1);
	printf_lcd("pulsos positivos");
	PosicionarCursor(2,2);
	printf_lcd("pulsos en mA    ");

	while(!(variable==3))
	{
		if(!(pulsado(BtnDown)))
		{
			variable++;
		}

		if(variable==1 && !(pulsado(BtnEnter)))
		{
			TemporizadorTimer0(500);
			ResetTimer0();
			if(signo==1){signo=0;}
			else if(signo==0){signo=1;}
			PosicionarCursor(2,1);
			if(signo==1) {printf_lcd("pulsos positivos");
							ModificarFlagPoN(1);}
			if(signo==0) {printf_lcd("pulsos negativos");
							ModificarFlagPoN(0);}
		}
		if(variable==2 && !(pulsado(BtnEnter)))
		{
			TemporizadorTimer0(500);
			ResetTimer0();
			if(tipo==1){tipo=0;}
			else if(tipo==0){tipo=1;}
			PosicionarCursor(2,2);
			if(tipo==1) {printf_lcd("pulsos en mA    ");
							ModificarFlagVoI(1);}
			if(tipo==0) {printf_lcd("pulsos en V     ");
							ModificarFlagVoI(0);}
		}

	}


}

void Conf_Pulsos(uint8_t menuPosition)
{
	inicializarPulsadores();
	ClearDisplay();



	PosicionarCursor(1,1);
	printf_lcd(txSUBMENU[menuPosition-1]);
	//PosicionarCursor(1,2);
	//printf_lcd("   pulsos      ");

//-----------------
	PosicionarCursor(1,2);
	Cursor_sinBlink();
	salir2=0;
	dato_pulsos[0] = 15;
	dato_pulsos[1] = 15;

	x=1;


	while(!salir2)
	{

			if(!(pulsado(BtnDown)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();
				x++;
				if(x>2){x=2;}
				unidad=0;
			}

			if(!(pulsado(BtnUp)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();
				lcd_putInt(unidad);
				dato_pulsos[2-x]=unidad;
				unidad++;
				if(unidad>9){unidad=0;}

			}

			if(!(pulsado(BtnEnter)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();
				salir2=1;

			}

		   PosicionarCursor(x,2);



	}


//-------------------

	    x=1;
	    unidad=0;
	    ClearDisplay();
}


void Guardar_Pulsos()
{
	uint8_t dato= GuardarDato(dato_pulsos,2);
	ModificarNumPulsos(dato);

}


void Conf_Amplitud(uint8_t menuPosition)
{
	inicializarPulsadores();
	ClearDisplay();
	//Conf_previa();

	PosicionarCursor(1,1);
	printf_lcd(txSUBMENU[menuPosition-1]);

//-----------------
	PosicionarCursor(1,2);
	Cursor_sinBlink();
	salir2=0;
	dato_amplitud[0] = 15;
	dato_amplitud[1] = 15;
	dato_amplitud[2] = 15;

	x=1;

	while(!salir2)
	{

			if(!(pulsado(BtnDown)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();
				x++;
				if(x>3){x=3;}
				unidad=0;

			}

			if(!(pulsado(BtnUp)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();
				lcd_putInt(unidad);
				dato_amplitud[3-x]=unidad;
				unidad++;
				if(unidad>9){unidad=0;}

			}

			if(!(pulsado(BtnEnter)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();
				salir2=1;

			}

		   PosicionarCursor(x,2);

	}

	//-------------------

		    x=1;
		    unidad=0;
		    ClearDisplay();
}


void Guardar_Amplitud()
{
	uint16_t dato= GuardarDato(dato_amplitud,3);
	uint16_t aux1=0;
	uint16_t aux2=0;
	uint16_t aux3=0;
	uint16_t dat=0;
	aux1=dato*1000/31;//valor entero
	aux2=dato*10000/31;//valor con el decimal
	aux3=aux1*10;
	aux3= aux2-aux3;//decimal
	if(aux3>0){dat= aux1+1;}
	else{dat=aux1;}

	ModificarValueUp(dat);

}


void Conf_Periodo(uint8_t menuPosition)
{
	inicializarPulsadores();
	ClearDisplay();

	PosicionarCursor(1,1);
	printf_lcd(txSUBMENU[menuPosition-1]);

	//-----------------
	PosicionarCursor(1,2);
	Cursor_sinBlink();
	salir2=0;
	dato_periodo[0] = 15;
	dato_periodo[1] = 15;
	dato_periodo[2] = 15;
	dato_periodo[3] = 15;

		x=1;


	while(!salir2)
	{

			if(!(pulsado(BtnDown)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();
				x++;
				if(x>4){x=4;}
				unidad=0;

			}

			if(!(pulsado(BtnUp)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();
				lcd_putInt(unidad);
				dato_periodo[4-x]=unidad;
				unidad++;
				if(unidad>9){unidad=0;}

			}

			if(!(pulsado(BtnEnter)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();
				salir2=1;

			}

		   PosicionarCursor(x,2);

	}


	//-------------------

	    x=1;
	    unidad=0;
	    ClearDisplay();
}

void Guardar_Periodo()
{
	uint16_t dato= GuardarDato(dato_periodo,4);
	ModificarPeriodo(dato);

}


void Conf_TUp(uint8_t menuPosition)

{
	inicializarPulsadores();
	ClearDisplay();

	PosicionarCursor(1,1);
	printf_lcd(txSUBMENU[menuPosition-1]);

	//-----------------
	PosicionarCursor(1,2);
	Cursor_sinBlink();
	salir2=0;
	dato_talto[0] = 15;
	dato_talto[1] = 15;
	dato_talto[2] = 15;
	dato_talto[3] = 15;

	x=1;


while(!salir2)
{

		if(!(pulsado(BtnDown)))
		{
			TemporizadorTimer0(500);
			ResetTimer0();
			x++;
			if(x>4){x=4;}
			unidad=0;

		}

		if(!(pulsado(BtnUp)))
		{
			TemporizadorTimer0(500);
			ResetTimer0();
			lcd_putInt(unidad);
			dato_talto[4-x]=unidad;
			unidad++;
			if(unidad>9){unidad=0;}

		}

		if(!(pulsado(BtnEnter)))
		{
			TemporizadorTimer0(500);
			ResetTimer0();
			salir2=1;

		}

	   PosicionarCursor(x,2);

}


//-------------------

    x=1;
    unidad=0;
    ClearDisplay();


}

void Guardar_TUp()
{
	uint16_t dato= GuardarDato(dato_talto,4);
	ModificarTimeUp(dato);

}






void OpenMenu()
{
	inicializarPulsadores();
	uint8_t i;
	uint8_t aux=0;
	dato_guardado=0;
	flag1=0;
	flag2=0;
	flag3=0;
	flag4=0;


	ClearDisplay();

	while(!salir)
	{
		//key1=ReadPulsador();

		if(!(pulsado(BtnUp)) && menuPosition-1 > 0)
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				menuPosition--;

			}
		else if(!(pulsado(BtnDown)) && menuPosition < iMENU)
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				menuPosition++;
			}

		else if(!(pulsado(BtnEnter)))
			{
			TemporizadorTimer0(300);
			ResetTimer0();

			switch(menuPosition)
			     {
			         case 1: Conf_Pulsos(menuPosition);
			         	 	 flag1=1; break;
			         case 2: Conf_Amplitud(menuPosition);
			         	 	 flag2=1; break;
			         case 3: Conf_TUp(menuPosition);
			         	 	 flag3=1; break;
			         case 4: Conf_Periodo(menuPosition);
			         	 	 flag4=1; break;
			         case 5:
			        	 if(flag1==1)
			        	 { Guardar_Pulsos();}
			        	 if(flag2==1)
			        	 { Guardar_Amplitud();}
			        	 if(flag3==1)
			        	 { Guardar_TUp();}
			        	 if(flag4==1)
			        	 { Guardar_Periodo();}
			        	 ClearDisplay();

			        	 	 salir = 1;
			         	 	 DesactivarCursor();
			         	 	 break; //Salir y guardar
			         case 6: salir = 1;
			         	 	 DesactivarCursor();
			         	 	 break; //Salir y cancelar cambios
			     }
		}

		if(!salir)
		{
			if(menuPosition==1||menuPosition==2)
				{
					PosicionarCursor(2, 1);
					printf_lcd(txMENU[0]);
					PosicionarCursor(2, 2);
					printf_lcd(txMENU[1]);
					if(menuPosition==1)
						{
							PosicionarCursor(1,1);
							arrow();
							//printf_lcd("-");
							PosicionarCursor(1,2);
							printf_lcd(" ");


						}
					if(menuPosition==2)
						{
							PosicionarCursor(1,1);
							printf_lcd(" ");
							PosicionarCursor(1,2);
							arrow();
							//printf_lcd("-");

						}
				}
			if(menuPosition==3||menuPosition==4)
				{
					PosicionarCursor(2, 1);
					printf_lcd(txMENU[2]);
					PosicionarCursor(2, 2);
					printf_lcd(txMENU[3]);
					if(menuPosition==3)
						{
							PosicionarCursor(1,1);
							arrow();
							//printf_lcd("-");
							PosicionarCursor(1,2);
							printf_lcd(" ");
						}
					if(menuPosition==4)
						{
							PosicionarCursor(1,1);
							printf_lcd(" ");
							PosicionarCursor(1,2);
							arrow();
							//printf_lcd("-");
						}


				}
			if(menuPosition==5||menuPosition==6)
				{
					PosicionarCursor(2, 1);
					printf_lcd(txMENU[4]);
					PosicionarCursor(2, 2);
					printf_lcd(txMENU[5]);
					if(menuPosition==5)
						{
							PosicionarCursor(1,1);
							arrow();
							//printf_lcd("-");
							PosicionarCursor(1,2);
							printf_lcd(" ");
						}
					if(menuPosition==6)
						{
							PosicionarCursor(1,1);
							printf_lcd(" ");
							PosicionarCursor(1,2);
							arrow();
							//printf_lcd("-");
						}
				}


		}

	}

	salir=0;
	menuPosition = 1;
	ClearDisplay();
}

