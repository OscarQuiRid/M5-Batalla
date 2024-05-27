#pragma once

#include "Personaje.h"
#include "Spells.h"

class Logica {
public:
    static Spells spell1, spell2, spell3, spell4, reusable1, reusable2;
    static Personaje mapa[10][5], mapaPrint[10][5], player, enemy1, enemy2, enemy3, enemy4, enemy5, enemy6, enemy7, enemy8, boss, reutilizable, vacio;
    static bool map[10][5];

    static void createSpells();
    static void createEnemis();
    static Personaje generateMonster(Personaje pEnemigo);
    static int asignarPosicionX(int& x);
    static int asignarPosicionY(int& y);
    static void createMapInicial();
    static void printarMapa();
    static void pelea(int posY, int posX, bool &salirJuego);
    static void procesarFlecha(int key, bool &salirJuego);
    static void crateBoss(Spells &spellUno);
    static void hits(int &valorAtaque, bool esBoss, bool esPlayer, int posY, int posX);
    static void revisarEnemigos(bool& salirJuego);
};