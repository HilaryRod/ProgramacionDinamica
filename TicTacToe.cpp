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
bool empate(); //funcion si hay empate
void cambiarTurno();
void jugar();
void reiniciarTablero(); //funcion para reiniciar tablero o se limpiarlo
//Funcion principal
int main() {
    cout << "Ingresa el nombre del primer jugador (X): ";
    cin >> jugador1;
    cout << "Ingresa el nombre del segundo jugador (O): ";
    cin >> jugador2;
    char jugarOtraVez = 'S';
    do{
        reiniciarTablero(); //asegurarnos de que este limpio
        jugar(); // Llamada a la función que contiene toda la lógica del juego
        cout << "\n¿Desean jugar otra partida? (S/N): ";
        cin >> jugarOtraVez;
        jugarOtraVez = toupper(jugarOtraVez); // Para aceptar s/S
    } while (jugarOtraVez == 'S');
    
    cout << "Gracias por jugar. ¡Hasta luego!\n";
    return 0;
}

//Funcion que va a ir ejecutando el juego
void jugar() {
    string entrada;
    int movimiento; //declaro la variable para los movimientos
    bool juegoTerminado = false; //inicializo mi variable en falso

    do {
        estructuragato(); //muestro el gato
        // Imprime de quien es el turno, si el turno estaba en x muestra el nombre del jugador 2 y viceversa
        cout << "\nTurno de " << (turno == 'X' ? jugador1 : jugador2) << " (" << turno << ")" << endl;
        //pide que el usuario digite un numero donde quiere colocar su X o O
        cout << "Elige una posicion (solo numero del 1 al 9): ";
        //leemos el num de digito y lo guardamos en la variable movimiento
        cin >> entrada;
        //para verificar que sean solo numeros los ingresados
        bool esNumero = true;
        for (char c : entrada) { //se recorre la entrada por caracteres
            if (!isdigit(c)) {  // Si algún carácter no es número
                esNumero = false; //se pone que es falso que sea numero
                break;
            }
        }
        if(!esNumero){
            cout << "Entrada invalida, solo puedes poner numeros. \n";
            continue;
        }

        movimiento = stoi(entrada); //para convertir a int la entrada de el usuario
        // Validar numero escogido de movimiento, si tiene alguna de estas cosas nos va a pedir ingresar otra posicion
        if ( movimiento < 1 || movimiento > 9 || tablero[movimiento - 1] == 'X' || tablero[movimiento - 1] == 'O' ) {
            cout << "Movimiento invalido, intenta de nuevo.\n";
            continue;
        }
        // Marcar el movimiento en el tablero, se usa el menos 1 porque inicia de 0
        tablero[movimiento - 1] = turno; //se marca con X o O dependiendo el turno

        // Comprobar si hay ganador
        if (ganador()) {
            estructuragato(); //imprimimos el tablero
            //mostramos en consola que gano
            cout << "\n ¡Felicidades " << (turno == 'X' ? jugador1 : jugador2) << "! Has ganado. \n"; 
            //se termina el juego
            juegoTerminado = true;
        } 
        //por si llega a existir empate
        else if (empate()) {
            estructuragato();
            cout << "\n ¡Empate! No hay más movimientos posibles.\n";
            juegoTerminado = true;
        } 
        else {
            //llamamos a nuestra funcion que cambia el turno
            cambiarTurno(); // Cambiar turno
        }

    } while (!juegoTerminado); //mientras el juego aun no termine se seguira repitiendo
}

//funcion para imprimir en consola el gato con estructura
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
       //es como decir la casilla en el indice linea[] pertenece al jugador que esta en turno
        if (tablero[linea[0]] == turno && tablero[linea[1]] == turno && tablero[linea[2]] == turno) { //verifica si las 3 posiciones estan ocupadas por el simbolo del jugador
            return true; //si es cierto el jugador ya gano y por eso devuelve true
        }
    }
    return false; //si no retorna falso 
}

// Función para verificar si el tablero está lleno y no ha habido ganador
bool empate() {
    for (int i = 0; i < 9; i++) { //recorre el tablero con el for
        //va verificando si hay algun espacio que no tenga X u O
        if (tablero[i] != 'X' && tablero[i] != 'O') 
        //retorna falso si aun hay un espacio sin X u O
            return false;
    }
    //retorna verdadero si realmente todo esta lleno con X o O 
    return true;
}

// Función para cambiar el turno
void cambiarTurno() {
    if (turno == 'X') { //si turno esta en X
        turno = 'O'; //Ahora es turno del O 
    } else { //Si no estaba en X
        turno = 'X'; //Ahora es turno de X
    }
}