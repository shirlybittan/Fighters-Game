#include "WhiteWizard.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "Wizard.h"
#include "Weapon.h"
#include "pch.h"

WhiteWizard::WhiteWizard() : Wizard()
{
}



WhiteWizard::WhiteWizard(string name) : Wizard(name)
{
}

WhiteWizard::WhiteWizard(string weapon, int damageWeapon) : Wizard(weapon, damageWeapon)
{
}

//int chosen = the action the user chose
void WhiteWizard::attack(Player& target, int chosen) {
	if (chosen == 1)
		blindingLight(target);
	if (chosen == 2)
		iceBall(target);
	if (chosen == 3)
		whiteCristal(target);

}

void WhiteWizard::blindingLight(Player& target) 
{	
	m_weapon->change("Blinding Light", 15);
	target.receiveDamage(m_weapon->getDamage());
}



WhiteWizard::~WhiteWizard()
{
}

void WhiteWizard::iceBall(Player& target)  {

	m_weapon->change("Ice Ball", 25);
	target.receiveDamage(m_weapon->getDamage());
}

void WhiteWizard::whiteCristal(Player& target) 
{
	m_weapon->change("White Cristal", 20);
	target.receiveDamage(m_weapon->getDamage());
}
