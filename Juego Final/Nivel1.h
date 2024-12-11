#include <iostream>
#include <ctime>// Para generar números aleatorios, intrucciones srand y rand
#include <conio.h>// Para la instruccion getch().
#include <cstdlib>// Para rand y srand
#include <windows.h>// Para Sleep en Windows
#include "Herramientas.h"

using namespace std;

bool resultado,dificultadSeleccionado=false;// False para normal, true para dificil
int puntaje_Final = 100000;
char direccion = 'w';// Dirección inicial del movimiento
int puntaje=0;

void pasoNivel(){
	siguienteNivel=siguienteNivel+1;// Incrementa para pasar de nivel
}

void Puntaje_Total(bool resultado){
	if(resultado==false){
		puntaje_Final-=5000;// Restar puntaje si perdio
	} else{
		puntaje_Final+=7000;// Sumar puntaje si gano
	}
}

void movimiento_Enemigos(char campo_Peque[MATRIZ2_C][MATRIZ2_L]){
	int Probabilidad;
	if(dificultadSeleccionado == false){
		Probabilidad = rand() % 10;// Probabilidad del 10%
	    if(Probabilidad < 3){
		    if (personajeSeleccionado){ // Seguir al elfo
		        if(enemigo[1].x < personaje[1].y){
		        	enemigo[1].modX=1;
				} 
		        else{
		        	if(enemigo[1].x > personaje[1].y){
		        		enemigo[1].modX=-1;
					}
				}  
		        if(enemigo[1].y < personaje[1].x){
		        	enemigo[1].modY=1;
				} 
		        else{
		        	if(enemigo[1].y > personaje[1].x){
		        		enemigo[1].modY=-1;
					}
				}  
		    } 
			else{ // Seguir al humano
		        if(enemigo[1].x < personaje[0].y){
		        	enemigo[1].modX=1;
				} 
		        else{
		        	if(enemigo[1].x > personaje[0].y){
		        		enemigo[1].modX=-1;
					} 
				}
		        if(enemigo[1].y < personaje[0].x){
		        	enemigo[1].modY=1;
				} 
		        else{
		        	if(enemigo[1].y > personaje[0].x){
		        		enemigo[1].modY=-1;
					}
				} 
		    }    
		}	
	}
	else{
		Probabilidad = rand() % 15;// Probabilidad del 15%
	    if(Probabilidad < 5) {
		    if(personajeSeleccionado){ // Seguir al elfo
		        if(enemigo[0].x < personaje[1].y){
		        	enemigo[0].modX=1;
				} 
		        else{
		        	if(enemigo[0].x > personaje[1].y){
					enemigo[0].modX=-1;
					} 
				} 
		        if(enemigo[0].y < personaje[1].x){
		        	enemigo[0].modY=1;	
				} 
		        else{
		        	if(enemigo[0].y > personaje[1].x){
					enemigo[0].modY=-1;
					} 
				} 
		    } 
			else { // Seguir al humano
		        if(enemigo[0].x < personaje[0].y){
		        	enemigo[0].modX=1;
				} 
		        else{
		        	if(enemigo[0].x > personaje[0].y){
					enemigo[0].modX=-1;
					} 
				} 
		        if(enemigo[0].y < personaje[0].x){
		        	enemigo[0].modY=1;
				} 
		        else{
			        if(enemigo[0].y > personaje[0].x){
						enemigo[0].modY=-1;
					} 	
				} 
			}
		    if (personajeSeleccionado){ // Seguir al elfo
		        if(enemigo[1].x < personaje[1].y){
		        	enemigo[1].modX=1;
				} 
		        else{
		        	if(enemigo[1].x > personaje[1].y){
		        		enemigo[1].modX=-1;
					}
				}  
		        if(enemigo[1].y < personaje[1].x){
		        	enemigo[1].modY=1;
				} 
		        else{
		        	if(enemigo[1].y > personaje[1].x){
		        		enemigo[1].modY=-1;
					}
				}  
		    } 
			else{ // Seguir al humano
		        if(enemigo[1].x < personaje[0].y){
		        	enemigo[1].modX=1;
				} 
		        else{
		        	if(enemigo[1].x > personaje[0].y){
		        		enemigo[1].modX=-1;
					} 
				}
		        if(enemigo[1].y < personaje[0].x){
		        	enemigo[1].modY=1;
				} 
		        else{
		        	if(enemigo[1].y > personaje[0].x){
		        		enemigo[1].modY=-1;
					}
				} 
		    }    
		}
	}
    // Actualizar posición del enemigo
    enemigo[0].x +=enemigo[0].modX;
    enemigo[0].y +=enemigo[0].modY;
    enemigo[1].x +=enemigo[1].modX;
    enemigo[1].y +=enemigo[1].modY;
	// Verificación de bordes
    if (enemigo[0].x <= 1 || enemigo[0].x >= MATRIZ2_L-3){
        enemigo[0].modX = -enemigo[0].modX;  // Cambiar dirección horizontal
    }
    if (enemigo[0].y <= 1 || enemigo[0].y >= MATRIZ2_C-3){
        enemigo[0].modY = -enemigo[0].modY;  // Cambiar dirección vertical
    }
    if (enemigo[1].x <= 1 || enemigo[1].x >= MATRIZ2_L-3){
        enemigo[1].modX = -enemigo[1].modX;  // Cambiar dirección horizontal
    }
    if (enemigo[1].y <= 1 || enemigo[1].y >= MATRIZ2_C-3){
        enemigo[1].modY = -enemigo[1].modY;  // Cambiar dirección vertical
    }
}

