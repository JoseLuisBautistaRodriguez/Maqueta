//			||	Maqueta	|| El programa genera un espacio diseñado de impreción.

/*
	------------------------------------------------------------------------------------------
	Descripción del archivo.
	
	Uso de variables:
	
		Las variables se nombran de la siguiente manera: 
				
				(Tipo-de-variable)(Tipo-dato)_(palabra_en_funcion_del_uso_de_la_variable)  
	
				Global  = g		int   = i	* Al momento de declararla se requiere hacer una	
				funcion = f 	float = f		descripción de su uso dentro del programa.
								char  = c
								short = sh
				
		Al momento de declararla, por ejemplo:
					
						int fi_contadorUsuario 	// Contador del número que ingresa el usuario 
						int fi_contadorPc;	// Contador del número génerado por el pc.
				
		* Las variables que tienen la finalidad de actuar cómo contadores dentro de un 
		ciclo, son i, j, k y l. (En ese orden conforme se este trabajando).
			
	Uso de funciónes:
	
		Las funciónes se nombran de acuerdo con el siguiente criterio:
		
			(Tipo-de-funcion)_(descripción_Cada_palabra_inicil_con_mayuscula)
			
			void	= v			* Al momento de declararla se requiere hacer una
			int		= i				descripción de su uso dentro del programa.
				
		Al momento de declararla, por ejemplo:
		
						i_SumaDatos , v_RestaResultados , i_ImprimirDatos 	
	
	------------------------------------------------------------------------------------------
*/

/*		1- Librerias		*///--------------------------------------------------------------

	#include <stdio.h>
	#include <conio.h>

/*--	1- Librerias   	  --*/
							
/*		2- Manejo de variables Globales		*///----------------------------------------------
	
	struct Color
	{
		short configuracionRapida;
		short texto;
		short fondo;
		short espacio;
		char tituloDelPrograma[50];
		char autor[40];	
	};
	
/*--	2- Manejo de variables Glovales   	  --*/

/*		3- Prototipado de funciones		*///--------------------------------------------------
	
	void v_ImprimirMaquetacion ( struct Color *as_Color_Maqueta ); 
	
/*--	3- Prototipado de funciones 	  --*/

/*		4- Función principal (Descripción de uso)	*///--------------------------------------

	void main()
	{
		/*----------------------------------------------------------------------------------*/
		struct Color Color_Maqueta;
		short sh_i;
		/*----------Asignar doble espacio al final del c_tituloPrograma y c_nombreAutor-----*/
		char c_tituloPrograma[50] = "Titulo del programa  ";
		char c_nombreAutor[40] = "Jose Luis Bautista Rodriguez  " ;
		/*-------------Configuracion Rapida---------------------------------------------------
			Programado:						0	(Usará los valores de titulo y fondo)
			Normal:							1	Texto Blanco	Fondo Negro
			Nocturno:						2	Texto Gris 		Fondo Negro
			Papel:							3	Texto Negro		Fondo Blanco
			Facultad de Ingenieria:			4	Texto Rojo		Fondo Blanco
			Claro:							5	Texto Gris		Fondo Blanco
			Clasico 1:						6	Texto Verde		Fondo Negro
			Clasico 2:						7	Texto Negro		Fondo Verde
			Todo esta bien:					8	Texto Verde	Cl	Fondo Verde
			Advertencia:					9	Texto Amarillo	Fondo Rojo
		------------------------------------------------------------------------------------*/
		Color_Maqueta.configuracionRapida = 0 ;
		Color_Maqueta.fondo   = 0 ;
		Color_Maqueta.texto   = 3 ;
		Color_Maqueta.espacio = 75 ;
		
		for ( sh_i = 0 ; sh_i < 50 ; sh_i++)Color_Maqueta.tituloDelPrograma[sh_i] = c_tituloPrograma[sh_i];
		for ( sh_i = 0 ; sh_i < 40 ; sh_i++) Color_Maqueta.autor[sh_i] = c_nombreAutor[sh_i];
		
		v_ImprimirMaquetacion( &Color_Maqueta );
		/*-----------------------------------------------------------------------------------*/		
		printf( "\n\n\t Hola \n\n\n" );
		
		system ("pause");
	}

