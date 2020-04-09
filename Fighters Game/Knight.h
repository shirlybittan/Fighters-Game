#pragma once

#include <string>
#include <iostream>
#include "Player.h"
#include "Warrior.h"


using namespace std;


class Knight : public Warrior
{
public:
	Knight(string name);
	Knight();
	Knight(string weapon, int damageWeapon);
	void attack(Player& target, int chosen);
	~Knight();
	void sword(Player& target);
	void axe(Player& target);
	void hammer(Player& target);
};

