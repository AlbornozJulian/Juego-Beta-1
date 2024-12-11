#include <iostream>
#include <ctime>// Para generar números aleatorios, intrucciones srand y rand
#include <conio.h>// Para la instruccion getch().
#include <cstdlib>// Para rand y srand
#include "Tabla_puntajes.h"

using namespace std;

char eleccion;
int golpe,A=0,B=0,D=0,def=0,ata=0,vid=0,ataque;
bool turno_Inicial,especial;

void mostrar_Estadisticas_j(){
	if(personajeSeleccionado == false){
	gotoxy(89,11);cout<<">> H U M A N O";
	gotoxy(91,13);cout<<"<< V I D A: "<<personaje[0].vidaFull;
	gotoxy(91,14);cout<<"<< A T A Q U E: "<<personaje[0].ataque;
	gotoxy(91,15);cout<<"<< D E F E N S A: "<<personaje[0].defensa;
	}
	else{
	gotoxy(89,11);cout<<">> E L F O";
	gotoxy(91,13);cout<<"<< V I D A: "<<personaje[1].vidaFull;
	gotoxy(91,14);cout<<"<< A T A Q U E: "<<personaje[1].ataque;
	gotoxy(91,15);cout<<"<< D E F E N S A: "<<personaje[1].defensa;
	}
}

void mostrar_Estadisticas_e(){
	gotoxy(89,5);cout<<">> L E Ó N   E C L I P S E";
	gotoxy(91,7);cout<<"<< V I D A: "<<enemigo[2].vida;
	gotoxy(91,8);cout<<"<< A T A Q U E: "<<enemigo[2].ataque;
	gotoxy(91,9);cout<<"<< D E F E N S A: "<<enemigo[2].defensa;
}

