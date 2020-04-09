#include "Horseman.h"
#include "Player.h"
#include <string>
#include <iostream>
#include "Warrior.h"
#include "Weapon.h"
#include "pch.h"



Horseman::Horseman(string name) : Warrior(name) 
{
}

Horseman::Horseman() : Warrior()
{
}

Horseman::Horseman(string weapon, int damageWeapon) : Warrior(weapon, damageWeapon)
{
}

void Horseman::attack(Player& target, int chosen) {

	if (chosen == 1)
		charge(target);
	if (chosen == 2)
		arrow(target);
	if (chosen == 3)
		lance(target);
}


void Horseman::charge(Player& target)
{
	m_weapon->change("Charge", 25);
	target.receiveDamage(m_weapon->getDamage());
	cout << "Charge has been used! lost = 25 points";
}

void Horseman::lance(Player& target)
{
	m_weapon->change("Lance", 15);
	target.receiveDamage(m_weapon->getDamage());
	cout << "Lance has been used! lost = 15 points";

}

void Horseman::arrow(Player& target)
{
	m_weapon->change("Arrow", 10);
	target.receiveDamage(m_weapon->getDamage());
	cout << "Arrow has been used! lost = 10 points";

}


Horseman::~Horseman()
{
}
