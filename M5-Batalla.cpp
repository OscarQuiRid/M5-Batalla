#include "Logica.h"
#include <iostream>

using namespace std;

// no printa nombres revisar por que, si es por que no se esta accediendo correctamente a la memoria royo ememy1.getnombre() si asi buscar como relacionar o saltarse el random y meter los enemigos a mano igual que ize con el player y el boss



// el juego apareceras en posicion [0][3] y te moveras en las [1][2],[1][3],[1][4]
// posicion 0 es la salida, posicion 1 al 8 son monstruos y la 9 es el boss
int main() {
    cout << "\ninicio\n";
    Logica::createSpells();
    cout << "\nentre spells y enemis\n";
    Logica::createEnemis();
    cout << "\nentre enemigos y mapa\n";
    Logica::createMapInicial();
    cout << "\nentre mapa y printar mapa\n";
    Logica::printarMapa();
    cout << "\nantessaludo\n";
    Logica::saludo();
}