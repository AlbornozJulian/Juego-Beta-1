#include <iostream>
#include "Personajes.h"
#include "Carga_personajes_Campo.h"
#include "Reglas.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"
#include "Logo.h"
#include "Bienvenida.h"
#include "Creditos.h"

using namespace std;

void Carga();
void Presentacion();
void Menu_principal();
void Caso_2();
void Caso_3();
void portada();
void Reglas_niveles();
void selectorNiveles(char campo_Peque[MATRIZ2_C][MATRIZ2_L]);

bool repite,aux;
int opcion,n,fila=8;

int main(){
	Carga();
	Presentacion();
	limpia();
	Menu_principal();
    limpia();
    return 0; 
}

void Carga(){
	Spanish();
	ConfigurarConsola();
	ajustarTamanoConsola();
	personajes();
	enemigos();
}
void Presentacion(){
	Logo();
	Sleep(3700);
	limpia();
	espacio15();
	Bienvenida();
	Sleep(3700);
}
void Menu_principal(){
	repite = true;
	const char *titulo ="<<:: M A Z M O R R A   D E L   G U A R D I Á N   B L A N C O ::>>";
	const char *opciones[] = {">> INICIAR JUEGO", ">> DIFICULTAD", ">> PERSONAJES", "<< SALIR"};
	n = 4;// Numero de opciones
	do{
		setConsoleFont(24);// Establece el tamaño de la fuente
		system("COLOR 9F");
		opcion = flecha(titulo, opciones, n);
		switch(opcion){
			case 1:{
				portada();
				repite = true;
				n = 4;
				break;
			}
			case 2:{
				limpia();
				Caso_2();
				repite = true;
				n = 4;
				break;
			}
			case 3:{
				limpia();
				Caso_3();
				repite = true;
				n = 4;
				break;
			}
			case 4:{
				limpia();
				Marco();
				espacio3();
				gotoxy(30,3);Creditos_Alumno();
				espacio3();
				cout<<"\t << Cerrando Programa..."<<endl;
				Sleep(3700);
				repite = false;
				break;
			}
		}	
	}while(repite);
}
void Caso_2(){
	repite = true;
	const char *titulo ="<<:: N I V E L E S   D E   D I F I C U L T A D ::>>";
	const char *opciones[] = {">> NORMAL", ">> DIFICÍL", "<< REGRESAR"};
	int n = 3;// Numero de opciones 
	do{
		opcion = flecha(titulo, opciones, n);
		switch(opcion){
			case 1:{
				espacio3();
				cout<<"\t >> Has seleccionado la Dificultad NORMAL para jugar.";
				dificultadSeleccionado=false;
				getch();
				break;
			}
			case 2:{
				espacio3();
				cout<<"\t >> Has seleccionado la Dificultad DIFICÍL para jugar.";
				dificultadSeleccionado=true;
				getch();
				break;
			}
			case 3:{
				espacio3();
				cout<<"\t << Regresando al Menú..."<<endl;
				getch();
				repite = false; 
				break;
			}
		}	
	}while(repite);
}
void Caso_3(){
	repite = true;
	const char *titulo ="<<:: E L I J E   U N   P E R S O N A J E ::>>";
	const char *opciones[] = {">> HUMANO", ">> ELFO", "<< REGRESAR"};
	n = 3;// Numero de opciones
	Marco();
	gotoxy(30,2);cout<<"<<:: E S T A D Í S T I C A S   D E   L O S   P E R S O N A J E S ::>>";
	for(i=1;i<=120;i++){
		gotoxy(1+i,3);cout<<"-";
	}
	gotoxy(7,6);cout<<"N Ú M E R O        N O M B R E        V I D A        D E F E N S A        A T A Q U E        I M A G E N";
	gotoxy(7,7);cout<<"---------------------------------------------------------------------------------------------------------";
	for(i=0;i<2;i++){
		gotoxy(12,fila);cout<< personaje[i].num;
		gotoxy(26,fila);cout<< personaje[i].nombre;
		gotoxy(47,fila);cout<< personaje[i].vidaFull;
		gotoxy(65,fila);cout<< personaje[i].defensa;
		gotoxy(85,fila);cout<< personaje[i].ataque;
		gotoxy(105,fila);cout<< personaje[i].imagen;
		fila++;
	}
	Barra("<<:: A N A L I Z A N D O ::>>");
	Spanish();
	do{
		opcion = flecha(titulo, opciones, n);
		switch(opcion){
			case 1:{
				espacio3();
				cout<<"\t >> Has seleccionado al Personaje HUMANO para jugar.";
				personajeSeleccionado=false;
				getch();
				break;
			}
			case 2:{
				espacio3();
				cout<<"\t >> Has seleccionado al Personaje ELFO para jugar.";
				personajeSeleccionado=true;
				getch();
				break;
			}
			case 3:{
				espacio3();
				cout<<"\t << Regresando al Menú..."<<endl;
				getch();
				repite = false; 
				break;
			}
		}	
	}while(repite);
}

