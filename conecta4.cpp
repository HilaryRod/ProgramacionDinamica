#include <iostream> // Para entrada y salida
using namespace std; //para no tener que usar std en todas las lineas

//Declaracion de variables que voy a usar
string jugador1;
string jugador2;
char turno = 'X';
char tablero[14] = {'1','2','3','4','5','6','7','8','9','10','11','12','13','14'}; // Tablero para jugar 9 posiciones

//Declaracion de mis funciones
void estructurtablero();
bool ganador();//declaracion para que sea falso o verdadero si gano o no
void cambiarTurno();
void jugar();
void reiniciarTablero(); //funcion para reiniciar tablero o se limpiarlo