#ifndef _ITEM_H
#define _ITEM_H

#include <map>
using std::map;

#include <string>
using std::string;

class Item
{
public:
	Item(string, unsigned,int);
	~Item();

	static Item *make_item(unsigned ID);

	virtual unsigned getValue() = 0;
	virtual int durabilityDmg() = 0;

private:

	string itemName;
	unsigned itemValue;
	int itemDurability;
};

#endif