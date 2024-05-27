#include "Logica.h"
#include <iostream>
#include <conio.h>

using namespace std;


// para hacer el loot hay que hacer un Loot.h crear las variables ahi, hacer un constructor para cada item (string nombre, int ataque, int defensa), 
//      un switch donde del 1 al 3 esten todos los items de malo medio y bueno con cada parte del set, con rand que genere cada parte del switch y lo guarde
//      una variable equipo ejemplo equipoHelmet etc que sera -- equipoHelmet = botinHelmet; con armor legs botas shield y sword 
// suma de todos los .getatake y .getdefensa y eso se suma a los stats del personaje y printar todos los nombres de lo que encontraste.
// incluir tambien probabilidad de generar 1 spell aleatoria en el lot y que la muestre como has encontrado un pergamino con unas inscripciones antiguas y decir el nombre
// un rand que pase por cada una de las funciones del set y lo genere y lo guarde en

int main() {
    srand(time(NULL));
    string apodo;

    Logica::createSpells();
    Logica::createEnemis();
    Logica::createMapInicial();

    cout << "\n\n";                 // borrar

    cout << "Introduce tu nombre: ";
    cin >> apodo;
    Logica::player.setNombre(apodo);
    cout << "Hola, " << Logica::player.getNombre() << "! Bienvenido al juego." << endl;

    cout << "Presiona flechas para desplazarte por el mapa o Presiona tecla ESC para salir \n";

    bool juego = true;
    while (juego) {
        if (_kbhit()) {
            int tecla = _getch();
            if (tecla == 27) {
                break;
            }
            if (tecla == 224) {
                tecla = _getch();
                Logica::procesarFlecha(tecla, juego);
                Logica::revisarEnemigos(juego);
                if (!juego)
                {
                    break;
                }
            }
        }
    }
}