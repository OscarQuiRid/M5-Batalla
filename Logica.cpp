#include "Logica.h"
#include "Personaje.h"
#include "Spells.h"
#include <conio.h>
#include <iostream>
using namespace std;
// x altura, Y ancho
// falta ponerle magias al boss creando una funcion para asignarlas con un rand y un constructor o un set spell
Spells Logica::spell1, Logica::spell2, Logica::spell3, Logica::spell4, Logica::reusable1, Logica::reusable2;
Personaje Logica::mapa[10][5], Logica::player, Logica::enemy1, Logica::enemy2, Logica::enemy3, Logica::enemy4, Logica::enemy5, Logica::enemy6, Logica::enemy7, Logica::enemy8, Logica::boss, Logica::reutilizable, Logica::vacio;
bool Logica::map[10][5];

void Logica::createSpells() {
	spell1 = Spells("Exori Mort", 50);
	spell2 = Spells("Exori Frigo", 50);
	spell3 = Spells("Exori Tera", 50);
	spell4 = Spells("Exori Flam", 50);
}
void Logica::crateBoss(Spells& spellUnos) {
	int randomNumber = rand() % 4 + 1;
	switch (randomNumber)
	{
	case 1:
		spellUnos = spell1;
		break;
	case 2:
		spellUnos = spell2;
		break;
	case 3:
		spellUnos = spell3;
		break;
	case 4:
		spellUnos = spell4;
		break;
	default:
		break;
	}

}
void Logica::createEnemis() {
	crateBoss(reusable1);
	crateBoss(reusable2);
	player = Personaje(1400, 15, "", 0, 0);
	enemy1 = Personaje(100, 10, "Orc", 0, 0);
	enemy2 = Personaje(100, 10, "Troll", 0, 0);
	enemy3 = Personaje(100, 10, "Bear", 0, 0);
	enemy4 = Personaje(100, 10, "Skeleton", 0, 0);
	enemy5 = Personaje(100, 10, "Minotaur", 0, 0);
	enemy6 = Personaje(100, 10, "Mutated Human", 0, 0);
	enemy7 = Personaje(100, 10, "Cyclop", 0, 0);
	enemy8 = Personaje(100, 10, "Gargole", 0, 0);
	boss = Personaje(500, 15, "Demon", 0, 0, reusable1.getSpellName(), reusable1.getSpell(), reusable2.getSpellName(), reusable2.getSpell());
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

	x = rand() % 5;
	return x;
}
int Logica::asignarPosicionY(int& y) {

	y = rand() % 10;
	return y;

}
void Logica::createMapInicial() {
	player.setPosicionY(0);
	player.setPosicionX(0);
	mapa[0][0] = player;

	int x = asignarPosicionX(x);
	boss.setPosicionY(9);
	boss.setPosicionX(x);
	mapa[9][x] = boss;
	map[9][x] = true;

	for (int i = 1; i < 9; ++i) {
		x = asignarPosicionX(x);
		reutilizable = generateMonster(reutilizable);
		reutilizable.setPosicionY(i);
		reutilizable.setPosicionX(x);
		mapa[i][x] = reutilizable;
		map[i][x] = true;
	}
}
void Logica::hits(int& valorAtaque, bool esBoss, bool esPlayer, int posY, int posX)
{
	if (esPlayer) {
		valorAtaque = rand() % player.getAtaque() + 1;
	}
	else if (esBoss) {
		int spell = rand() % 100 + 1;
		if (spell <= 10) {
			valorAtaque = rand() % boss.getSpell() + 1;
			cout << boss.getNombre() << " a lanzado la magia " << boss.getSpellName() << "\n";
		}
		else if (spell >= 11 && spell <= 20) {

			valorAtaque = rand() % boss.getSpell2() + 1;
			cout << boss.getNombre() << " a lanzado la magia " << boss.getSpellName2() << "\n";
		}
		else
		{
			valorAtaque = rand() % boss.getAtaque() + 1;
		}
	}
	else {
		valorAtaque = rand() % mapa[posY][posX].getAtaque() + 1;
	}
}
void Logica::pelea(int posY, int posX, bool& salirJuego) {
	bool esPlayer, esBoss = mapa[posY][posX].getNombre() == "Demon";
	int valorAtaque = 0;

	if (mapa[posY][posX].getNombre() != "" && mapa[posY][posX].getNombre() != "player") {
		cout << "Tu presencia a enfurecido a " << mapa[posY][posX].getNombre() << "!\n";
		while (player.getVida() > 0 && mapa[posY][posX].getVida() > 0) {
			esPlayer = true;
			valorAtaque = player.getAtaque();
			hits(valorAtaque, esBoss, esPlayer, posY, posX);
			mapa[posY][posX].setVida(mapa[posY][posX].getVida() - valorAtaque);
			if (mapa[posY][posX].getVida() <= 0) {
				mapa[posY][posX].setVida(0);
				cout << mapa[posY][posX].getNombre() << " a recivido " << valorAtaque << " de un golpe, le queda " << mapa[posY][posX].getVida() << " de vida.\n";
				cout << "El enemigo " << mapa[posY][posX].getNombre() << " ha muerto.\n";
				mapa[posY][posX] = Personaje();
				map[posY][posX] = false;
				break;
			}
			else if (valorAtaque == 0)
			{
				cout << player.getNombre() << " ha fallado el ataque.\n";
			}
			else
			{
				cout << mapa[posY][posX].getNombre() << " a recivido " << valorAtaque << " de un golpe, le queda " << mapa[posY][posX].getVida() << " de vida.\n";
			}
			revisarEnemigos(salirJuego);
			esPlayer = false;
			valorAtaque = mapa[posY][posX].getAtaque();
			hits(valorAtaque, esBoss, esPlayer, posY, posX);
			player.setVida(player.getVida() - valorAtaque);
			if (player.getVida() <= 0) {
				player.setVida(0);
				cout << player.getNombre() << " ha recibido " << valorAtaque << " de un golpe, le queda " << player.getVida() << " de vida.\n";
				cout << "You are Dead!\n";
				salirJuego = false;
				break;
			}
			else if (valorAtaque == 0)
			{
				cout << mapa[posY][posX].getNombre() << " ha fallado el ataque.\n";
			}
			else
			{
				cout << player.getNombre() << " ha recibido " << valorAtaque << " de un golpe, le queda " << player.getVida() << " de vida.\n";
			}
		}
	}
}
void Logica::procesarFlecha(int key, bool& salirJuego) {
	int nuevaX = player.getPosicionX();
	int nuevaY = player.getPosicionY();

	switch (key) {
	case 72: // Flecha hacia arriba
		if (nuevaY > 0) {
			nuevaY--;
		}
		else {
			cout << "No puedes ir hacia arriba desde esta posicion.\n";
			return;
		}
		break;
	case 80: // Flecha hacia abajo
		if (nuevaY < 9) {
			nuevaY++;
		}
		else {
			cout << "No puedes ir hacia abajo desde esta posicion.\n";
			return;
		}
		break;
	case 75: // Flecha hacia izquierda
		if (nuevaX > 0) {
			nuevaX--;
		}
		else {
			cout << "No puedes ir hacia la izquierda desde esta posicion.\n";
			return;
		}
		break;
	case 77: // Flecha hacia derecha
		if (nuevaX < 4) {
			nuevaX++;
		}
		else {
			cout << "No puedes ir hacia la derecha desde esta posicion.\n";
			return;
		}
		break;
	default:
		cout << "Otra tecla presionada\n";
		break;
	}
	if (mapa[nuevaY][nuevaX].getNombre() != "" && mapa[nuevaY][nuevaX].getNombre() != "player") {
		cout << "Te topaste con " << mapa[nuevaY][nuevaX].getNombre() << "!\n";
		pelea(nuevaY, nuevaX, salirJuego);
	}
	else {
		mapa[player.getPosicionY()][player.getPosicionX()] = Personaje();
		player.setPosicionX(nuevaX);
		player.setPosicionY(nuevaY);
		mapa[player.getPosicionY()][player.getPosicionX()] = player;
		printarMapa();
		cout << "\n\n\n";
	}
}
void Logica::printarMapa() {
	// i == x
	// j == y
	for (size_t i = 0; i < sizeof(mapa) / sizeof(mapa[0]); i++) {
		for (size_t j = 0; j < sizeof(mapa[0]) / sizeof(mapa[0][0]); j++) {
			if (player.getPosicionY() == i && player.getPosicionX() == j) {
				cout << "[P]";
			}
			//else if (map[i][j])		// ocultar
			//{
			//	reutilizable = mapa[i][j];
			//	cout << "[" << reutilizable.getNombre() << "]";
			//}
			else {
				cout << "[ ]";
			}
		}
		cout << "\n";
	}
}
void Logica::revisarEnemigos(bool& salirJuego) {
	int enemigosRestantes = 0;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (map[i][j] == true) {
				enemigosRestantes++;
			}
		}
	}
	if (enemigosRestantes == 0) {
		cout << "Felizidades has limpiado toda la cueva! \n";
		salirJuego = false;
	}
}