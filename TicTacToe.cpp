#include <iostream> // Para entrada y salida
using namespace std; //para no tener que usar std en todas las lineas

//Declaracion de variables que voy a usar
string jugador1;
string jugador2;
char turno = 'X';
char tablero[9] = {'1','2','3','4','5','6','7','8','9'}; // Tablero para jugar 9 posiciones

//Declaracion de mis funciones
void estructuragato();

//Funcion principal
int main() {
    cout << "Ingresa el nombre del primer jugador (X): ";
    cin >> jugador1;
    cout << "Ingresa el nombre del segundo jugador (O): ";
    cin >> jugador2;
    estructuragato();//prueba para ver si funciona la estructura
}

void estructuragato(){
     cout << "\n  " << tablero[0] << " | " << tablero[1] << " | " << tablero[2] << endl;
     cout << " ---|---|---" << endl;
     cout << "  " << tablero[3] << " | " << tablero[4] << " | " << tablero[5] << endl;
     cout << " ---|---|---" << endl;
     cout << "  " << tablero[6] << " | " << tablero[7] << " | " << tablero[8] << endl;
}