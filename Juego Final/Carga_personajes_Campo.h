#include <iostream>

#define MATRIZ1_V 41  // Altura de la matriz de submenú
#define MATRIZ1_H 128  // Ancho de la matriz de submenú
#define MATRIZ2_C 23  // Altura de la matriz del Juego
#define MATRIZ2_L 80  // Ancho de la matriz del Juego
#define MATRIZ3_E 8   // Altura de la matriz del Puente
#define MATRIZ3_J 2   // Ancho de la matriz del Puente

using namespace std;

int i,j;
int siguienteNivel=0;// 0 Nivel, 1 Nivel, etc
bool personajeSeleccionado=false;// False para aventurero, true para elfo

void dibujo_Aventurero(char campo[MATRIZ1_V][MATRIZ1_H],int posX,int posY){
    campo[posY][posX] = '+';           //Cabeza
    campo[posY + 1][posX] = '|';       //Cuerpo
    campo[posY + 2][posX - 1] = '/';   //Pierna izquierda
    campo[posY + 2][posX + 1] = '\\';  //Pierna derecha
    campo[posY + 1][posX - 1] = '/';   //Brazo izquierdo
    campo[posY + 1][posX + 1] = '\\';  //Brazo derecho
    campo[posY + 1][posX + 2] = '^';   //Mango espada
    campo[posY][posX + 2] = '|';       //Espada
    campo[posY + 1][posX - 2] = '0';   //Escudo
}

void dibujo_Elfo(char campo[MATRIZ1_V][MATRIZ1_H],int posX,int posY){
    campo[posY][posX-1] = '-';         //Oreja izquierda
    campo[posY][posX+1] = '-';         //Oreja derecha
    campo[posY][posX] = '&';           //Cabeza
    campo[posY + 1][posX] = '|';       //Cuerpo
    campo[posY + 1][posX - 1] = '/';   //Brazo izquierdo
    campo[posY + 1][posX + 1] = '\\';  //Brazo derecho
    campo[posY + 2][posX-1] = '/';     //Pierna izquierda
    campo[posY + 2][posX + 1] = '\\';  //Pierna derecha
    campo[posY + 1][posX + 2] = '|';   //Base arco
	campo[posY + 1][posX + 3] = ')';   //Cuerda arco
}

void dibujo_Arbol(char campo[MATRIZ1_V][MATRIZ1_H],int posX,int posY){
	campo[posY-1][posX-1] = '/'; 
	campo[posY-1][posX+1] = '\\';
	campo[posY][posX+1] = '\\'; 
	campo[posY][posX-1] = '/'; 
	campo[posY][posX+2] = '\\'; 
	campo[posY][posX-2] = '/'; 
    campo[posY+1][posX - 2] = '/';        
    campo[posY+1][posX + 2] = '\\';
    campo[posY+2][posX - 2] = '/';
    campo[posY+2][posX + 2] = '\\';
    campo[posY+1][posX - 3] = '/';        
    campo[posY+1][posX + 3] = '\\';
    campo[posY+2][posX - 3] = '/';
    campo[posY+2][posX + 3] = '\\';
	for(i=1;i<=3;i++){
		campo[posY+i][posX+1] = '|';
		campo[posY+i][posX] = '=';
		campo[posY+i][posX-1] = '|';
	}
    campo[posY+3][posX-2] = '_'; 
	campo[posY+3][posX+2] = '_'; 
}

