#include "Logica.h"
#include "Personaje.h"
#include "Spells.h"
#include <iostream>
using namespace std;
// x altura, Y ancho
Spells Logica::spell1, Logica::spell2, Logica::spell3, Logica::spell4;
Personaje Logica::mapa[10][5], Logica::player, Logica::enemy1, Logica::enemy2, Logica::enemy3, Logica::enemy4, Logica::enemy5, Logica::enemy6, Logica::enemy7, Logica::enemy8, Logica::boss, Logica::reutilizable;
bool Logica::map[10][5];

void Logica::createSpells() {
	cout << "dentro de spells";
	spell1 = Spells("Exori Mort", 50);
	spell2 = Spells("Exori Frigo", 50);
	spell3 = Spells("Exori Tera", 50);
	spell4 = Spells("Exori Flam", 50);
}
void Logica::createEnemis() {
	cout << "dentro de enemigos";
	//Personaje(pVida,pAtaque,pNombre,pPosicionX,pPosicionY)
	player = Personaje(500, 15, "player", 0, 0);
	enemy1 = Personaje(100, 10, "Orc", 0, 0);
	enemy2 = Personaje(100, 10, "Troll", 0, 0);
	enemy3 = Personaje(100, 10, "Bear", 0, 0);
	enemy4 = Personaje(100, 10, "Skeleton", 0, 0);
	enemy5 = Personaje(100, 10, "Minotaur", 0, 0);
	enemy6 = Personaje(100, 10, "Mutated Human", 0, 0);
	enemy7 = Personaje(100, 10, "Cyclop", 0, 0);
	enemy8 = Personaje(100, 10, "Gargole", 0, 0);
	boss = Personaje(500, 30, "Demon", 0, 0);
}
Personaje Logica::generateMonster(Personaje pEnemigo) {
	int randomNumber = rand() % 8 + 1;

	switch (randomNumber)
	{
	case 1:
		pEnemigo = enemy1;
		break;
	case 2:
		pEnemigo = enemy2;
		break;
	case 3:
		pEnemigo = enemy3;
		break;
	case 4:
		pEnemigo = enemy4;
		break;
	case 5:
		pEnemigo = enemy5;
		break;
	case 6:
		pEnemigo = enemy6;
		break;
	case 7:
		pEnemigo = enemy7;
		break;
	case 8:
		pEnemigo = enemy8;
		break;
	default:
		break;
	}
	return pEnemigo;
}
int Logica::asignarPosicionX(int& x) {

	x = rand() % 10;
	return x;
}
int Logica::asignarPosicionY(int& y) {

	y = rand() % 5;
	return y;

}
void Logica::createMapInicial() {
	int y = 0;
	cout << "dentro de mapa";
	player.setPosicionX(0);
	player.setPosicionY(asignarPosicionY(y));
	mapa[0][y] = player;
	map[0][y] = true;

	boss.setPosicionX(9);
	boss.setPosicionY(asignarPosicionY(y));
	mapa[9][y] = boss;
	map[9][y] = true;

	// Posicionamiento de los enemigos
	for (int i = 1; i < 9; ++i) {
		int y = asignarPosicionY(y);
		enemy1 = generateMonster(reutilizable);
		mapa[i][y] = reutilizable;
		map[i][y] = true;
	}
}
void Logica::printarMapa() {
	cout << "dentro de print\n";
	for (size_t i = 0; i < sizeof(mapa) / sizeof(mapa[0]); i++) {
		for (size_t j = 0; j < sizeof(mapa[0]) / sizeof(mapa[0][0]); j++) {
			if (map[i][j]) {
				reutilizable = mapa[i][j];
				cout << "[" << reutilizable.getNombre() << "]";
			}
			else {
				cout << "[ ]";
			}
		}
		cout << "\n";
	}
}
void Logica::saludo() {
	string apodo;
	cout << "Introduce tu nombre: ";
	cin >> apodo;
	player.setNombre(apodo);
	cout << "¡Hola, " << player.getNombre() << "! Bienvenido al juego." << endl;
}