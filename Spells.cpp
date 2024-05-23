#include "Spells.h"
using namespace std;


void Spells::setSpellName(string pSpellName1)
{
	spellName = pSpellName1;
}

void Spells::setSpell(int pSpell1)
{
	spell = pSpell1;
}

void Spells::setSpellName2(string pSpellName2)
{
	spellName2 = pSpellName2;
}

void Spells::setSpell2(int pSpell2)
{
	spell2 = pSpell2;
}

string Spells::getSpellName()
{
	return spellName;
}

int Spells::getSpell()
{
	return spell;
}

string Spells::getSpellName2()
{
	return spellName2;
}

int Spells::getSpell2()
{
	return spell2;
}
Spells::Spells() {

}
Spells::Spells(string pSpellName1, int pSpell1, string pSpellName2, int pSpell2)
{
	spellName = pSpellName1;
	spell = pSpell1;
	spellName2 = pSpellName2;
	spell2 = pSpell2;
}
