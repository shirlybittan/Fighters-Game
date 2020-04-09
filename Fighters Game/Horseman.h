#pragma once

#include <string>
#include <iostream>
#include "Player.h"
#include "Warrior.h"

using namespace std;

class Horseman : public Warrior
{
public:
	Horseman(string str);
	void attack(Player& target, int chosen);
	Horseman();
	Horseman(string weapon, int damageWeapon);
	~Horseman();
	void charge(Player& target);
	void lance(Player& target);
	void arrow(Player& target);




};

