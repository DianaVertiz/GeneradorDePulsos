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
#include "lcd_r.h"
#include "puertos_lcd_r.h"




#elif (mk60fx512vlq15 == CPU)
#else
#endif

/*
uint16_t GuardarDato(uint8_t* variable, uint8_t tamanio, uint16_t var)
{
	uint8_t i,j;
	uint16_t aux=0;
	uint16_t aux2=0;
	dato_guardado=0;
	uint8_t flag=0;


	for(j=0; j<tamanio; j++)
	{
		if(variable[j]==15) //cuento las veces que aparece 15 (sin valor)  en el vector variable con aux2
		{
			aux2++;
			flag=1;
			//Si aux2 == a tamanio, entonces no se ingresó valor
		}
	}

	if(flag==1)
	{

		if(aux2 !=tamanio)
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
			dato_guardado=var;
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

	PosicionarCursor(2,1);
	if(DevolverFlagPoN()==1)
	{	signo=1;

		printf_lcd("P. positivos    ");

	}
	else
	{
		signo=0;
		printf_lcd("P. Negativos    ");
	}

	PosicionarCursor(2,2);
	if(DevolverFlagVoI()==1)
	{	tipo=1;
		printf_lcd("Pulsos en mA    ");
	}
	else
	{
		tipo=0;
		printf_lcd("Pulsos en V     ");
	}


	while(!(variable==3))
	{
		if(!(pulsado(BtnDown)))
		{
			TemporizadorTimer0(500);
			ResetTimer0();
			variable++;
		}
		if(!(pulsado(BtnUp)))
		{
			TemporizadorTimer0(500);
			ResetTimer0();
			if(variable==2)
			{variable--;}
		}


		if(variable==1 && !(pulsado(BtnEnter)))
		{
			TemporizadorTimer0(500);
			ResetTimer0();

			if(signo==1){signo=0;}
			else if(signo==0){signo=1;}
			PosicionarCursor(2,1);
			if(signo==1) {printf_lcd("P. Positivos    ");
							ModificarFlagPoN(1);
							PulsosPositivos();
						  }
			if(signo==0) {printf_lcd("P. Negativos    ");
							ModificarFlagPoN(0);
							PulsosNegativos();
						 }

		}

		if(variable==2 && !(pulsado(BtnEnter)))
		{
			TemporizadorTimer0(500);
			ResetTimer0();

			if(tipo==1){tipo=0;}
			else if(tipo==0){tipo=1;}
			PosicionarCursor(2,2);
			if(tipo==1) {printf_lcd("Pulsos en mA    ");
							ModificarFlagVoI(1);}
			if(tipo==0) {printf_lcd("Pulsos en V     ");
							ModificarFlagVoI(0);}
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
	unidad1=0;
	unidad2=0;

	while(!salir2)
	{

			if(!(pulsado(BtnRight)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();
				x++;
				if(x>2){x=2;}

			}

			if(!(pulsado(BtnLeft)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();
				x--;
				if(x<1){x=1;}

			}


			if(!(pulsado(BtnUp)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();

				switch(x)
				{
				case 1: lcd_putInt(unidad1);
						if(unidad1>9){unidad1=0;}
						dato_pulsos[2-x]=unidad1;
						//unidad=unidad1;
						unidad1++;
						if(unidad1>9){unidad1=0;}
						//unidad1=unidad;
						break;
				case 2: lcd_putInt(unidad2);
						if(unidad2>9){unidad2=0;}
						dato_pulsos[2-x]=unidad2;

						unidad2++;
						if(unidad2>9){unidad2=0;}
						//unidad2=unidad;
						break;
				}

			}

			if(!(pulsado(BtnDown)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();

				switch(x)
				{
				case 1: if(unidad1==0)
						{unidad1=9;}
						else
						{unidad1--;}
						lcd_putInt(unidad1);
						dato_pulsos[2-x]=unidad1;
						break;
				case 2: if(unidad2==0)
						{unidad2=9;}
						else
						{unidad2--;}
						lcd_putInt(unidad2);
						dato_pulsos[2-x]=unidad2;
						break;
				}

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
	    DesactivarCursor();
	    ClearDisplay();
}


void Guardar_Pulsos()
{
	uint8_t dato= GuardarDato(dato_pulsos,2, DevolverNumPulsos());
	ModificarNumPulsos(dato);
}


void Conf_Amplitud(uint8_t menuPosition)
{
	inicializarPulsadores();
	ClearDisplay();
	Conf_previa();
	ClearDisplay();

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
	unidad1=0;
	unidad2=0;
	unidad3=0;

	while(!salir2)
	{


			if(!(pulsado(BtnRight)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();
				x++;
				if(x>3){x=3;}

			}

			if(!(pulsado(BtnLeft)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();
				x--;
				if(x<1){x=1;}

			}

			if(!(pulsado(BtnUp)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();

				switch(x)
				{
				case 1: lcd_putInt(unidad1);
						if(unidad1>9){unidad1=0;}
						dato_amplitud[3-x]=unidad1;
						//unidad=unidad1;
						unidad1++;
						if(unidad1>9){unidad1=0;}
						//unidad1=unidad;
						break;
				case 2: lcd_putInt(unidad2);
						if(unidad2>9){unidad2=0;}
						dato_amplitud[3-x]=unidad2;

						unidad2++;
						if(unidad2>9){unidad2=0;}
						//unidad2=unidad;
						break;
				case 3: lcd_putInt(unidad3);
						if(unidad3>9){unidad3=0;}
						dato_amplitud[3-x]=unidad3;

						unidad3++;
						if(unidad3>9){unidad3=0;}
						//unidad2=unidad;
						break;


				}

			}

			if(!(pulsado(BtnDown)))
			{
				TemporizadorTimer0(500);
				ResetTimer0();

				switch(x)
				{
				case 1: if(unidad1==0)
						{unidad1=9;}
						else
						{unidad1--;}
						lcd_putInt(unidad1);
						dato_amplitud[3-x]=unidad1;
						break;
				case 2: if(unidad2==0)
						{unidad2=9;}
						else
						{unidad2--;}
						lcd_putInt(unidad2);
						dato_amplitud[3-x]=unidad2;
						break;
				case 3: if(unidad3==0)
						{unidad3=9;}
						else
						{unidad3--;}
						lcd_putInt(unidad3);
						dato_amplitud[3-x]=unidad3;
						break;
				}

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
		    DesactivarCursor();
		    ClearDisplay();
}


void Guardar_Amplitud()
{
	uint16_t amp=0;
	if(DevolverFlagVoI()==1)
	{
		amp= (DevolverValueUp()*31)/1000;
	}
	if(DevolverFlagVoI()==0)
	{
		amp= (DevolverValueUp()*62)/1000;
	}

	uint16_t dato= GuardarDato(dato_amplitud,3,amp);
	uint32_t aux1=0;
	uint32_t aux2=0;
	uint16_t dat=0;
	if(DevolverFlagVoI()==1)
	{
		// For upper value of x/y, use this ( x + y - 1 ) / y
		if(dato>= 100)	{dato=100;}
		aux1=dato*1000; //value x
		aux2= aux1 + 31; //x+y
		dat= (aux2-1)/31;

	}
	if(DevolverFlagVoI()==0)
	{
		if(dato>= 200)	{dato=200;}
		aux1=dato*1000; //value x
		aux2= aux1 + 62; //x+y
		dat=(aux2-1)/62;
	}

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
	unidad1=0;
	unidad2=0;
	unidad3=0;
	unidad4=0;

	while(!salir2)
	{

		if(!(pulsado(BtnRight)))
		{
			TemporizadorTimer0(500);
			ResetTimer0();
			x++;
			if(x>4){x=4;}

		}

		if(!(pulsado(BtnLeft)))
		{
			TemporizadorTimer0(500);
			ResetTimer0();
			x--;
			if(x<1){x=1;}

		}

		if(!(pulsado(BtnUp)))
		{
			TemporizadorTimer0(500);
			ResetTimer0();

			switch(x)
			{
			case 1: lcd_putInt(unidad1);
					if(unidad1>9){unidad1=0;}
					dato_periodo[4-x]=unidad1;
					unidad1++;
					if(unidad1>9){unidad1=0;}
					break;
			case 2: lcd_putInt(unidad2);
					if(unidad2>9){unidad2=0;}
					dato_periodo[4-x]=unidad2;
					unidad2++;
					if(unidad2>9){unidad2=0;}
					break;
			case 3: lcd_putInt(unidad3);
					if(unidad3>9){unidad3=0;}
					dato_periodo[4-x]=unidad3;
					unidad3++;
					if(unidad3>9){unidad3=0;}
					break;
			case 4: lcd_putInt(unidad4);
					if(unidad4>9){unidad4=0;}
					dato_periodo[4-x]=unidad4;
					unidad4++;
					if(unidad4>9){unidad4=0;}
					break;

			}

		}

		if(!(pulsado(BtnDown)))
		{
			TemporizadorTimer0(500);
			ResetTimer0();

			switch(x)
			{
			case 1: if(unidad1==0)
					{unidad1=9;}
					else
					{unidad1--;}
					lcd_putInt(unidad1);
					dato_periodo[4-x]=unidad1;
					break;
			case 2: if(unidad2==0)
					{unidad2=9;}
					else
					{unidad2--;}
					lcd_putInt(unidad2);
					dato_periodo[4-x]=unidad2;
					break;
			case 3: if(unidad3==0)
					{unidad3=9;}
					else
					{unidad3--;}
					lcd_putInt(unidad3);
					dato_periodo[4-x]=unidad3;
					break;
			case 4: if(unidad4==0)
					{unidad4=9;}
					else
					{unidad4--;}
					lcd_putInt(unidad4);
					dato_periodo[4-x]=unidad4;
					break;
			}

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
	    DesactivarCursor();
	    ClearDisplay();
}

void Guardar_Periodo()
{
	uint16_t dato= GuardarDato(dato_periodo,4,DevolverPeriodo());
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
	unidad1=0;
	unidad2=0;
	unidad3=0;
	unidad4=0;


while(!salir2)
{

	if(!(pulsado(BtnRight)))
	{
		TemporizadorTimer0(500);
		ResetTimer0();
		x++;
		if(x>4){x=4;}

	}

	if(!(pulsado(BtnLeft)))
	{
		TemporizadorTimer0(500);
		ResetTimer0();
		x--;
		if(x<1){x=1;}

	}

	if(!(pulsado(BtnUp)))
	{
		TemporizadorTimer0(500);
		ResetTimer0();

		switch(x)
		{
		case 1: lcd_putInt(unidad1);
				if(unidad1>9){unidad1=0;}
				dato_talto[4-x]=unidad1;
				unidad1++;
				if(unidad1>9){unidad1=0;}
				break;
		case 2: lcd_putInt(unidad2);
				if(unidad2>9){unidad2=0;}
				dato_talto[4-x]=unidad2;
				unidad2++;
				if(unidad2>9){unidad2=0;}
				break;
		case 3: lcd_putInt(unidad3);
				if(unidad3>9){unidad3=0;}
				dato_talto[4-x]=unidad3;
				unidad3++;
				if(unidad3>9){unidad3=0;}
				break;
		case 4: lcd_putInt(unidad4);
				if(unidad4>9){unidad4=0;}
				dato_talto[4-x]=unidad4;
				unidad4++;
				if(unidad4>9){unidad4=0;}
				break;

		}

	}

	if(!(pulsado(BtnDown)))
	{
		TemporizadorTimer0(500);
		ResetTimer0();

		switch(x)
		{
		case 1: if(unidad1==0)
				{unidad1=9;}
				else
				{unidad1--;}
				lcd_putInt(unidad1);
				dato_talto[4-x]=unidad1;
				break;
		case 2: if(unidad2==0)
				{unidad2=9;}
				else
				{unidad2--;}
				lcd_putInt(unidad2);
				dato_talto[4-x]=unidad2;
				break;
		case 3: if(unidad3==0)
				{unidad3=9;}
				else
				{unidad3--;}
				lcd_putInt(unidad3);
				dato_talto[4-x]=unidad3;
				break;
		case 4: if(unidad4==0)
				{unidad4=9;}
				else
				{unidad4--;}
				lcd_putInt(unidad4);
				dato_talto[4-x]=unidad4;
				break;
		}

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
    DesactivarCursor();
    ClearDisplay();


}

void Guardar_TUp()
{
	uint16_t dato= GuardarDato(dato_talto,4, DevolverTimeUp());
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

		if(!(pulsado(BtnUp)))
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				if(menuPosition-1> 0)
				{ menuPosition--;}
				else
				{ menuPosition=6;}

			}
		else if(!(pulsado(BtnDown)) )
			{
				TemporizadorTimer0(300);
				ResetTimer0();
				if(menuPosition <iMENU)
				{ menuPosition++;}
				else
				{ menuPosition=1;}

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
			        	 //aseguro que periodo y tiempo en alto no sean iguales
			        	 //ni periodo menor a tiempo en alto
			        	 if( DevolverTimeUp()==DevolverPeriodo() || DevolverPeriodo()< DevolverTimeUp() )
			        	 { ModificarPeriodo(DevolverTimeUp()+1);}
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
							PosicionarCursor(1,2);
							printf_lcd(" ");
						}
					if(menuPosition==4)
						{
							PosicionarCursor(1,1);
							printf_lcd(" ");
							PosicionarCursor(1,2);
							arrow();
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
							PosicionarCursor(1,2);
							printf_lcd(" ");
						}
					if(menuPosition==6)
						{
							PosicionarCursor(1,1);
							printf_lcd(" ");
							PosicionarCursor(1,2);
							arrow();

						}
				}


		}

	}

	salir=0;
	menuPosition = 1;
	ClearDisplay();
}

VariarAmplitud()
{
	uint16_t value, value_aux;
	value=DevolverValueUp();
	static char auxVal[10];
	static char auxValue[10];
	uint32_t aux1=0;
	uint32_t aux2=0;
	uint16_t dat=0;
	uint8_t exit=0;
	ClearDisplay();
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
			printf_lcd("mA  ");
		}
	if(DevolverFlagVoI()==0)
		{
			printf_lcd("V  ");
		}


	while(!exit)
	{
		if(!(pulsado(BtnUp)))
		{
			TemporizadorTimer0(300);
			ResetTimer0();
			value_aux++;
			if(DevolverFlagVoI()==1 && value_aux>100)
			{
				value_aux=0;
			}
			if(DevolverFlagVoI()==0 && value_aux>200)
			{
				value_aux=0;
			}
		}


		if(!(pulsado(BtnDown)))
		{
			TemporizadorTimer0(300);
			ResetTimer0();

			if(DevolverFlagVoI()==1 && value_aux==0)
			{
				value_aux=101; //después se le resta 1
			}
			if(DevolverFlagVoI()==0 && value_aux==0)
			{
				value_aux=201;
			}
			value_aux--;
		}


		if(!(pulsado(BtnEnter)))
		{
			TemporizadorTimer0(300);
			ResetTimer0();
			exit=1;
		}

		PosicionarCursor(1,2);

		lcd_putInt(value_aux);

		printf_lcd(" ");

		if(DevolverFlagVoI()==1)
				{
					printf_lcd("mA  ");
				}
			if(DevolverFlagVoI()==0)
				{
					printf_lcd("V   ");
				}


	}

//---------------------------------------------------------------------
	if(DevolverFlagVoI()==1)
		{
			// For upper value of x/y, use this ( x + y - 1 ) / y

			if(value_aux>= 100)	{value_aux=100;}
			aux1=value_aux*1000; //value x
			aux2= aux1 + 31; //x+y
			dat= (aux2-1)/31;
		}
		if(DevolverFlagVoI()==0)
		{
			if(value_aux>= 200)	{value_aux=200;}
			aux1=value_aux*1000; //value x
			aux2= aux1 + 62; //x+y
			dat=(aux2-1)/62;

		}
//------------------------------------------------------------------

	ModificarValueUp(dat);

	ClearDisplay();


}
*/
