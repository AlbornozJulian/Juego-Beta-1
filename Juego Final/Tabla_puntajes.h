#include <iostream>
#include <fstream>// Para manejar archivos
#include <sstream>// Para ostringstream
#include <string>// Para usar string
#include <iomanip>
#include <ctime>// Para generar números aleatorios, intrucciones srand y rand
#include <conio.h>// Para la instruccion getch().

string nombre= "",texto= "";

void Crear(){
    ofstream archivo;// De output para escribir
    archivo.open("Tabla_puntaje.txt", ios::out);// Crea o reemplaza el archivo
    if (archivo.fail()) {
        cout<<"\n\t No se pudo crear el archivo."<<endl;
    } else {
        cout <<"\n\t Archivo creado con exito."<<endl;
    }
    archivo.close();// Cerrar el archivo
}

void Aniadir(string &texto){
    ofstream archivo;
    archivo.open("Tabla_puntaje.txt", ios::app);// Abrimos el archivo en modo añadir
    if (archivo.fail()) { // Si no se pudo abrir el archivo, lo creamos
        Crear();// Crear el archivo si no existe
        archivo.open("Tabla_puntaje.txt", ios::app);// Volver a intentar abrir el archivo
        if (archivo.fail()) { // Verificar que se abrió correctamente
            cout<<"\n\t Error al abrir el archivo."<<endl;
            exit(1);
        }
    }
    archivo<<texto<<endl;
    archivo.close();// Cerrar el archivo
}

void Lectura(){
    ifstream archivo;// De lectura
    archivo.open("Tabla_puntaje.txt", ios::in);// Abrimos el archivo en modo lectura
    if (archivo.fail()) {
        archivo.close();// Cerrar el archivo
        Crear();
        exit(1);
    }
    string linea;
    limpia();
    espacio3();
    cout<<"\n\t\t>> FECHA"<<"\t\t>> PUNTAJE"<<"\t\t>> NOMBRE JUGADOR"<<endl;
    while (getline(archivo, linea)) { // Leer línea a línea
        cout<<"\n\t\t"<<linea<<endl;
    }
    archivo.close();// Cerrar el archivo
}

void crear_Archivo(){
    char aux;
    setConsoleFont(24);// Establece el tamaño de la fuente
	system("COLOR 9F");
	Spanish();
    // Usando ostringstream para convertir int a string
    ostringstream ss_puntaje;
    ss_puntaje << puntaje_Final;
    string puntos = ss_puntaje.str();
    // Timpo
    time_t now = time(0);
    tm *ltm = localtime(&now);        
    // Formatear la fecha como "dd/mm/aaaa"
    ostringstream ss_fecha; // Crear ostringstream para la fecha
    ss_fecha << setfill('0') << setw(2) << ltm->tm_mday << "/" << setw(2) << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year;
    string fecha = ss_fecha.str();
    do {
    	limpia();
    	espacio3();
        cout << "\n\t\t >> Ingrese su nombre." << endl;
        cin.ignore();
        cout << "\n\t\t << Nombre: ";
        getline(cin, nombre);
        cout << "\n\t\t >> ¿El nombre ingresado es correcto? (S/N): ";
        cin >> aux;
    } while ((aux == 'N') || (aux == 'n'));
    limpia();
    texto = fecha + "\t\t" + puntos + "\t\t\t" + nombre ;
    Aniadir(texto);
    Lectura();
}
