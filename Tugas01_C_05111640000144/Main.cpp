#include <iostream>
#include <stdlib.h>
#include <string>
#include "Pet.h"
#include "Weapon.h"
#include <vector>


using namespace std;
vector<Weapon> WeaponList;
vector<Pet> PetList;

void printMenu();
void listPet();
void listWeapon();
void createWeapon();
void createPet();
void playPet(int petid);
void printPetMenu(Pet &pet);

int main()
{
	string command;
	printMenu();
	//mainloop
	while(1)
	{
		cin >> command;
		if (command.compare("HELP") == 0)
		{
			printMenu();
		}
		else if (command.compare("LISTPET") == 0)
		{
			listPet();
		}
		else if (command.compare("LISTWEAPON") == 0)
		{
			listWeapon();
		}
		else if (command.compare("CREATEWEAPON") == 0)
		{
			createWeapon();
		}
		else if (command.compare("CREATEPET") == 0)
		{
			createPet();
		}
		else if (command.compare(0,4,"PLAY") == 0)
		{
			int petid;
			listPet();
			cout << "Masukkan Pet id :" << endl;
			cin >> petid;
			playPet(petid);
		}
		else if (command.compare("EXIT") == 0)
		{
			break;
		}
		else
		{
			cout << "Perintah salah !";
		}
	}
}

void printMenu()
{
	system("CLS");
	cout << "Selamat datang di super tamagochi!" << endl;
	cout << "HELP - untuk print help" << endl;
	cout << "LISTPET - untuk list semua pet" << endl;
	cout << "LISTWEAPON - untuk list semua weapon" << endl;
	cout << "CREATEPET - untuk bikin pet" << endl;
	cout << "CREATEWEAPON - untuk bikin weapon" << endl;
	cout << "PLAY - untuk bermain sebagai pet yang dipilih" << endl;
	cout << "EXIT - untuk keluar" << endl;
}

void listPet()
{
	for (int i = 0; i < PetList.size(); i++)
	{
		cout << i << ". ";
		PetList[i].prinstat();
	}
}

void listWeapon()
{
	for (int i = 0; i < WeaponList.size(); i++)
	{
		cout << i << ". " << WeaponList[i].getName() << " " << WeaponList[i].getDamage() << " damage" << endl;
	}
}

void createPet()
{
	system("CLS");
	string name;
	int senjata;
	getchar();
	cout << "Masukan nama pet:" << endl;
	getline(cin, name);
	cout << "Masukkan senjata id:" << endl;
	cin >> senjata;
	PetList.push_back(Pet(name,WeaponList[senjata]));
	printMenu();
}

void createWeapon()
{
	system("CLS");
	string name;
	int damage;
	getchar();
	cout << "Masukan nama weapon:" << endl;
	getline(cin, name);
	cout << "Masukkan damage:" << endl;
	cin >> damage;
	WeaponList.push_back(Weapon(name, damage));
	printMenu();
}

void playPet(int petid)
{
	Pet &current = PetList[petid];
	printPetMenu(current);
	string command;
	while (1)
	{
		cin >> command;
		if (command.compare("HELP") == 0)
		{
			printPetMenu(current);
		}
		else if (command.compare("PLAY") == 0)
		{
			current.doPlay();
		}
		else if (command.compare("FEED") == 0)
		{
			current.doFeed();
		}
		else if (command.compare("SLEEP") == 0)
		{
			current.doSleep();
		}
		else if (command.compare("STATUS") == 0)
		{
			current.prinstat();
		}
		else if (command.compare("WEAPON") == 0)
		{
			int wepid;
			listWeapon();
			cout << "Masukkan weapon id:" << endl;
			cin >> wepid;
			current.setWeapon(WeaponList[wepid]);
		}
		else if (command.compare("ATTACK") == 0)
		{
			int petid;
			listPet();
			cout << "Masukkan pet id:" << endl;
			cin >> petid;
			current.doAttack(PetList[petid]);
		}
		else if (command.compare("NAME") == 0)
		{
			string newname;
			getchar();
			cout << "masukkan nama pet:" << endl;
			getline(cin, newname);
			current.setName(newname);
			printPetMenu(current);
		}
		else if (command.compare("EXIT") == 0)
		{
			break;
		}
		else
		{
			cout << "Perintah tidak ditemukan!" << endl;
		}
	}
}

void printPetMenu(Pet &pet)
{
	cout << pet.getName() <<" Action!" << endl;
	cout << "HELP - untuk print help" << endl;
	cout << "PLAY - untuk mengajak bermain pet" << endl;
	cout << "FEED - untuk memberi makan pet" << endl;
	cout << "SLEEP - untuk mengistirahatkan" << endl;
	cout << "NAME - untuk merubah nama pet" << endl;
	cout << "STATUS - untuk melihat status pet" << endl;
	cout << "WEAPON - untuk merubah senjata pet" << endl;
	cout << "ATTACK - untuk menyerang pet lain" << endl;
	cout << "EXIT - untuk kembali" << endl;
}