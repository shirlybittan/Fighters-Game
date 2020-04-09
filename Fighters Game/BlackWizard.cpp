#include "BlackWizard.h"
#include <string>
#include <iostream>
#include "pch.h"


BlackWizard::BlackWizard()
{
}


BlackWizard::~BlackWizard()
{
}

BlackWizard::BlackWizard(string name) : Wizard(name)
{
}

BlackWizard::BlackWizard(string weapon, int damageWeapon) : Wizard(weapon, damageWeapon)
{
}


//int chosen = the action the user chose
void BlackWizard::attack(Player& target, int chosen) {
	 
	if (chosen == 1)
		darkExplosion(target);
	if (chosen == 2)
		fireBall(target);
	if (chosen == 3)
		darkStrike(target);

}

void BlackWizard::fireBall(Player & target)
{
	m_weapon->change("Fire Ball", 20);
	target.receiveDamage(m_weapon->getDamage());
	
}


void BlackWizard::darkExplosion(Player& target)
{
	m_weapon->change("Dark Eplosion", 25);
	target.receiveDamage(m_weapon->getDamage());
	
}

void BlackWizard::darkStrike(Player& target) 
{
	m_weapon->change("Dark Strike", 15);
	target.receiveDamage(m_weapon->getDamage());
	
}
