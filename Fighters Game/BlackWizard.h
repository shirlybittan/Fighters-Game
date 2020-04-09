#pragma once

#include <string>
#include <iostream>
#include "Wizard.h"



class BlackWizard : public Wizard
{
public:

	BlackWizard(string name);
	BlackWizard(string weapon, int damageWeapon);
	void fireBall(Player& target);
	void darkExplosion(Player& target);
	void darkStrike(Player& target);
	void attack(Player& target, int chosen);
	BlackWizard();
	~BlackWizard();
};