void dibujo_Leon(char campo[MATRIZ1_V][MATRIZ1_H],int posX,int posY){
	campo[posY-3][posX+11] = '\\';
	campo[posY-3][posX-9] = '/';
	for(i=1;i<=10;i++){
		campo[posY-4][posX+i] = '_';
	}
	for(i=0;i<=8;i++){
		campo[posY-4][posX-i] = '_';
	}
	campo[posY-2][posX+3] = '0';
	campo[posY-2][posX-1] = '0';
	campo[posY-1][posX+2] = '\\';
    campo[posY-1][posX] = '/';
	campo[posY][posX + 1] = '-';
    campo[posY][posX] = '\\';
    campo[posY][posX + 2] = '/';
    campo[posY+1][posX+1] = '|';
    campo[posY+2][posX+2] = '\\';
    campo[posY+2][posX] = '/';
    campo[posY+3][posX+2] = '/';
    campo[posY+3][posX] = '\\';
    campo[posY+4][posX+1] = '"';
    campo[posY+2][posX+3] = ')';
    campo[posY+2][posX-1] = '(';
    campo[posY+2][posX+4] = ')';
    campo[posY+2][posX-2] = '(';
    campo[posY+1][posX+4] = '/';
    campo[posY+1][posX-2] = '\\';
    campo[posY][posX+5] = '/';
    campo[posY][posX-3] = '\\';
    campo[posY-1][posX+5] = ')';
    campo[posY-1][posX-3] = '(';
    campo[posY-2][posX+5] = ')';
    campo[posY-2][posX-3] = '(';
    campo[posY-2][posX+7] = '>';
    campo[posY-2][posX-5] = '<';
    campo[posY+5][posX+1] = '_';
    campo[posY+5][posX+3] = '/';
    campo[posY+5][posX-1] = '\\';
    campo[posY+4][posX+5] = ')';
    campo[posY+4][posX-3] = '(';
    campo[posY+3][posX+6] = ')';
    campo[posY+3][posX-4] = '(';
    campo[posY+2][posX+7] = ')';
    campo[posY+2][posX-5] = '(';
    campo[posY+1][posX+8] = ')';
    campo[posY+1][posX-6] = '(';
    campo[posY][posX+9] = ')';
    campo[posY][posX-7] = '(';
    campo[posY-1][posX+10] = ')';
    campo[posY-1][posX-8] = '(';
    campo[posY-2][posX+10] = ')';
    campo[posY-2][posX-8] = '(';
    campo[posY-3][posX+9] = ')';
    campo[posY-3][posX-7] = '(';
}

void dibujo_Titulo(char campo[MATRIZ1_V][MATRIZ1_H]){
    string title = "M A Z M O R R A   D E L   G U A R D I Á N   B L A N C O"; //Devulve un valor de la cantidad de letras de la frase 
    int titleLength = title.length();
    int startCol = (MATRIZ1_H - titleLength) / 2; //Centrar el título horizontalmente
    for(i = 0; i < titleLength; i++){
        campo[1][startCol + i] = '>'; //Línea superior del título
        campo[2][startCol + i] = title[i];  // Línea del texto del título
        campo[3][startCol + i] = '<'; //Línea inferior del título
    }
}

void puerta(char campo[MATRIZ1_V][MATRIZ1_H],int posX,int posY){
	for(i=8;i<19;i++){
		campo[posY][posX+i] = 'v';	
	}
    for(i=6;i<17;i++){
		campo[posY][posX-i] = 'v';	
	}
}

void carga_Matriz(char campo[MATRIZ1_V][MATRIZ1_H]){
    for(i=0;i<23;i++){
        for(j=0;j<47;j++){
            if(i==0 or i==22){
                campo[i][j]='-';
            }
            else {
                if(j==0 or j==46){
                    campo[i][j]='|';
                }
                else{
                    campo[i][j]=' ';
                }
            }
        }
    }
    for(i=0;i<23;i++){
        for(j=80;j<MATRIZ1_H;j++){
            if(i==0 or i==22){
                campo[i][j]='-';
            }
            else {
                if(j==80 or j==MATRIZ1_H-1){
                    campo[i][j]='|';
                }
                else{
                    campo[i][j]=' ';
                }
            }
        }
    }
    // Dibujar una frace en el inicio del juego, dentro de la matriz
    dibujo_Titulo(campo);
    //Fila 1 Arbol
    dibujo_Arbol(campo, 7, 19);
	dibujo_Arbol(campo, 10, 28);
	dibujo_Arbol(campo, 33, 34);
	dibujo_Arbol(campo, 85, 19);
	dibujo_Arbol(campo, 50, 30);
	dibujo_Arbol(campo, 66, 36);
	//Fila 2 Arbol
	dibujo_Arbol(campo, 22, 24);
	dibujo_Arbol(campo, 17, 30);
	dibujo_Arbol(campo, 17, 36);
	dibujo_Arbol(campo, 110, 24);
	dibujo_Arbol(campo, 90, 32);
	dibujo_Arbol(campo, 100, 36);
	//Fila 3 Arbol
	dibujo_Arbol(campo, 40, 19);
	dibujo_Arbol(campo, 42, 28);
	dibujo_Arbol(campo, 40, 36);
	dibujo_Arbol(campo, 75, 24);
	dibujo_Arbol(campo, 100, 30);
	dibujo_Arbol(campo, 122, 36);
	//Leon
	dibujo_Leon(campo, 21, 13);
	dibujo_Leon(campo, 104, 13);
    dibujo_Leon(campo, 62, 8);
    puerta(campo, 62, 10);
    //Dibuja un personaje, dentro de la matriz
    if(personajeSeleccionado==false){
		dibujo_Aventurero(campo,62,23);
	}
	else{
		dibujo_Elfo(campo,62,23);
	}
}

