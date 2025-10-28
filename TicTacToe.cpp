#include <iostream> // Para entrada y salida
using namespace std; //para no tener que usar std en todas las lineas

//Declaracion de variables que voy a usar
string jugador1;
string jugador2;
char turno = 'X';
char tablero[9] = {'1','2','3','4','5','6','7','8','9'}; // Tablero para jugar 9 posiciones

//Declaracion de mis funciones
void estructuragato();
bool ganador();//declaracion para que sea falso o verdadero si gano o no

//Funcion principal
int main() {
    cout << "Ingresa el nombre del primer jugador (X): ";
    cin >> jugador1;
    cout << "Ingresa el nombre del segundo jugador (O): ";
    cin >> jugador2;
   
}

void estructuragato(){
     cout << "\n  " << tablero[0] << " | " << tablero[1] << " | " << tablero[2] << endl;
     cout << " ---|---|---" << endl;
     cout << "  " << tablero[3] << " | " << tablero[4] << " | " << tablero[5] << endl;
     cout << " ---|---|---" << endl;
     cout << "  " << tablero[6] << " | " << tablero[7] << " | " << tablero[8] << endl;
}

bool ganador() {
    int combinaciones[8][3] = { //va a recorrer cada una de las 8 combinaciones ganadoras
        {0,1,2}, {3,4,5}, {6,7,8}, // Se puede ganar asi por filas
        {0,3,6}, {1,4,7}, {2,5,8}, // Se puede ganar asi por columnas
        {0,4,8}, {2,4,6}           // Se puede ganar asi en diagonales
    };

    for (auto &linea : combinaciones) { //para cada linea en combinacion, bucle

        if (tablero[linea[0]] == turno && tablero[linea[1]] == turno && tablero[linea[2]] == turno) { //verifica si las 3 posiciones estan ocupadas por el simbolo del jugador
            return true; //si es cierto el jugador ya gano y por eso devuelve true
        }
    }
    return false; //si no retorna falso 
}
