#include "Weapon.h"


Weapon::Weapon(string name, int damage) : _name(name), _damage(damage)
{
	this->_name = name;
	this->_damage = damage;
}

int Weapon::getDamage()
{
	return this->_damage;
}

string Weapon::getName()
{
	return this->_name;
}


Weapon::~Weapon()
{
}