void dibujo(char campo[MATRIZ1_V][MATRIZ1_H]){
	cout<<"\n\n\n";
    for(i=0;i<MATRIZ1_V;i++){
    	cout<<"\t\t";
        for(j=0;j<MATRIZ1_H;j++){
            cout<<campo[i][j];
        }
        cout<<"\n";
    }
}

void carga_Campo(char campo[MATRIZ1_V][MATRIZ1_H]){
    for(i=0;i<MATRIZ1_V;i++){
        for(j=0;j<MATRIZ1_H;j++){
            if(i==0 or i==MATRIZ1_V-1){
                campo[i][j]='-';
            }
            else{
                if(j==0 or j==MATRIZ1_H-1){
                    campo[i][j]='|';
                }
                else{
                    campo[i][j]=' ';
                }
            }
        }
    }
}

void dibujo_Aventurero2(char campo_Peque[MATRIZ2_C][MATRIZ2_L],int posX,int posY){
    campo_Peque[posY][posX] = '+';           //Cabeza
    campo_Peque[posY + 1][posX] = '|';       //Cuerpo
    campo_Peque[posY + 2][posX - 1] = '/';   //Pierna izquierda
    campo_Peque[posY + 2][posX + 1] = '\\';  //Pierna derecha
    campo_Peque[posY + 1][posX - 1] = '/';   //Brazo izquierdo
    campo_Peque[posY + 1][posX + 1] = '\\';  //Brazo derecho
    campo_Peque[posY + 1][posX + 2] = '^';   //Mango espada
    campo_Peque[posY][posX + 2] = '|';       //Espada
    campo_Peque[posY + 1][posX - 2] = '0';   //Escudo
}

void dibujo_Elfo2(char campo_Peque[MATRIZ2_C][MATRIZ2_L],int posX,int posY){
    campo_Peque[posY][posX-1] = '-';         //Oreja izquierda
    campo_Peque[posY][posX+1] = '-';         //Oreja derecha
    campo_Peque[posY][posX] = '&';           //Cabeza
    campo_Peque[posY + 1][posX] = '|';       //Cuerpo
	campo_Peque[posY + 1][posX - 1] = '/';   //Brazo izquierdo
    campo_Peque[posY + 1][posX + 1] = '\\';  //Brazo derecho
    campo_Peque[posY + 2][posX-1] = '/';     //Pierna izquierda
    campo_Peque[posY + 2][posX + 1] = '\\';  //Pierna derecha
    campo_Peque[posY + 1][posX + 2] = '|';   //Base arco
	campo_Peque[posY + 1][posX + 3] = ')';   //Cuerda arco
}

void dibujo_Ogro(char campo_Peque[MATRIZ2_C][MATRIZ2_L], int posX,int posY){
    campo_Peque[posY][posX - 1] = '"';       //Oreja izquierda
    campo_Peque[posY][posX + 1] = '"';       //Oreja derecha
    campo_Peque[posY][posX] = '@';           //Cabeza
    campo_Peque[posY + 1][posX] = '|';       //Cuerpo
    campo_Peque[posY + 2][posX - 1] = '/';   //Pierna izquierda
    campo_Peque[posY + 2][posX + 1] = '\\';  //Pierna derecha
    campo_Peque[posY + 1][posX - 1] = '/';   //Brazo izquierdo
    campo_Peque[posY + 1][posX + 1] = '\\';  //Brazo derecho
    campo_Peque[posY + 1][posX + 2] = '|';   //Mango maza
    campo_Peque[posY][posX + 2] = '*';       //Trinchadora con cuchillas
}

void dibujo_Esqueleto(char campo_Peque[MATRIZ2_C][MATRIZ2_L],int posX,int posY){
    campo_Peque[posY][posX] = '!';           //Cabeza
    campo_Peque[posY + 1][posX] = '|';       //Cuerpo
    campo_Peque[posY + 2][posX - 1] = '/';   //Pierna izquierda
    campo_Peque[posY + 2][posX + 1] = '\\';  //Pierna derecha
    campo_Peque[posY + 1][posX - 1] = '/';   //Brazo izquierdo
    campo_Peque[posY + 1][posX + 1] = '\\';  //Brazo derecho
    campo_Peque[posY + 1][posX + 2] = '|';   //Base arco
    campo_Peque[posY + 1][posX + 3] = ')';   //Cuerda arco
}