void movimiento_Jugador(char campo_Peque[MATRIZ2_C][MATRIZ2_L]){
    if (kbhit()){ // Detectar la dirección de movimiento del jugador
        char key = getch();
        if(key == 'w'){
        	direccion = 'w';
		} 
        if(key == 's'){
        	direccion = 's';
		} 
        if(key == 'a'){
        	direccion = 'a';
		} 
        if(key == 'd'){
        	direccion = 'd';
		} 
    }
    if(personajeSeleccionado == false){ // Mover el jugador en la dirección actual
        if(direccion == 's' and personaje[0].x < MATRIZ2_C-3){  // Verificar límite inferior
            personaje[0].x++;
        }
        if(direccion == 'w' and personaje[0].x > 2){    // Verificar límite superior
            personaje[0].x--;
        }
        if(direccion == 'a' and personaje[0].y > 2){    // Verificar límite izquierdo
            personaje[0].y--;
        }
        if(direccion == 'd' and personaje[0].y < MATRIZ2_L-3){  // Verificar límite derecho
            personaje[0].y++;
        }
    } 
	else{
        if(direccion == 's' and personaje[1].x < MATRIZ2_C-3){  // Verificar límite inferior
            personaje[1].x++;
        }
        if(direccion == 'w' and personaje[1].x > 2){    // Verificar límite superior
            personaje[1].x--;
        }
        if(direccion == 'a' and personaje[1].y > 2){    // Verificar límite izquierdo
            personaje[1].y--;
        }
        if(direccion == 'd' and personaje[1].y < MATRIZ2_L-3){  // Verificar límite derecho
            personaje[1].y++;
        }
    }
}

void recoleccion(char campo_Peque[MATRIZ2_C][MATRIZ2_L],int* muerte,int* distancia){
    // Verificar si el jugador recoge la moneda
    if (!personajeSeleccionado && campo_Peque[personaje[0].x][personaje[0].y] == '$') {
        puntaje=puntaje+50;
        dinero.x = rand() % (MATRIZ2_L-2* *distancia) + *distancia;
    	dinero.y = rand() % (MATRIZ2_C-2* *distancia) + *distancia;
    } 
	else{
		if (personajeSeleccionado && campo_Peque[personaje[1].x][personaje[1].y] == '$') {
	        puntaje=puntaje+50;
	            dinero.x = rand() % (MATRIZ2_L-2* *distancia) + *distancia;
    			dinero.y = rand() % (MATRIZ2_C-2* *distancia) + *distancia;
    	}
	} 
    gotoxy(1,1);cout<<"<< Puntaje: "<< puntaje;
    gotoxy(11,4);cout<<"Letras para Jugar: |W|S|A|D|. Juntar Monedas al pasar por encima con: |+|&|";
    if(dificultadSeleccionado==false){// Condicion de dificultad para pasar de nivel 
    	if(puntaje==100){
    		resultado=true;
        	Puntaje_Total(resultado);
    		system("color 2F");
    		gotoxy(1,1);cout<<">> Felicidades pasaste de Nivel!!!.";
    		Sleep(3000);
    		pasoNivel();
    		*muerte = 1;
		}
	}
	else{
		if(puntaje==200){
			resultado=true;
        	Puntaje_Total(resultado);
			system("color 2F");
    		gotoxy(1,1);cout<<">> Felicidades pasaste de Nivel!!!.";
    		Sleep(3000);
    		pasoNivel();
    		*muerte = 1;
		}
	}	
}

