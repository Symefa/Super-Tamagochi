#pragma once
#include "Weapon.h"
#include <string>

using namespace std;

class Pet
{
private:
	int health;
	int energy;
	int mood;
	int hunger;
	Weapon &_weapon;
	string _name;
	void changestat(int health, int energy, int mood, int hunger);
	void setHealth(int health);
	void setEnergy(int energy);
	void setMood(int mood);
	void setHunger(int hunger);
public:
	//max var
	int MAXHEALTH = 100;
	int MAXENERGY = 20;
	int MAXMOOD = 20;
	int MAXHUNGER = 40;

	//cons
	Pet(string name, Weapon &weapon);
	
	//attack action
	void doAttack(Pet &to);
	void getDamage(Pet &from);
	
	//basic need action
	void doFeed();
	void doSleep();
	void doPlay();
	
	//info
	Weapon getWeapon();
	void setWeapon(Weapon &weapon);
	string getName();
	void setName(string name);
	int getHealth();
	int getEnergy();
	int getMood();
	int getHunger();
	void prinstat();
	//desctruc
	~Pet();
};

