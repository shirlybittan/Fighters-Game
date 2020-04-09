#include "Knight.h"
#include "pch.h"


Knight::Knight(string name) : Warrior(name)
{
}


Knight::Knight()
{
}

Knight::Knight(string weapon, int damageWeapon) : Warrior(weapon, damageWeapon)
{
}

void Knight::attack(Player& target, int chosen) {

	if (chosen == 1)
		sword(target);
	if (chosen == 2)
		axe(target);
	if (chosen == 3)
		hammer(target);
}


Knight::~Knight()
{
}

void Knight::sword(Player& target)
{
	m_weapon->change("Sword", 20);
	target.receiveDamage(m_weapon->getDamage());
	cout << "Sword has been used! lost = 20 points";

}

void Knight::axe(Player& target)
{
	m_weapon->change("Axe", 25);
	target.receiveDamage(m_weapon->getDamage());
	cout << "Axe has been used! lost = 25 points";

}

void Knight::hammer(Player& target)
{
	m_weapon->change("Hammer", 15);
	target.receiveDamage(m_weapon->getDamage());
	cout << "Hammer has been used! lost = 15 points";

}
