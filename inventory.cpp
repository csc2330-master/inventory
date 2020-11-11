//
// Created by Arias Arevalo, Carlos on 11/11/20.
//

#include "inventory.h"
#include "item.h"

#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::stringstream;
using std::ostream;
using std::istream;
using std::endl;


Inventory::Inventory(const Inventory &original): _count(original._count) {
	for (unsigned int i=0; i < _count; i++)
		_items[i] = new Item(*original._items[i]);
	for (unsigned int i = _count; i < MAX_ITEMS; ++i) {
		_items[i] = nullptr;
	}
}

const Inventory& Inventory::operator=(const Inventory &rhs) {
	// Doesn't assign anything
	return *this;
}

Inventory::Inventory() {
	_count = 0;
	for (unsigned int i = _count; i < MAX_ITEMS; ++i) {
		_items[i] = nullptr;
	}
}

Inventory::~Inventory() {
	for (unsigned int i=0; i < _count; i++)
		delete _items[i];
}

string Inventory::ToJSON() const {
	stringstream retVal;
	retVal << "[";
	for (unsigned int i = 0; i < _count; ++i) {
		if (i == _count - 1)
			retVal << _items[i]->ToJSON();
		else
			retVal << _items[i]->ToJSON() << ", ";
	}
	retVal << "]";
	return retVal.str();
}

bool Inventory::AddItem(const Item &item) {
	if (_count == MAX_ITEMS)
		return false;
	_items[_count] = new Item(item);
	_count++;
	return true;
}

Item *Inventory::GetItem(const string &name) {
	Item temporal(name.c_str());
	for (int i = 0; i < _count; ++i) {
		if (_items[i]->Equals(temporal))
			return _items[i];
	}
	return nullptr;
}

unsigned int Inventory::Read(istream &input) {
	unsigned int counter = 0;
	Item temporal("");
	while (temporal.Read(input)){
		if (AddItem(temporal))
			counter++;
	}
	return counter;
}

unsigned int Inventory::Write(ostream &output) {
	for (unsigned int i = 0; i < _count; ++i) {
		_items[i]->Write(output);
		output << endl;
	}
	return _count;
}

double Inventory::GetInventoryValue() const {
	double sum = 0.0;
	for (unsigned int i = 0; i < _count; ++i) {
		sum += _items[i]->GetPrice() * _items[i]->GetQuantity();
	}
	return sum;
}

double Inventory::GetInventoryValue(unsigned int category) {
	double sum = 0.0;
	for (unsigned int i = 0; i < _count; ++i) {
		if (_items[i]->GetCategory() == category)
			sum += _items[i]->GetPrice() * _items[i]->GetQuantity();
	}
	return sum;
}

unsigned int Inventory::GetCount() const {
	return _count;
}
