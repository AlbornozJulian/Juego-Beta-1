#include <iostream>
#include <ctime>// Para generar números aleatorios, intrucciones srand y rand
#include <conio.h>// Para la instruccion getch().
#include <cstdlib>// Para rand y srand

using namespace std;

bool final=false;

void analizarVida(bool *final){
	if(personajeSeleccionado == false){
		if(personaje[0].vidaFull < 0){
			*final=true;
		}
		if(personaje[0].vida == 0){
			*final=true;
		}
	}
	else{
		if(personaje[1].vidaFull < 0){
			*final=true;
		}
		if(personaje[1].vida == 0){
			*final=true;
		}
	}
	if(enemigo[2].vida < 0){
		*final=true;
	}
}

void inicializarTrampas(int puente[MATRIZ3_E][MATRIZ3_J]){
	int i,j,trampa;
    srand(time(0));
    for(i=0;i<MATRIZ3_E;i++){
        trampa = rand() % MATRIZ3_J;// Eleccion aleatoria
        for(j=0;j<MATRIZ3_J;j++) {
            puente[i][j] = (j == trampa) ? 1 : 0;// Operador Ternario
        }
    }
}

void escenarioBatalla2(char campo_Peque[MATRIZ2_C][MATRIZ2_L]){
	int puente[MATRIZ3_E][MATRIZ3_J],i,aux=0;
	char columna;
    bool finPuente=false,final=false;
    inicializarTrampas(puente);
	carga_Campo2(campo_Peque);
		if(personajeSeleccionado == false){ // Dibuja Personaje y muestra la cantidad de Vida
	    dibujo_Aventurero2(campo_Peque, personaje[0].y, personaje[0].x);
	    gotoxy(20,1);cout<<">> Vidas iniciales: "<<personaje[0].vida;
	} 
	else{
	    dibujo_Elfo2(campo_Peque, personaje[1].y, personaje[1].x);
		gotoxy(20,1);cout<<">> Vidas iniciales: "<<personaje[1].vida;   
	}
    for (i=0;i<MATRIZ3_E;i++){ // Bucle del Juego
    	system("COLOR 0F");
    	Spanish();
		setConsoleFont(25);// Establece el tamaño de la fuente
    	dibujo2(campo_Peque);
        gotoxy(15,0);cout<<">> Escalón "<<aux+1;
        aux++;
        gotoxy(25,2);cout<<">> Selecciona una Tabla del Puente: [1|2]";
        gotoxy(30,3);cout<<" Opción: ";
        cin>>columna;
        if(columna<'1' or columna>'2'){
        	system("color CF");
            gotoxy(20,1);cout<<"<< Resbalaste y caíste al río!!!";
            // Resta Vida
            if(personajeSeleccionado == false){
			    personaje[0].vida--;
			} 
			else{
				personaje[1].vida--;  
			}
			getch();
            limpia();
        }
		else{
        	if(puente[i][columna - '1'] == 1){ // La posicion es 1 (Trampa)
        		system("color CF");
            	gotoxy(20,1);cout<<"<< Caíste porque la Tabla estaba Floja!!!. Pierdes una Vida...";
            	if(personajeSeleccionado == false){ // Resta Vida
				    personaje[0].vida--;
				} 
				else{
					personaje[1].vida--;  
				}
				carga_Campo2(campo_Peque);
	            if(personajeSeleccionado == false){ // Movimiento de personaje
				    personaje[0].x -= 2; // Mover al personaje hacia arriba
				    dibujo_Aventurero2(campo_Peque, personaje[0].y, personaje[0].x);
				} 
				else{
					personaje[1].x -= 2; // Mover al personaje hacia arriba
					dibujo_Elfo2(campo_Peque, personaje[1].y, personaje[1].x);
				}
            	getch();
            	limpia();
        	}
			else{
				system("color 2F");
	            gotoxy(20,1);cout<<">> Avanzas sin problema.";
	            carga_Campo2(campo_Peque);
	            // Movimiento de personaje
	            if(personajeSeleccionado == false){
				    personaje[0].x -= 2; // Mover al personaje hacia arriba
				    dibujo_Aventurero2(campo_Peque, personaje[0].y, personaje[0].x);
				} 
				else{
					personaje[1].x -= 2; // Mover al personaje hacia arriba
					dibujo_Elfo2(campo_Peque, personaje[1].y, personaje[1].x);
				}
	            getch();
	            limpia();
        	}	
		}
		 if(personajeSeleccionado == false){
			if(i == MATRIZ3_E-1 and personaje[0].vida > 0){
             finPuente=true;
        	}
        	gotoxy(20,1);cout<<"<< Vidas restantes: "<<personaje[0].vida;
		} 
		else{
			if(i == MATRIZ3_E-1 and personaje[1].vida > 0){
             finPuente=true;
        	}
			gotoxy(20,1);cout<<"<< Vidas restantes: "<<personaje[1].vida; 
		} 
		analizarVida(&final);
		if(final==true){
			break;
		}
    }
    if((finPuente == true) && (final==false)){
    	resultado=true;
        Puntaje_Total(resultado);
    	system("color 2F");
        gotoxy(20,1);cout<<">> Felicidades pasaste de Nivel!!!";
        Sleep(3000);
        pasoNivel();
        limpia();
    } 
	else{
		resultado=false;
        Puntaje_Total(resultado);
		system("color CF");
        gotoxy(20,1);cout<<">> Fuiste Derrotado por el Puente. Suerte la Proxima!!!";
        Sleep(3000);
        limpia();
    }
}
