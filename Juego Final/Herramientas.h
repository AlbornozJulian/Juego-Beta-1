#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstring> 
#include <clocale>

#define Arriba 72
#define Abajo 80
#define Enter 13

using namespace std;

void setConsoleFont(int fontSize){
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &fontInfo);
    fontInfo.dwFontSize.Y = fontSize;  // Tamaño de la fuente
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &fontInfo);
}

void espacio3(){
	for(i=0;i<3;i++){
		cout<<"\n";	
	}
}
void espacio15(){
	for(i=0;i<15;i++){
		cout<<"\n";	
	}
}
void limpia(){
	system("cls");
}
void Spanish(){ // LC_TYPE afecta los caracteres de la función
	setlocale(LC_CTYPE,"Spanish"); // Librería clocale
}

void ConfigurarConsola(){ // Función para configurar la ventana de la consola
    HWND hwnd = GetConsoleWindow();// Obtiene el handle de la ventana de la consola
    ShowWindow(hwnd, SW_MAXIMIZE);// Maximiza la ventana de la consola
    SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);// Desactiva la opción de maximizar y cambiar el tamaño
}

void ajustarTamanoConsola(){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hOut, &bufferInfo);
    // Ajusta el tamaño del buffer de pantalla a las dimensiones actuales de la ventana
    COORD newSize = { bufferInfo.dwSize.X, bufferInfo.srWindow.Bottom - bufferInfo.srWindow.Top + 1 };
    SetConsoleScreenBufferSize(hOut, newSize);
}

void gotoxy(int x,int y){
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}
void centrar_Texto(const char *texto,int y){
	int longitud=strlen(texto);
	gotoxy(60-(longitud/2),y);cout<<texto;
}

void Marco(){
	for(i=1;i<=120;i++){
		gotoxy(1+i,1);cout<<"-";
	}
	for(i=2;i<=26;i++){
		gotoxy(2,i);cout<<"|";
	}
	for(i=2;i<=26;i++){
		gotoxy(121,i);cout<<"|";
	}
	for(i=1;i<=120;i++){
		gotoxy(1+i,26);cout<<"-";
	}
}

int flecha(const char *titulo, const char *opciones[], int n){
	int opSeleccionada = 1, tecla;
	bool repite = true;
	do{
		limpia();
		Marco();
		for(i=1;i<=120;i++){
			gotoxy(1+i,3);cout<<"-";
		}
		gotoxy(40,5+opSeleccionada);cout<<"==>";
		gotoxy(30,2); cout<<titulo; // Imprimir el titulo
		for(i=0;i<n;i++){ // Imprimir las opciones
			gotoxy(45,6+i); cout<< i+1 <<") " << opciones[i];
		}
		do{
		tecla=getch();
		}while(tecla != Arriba && tecla != Abajo && tecla != Enter);
		switch(tecla){
			case Arriba:{
				opSeleccionada--;
				if(opSeleccionada < 1){
					opSeleccionada = n;
				}
				break;
			}
			case Abajo:{
				opSeleccionada++;
				if(opSeleccionada > n){
					opSeleccionada = 1;
				}
				break;
			}
			case Enter:{
				repite = false;
				break;
			}
		}
	}while(repite);
	return opSeleccionada;
}

int flecha2(const char *opciones[], int n){
	char campo[MATRIZ1_V][MATRIZ1_H];
	int opSeleccionada = 1, tecla;
	bool repite = true;
	do{
		limpia();
		carga_Campo(campo);
	    carga_Matriz(campo);
	    dibujo(campo);
		gotoxy(67,18+opSeleccionada);cout<<"==>";
		for(i=0;i<n;i++){ // Imprimir las opciones
			gotoxy(72,19+i); cout<< i+1 <<") " << opciones[i];
		}
		do{
		tecla=getch();
		}while(tecla != Arriba && tecla != Abajo && tecla != Enter);
		switch(tecla){
			case Arriba:{
				opSeleccionada--;
				if(opSeleccionada < 1){
					opSeleccionada = n;
				}
				break;
			}
			case Abajo:{
				opSeleccionada++;
				if(opSeleccionada > n){
					opSeleccionada = 1;
				}
				break;
			}
			case Enter:{
				repite = false;
				break;
			}
		}
	}while(repite);
	return opSeleccionada;
}

void Barra(const char *texto){ // Barra de carga
	setlocale(LC_CTYPE,"C");
	centrar_Texto(texto, 23);
	for(i=3;i<=120;i++){
		gotoxy(i,24);cout<<static_cast<char>(177);
	}
	for(i=3;i<=120;i++){
		gotoxy(i,24);cout<<static_cast<char>(219);
		Sleep(35);//Milisegundos 1000 = 1 segundo
	}
}
