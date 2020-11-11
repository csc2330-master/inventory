//
// Created by Arias Arevalo, Carlos on 11/11/20.
//

#ifndef INVENTORY_INVENTORY_H
#define INVENTORY_INVENTORY_H

#include "item.h"

#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::istream;

const int MAX_ITEMS = 5;

class Inventory {
	Item* _items[MAX_ITEMS];
	unsigned int _count;
	// To prevent Inventory users to make copies
	// but providing the code to respect the rule of three
	Inventory(const Inventory& original);
	const Inventory& operator=(const Inventory& rhs);
public:
	Inventory();
	~Inventory();
	unsigned int GetCount()const;
	string ToJSON()const;
	bool AddItem(const Item& item);
	Item* GetItem(const string& name);
	unsigned int Read(istream& input);
	unsigned int Write(ostream& output);
	double GetInventoryValue()const;
	double GetInventoryValue(unsigned int category);
};


#endif //INVENTORY_INVENTORY_H
