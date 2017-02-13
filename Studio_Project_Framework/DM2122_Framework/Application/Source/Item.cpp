#include "Item.h"
#include "Weapon.h"

Item::Item(string iName, unsigned value, int iDurability) : itemName(iName), itemValue(value), itemDurability(iDurability) {}

Item::~Item() {}

Item* Item::make_item(unsigned ID) //tetsing
{
	if (ID == 1)
	{
		return new Weapon(1, "gun", 1, 1);
	}
	return 0;
}

