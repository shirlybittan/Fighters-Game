#pragma once

#include <iostream>
#include <string>
#include "Weapon.h"

using namespace std;



class Player
{

public:
	//constructors ////////////

	Player();
	Player(string name);
	Player(string weapon, int damageWeapon);
	Player(Player const& playerToCopy);//copy constructor 

	////////////////////////////////////

	// getters /////////////////
	int getHp();
	int getmoney() const;
	Weapon getWeapon();

	////////////////////////////////////

	void AddMoney(int amount);
	virtual void receiveDamage(int nbDamage);
	virtual void attack(Player& target);
	virtual void drinkLifePotion(int quantityPotion);
	virtual void switchWeapon(string newWeapon, int damageNewWeapon);
	virtual bool isAlive() const;
	virtual void punch(Player& target) const;

	~Player();

protected:
	string m_name;
	int m_hp;
	Weapon* m_weapon;
	int money;
};

