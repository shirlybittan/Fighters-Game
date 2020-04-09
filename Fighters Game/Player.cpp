
#include "Player.h"

#include "pch.h"


// constructors //////////

Player::Player() : m_weapon(0), m_hp(100) , money(0)
{
	m_weapon = new Weapon();
}

Player::Player(string name) : m_hp(100), m_name(name), money(0)
{
	m_weapon = new Weapon();
}


Player::Player(string weapon, int damageWeapon) : m_weapon(0), m_hp(100), money(0)
{
	m_weapon = new Weapon(weapon, damageWeapon);
}

//copy constructor

Player::Player(Player const& playerToCopy) : m_hp(playerToCopy.m_hp), m_weapon(0) {
	m_weapon = new Weapon(*(playerToCopy.m_weapon));

}

//////////////////////////////////////////



// getters /////////////////////

int Player::getHp() {
	return m_hp;
}

Weapon Player::getWeapon() {
	return *(m_weapon);

}

int Player::getmoney() const {
	return money;
}

////////////////

 void Player::AddMoney(int amount) {
	 money += amount;
}


void Player::receiveDamage(int nbDamage) {

	m_hp -= nbDamage;

	if (m_hp < 0)
		m_hp = 0;
}


void Player::attack(Player& target) {
	target.receiveDamage(m_weapon->getDamage());

}

void Player::drinkLifePotion(int quantityPotion) {
	m_hp += quantityPotion;
	if (m_hp > 100)
		m_hp = 100;
}

void Player::switchWeapon(string newWeapon, int damageNewWeapon) {
	m_weapon->change(newWeapon, damageNewWeapon);

}


bool Player::isAlive() const {
	return m_hp > 0;
}


void Player::punch(Player& target) const {
	target.receiveDamage(10);
}

Player::~Player()
{
	delete m_weapon;
}

