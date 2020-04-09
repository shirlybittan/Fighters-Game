#pragma once

#include <string>
#include <iostream>

using namespace std;


class Weapon
{
public:
	Weapon();
	Weapon(string name, int damage);
	void change(string name, int damage);
	int getDamage() const;
	string m_name;
	~Weapon();

private:

	int m_damage;


};

