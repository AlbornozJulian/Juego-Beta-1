#include <iostream>

using namespace std;

//Estructura de registro
struct jugador{
	int num;
	string nombre;
	int vida;
	int vidaFull;
	int ataque;
    int defensa;
	int x,y;        //Posicion
	int modX,modY;  //Modificadores
	char imagen;
};
struct npc{
    int num;
    string nombre;
    int vida;
	int ataque;
    int defensa;
    int x,y;        //Posición
    int modX,modY;  //Modificadores
    char imagen;
};
//Estructura de la monedas
struct pun{
	int x,y;//Posición
};

jugador personaje[2];
npc enemigo[3];
pun dinero;

void personajes(){
	personaje[0].num=1;
	personaje[0].nombre="H U M A N O";
	personaje[0].vida=3;
	personaje[0].vidaFull=200;
	personaje[0].ataque=590;
	personaje[0].defensa=360;
	personaje[0].imagen='+';
	personaje[0].x=20; //F
	personaje[0].y=39; //C
	personaje[1].num=2;
	personaje[1].nombre="E l F O";
	personaje[1].vida=3;
	personaje[1].vidaFull=250;
	personaje[1].ataque=550;
	personaje[1].defensa=350;
	personaje[1].imagen='&';
	personaje[1].x=20; //F
	personaje[1].y=39; //C
}
void enemigos(){
    enemigo[0].num=1;
    enemigo[0].nombre ="O G R O";
    enemigo[0].vida=50;
    enemigo[0].ataque=20;
    enemigo[0].defensa=10;
    enemigo[0].imagen='@';
    enemigo[0].x=20;
    enemigo[0].y=10;
    enemigo[1].num=2;
    enemigo[1].nombre="E S Q U E L E T O";
    enemigo[1].vida=40;
    enemigo[1].ataque=15;
    enemigo[1].defensa=10;
    enemigo[1].imagen='!';
    enemigo[1].x=60;
    enemigo[1].y=10;
    enemigo[2].num = 3;
    enemigo[2].nombre="L E Ó N   E C L I P S E";
    enemigo[2].vida=1800;
    enemigo[2].ataque=400;
    enemigo[2].defensa=750;
    enemigo[2].imagen='#';
    enemigo[2].x=38; //C
    enemigo[2].y=8;  //F
}
