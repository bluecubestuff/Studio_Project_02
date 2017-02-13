#ifndef _WEAPON_H
#define _WEAPON_H

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(unsigned, string, unsigned, int);
	~Weapon();

	unsigned getWeaponDamage();
	//void generateWeapon(unsigned);
	Weapon* getWeapon(unsigned);

	virtual unsigned getValue();
	virtual int durabilityDmg();

private:
	string weaponName;
	unsigned weaponDamage;
	unsigned weaponValue;
	int weaponDurability;

	unsigned weaponID;
	map<unsigned, Weapon*> WeaponDataBase;
};

#endif