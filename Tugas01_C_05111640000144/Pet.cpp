#include "Pet.h"
#include <iostream>
#include <stdlib.h>
#include <memory>

Pet::Pet(string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	this->_weapon = weapon;
	this->_name = name;
	this->health = MAXHEALTH;
	this->mood = MAXMOOD;
	this->energy = MAXENERGY;
	this->hunger = MAXHUNGER;
}

void Pet::doAttack(Pet & monster)
{
	int hunger = -3;
	int health = -div(monster.getWeapon().getDamage(),2).quot;
	int mood = -2;
	int energy = -3;

	if (addressof(*this) == addressof(monster))
	{
		cout << "Tidak bisa menyerang diri sendiri!" << endl;
		return;
	}
	
	if ((this->getHealth() + health <= 0) || (this->getHunger() + hunger <= 0) || (this->getMood() + mood <= 0) || (this->getEnergy() + energy <= 0))
	{
		cout << this->getName() << " Tidak dapat bertarung lagi !" << endl;
		return;
	}

		
	cout << "Pertarungan dimulai antara" << this->getName() << " dan " << monster.getName() << endl;

	changestat(health, energy, mood, hunger);
	monster.getDamage(*this);
}

void Pet::getDamage(Pet &from)
{
	int hunger = 0;
	int health = -from.getWeapon().getDamage();
	int mood = -3;
	int energy = -1;

	if (addressof(*this) == addressof(from))
	{
		cout << "Tidak menerima serangan dari diri sendiri!" << endl;
		return;
	}

	if ((this->getHealth() + health <= 0) || (this->getHunger() + hunger <= 0) || (this->getMood() + mood <= 0) || (this->getEnergy() + energy <= 0))
	{
		cout << this->getName() << " Tidak dapat bertarung lagi !" << endl;
		return;
	}


	cout << this->getName() << " menerima serangan dari " << from.getName() << "dengan menggunakan " << from.getWeapon().getName()<<"!" << endl;

	changestat(health, energy, mood, hunger);
}

void Pet::doFeed()
{
	int hunger = 3;
	int health = 4;
	int mood = 2;
	int energy = 3;

	if (this->getHunger() + hunger >= MAXHUNGER)
	{
		cout << this->_name << " Telah kenyang !" << endl;
		return;
	}
	cout << "Memberi makan pet :" << this->getName() << endl;

	changestat(health, energy, mood, hunger);

}

void Pet::doSleep()
{
	int hunger = -3;
	int health = 5;
	int mood = -3;
	int energy = 3;

	if (this->getEnergy() + energy >= MAXHUNGER)
	{
		cout << this->_name << " Tidak ngantuk !" << endl;
		return;
	}
	cout << "Mengistirahatkan Pet :" << this->getName() << endl;

	changestat(health, energy, mood, hunger);
}

void Pet::doPlay()
{
	int hunger = -2;
	int health = 0;
	int mood = 3;
	int energy = -2;

	if (this->getMood() + mood >= MAXMOOD)
	{
		cout << this->_name << " Sedang bahagia !" << endl;
		return;
	}
	cout << "Bermain dengan pet :" << this->getName() << endl;

	changestat(health, energy, mood, hunger);
}

Weapon Pet::getWeapon()
{
	return this->_weapon;
}

void Pet::setWeapon(Weapon &weapon)
{
	this->_weapon = weapon;
}

string Pet::getName()
{
	return this->_name;
}

void Pet::setName(string name)
{
	this->_name = name;
}

int Pet::getHealth()
{
	return this->health;
}

void Pet::changestat(int health, int energy, int mood, int hunger)
{
	if (this->getHunger() + hunger <= MAXHUNGER)
	{
		this->setHunger(this->getHunger() + hunger);
	}
	if (this->getMood() + mood <= MAXMOOD)
	{
		this->setMood(this->getMood() + mood);		
	}
	if (this->getEnergy() + energy <= MAXENERGY)
	{
		this->setEnergy(this->getEnergy() + energy);
	}
	if (this->getHealth() + health <= MAXHEALTH)
	{
		this->setHealth(this->getHealth() + energy);
	}
	this->prinstat();
}

void Pet::setHealth(int health)
{
	this->health = health;
}

int Pet::getEnergy()
{
	return this->energy;
}

void Pet::setEnergy(int energy)
{
	this->energy = energy;
}

int Pet::getMood()
{
	return this->mood;
}

void Pet::setMood(int mood)
{
	this->mood = mood;
}

int Pet::getHunger()
{
	return this->hunger;
}

void Pet::prinstat()
{
	cout << getName() << " Current Stat:" << endl;
	cout << "Health Point : " << getHealth() << "/" << MAXHEALTH << endl;
	cout << "Energy Point : " << getEnergy() << "/" << MAXENERGY << endl;
	cout << "Mood Point : " << getMood() << "/" << MAXMOOD << endl;
	cout << "Hunger Point : " << getHunger() << "/" << MAXHUNGER << endl;
}

void Pet::setHunger(int hunger)
{
	this->hunger = hunger;
}


Pet::~Pet()
{
}