/*--	4- Función principal 	--*/

/*		5- Manejo de funciones		*///------------------------------------------------------
	
	void v_ImprimirMaquetacion (  struct Color *as_Color_Maqueta  )
	{
		/*------------------------------------------------------------------------------------		
		system("color FondoTexto");

		0 = Black  | Negro			   8 = Gray
		1 = Blue   | Azul			   9 = Light Blue
		2 = Green  | Verde			10 A = Light Green
		3 = Aqua   | Aguamarina		11 B = Light Aqua
		4 = Red	   | Rojo			12 C = Light Red
		5 = Purple | Púrpura		13 D = Light Purple
		6 = Yellow | Amarillo		14 E = Light Yellow					
		7 = White  | Blanco			15 F = Bright White	 	

		Ejemplo:

			Sí quieres un fondo Blanco y un texto Azul Claro entonces debes codificar:

			system("color 09"); 

		-------------------------------------------------------------------------------------*/
		
		short sh_controlDeUs = 0 , contador_a= 0, contador_b = 0, contador_c = 0 , sh_espacioParaTitulo, sh_espacioParaAutor, metrica = as_Color_Maqueta->espacio ;
		
		for ( contador_a = 0 ; contador_c < 1 ; contador_a++ )
		{
			if ( as_Color_Maqueta->tituloDelPrograma[contador_a] == ' ' )
			{
				if ( as_Color_Maqueta->tituloDelPrograma[contador_a + 1 ] == ' ')contador_c++;
			}
			contador_b++;	
		}
		contador_b--;
		
		sh_espacioParaTitulo = contador_b ;
		contador_b = 0 ;
		contador_c = 0 ;
		
		for ( contador_a = 0 ; contador_c < 1 ; contador_a++ )
		{
			if ( as_Color_Maqueta->autor[contador_a] == ' ' )
			{
				if ( as_Color_Maqueta->autor[contador_a + 1 ] == ' ')contador_c++;
			}
			contador_b++;	
		}
		contador_b--;
		
		sh_espacioParaAutor = contador_b ;
		
		if ( as_Color_Maqueta->fondo == as_Color_Maqueta->texto )
		{
			printf ("\n\t\tAdvertencia:\n");
			printf ("\n\tLos valores de color del fondo y el texto son iguales.\n");
			printf ( "\tSe les ha reasignado un color." );
			system("color 47");
			sh_controlDeUs ++;
		} 
		
		if ( as_Color_Maqueta->configuracionRapida != 0 )
		{
			switch( as_Color_Maqueta->configuracionRapida )
			{
				case 1 : //Normal:							1	Texto Blanco	Fondo Negro
					as_Color_Maqueta->texto = 7 ;
					as_Color_Maqueta->fondo = 0 ; 
					break;
				case 2 : //Nocturno:						2	Texto Gris 		Fondo Negro
					as_Color_Maqueta->texto = 8 ;
					as_Color_Maqueta->fondo = 0 ; 
					break;
				case 3 : //Papel:							3	Texto Negro		Fondo Blanco
					as_Color_Maqueta->texto = 0 ;
					as_Color_Maqueta->fondo = 7 ; 
					break;
				case 4 : //Facultad de Ingenieria:			4	Texto Rojo		Fondo Blanco
					as_Color_Maqueta->texto = 4 ;
					as_Color_Maqueta->fondo = 7 ; 
					break;
				case 5 : //Claro:							5	Texto Gris		Fondo Blanco
					as_Color_Maqueta->texto = 8 ;
					as_Color_Maqueta->fondo = 7 ; 
					break;
				case 6 : //Clasico 1:						6	Texto Verde		Fondo Negro
					as_Color_Maqueta->texto = 2 ;
					as_Color_Maqueta->fondo = 0 ; 
					break;
				case 7 : //Clasico 2:						7	Texto Negro		Fondo Verde
					as_Color_Maqueta->texto = 0 ;
					as_Color_Maqueta->fondo = 2 ; 
					break;
				case 8 : //Todo esta bien:					8	Texto verde		Fondo Verde
					as_Color_Maqueta->texto = 10 ;
					as_Color_Maqueta->fondo = 2 ; 
					break;
				case 9 : //Advertencia:						9	Texto Amarillo	Fondo Rojo
					as_Color_Maqueta->texto = 14 ;
					as_Color_Maqueta->fondo = 4 ;
					break;
				default : //Advertencia:					9	Texto Amarillo	Fondo Rojo
					printf("\n\t Valor en Color Configuracion Rapida no valido\n");
					as_Color_Maqueta->texto = 14 ;
					as_Color_Maqueta->fondo = 4 ;
					break;																										
			}
		}
		
		if ( as_Color_Maqueta->fondo != as_Color_Maqueta->texto )
		{
			if ( as_Color_Maqueta->fondo < 16 && as_Color_Maqueta->texto < 16 )
			{
				
				if ( as_Color_Maqueta->fondo > -1 && as_Color_Maqueta->texto > -1 )
				{
					
					switch ( as_Color_Maqueta->fondo )
					{
						case 0 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 00");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 01");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 02");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 03");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 04");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 05");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 06");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 07");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 08");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 09");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 0A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 0B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 0C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 0D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 0E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 0F");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 1 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 10");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 11");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 12");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 13");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 14");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 15");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 16");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 17");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 18");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 19");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 1A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 1B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 1C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 1D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 1E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 1F");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 2 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 20");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 21");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 22");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 23");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 24");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 25");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 26");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 27");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 28");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 29");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 2A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 2B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 2C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 2D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 2E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 2F");
									sh_controlDeUs ++;
									break;						
							}
							break;

						case 3 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 30");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 31");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 32");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 33");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 34");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 35");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 36");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 37");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 38");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 39");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 3A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 3B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 3C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 3D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 3E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 3F");
									sh_controlDeUs ++;
									break;						
							}
							break;

						case 4 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 40");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 41");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 42");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 43");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 44");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 45");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 46");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 47");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 48");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 49");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 4A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 4B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 4C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 4D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 4E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 4F");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 5 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 50");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 51");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 52");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 53");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 54");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 55");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 56");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 57");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 58");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 59");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 5A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 5B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 5C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 5D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 5E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 5F");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 6 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 60");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 61");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 62");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 63");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 64");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 65");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 66");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 67");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 68");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 69");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 6A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 6B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 6C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 6D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 6E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 6F");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 7 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 70");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 71");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 72");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 73");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 74");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 75");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 76");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 77");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 78");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 79");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 7A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 7B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 7C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 7D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 7E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 7F");
									sh_controlDeUs ++;
									break;						
							}
							break;	
							
						case 8 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 80");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 81");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 82");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 83");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 84");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 85");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 86");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 87");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 88");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 89");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 8A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 8B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 8C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 8D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 8E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 8F");
									sh_controlDeUs ++;
									break;						
							}
							break;	
							
						case 9 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 90");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 91");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 92");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 93");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 94");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 95");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 96");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 97");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 98");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 99");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 9A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 9B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 9C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 9D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 9E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 9F");
									sh_controlDeUs ++;
									break;						
							}
							break;	
							
						case 10 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color A0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color A1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color A2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color A3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color A4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color A5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color A6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color A7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color A8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color A9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color AA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color AB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color AC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color AD");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color AE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color AF");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 11 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color B0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color B1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color B2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color B3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color B4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color B5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color B6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color B7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color B8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color B9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color BA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color BB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color BC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color BD");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color BE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color BF");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 12 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color C0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color C1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color C2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color C3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color C4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color C5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color C6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color C7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color C8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color C9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color CA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color CB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color CC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color CD");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color CE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color CF");
									sh_controlDeUs ++;
									break;						
							}
							break;	
							
						case 13 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color D0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color D1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color D2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color D3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color D4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color D5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color D6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color D7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color D8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color D9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color DA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color DB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color DC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color DD");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color DE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color DF");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 14 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color E0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color E1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color E2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color E3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color E4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color E5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color E6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color E7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color E8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color E9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color EA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color EB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color EC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color ED");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color EE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color EF");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 15 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color F0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color F1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color F2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color F3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color F4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color F5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color F6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color F7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color F8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color F9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color FA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color FB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color FC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color FD");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color FE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color FF");
									sh_controlDeUs ++;
									break;						
							}
							break;	
							
						default : 
							printf("\n\tFuncion v_ImprimirMaquetacion no funciono como se esperaba. \n ");
							system( "color 47" );
							break;		  																																																																																					
					}
					
				}
				else if ( as_Color_Maqueta->fondo < 0 && as_Color_Maqueta->texto < 0 )
				{
					printf ("\n\t\tAdvertencia:\n");
					printf( "\n\tEl n%cmero del color del fondo es mayor a 15. " , 163 );
					printf ( "\tSe les ha reasignado un color." );
					system("color 47");
					sh_controlDeUs ++;
				}
			}
			else if ( as_Color_Maqueta->fondo > 16 && as_Color_Maqueta->texto > 16 ) 
			{
				printf ("\n\t\tAdvertencia:\n");
				printf( "\n\tEl n%cmero del color del fondo es mayor a 15. " , 163 );
				printf ( "\tSe les ha reasignado un color." );
				system("color 47");
				sh_controlDeUs ++;
			}
		}
		
		short i, i_espacio, i_imprimir, espacio_Imprimir;
		
		if ( sh_controlDeUs == 1 )
		{
			if ( sh_espacioParaAutor > sh_espacioParaTitulo ) espacio_Imprimir = sh_espacioParaAutor ;
			else if ( sh_espacioParaTitulo > sh_espacioParaAutor ) espacio_Imprimir = sh_espacioParaTitulo ;
			
			espacio_Imprimir = metrica - espacio_Imprimir;
			espacio_Imprimir = espacio_Imprimir - 2 ;
			if ( espacio_Imprimir < 0 )
			{
				printf("\n\tEl tama%co del titulo o nombre es demaciado largo \n");
				espacio_Imprimir = 10 ;	
			}
			
			for ( i = 0 ; i < as_Color_Maqueta->espacio ; i++)printf( "%c" , 219 );
			printf("\n");
			
			for ( i = 0 ; i < espacio_Imprimir ; i++ ) printf("%c" , 219 ); 
			printf(" ");
			for( i = 0; i < 50; i++)printf("%c" ,  as_Color_Maqueta->tituloDelPrograma[i] );
			
			printf("\n");
			
			for ( i = 0 ; i < espacio_Imprimir ; i++ ) printf( "%c" , 219 );
			printf( " " );			
			for( i = 0; i < 40; i++)printf("%c" ,  as_Color_Maqueta->autor[i] );
			printf("\n");
			
			for ( i = 0 ; i < as_Color_Maqueta->espacio ; i++)printf( "%c" , 219 );
			printf("\n");	
		}
	}
	
/*--	5- Manejo de funciones 	  --*/

/*
		||		Datos Generales del archivo		||
	------------------------------------------------------------------------------------------
	Universidad Nacional Autónoma de México
	Facultad de Ingeniería
	
	Grupo: 09
	 
	Autor: José Luis Bautista Rodríguez
	Fecha de inicio: 18-19/03/2018
	Lugar: AV. UNIVERSIDAD Nº 3000, UNIVERSIDAD NACIONAL AUTÓNOMA DE MÉXICO, C.U., CIUDAD DE 
	MÉXICO, 04510
	------------------------------------------------------------------------------------------

*/
