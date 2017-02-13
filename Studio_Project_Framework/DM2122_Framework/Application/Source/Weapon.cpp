#include "Weapon.h"

Weapon::Weapon(unsigned dmg, string wName, unsigned value, int wDurability) : weaponDamage(dmg), Item (wName, value, wDurability)
{
	weaponID = 0;
}

Weapon::~Weapon() {}

unsigned Weapon::getWeaponDamage()
{
	return 0;
}

//void Weapon::generateWeapon(unsigned numOfWeapon)
//{
//	for (unsigned i = 0; i < numOfWeapon; ++i)
//	{
//		WeaponDataBase[weaponID] = new Weapon(1, "gun", 1, 1);
//		weaponID++;
//	}
//}

unsigned Weapon::getValue()
{
	return 0;
}

int Weapon::durabilityDmg()
{
	return 0;
}

Weapon* Weapon::getWeapon(unsigned ID)
{
	return 0;
}