void Incremento(char eleccion){
	if(dificultadSeleccionado == false){
		def=10; ata=20; vid=30;
	}
	else{
		def=20; ata=40; vid=60;
	}
	switch(eleccion){
        case '1':{
        	if(personajeSeleccionado == false){
        		personaje[0].defensa += def;
            	cout<<"\n\t >> Aumentaste tu defensa en "<<def<<" puntos!"<<endl;
			}
			else{
				personaje[1].defensa += def;
            	cout<<"\n\t >> Aumentaste tu defensa en "<<def<<" puntos!"<<endl;
			}
			break;
		}
        case '2':{
        	if(personajeSeleccionado == false){
        		personaje[0].ataque += ata;
            	cout<<"\n\t >> Aumentaste tu ataque en "<<ata<<" puntos!"<<endl;
			}
			else{
				personaje[1].ataque += ata;
            	cout<<"\n\t >> Aumentaste tu ataque en "<<ata<<" puntos!"<<endl;
			}
			break;
		} 
        case '3':{
        	if(personajeSeleccionado == false){
        		personaje[0].vidaFull += vid;
            	cout<<"\n\t >> Te curaste "<<vid<<" puntos de vida!"<<endl;
			}
			else{
				personaje[1].vidaFull += vid;
            	cout<<"\n\t >> Te curaste "<<vid<<" puntos de vida!"<<endl;
			}
			break;
		}
        case '4':{
        	if(personajeSeleccionado == false){
        		golpe = personaje[0].ataque - enemigo[2].defensa;
            	if (golpe > 0) {
                enemigo[2].defensa -= personaje[0].ataque;
                if (enemigo[2].defensa < 0) {
                    enemigo[2].vida += enemigo[2].defensa;// Restar el valor negativo de defensa a la vida
                    enemigo[2].defensa = 0;
                }
                cout<<"\n\t >> Atacaste al Jefe del Nivel y le hiciste "<<golpe<<" puntos de Daño!"<<endl;
            	} 
				else {
                	cout<<"\n\n\t << El Jefe del Nivel bloqueó tu ataque!"<<endl;
            	}
			}
			else{
				golpe = personaje[1].ataque - enemigo[2].defensa;
            	if (golpe > 0) {
                	enemigo[2].defensa -= personaje[1].ataque;
                	if (enemigo[2].defensa < 0) {
                    enemigo[2].vida += enemigo[2].defensa;// Restar el valor negativo de defensa a la vida
                    enemigo[2].defensa = 0;
                	}
                cout<<"\n\t >> Atacaste al Jefe del Nivel y le hiciste "<<golpe<<" puntos de Daño!"<<endl;
            	} 
				else {
                	cout<<"\n\n\t << El Jefe del Nivel bloqueó tu ataque!"<<endl;
            	}
			}
			break;
		}
		case '5':{
			if(personajeSeleccionado == false){
				if(especial==false){
					ataque=personaje[0].ataque;
					personaje[0].ataque=1000;
					personaje[0].vidaFull=1;
					golpe = personaje[0].ataque - enemigo[2].defensa;
					if(golpe > 0){
				    enemigo[2].defensa -= personaje[0].ataque;
				    if(enemigo[2].defensa < 0){
				        enemigo[2].vida += enemigo[2].defensa;// Restar el valor negativo de defensa a la vida
				        enemigo[2].defensa = 0;
				    }
				    cout<<"\n\t >> Atacaste al Jefe del Nivel y le hiciste "<<golpe<<" puntos de Daño!"<<endl;
					}
					personaje[0].ataque=ataque;
					especial=true;
				}
				else{
					cout<<"\n\n\t >> Estas agotado después de realizar tu ataque especial... Pierdes tu Turno."<<endl;
				}
			}
			else{
				if(especial==false){
					ataque=personaje[1].ataque;
					personaje[1].ataque=1000;
					personaje[1].vidaFull=1;
					golpe = personaje[1].ataque - enemigo[2].defensa;
					if(golpe > 0){
						enemigo[2].defensa -= personaje[1].ataque;
						if(enemigo[2].defensa < 0){
					    enemigo[2].vida += enemigo[2].defensa;// Restar el valor negativo de defensa a la vida
					    enemigo[2].defensa = 0;
						}
					cout<<"\n\t >> Atacaste al Jefe del Nivel y le hiciste "<<golpe<<" puntos de Daño!"<<endl;
					}
					personaje[1].ataque=ataque;
					especial=true;
				}
				else{
					cout<<"\n\n\t >> Estas agotado después de realizar tu ataque especial... Pierdes tu Turno."<<endl;
				}
			}
			break;
		}
        default:{
        	cout<<"\n\n\t >> Movimiento no Programado... Pierdes tu Turno."<<endl;
			break;
		}
    }	
}

void turno_Jugador(){
	gotoxy(89,18);cout<<">> Es tu turno. Elige un movimiento:";
	if(personajeSeleccionado == false){
		gotoxy(91,20);cout<<"1) PROTEGERSE CON ESCUDO";
		gotoxy(91,21);cout<<"2) POCIÓN DE FUERZA";
		gotoxy(91,22);cout<<"3) POCIÓN DE VIDA";
		gotoxy(91,23);cout<<"4) ATACAR CON ESPADA";
		gotoxy(91,24);cout<<"5) BERSERKER";
	}
	else{
		gotoxy(91,20);cout<<"1) ACTIVAR BARRERA";
		gotoxy(91,21);cout<<"2) POCIÓN DE FUERZA";
		gotoxy(91,22);cout<<"3) POCIÓN DE VIDA";
		gotoxy(91,23);cout<<"4) DISPARAR FECHA";
		gotoxy(91,24);cout<<"5) LLUVIA DE FLECHAS";
	}
	gotoxy(91,26);cout<<" Opción: ";
	cin>>eleccion;
	Incremento(eleccion);
}

