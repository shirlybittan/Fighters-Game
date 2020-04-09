#pragma once

#include <string>
#include <iostream>
#include "Player.h"



class Wizard : public Player
{
public:


	Wizard();
	Wizard(string name);
	Wizard(string weapon, int damageWeapon);
	bool hasMana(int howMuchNeeded) const;
	void useSpell(int used);
	int getMana() const;
	~Wizard();

private:
	//when mana=0 the wizard cannot send spells anymore
	int m_mana;
};

