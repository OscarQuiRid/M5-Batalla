//#include "Personaje.h"
//#include "Spells.h"
//#include <iostream>
//using namespace std;
//// x altura, Y ancho
//Spells spell1, spell2, spell3, spell4;
//Personaje mapa[4][9], player, enemy1, enemy2, enemy3, enemy4, enemy5, enemy6, enemy7, enemy8, boss, reutilizable;
//bool map[4][9];
//
//void createSpells() {
//	spell1 = Spells("Exori Mort", 50);
//	spell2 = Spells("Exori Frigo", 50);
//	spell3 = Spells("Exori Tera", 50);
//	spell4 = Spells("Exori Flam", 50);
//}
//void createEnemis() {
//	//Personaje(pVida,pAtaque,pNombre,pPosicionX,pPosicionY)
//	player = Personaje(500, 15, "", 0, 0);
//	enemy1 = Personaje(100, 10, "Orc", 0, 0);
//	enemy2 = Personaje(100, 10, "Troll", 0, 0);
//	enemy3 = Personaje(100, 10, "Bear", 0, 0);
//	enemy4 = Personaje(100, 10, "Skeleton", 0, 0);
//	enemy5 = Personaje(100, 10, "Minotaur", 0, 0);
//	enemy6 = Personaje(100, 10, "Mutated Human", 0, 0);
//	enemy7 = Personaje(100, 10, "Cyclop", 0, 0);
//	enemy8 = Personaje(100, 10, "Gargole", 0, 0);
//	boss = Personaje(500, 30, "Demon", 0, 0);
//}
//Personaje generateMonster(Personaje pEnemigo) {
//	int randomNumber = rand() % 8 + 1;
//
//	switch (randomNumber)
//	{
//	case 1:
//		pEnemigo = enemy1;
//		break;
//	case 2:
//		pEnemigo = enemy2;
//		break;
//	case 3:
//		pEnemigo = enemy3;
//		break;
//	case 4:
//		pEnemigo = enemy4;
//		break;
//	case 5:
//		pEnemigo = enemy5;
//		break;
//	case 6:
//		pEnemigo = enemy6;
//		break;
//	case 7:
//		pEnemigo = enemy7;
//		break;
//	case 8:
//		pEnemigo = enemy8;
//		break;
//	default:
//		break;
//	}
//	return pEnemigo;
//}
//int asignarPosicionX(int& x) {
//
//	x = rand() % 4;
//	return x;
//}
//int asignarPosicionY(int& y) {
//
//	y = rand() % 9;
//	return y;
//
//}
//
//void createMapInicial() {
//	int y = 0;
//	player.setPosicionX(0);
//	player.setPosicionY(asignarPosicionY(y));
//	mapa[player.getPosicionX()][player.getPosicionY()] = player;
//	map[player.getPosicionX()][player.getPosicionY()] = true;
//
//	boss.setPosicionX(9);
//	boss.setPosicionY(asignarPosicionY(y));
//	mapa[boss.getPosicionX()][boss.getPosicionY()] = boss;
//	map[boss.getPosicionX()][boss.getPosicionY()] = true;
//
//	for (size_t i = 1; i < sizeof(mapa); i++)
//	{
//		generateMonster(reutilizable);
//		asignarPosicionY(y);
//		if (!map[i][y])
//		{
//			mapa[i][y] = reutilizable;
//			map[i][y] = true;
//		}
//	}
//}
//void printarMapa() {
//	for (size_t i = 0; i < sizeof(mapa) / sizeof(mapa[0]); i++) {
//		for (size_t j = 0; j < sizeof(mapa[0]) / sizeof(mapa[0][0]); j++) {
//			cout << mapa[i][j].getNombre(); // Imprime el nombre del personaje en esa posición
//			if (map[i][j]) {
//				cout << "[X]"; // Si el mapa en esa posición está marcado como ocupado, muestra una 'X'
//			}
//			else {
//				cout << "[ ]";
//			}
//		}
//	}
//}
//void saludo() {
//	string apodo;
//	cout << "Introduce tu nombre";
//	cin >> apodo;
//	player.setNombre(apodo);
//}