void vidas(char campo_Peque[MATRIZ2_C][MATRIZ2_L],int* muerte){
    // Verificar colision con enemigos
    if(((enemigo[0].x == personaje[0].y) && (enemigo[0].y == personaje[0].x)) || ((enemigo[1].x == personaje[0].y) && (enemigo[1].y == personaje[0].x))){
        personaje[0].vida--;// Disminuir la vida del jugador 1 (Humano)
        gotoxy(1,1);cout<<"<< Vida Perdida...";
        getch();
        if(personaje[0].vida == 0){
        	resultado=false;
        	Puntaje_Total(resultado);
        	system("color CF");
        	gotoxy(1,1);cout<<">> Fuiste Derrotado. Suerte la Proxima!!!.";
        	Sleep(3000);
            *muerte = 1;
        }
    } 
	else{
		if(((enemigo[0].x == personaje[1].y) && (enemigo[0].y == personaje[1].x)) || ((enemigo[1].x == personaje[1].y) && (enemigo[1].y == personaje[1].x))){
	        personaje[1].vida--;// Disminuir la vida del jugador 2 (Elfo)
	        gotoxy(1,1);cout<<"<< Vida Perdida...";
	        getch();
	        if(personaje[1].vida == 0){
	        	resultado=false;
        		Puntaje_Total(resultado);
	        	system("color CF");
	        	gotoxy(1,1);cout<<">> Fuiste Derrotado. Suerte la Proxima!!!.";
	        	Sleep(3000);
	            *muerte = 1;
	        }
		}	
	}
}

void escenarioBatalla1(char campo_Peque[MATRIZ2_C][MATRIZ2_L]){
    int muerte = 0,distancia=5,i;
    srand(time(NULL));// Inicializar posición de la moneda
    dinero.x = rand() % (MATRIZ2_L-2* distancia) + distancia;
    dinero.y = rand() % (MATRIZ2_C-2* distancia) + distancia;
    while(muerte == 0){ // Bucle del Juego
    	system("COLOR 0F");
    	Spanish();
		setConsoleFont(25);// Establece el tamaño de la fuente
        carga_Campo2(campo_Peque);
        if(personajeSeleccionado == false){ // Dibujo personajes
            dibujo_Aventurero2(campo_Peque,personaje[0].y,personaje[0].x);
        } 
		else{
            dibujo_Elfo2(campo_Peque,personaje[1].y,personaje[1].x);
        }
        if(dificultadSeleccionado == false){ // Dibujo enemigos
            dibujo_Esqueleto(campo_Peque, enemigo[1].x, enemigo[1].y);
        } 
		else{
            dibujo_Ogro(campo_Peque,enemigo[0].x,enemigo[0].y);
        	dibujo_Esqueleto(campo_Peque, enemigo[1].x, enemigo[1].y);
        }
        if(personajeSeleccionado == false){ // Muestra vidas
        	gotoxy(1,2);cout<<">> Vidas: "<<personaje[0].vida;
        } else {
        	gotoxy(1,2);cout<<">> Vidas: "<<personaje[1].vida;
        }
        campo_Peque[dinero.y][dinero.x] = '$';//Dibujar la moneda en la pantalla
        limpia();
        dibujo2(campo_Peque);
        recoleccion(campo_Peque,&muerte,&distancia);
        vidas(campo_Peque, &muerte);
        movimiento_Jugador(campo_Peque);
        movimiento_Enemigos(campo_Peque);
        Sleep(150);
    }
}
