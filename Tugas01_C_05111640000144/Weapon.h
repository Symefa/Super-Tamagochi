#pragma once
#include <string>

using namespace std;

class Weapon
{
private:
	string _name;
	int _damage;

public:
	Weapon(string name, int damage);
	
	//get Info
	int getDamage();
	string getName();

	~Weapon();
};

