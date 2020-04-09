#include "Wizard.h"
#include "pch.h"


Wizard::Wizard() : Player(), m_mana(100) 
{
}

Wizard::Wizard(string name) : Player(name), m_mana(100) 
{
}



Wizard::Wizard(string weapon, int damageWeapon) : Player(weapon, damageWeapon) 
{
}

bool Wizard::hasMana(int howMuchNeeded) const {
	return m_mana >= howMuchNeeded;
}

int Wizard::getMana() const {
	return m_mana;
}


void Wizard::useSpell(int used) {

	m_mana -= used;

	if (m_mana < 0)
		m_mana = 0;
}


Wizard::~Wizard()
{
}