void portada(){
	char campo_Peque[MATRIZ2_C][MATRIZ2_L];
	aux = false;	
	repite = true;
	const char *opciones[] = {">< REGLAS",">> COMENZAR","<< MENÚ"};
	n = 3;// Numero de opciones
	do{
		if(siguienteNivel == 3){ // Reinicio despues de completar el juego
			siguienteNivel=0;
		}
		if(aux==false){
			Barra("<<:: C A R G A N D O  J U E G O ::>>");
			aux=true;
		}
		system("COLOR 0F");
		Spanish();
		limpia();
		setConsoleFont(16);// Establece el tamaño de la fuente
		opcion = flecha2(opciones, n);
		limpia();
		switch(opcion){
			case 1:{
				limpia();
				setConsoleFont(24);// Establece el tamaño de la fuente
				system("COLOR 9F");
				Reglas_niveles();
				repite = true;
				n = 3;
				break;
			}
			case 2:{
				limpia();
				selectorNiveles(campo_Peque);// Llama a la función del juego
				break;
			}
			case 3:{
				repite = false; 
				break;
			}
		}	
	}while(repite);
}

void Reglas_niveles(){
	repite = true;
	const char *titulo ="<<:: R E G L A S   D E   C A D A   N I V E L ::>>";
	const char *opciones[] = {">> NIVEL I", ">> NIVEL II",">> NIVEL III" ,"<< REGRESAR"};
	n = 4;// Numero de opciones 
	do{	
		opcion = flecha(titulo, opciones, n);
		switch(opcion){
			case 1:{
				limpia();
				espacio3();
				Marco();
				gotoxy(30,3);Regla1();
				getch();
				break;
			}
			case 2:{
				limpia();
				espacio3();
				Marco();
				gotoxy(30,3);Regla2();
				getch();
				break;
			}
			case 3:{
				limpia();
				espacio3();
				Marco();
				gotoxy(30,3);Regla3();
				getch();
				break;
			}
			case 4:{
				espacio3();
				cout<<"\t << Regresando al Menú..."<<endl;
				getch();
				repite = false; 
				break;
			}
		}	
	}while(repite);
} 

void selectorNiveles(char campo_Peque[MATRIZ2_C][MATRIZ2_L]){
	switch(siguienteNivel){ // Llamada Niveles
		case 0:{
			escenarioBatalla1(campo_Peque);
			puntaje=0;
			direccion = 'w';
			personajes();
    		enemigos();
			break;
		}
		case 1:{
			if(dificultadSeleccionado == false){ // Inicializa Vida
				personaje[0].vida=6;
				personaje[1].vida=6;
			}
			else{
				personaje[0].vida=5;
				personaje[1].vida=5;
			}
			carga_Campo2(campo_Peque);
			escenarioBatalla2(campo_Peque);
			personajes();
			break;
		}
		case 2:{
			personajes();
    		enemigos();
			escenarioBatalla3(campo_Peque);
			personajes();
			break;
		}
	}
}
