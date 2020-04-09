#pragma once

#include <string>
#include <iostream>
#include "Player.h"
using namespace std;


class Warrior : public Player
{

public:
	void introducing() const;
	Warrior(string name);
	Warrior(string weapon, int damageWeapon);
	void bigWarriorPunch() const;
	Warrior();
	~Warrior();
};

