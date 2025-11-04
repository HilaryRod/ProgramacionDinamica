//bIBLIOTECAS QUE SE USARAN
#include <iostream>
using namespace std;//para no tener que poner std en cada cin o cout 
//Se necesita hacer diferente al gato porque tiene mas casillas
const int filas = 6; //defino num de filas
const int columnas = 7;//defino num de columnas

// Función para inicializar el tablero
void inicializarTablero(char tablero[filas][columnas]) {
    for (int i = 0; i < filas; i++) { //se recorren las filas
        for (int k = 0; k < columnas; k++) { //se recorren las columnas
            tablero[i][k] = ' '; //cada celda comienza vacia 
        }
    }
}
// Mostrar el tablero
void mostrarTablero(char tablero[filas][columnas]) {
    cout << "\n   1 2 3 4 5 6 7\n"; //estos numero ayudan a guiar al jugador
    cout << "  ---------------\n"; //se va haciendo el trablero
    for (int i = 0; i < filas; i++) { //se usa un bucle 
        cout << i + 1 << " |"; //numero de fila 
        for (int k = 0; k < columnas; k++) {
            cout << tablero[i][k] << "|"; //contenido de cada celda
        }
        cout << "\n  ---------------\n"; //linea que va separar
    }
}

// Muestra el menú principal del juego
void mostrarMenu() {
    cout << "\n=== MENU PRINCIPAL ===\n";
    cout << "1. Jugar (2 jugadores)\n";
    cout << "2. Jugar contra computadora\n";
    cout << "3. Salir\n";
    cout << "Elige una opción: ";
}
// Punto de entrada del programa
int main() {
    //declaraciones variables
    int opcion;
    bool salir = false;

    do { //muestro el menu de opciones
        mostrarMenu();
        cin >> opcion; //leo la opcion ingresada por usuario

        // Validación de entrada
        if (cin.fail()) { //si no es numero 
            cin.clear(); //limpio 
            cin.ignore(1000, '\n');
            cout << "Opcion invalida. Intenta nuevamente.\n";
            continue; //vuelve a mostrar el menu 
        }
}}