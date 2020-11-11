//
// Created by Arias Arevalo, Carlos on 11/11/20.
//

#ifndef INVENTORY_ITEM_H
#define INVENTORY_ITEM_H

#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::istream;

const unsigned short int UNDEFINED = 0;
const unsigned short int FOOD = 1;
const unsigned short int DRINK = 2;
const unsigned short int CLEANING = 3;


class Item {
private:
	char* _name;
	unsigned short int _category;
	double _price;
	unsigned int _quantity;
public:
	Item(const char* name);
	Item(const char* name, unsigned short int category, double price, unsigned int quantity =
			0);
	Item(const Item& original);
	~Item();
	const Item& operator=(const Item& rhs);
	string ToJSON()const;
	bool Read(istream& input);
	bool Write(ostream& output)const;
	bool Equals(const Item& rhs)const;
	double GetPrice()const;
	unsigned int GetCategory()const;
	unsigned int GetQuantity()const;
};


#endif //INVENTORY_ITEM_H
