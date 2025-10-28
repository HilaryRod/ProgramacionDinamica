#include <iostream> // Para entrada y salida
using namespace std; //para no tener que usar std en todas las lineas

//Declaracion de variables que voy a usar
string jugador1;
string jugador2;
char turno = 'X';
char tablero[9] = {'1','2','3','4','5','6','7','8','9'}; // Tablero para jugar 9 posiciones

//Funcion principal
int main() {
    cout << "Ingresa el nombre del primer jugador (X): ";
    cin >> jugador1;
    cout << "Ingresa el nombre del segundo jugador (O): ";
    cin >> jugador2;
}