void dibujo_Leon2(char campo_Peque[MATRIZ2_C][MATRIZ2_L],int posX,int posY){
	campo_Peque[posY-4][posX+1] = '_';
	campo_Peque[posY-4][posX+2] = '_';
	campo_Peque[posY-4][posX+3] = '_';
	campo_Peque[posY-4][posX+4] = '_';
	campo_Peque[posY-4][posX+5] = '_';
	campo_Peque[posY-4][posX+6] = '_';
	campo_Peque[posY-4][posX+7] = '_';
	campo_Peque[posY-4][posX+8] = '_';
	campo_Peque[posY-4][posX-6] = '_';
	campo_Peque[posY-4][posX-5] = '_';
	campo_Peque[posY-4][posX-4] = '_';
	campo_Peque[posY-4][posX-3] = '_';
	campo_Peque[posY-4][posX-2] = '_';
	campo_Peque[posY-4][posX-1] = '_';
	campo_Peque[posY-4][posX] = '_';
	campo_Peque[posY-2][posX+3] = '#'; //Ojo
	campo_Peque[posY-2][posX-1] = '#'; //Ojo
	campo_Peque[posY-1][posX+2] = '\\';
    campo_Peque[posY-1][posX] = '/';
	campo_Peque[posY][posX + 1] = '-';
    campo_Peque[posY][posX] = '\\';
    campo_Peque[posY][posX + 2] = '/';
    campo_Peque[posY+1][posX+1] = '|';
    campo_Peque[posY+2][posX+2] = '\\';
    campo_Peque[posY+2][posX] = '/';
    campo_Peque[posY+2][posX+1] = '='; //Boca
    campo_Peque[posY+3][posX+2] = '/';
    campo_Peque[posY+3][posX] = '\\';
    campo_Peque[posY+4][posX+1] = '"';
    campo_Peque[posY+2][posX+3] = ')';
    campo_Peque[posY+2][posX-1] = '(';
    campo_Peque[posY+2][posX+4] = ')';
    campo_Peque[posY+2][posX-2] = '(';
    campo_Peque[posY+1][posX+4] = '/';
    campo_Peque[posY+1][posX-2] = '\\';
    campo_Peque[posY][posX+5] = '/';
    campo_Peque[posY][posX-3] = '\\';
    campo_Peque[posY-1][posX+5] = ')';
    campo_Peque[posY-1][posX-3] = '(';
    campo_Peque[posY-2][posX+5] = ')';
    campo_Peque[posY-2][posX-3] = '(';
    campo_Peque[posY-2][posX+7] = '>'; //Oreja
    campo_Peque[posY-2][posX-5] = '<'; //Oreja
    campo_Peque[posY+5][posX+1] = '_';
    campo_Peque[posY+5][posX+3] = '/';
    campo_Peque[posY+5][posX-1] = '\\';
    campo_Peque[posY+4][posX+5] = ')';
    campo_Peque[posY+4][posX-3] = '(';
    campo_Peque[posY+3][posX+6] = ')';
    campo_Peque[posY+3][posX-4] = '(';
    campo_Peque[posY+2][posX+7] = ')';
    campo_Peque[posY+2][posX-5] = '(';
    campo_Peque[posY+1][posX+8] = ')';
    campo_Peque[posY+1][posX-6] = '(';
    campo_Peque[posY][posX+9] = ')';
    campo_Peque[posY][posX-7] = '(';
    campo_Peque[posY-1][posX+10] = ')';
    campo_Peque[posY-1][posX-8] = '(';
    campo_Peque[posY-2][posX+10] = ')';
    campo_Peque[posY-2][posX-8] = '(';
    campo_Peque[posY-3][posX+9] = ')';
    campo_Peque[posY-3][posX-7] = '(';
	//Cuello
    campo_Peque[posY+3][posX+7] = '|'; 
    campo_Peque[posY+3][posX-5] = '|';
    campo_Peque[posY+4][posX+7] = '|';
    campo_Peque[posY+4][posX-5] = '|';
    campo_Peque[posY+5][posX+7] = '|';
    campo_Peque[posY+5][posX-5] = '|';
    campo_Peque[posY+6][posX+7] = '\\';
    campo_Peque[posY+6][posX-5] = '/';
}

