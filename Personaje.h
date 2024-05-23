#pragma once

#include <iostream>
using namespace std;

class Personaje
{
private:
	int vida;
	int ataque;
	string nombre;
	int posicionX;
	int posicionY;

public:
	void setVida(int pVida);
	void setAtaque(int pAtaque);
	void setNombre(string pNombre);
	void setPosicionX(int pPosicionX);
	void setPosicionY(int pPosicionY);

	int getVida();
	int getAtaque();
	string getNombre();
	int getPosicionX();
	int getPosicionY();

	Personaje();
	Personaje(int pVida, int pAtaque, string pNombre, int pPosicionX, int pPosicionY);
};