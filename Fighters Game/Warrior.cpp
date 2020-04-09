#include "Warrior.h"
#include "pch.h"

Warrior::Warrior()
{
}

Warrior::Warrior(string name) : Player(name)
{
}

Warrior::Warrior(string weapon, int damageWeapon) : Player(weapon, damageWeapon)
{
}

void Warrior::bigWarriorPunch() const
{
}



Warrior::~Warrior()
{
}
