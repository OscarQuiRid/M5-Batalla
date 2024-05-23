#include "Personaje.h"
#include "Spells.h"

using namespace std;

Spells spell1, spell2, spell3, spell4;
Personaje player, enemy1, enemy2, enemy3, enemy4, enemy5, enemy6, enemy7, boss;

void createSpells() {
	spell1 = Spells("Exori Mort", 50);
	spell2 = Spells("Exori Frigo", 50);
	spell3 = Spells("Exori Tera", 50);
	spell4 = Spells("Exori Flam", 50);
}
void createEnemis() {
	//Personaje(int pVida, int pAtaque, string pNombre, int pPosicionX, int pPosicionY)
	enemy1 = Personaje(100, 10, "Orc", 0, 0);
	enemy2 = Personaje(100, 10, "Troll", 0, 0);
	enemy3 = Personaje(100, 10, "Bear", 0, 0);
	enemy4 = Personaje(100, 10, "Skeleton", 0, 0);
	enemy5 = Personaje(100, 10, "Minotaur", 0, 0);
	enemy6 = Personaje(100, 10, "Mutated Human", 0, 0);
	enemy7 = Personaje(100, 10, "Cyclop", 0, 0);
	player = Personaje(100, 10, "", 0, 0);
	boss = Personaje(100, 10, "Demon", 0, 0);
}