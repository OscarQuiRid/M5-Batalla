#include "Personaje.h"
#include <iostream>

using namespace std;

Personaje::Personaje(int pVida, int pAtaque, string pNombre, int pPosicionX, int pPosicionY) {
	vida = pVida;
	ataque = pAtaque;
	nombre = pNombre;
	posicionX = pPosicionX;
	posicionY = pPosicionY;
}

Personaje::Personaje(int pVida, int pAtaque, string pNombre, int pPosicionX, int pPosicionY, string pSpellName1, int pSpell1, string pSpellName2, int pSpell2) : Spells(pSpellName1, pSpell1, pSpellName2, pSpell2){
	vida = pVida;
	ataque = pAtaque;
	nombre = pNombre;
	posicionX = pPosicionX;
	posicionY = pPosicionY;
}

void Personaje::setVida(int pVida) {
	vida = pVida;
}
void Personaje::setAtaque(int pAtaque) {
	ataque = pAtaque;
}
void Personaje::setNombre(string pNombre) {
	nombre = pNombre;
}
void Personaje::setPosicionX(int pPosicionX) {
	posicionX = pPosicionX;
}
void Personaje::setPosicionY(int pPosicionY) {
	posicionY = pPosicionY;
}

int Personaje::getVida() {
	return vida;
}
int Personaje::getAtaque() {
	return ataque;
}
string Personaje::getNombre() {
	return nombre;
}
int Personaje::getPosicionX() {
	return posicionX;
}
int Personaje::getPosicionY() {
	return posicionY;
}