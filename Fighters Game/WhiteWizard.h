#pragma once

#include <string>
#include <iostream>
#include "Player.h"
#include "Wizard.h"

using namespace std;


class WhiteWizard : public Wizard
{
public:
	WhiteWizard(string name);
	WhiteWizard(string weapon, int damageWeapon);
	void iceBall(Player& target) ;
	void whiteCristal(Player& target) ;
	void blindingLight(Player& target) ;
	void attack(Player& target, int chosen);

	WhiteWizard();
	~WhiteWizard();

	

};

