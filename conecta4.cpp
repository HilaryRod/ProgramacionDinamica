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
// Punto de entrada del programa
int main() {
    
}