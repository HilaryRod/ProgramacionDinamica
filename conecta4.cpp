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
//intenta colocar la ficha en la columna indicada
bool colocarFicha(char tablero[filas][columnas], int columna, char ficha) {
    if (columna < 0 || columna >= columnas) return false;//valida rango
    for (int i = filas - 1; i >= 0; i--) {
        if (tablero[i][columna] == ' ') {
            tablero[i][columna] = ficha; //coloca la ficha en la primera celda libre 
            return true;
        }
    }
    return false; // Columna llena
}

// Verifica si el jugador actual ha ganado
bool hayGanador(char tablero[filas][columnas], char ficha) {
    // Revisa combinaciones horizontales
    for (int i = 0; i < filas; i++) {
        for (int k = 0; k < columnas - 3; k++) {
            if (tablero[i][k] == ficha && tablero[i][k + 1] == ficha &&
                tablero[i][k + 2] == ficha && tablero[i][k + 3] == ficha)
                return true;
        }
    }

    // Revisa combinaciones verticales
    for (int i = 0; i < filas - 3; i++) {
        for (int k = 0; k < columnas; k++) {
            if (tablero[i][k] == ficha && tablero[i + 1][k] == ficha &&
                tablero[i + 2][k] == ficha && tablero[i + 3][k] == ficha)
                return true;
        }
    }

    // Revisa diagonales descendentes ↘
    for (int i = 0; i < filas - 3; i++) {
        for (int k = 0; k < columnas - 3; k++) {
            if (tablero[i][k] == ficha && tablero[i + 1][k + 1] == ficha &&
                tablero[i + 2][k + 2] == ficha && tablero[i + 3][k + 3] == ficha)
                return true;
        }
    }

    // Revisa diagonales ascendentes ↙
    for (int i = 3; i < filas; i++) {
        for (int k = 0; k < columnas - 3; k++) {
            if (tablero[i][k] == ficha && tablero[i - 1][k + 1] == ficha &&
                tablero[i - 2][k + 2] == ficha && tablero[i - 3][k + 3] == ficha)
                return true;
        }
    }

    return false; // No se encontró combinación ganadora
}

void jugarDosJugadores() {
     string jugador1, jugador2;
    cout << "\n=== MODO 2 JUGADORES ===\n";
    cout << "Nombre del jugador 1 (X): ";
    cin >> jugador1;
    cout << "Nombre del jugador 2 (O): ";
    cin >> jugador2;

    bool repetir = true;

    while (repetir) {//mientras repetir sea verdadero 
        char tablero[filas][columnas];
        inicializarTablero(tablero);
        char jugadorActual = 'X';
        bool juegoTerminado = false;

        while (!juegoTerminado) { //si el juego no ha terminado
            mostrarTablero(tablero);
            string nombreActual = (jugadorActual == 'X') ? jugador1 : jugador2;
            //elige el sig jugador
            int columna;
            cout << "\nTurno de " << nombreActual << " (" << jugadorActual << ")"
                 << ". Elige columna (1-7): ";
            cin >> columna;

            //verificaq que sea mayor que uno y menor que 7 y sigue solicitando otro numero hasta que este en ese rango
            if (cin.fail() || columna < 1 || columna > 7) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Entrada invalida. Intenta de nuevo.\n";
                continue;
            }
            //funcion para colocar ficha del jugador 
            if (!colocarFicha(tablero, columna - 1, jugadorActual)) {
                cout << "Columna llena. Intenta otra.\n";
                continue;
            }

            // Verifica si hay ganador o empate
            if (hayGanador(tablero, jugadorActual)) {
                mostrarTablero(tablero);
                cout << "\n¡Felicidades, " << nombreActual << "! Has ganado la partida.\n";
                juegoTerminado = true;
            } else if (tableroLleno(tablero)) {
                mostrarTablero(tablero);
                cout << "\n¡Empate! El tablero está lleno.\n";
                juegoTerminado = true;
            } else {
                // Cambia de jugador
                jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
            }
        }

        }
}}

void jugarContraMaquina(){
    cout << "Aun no esta listo, prueba otra opcion ";
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
          switch (opcion) {
            case 1:
                jugarDosJugadores();
                break;

            case 2:
                jugarContraMaquina();
                break;

            case 3:
                cout << "\nSaliendo del juego... ¡Gracias por jugar!\n";
                salir = true;
                break;

            default:
                cout << "Opcion invalida. Intenta nuevamente.\n";
        }

    } while (!salir);

    return 0;
}
