#include "Weapon.h"

#include "pch.h"



Weapon::Weapon(string name, int damage) : m_name(name), m_damage(damage)
{


}

Weapon::Weapon() : m_name("old sword"), m_damage(10)
{
}

void Weapon::change(string name, int damage) {
	m_name = name;
	m_damage = damage;
}

int Weapon::getDamage() const {
	return m_damage;

}


Weapon::~Weapon()
{
}
