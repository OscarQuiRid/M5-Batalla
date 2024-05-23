#pragma once
#include <iostream>
using namespace std;

class Spells
{
private:

	string spellName;
	int spell;
	string spellName2;
	int spell2;

public:
	void setSpellName(string pSpellName1);
	void setSpell(int pSpell1);
	void setSpellName2(string pSpellName2);
	void setSpell2(int pSpell2);

	string getSpellName();
	int getSpell();
	string getSpellName2();
	int getSpell2();


	Spells();
	Spells(string pSpellName1, int pSpell1, string pSpellName2, int pSpell2);
};