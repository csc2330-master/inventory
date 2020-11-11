//
// Created by Arias Arevalo, Carlos on 11/11/20.
//

#include "item.h"

#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

using std::string;
using std::stringstream;
using std::ostream;
using std::istream;
using std::setprecision;
using std::fixed;

Item::Item(const char *name): _category(UNDEFINED), _price(0.0), _quantity(0) {
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);
}

Item::Item(const char *name, unsigned short category, double price, unsigned int quantity):
_category(category), _price(price), _quantity(quantity) {
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);
}

Item::Item(const Item &original):
		_category(original._category), _price(original._price), _quantity(original._quantity) {
	_name = new char[strlen(original._name) + 1];
	strcpy(_name, original._name);

}

Item::~Item() {
	delete[] _name;
}

const Item &Item::operator=(const Item &rhs) {
	_quantity = rhs._quantity;
	_price = rhs._price;
	_category = rhs._category;
	_name = new char[strlen(rhs._name) + 1];
	strcpy(_name, rhs._name);
	return *this;
}

string Item::ToJSON() const {
	stringstream retVal;
	retVal << "{\"name\": \"" << _name << "\", \"quantity\": " << _quantity
		<<", \"price\": " << setprecision(2) << fixed << _price << ", \"category\": " <<
		_category	<< "}";
	return retVal.str();
}

bool Item::Read(istream &input) {
	if (input.fail())
		return false;
	char temporalName[80];
	input >> temporalName >> _category >> _price >> _quantity;
	if (strlen(temporalName) != strlen(_name)){
		delete[] _name;
		_name = new char[strlen(temporalName) + 1];
	}
	strcpy(_name, temporalName);
	return !input.fail();
}

bool Item::Write(ostream &output) const {
	output << _name << " " << _quantity << " " << setprecision(2) << fixed << _price << " " << _category;
	return !output.fail();
}

bool Item::Equals(const Item &rhs) const {
	return strcmp(_name, rhs._name) == 0;
}

double Item::GetPrice() const {
	return _price;
}

/*
 * JSON format looks like this:
{"name": "apple", "quantity": 2, "price": 2.88, "category": 3}

 */