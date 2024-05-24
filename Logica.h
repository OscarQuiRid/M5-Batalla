#pragma once

#include "Personaje.h"
#include "Spells.h"

class Logica {
public:
    static Spells spell1, spell2, spell3, spell4;
    static Personaje mapa[10][5], player, enemy1, enemy2, enemy3, enemy4, enemy5, enemy6, enemy7, enemy8, boss, reutilizable;
    static bool map[10][5];

    static void createSpells();
    static void createEnemis();
    static Personaje generateMonster(Personaje pEnemigo);
    static int asignarPosicionX(int& x);
    static int asignarPosicionY(int& y);
    static void createMapInicial();
    static void printarMapa();
    static void saludo();
};