void dibujo_Ataque_leon2(char campo_Peque[MATRIZ2_C][MATRIZ2_L],int posX,int posY){
	campo_Peque[posY-3][posX+1] = '*'; //Ojo superio
		//Mano derecha
    campo_Peque[posY+2][posX+15] = '|'; //Garra 
    campo_Peque[posY+2][posX+17] = '|';
    campo_Peque[posY+2][posX+13] = '|';
    campo_Peque[posY+3][posX+15] = '8'; //Dedo
    campo_Peque[posY+3][posX+17] = '8';
    campo_Peque[posY+3][posX+13] = '8';
    campo_Peque[posY+4][posX+15] = '^'; //Huella
    campo_Peque[posY+6][posX+15] = 'º'; //Adorno
    campo_Peque[posY+4][posX+17] = '|'; //Mano
    campo_Peque[posY+4][posX+13] = '|';
    campo_Peque[posY+5][posX+16] = '/';
    campo_Peque[posY+5][posX+14] = '\\';
    campo_Peque[posY+6][posX+16] = '|'; //Brazo
    campo_Peque[posY+6][posX+14] = '|';
    campo_Peque[posY+7][posX+16] = '|';
    campo_Peque[posY+7][posX+14] = '|';
    campo_Peque[posY+8][posX+16] = '\\';
    campo_Peque[posY+8][posX+14] = '/';
    //Mano izquierda
    campo_Peque[posY+2][posX-15] = '|'; //Garra 
    campo_Peque[posY+2][posX-13] = '|';
    campo_Peque[posY+2][posX-11] = '|';
    campo_Peque[posY+3][posX-15] = '8'; //Dedo
    campo_Peque[posY+3][posX-11] = '8';
    campo_Peque[posY+3][posX-13] = '8';
    campo_Peque[posY+4][posX-13] = '^'; //Huella
    campo_Peque[posY+6][posX-13] = 'º'; //Adorno
    campo_Peque[posY+4][posX-15] = '|'; //Mano
    campo_Peque[posY+4][posX-11] = '|';
    campo_Peque[posY+5][posX-14] = '\\';
    campo_Peque[posY+5][posX-12] = '/';
    campo_Peque[posY+6][posX-14] = '|'; //Brazo
    campo_Peque[posY+6][posX-12] = '|';
    campo_Peque[posY+7][posX-14] = '|';
    campo_Peque[posY+7][posX-12] = '|';
    campo_Peque[posY+8][posX-14] = '/';
    campo_Peque[posY+8][posX-12] = '\\';
}

void fin_Leon(char campo_Peque[MATRIZ2_C][MATRIZ2_L],int posX,int posY){
	campo_Peque[posY+6][posX+1] = '%'; //Corazon
}

void dibujo_Titulo2(char campo_Peque[MATRIZ2_C][MATRIZ2_L]){
    string title = "C Á M A R A   D E L   J E F E"; //Devulve un valor de la cantidad de letras de la frase 
    int titleLength = title.length();
    int startCol = (MATRIZ2_L - titleLength) / 2; //Centrar el título horizontalmente
    for(i=0;i<titleLength;i++){
        campo_Peque[1][startCol+i] = '>';  //Línea superior del título
        campo_Peque[2][startCol+i] = title[i];  //Línea del texto del título
        campo_Peque[3][startCol+i] = '<';  //Línea inferior del título
    }
}

void dibujo2(char campo_Peque[MATRIZ2_C][MATRIZ2_L]){
	cout<<"\n\n\n";
    for(i=0;i<MATRIZ2_C;i++){
    	cout<<"\t";
        for(j=0;j<MATRIZ2_L;j++){
            cout<<campo_Peque[i][j];
        }
        cout<<"\n";
    }
}

void carga_Campo2(char campo_Peque[MATRIZ2_C][MATRIZ2_L]){
    for(i=0;i<MATRIZ2_C;i++){
        for(j=0;j<MATRIZ2_L;j++){
            if(i==0 or i==MATRIZ2_C-1){
            	campo_Peque[i][j]='-';
            }
            else {
                if(j==0 or j==MATRIZ2_L-1){
                    campo_Peque[i][j]='|';
                }
                else{
                	switch(siguienteNivel){
                		case 0:{
                			campo_Peque[i][j]='.';
							break;
						}
						case 1:{
							campo_Peque[i][j]='~';
							if(j==32){
								campo_Peque[i][j]='(';
							}
							if(j==46){
								campo_Peque[i][j]=')';	
							}
							if(j>=33 && j<=45){
								campo_Peque[i][j]=' ';
							}
							break;
						}
						case 2:{
							campo_Peque[i][j]=' ';
							break;
						}
					}                    
                }
            }
        }
    }
}
