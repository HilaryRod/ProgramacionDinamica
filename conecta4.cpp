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
            tablero[i][k] = ' ';
        }
    }
}