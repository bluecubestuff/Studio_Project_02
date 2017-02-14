#include "Weapon.h"

Weapon::Weapon(string wName, unsigned value, int wDurability, unsigned dmg) : Item(wName, value, wDurability), weaponDamage(dmg)
{
	weaponID = 0;
	this->weaponName = wName;
	this->weaponValue = value;
	this->weaponDurability = wDurability;
}

Weapon::~Weapon() {}

unsigned Weapon::getWeaponDamage()
{
	return weaponDamage;
}

void Weapon::generateWeapon(unsigned numOfWeapon)
{
	for (unsigned i = 0; i < numOfWeapon; ++i)
	{
		this->WeaponDataBase[weaponID] = new Weapon("string", 1, 1, 1); //place holder
		//randomly generates all the variables in here
		this->weaponID++;
	}
}

void Weapon::add_weapon_to_data_base(Weapon* aWeapon)
{
	this->WeaponDataBase[weaponID] = aWeapon;
	weaponID++;
}

//void Weapon::add_item_to()
//{
//}

unsigned Weapon::getValue()
{
	return weaponValue;
}

int Weapon::getDurability()
{
	return weaponDurability;
}

Weapon* Weapon::getWeapon(unsigned ID)
{
	return WeaponDataBase[ID];
}