void turno_Jefe(){
	if (enemigo[2].vida<500){
        gotoxy(89,18);cout<<"<< El León acepta su Destino...";
        return;
	}
	if(personajeSeleccionado==false){
	    golpe = enemigo[2].ataque - personaje[0].defensa;
	    if (golpe > 0) {
	        personaje[0].vidaFull-=golpe;
	        gotoxy(89,18);cout<<">> El Jefe atacó y te hizo "<<golpe<<" Puntos de Daño!";
	    } else {
	        gotoxy(89,18);cout<<"<< Tu Defensa Bloqueó el Ataque del Jefel!!!";
	    }	
	}
	else{
	    golpe = enemigo[2].ataque - personaje[1].defensa;
		if (golpe > 0) {
		    personaje[1].vidaFull-=golpe;
		    gotoxy(89,18);cout<<">> El Jefe atacó y te hizo "<<golpe<<" Puntos de Daño!";
		} 
		else {
		    gotoxy(89,18);cout<<"<< Tu Defensa Bloqueó el Ataque del Jefel!!!";
		}
	}
}

void escenarioBatalla3(char campo_Peque[MATRIZ2_C][MATRIZ2_L]){
	especial=false;
	carga_Campo2(campo_Peque);
	dibujo_Titulo2(campo_Peque);
	if (personajeSeleccionado == false) {
        dibujo_Aventurero2(campo_Peque, personaje[0].y, personaje[0].x);
    } 
	else {
        dibujo_Elfo2(campo_Peque, personaje[1].y, personaje[1].x);
    }
	srand(time(0));
	turno_Inicial=rand()%2;
	while(final == false){ // Bucle del Juego
		system("COLOR 0F");
		Spanish();
		setConsoleFont(22);// Establece el tamaño de la fuente
		dibujo_Leon2(campo_Peque,enemigo[2].x,enemigo[2].y);
		if(dificultadSeleccionado == true){
			if(enemigo[2].vida < 500){
				A=1;// Bandera
			}
			if(A==1){
				if(B==0){
					B=1;// Bandera
					cout<<"\n\n>> Esta pasando algo Raro!!!\n";
					cout<<">> Preparate...";
					getch();
					limpia();
				}
				dibujo_Ataque_leon2(campo_Peque,enemigo[2].x,enemigo[2].y);
				if(D==0){
					D=1;// Bandera
					enemigo[2].vida=3600;
					enemigo[2].ataque=800;
					enemigo[2].defensa=1500;	
				}	
			}
		}
		if(enemigo[2].vida<500){
			fin_Leon(campo_Peque,38,9);
		}
   		dibujo2(campo_Peque);
		mostrar_Estadisticas_j();
		mostrar_Estadisticas_e();
		for(i=0;i<=40;i++){
		gotoxy(91+i,17);cout<<"-";	
		}
		if(turno_Inicial){
			turno_Jefe();
		}
		else{
			turno_Jugador();
		}
		analizarVida(&final);
		turno_Inicial=!turno_Inicial;// Alternar el turno
		getch();
		limpia();	
	}
	if(personajeSeleccionado == false){
		if(personaje[0].vidaFull<=0){
			resultado=false;
        	Puntaje_Total(resultado);
			system("color CF");
			cout<<"\n\t >> Fuiste Derrotado... Suerte la Proxima!!!"<<endl;
			Sleep(3000);
			final=false;
		}
		else{
			resultado=true;
        	Puntaje_Total(resultado);
			system("color 2F");
			cout<<"\n\t >> Venciste al Jefe!!!. Felicidades Ganaste!!!"<<endl;
			pasoNivel();
			Sleep(3000);
			crear_Archivo();
			getch();
			final=false;
		}	
	}
	else{
		if(personaje[1].vidaFull<=0){
			resultado=false;
        	Puntaje_Total(resultado);
			system("color CF");
			cout<<"\n\t >> Fuiste Derrotado... Suerte la Proxima!!!"<<endl;
			Sleep(3000);
			final=false;
		}
		else{
			resultado=true;
        	Puntaje_Total(resultado);
			system("color 2F");
			cout<<"\n\t >> Venciste al Jefe!!!. Felicidades Ganaste!!!"<<endl;
			pasoNivel();
			Sleep(3000);
			crear_Archivo();
			getch();
			final=false;
		}
	}
}
