#include "item.h"
#include "inventory.h"

#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
using std::cout;
using std::endl;
using std::stringstream;
using std::string;


int main() {
	Item a("flowers");
	assert(a.ToJSON() == "{\"name\": \"flowers\", \"quantity\": 0, \"price\": 0.00, "
					  "\"category\": 0}");
	cout << "Test 1 Passed!" << endl;

	assert(a.GetPrice() == 0);
	cout << "Test 2 Passed!" << endl;
	stringstream stream1;
	a.Write(stream1);
	assert(stream1.str() == "flowers 0 0.00 0");
	cout << "Test 3 Passed!" << endl;

	Item b(a);
	assert(b.ToJSON() == "{\"name\": \"flowers\", \"quantity\": 0, \"price\": 0.00, "
						 "\"category\": 0}");
	cout << "Test 4 Passed!" << endl;
	assert(a.Equals(b));
	cout << "Test 5 Passed!" << endl;
	assert(b.Equals(a));
	cout << "Test 6 Passed!" << endl;

	Item c("coke", DRINK, 0.75, 10 );
	stringstream stream2;
	stream2 << "{\"name\": \"coke\", \"quantity\": 10, \"price\": 0.75, "
			   "\"category\": " << DRINK << "}";
	assert(c.ToJSON() == stream2.str());
	cout << "Test 7 Passed!" << endl;

	a = c;
	assert(a.ToJSON() == c.ToJSON());
	cout << "Test 7 Passed!" << endl;

	stringstream stream3, stream4;
	stream3 << "apple " << FOOD << " 1.50 15";
	b.Read(stream3);
	stream4 << "{\"name\": \"apple\", \"quantity\": 15, \"price\": 1.50, "
			   "\"category\": " << FOOD << "}";
	assert(b.ToJSON() == stream4.str());
	cout << "Test 8 Passed!" << endl;

	cout << "----------------- Testing Inventory -----------------" << endl;
	Inventory inventory;
	assert(inventory.GetCount() == 0);
	cout << "Test 9 Passed!" << endl;
	assert(inventory.GetInventoryValue() == 0.0);
	cout << "Test 10 Passed!" << endl;
	assert(inventory.GetInventoryValue(UNDEFINED) == 0.0);
	cout << "Test 11 Passed!" << endl;
	assert(inventory.GetInventoryValue(FOOD) == 0.0);
	cout << "Test 12 Passed!" << endl;
	assert(inventory.GetInventoryValue(DRINK) == 0.0);
	cout << "Test 13 Passed!" << endl;
	assert(inventory.GetInventoryValue(CLEANING) == 0.0);
	cout << "Test 14 Passed!" << endl;
	assert(inventory.GetItem("none") == nullptr);
	cout << "Test 15 Passed!" << endl;
	// Adding Items (name, category, price, quantity)
	assert(inventory.AddItem(Item("flowers")));
	cout << "Test 16 Passed!" << endl;
	assert(inventory.AddItem(Item("coke", DRINK, 0.75, 10)));
	cout << "Test 17 Passed!" << endl;
	assert(inventory.AddItem(Item("apple", FOOD, 1.50, 5)));
	cout << "Test 18 Passed!" << endl;
	assert(inventory.AddItem(Item("pinesol", CLEANING, 3.25, 20)));
	cout << "Test 19 Passed!" << endl;
	assert(inventory.AddItem(Item("tea", DRINK, 1.10, 10)));
	cout << "Test 20 Passed!" << endl;
	assert(!inventory.AddItem(Item("should-not-get-in")));
	cout << "Test 21 Passed!" << endl;

	// Checking insertions
	stringstream flowers, coke, apple, pinesol, tea;
	flowers << "{\"name\": \"flowers\", \"quantity\": 0, \"price\": 0.00, "
			   "\"category\": " << UNDEFINED << "}";
	coke << "{\"name\": \"coke\", \"quantity\": 10, \"price\": 0.75, "
			   "\"category\": " << DRINK << "}";
	apple << "{\"name\": \"apple\", \"quantity\": 5, \"price\": 1.50, "
			   "\"category\": " << FOOD << "}";
	pinesol << "{\"name\": \"pinesol\", \"quantity\": 20, \"price\": 3.25, "
			   "\"category\": " << CLEANING << "}";
	tea << "{\"name\": \"tea\", \"quantity\": 10, \"price\": 1.10, "
			   "\"category\": " << DRINK << "}";

	assert(inventory.GetItem("flowers")->ToJSON() == flowers.str());
	cout << "Test 22 Passed!" << endl;
	assert(inventory.GetItem("coke")->ToJSON() == coke.str());
	cout << "Test 23 Passed!" << endl;
	assert(inventory.GetItem("apple")->ToJSON() == apple.str());
	cout << "Test 24 Passed!" << endl;
	assert(inventory.GetItem("pinesol")->ToJSON() == pinesol.str());
	cout << "Test 25 Passed!" << endl;
	assert(inventory.GetItem("tea")->ToJSON() == tea.str());
	cout << "Test 26 Passed!" << endl;

	// Testing sum operations
//	cout << inventory.GetInventoryValue() << endl;
	assert(inventory.GetInventoryValue() == 91);
	cout << "Test 27 Passed!" << endl;
	assert(inventory.GetInventoryValue(UNDEFINED) == 0);
	cout << "Test 28 Passed!" << endl;
	assert(inventory.GetInventoryValue(DRINK) == 18.5);
	cout << "Test 29 Passed!" << endl;
	assert(inventory.GetInventoryValue(FOOD) == 7.5);
	cout << "Test 30 Passed!" << endl;
	assert(inventory.GetInventoryValue(CLEANING) == 65);
	cout << "Test 31 Passed!" << endl;

	assert(inventory.GetCount() == MAX_ITEMS);
	cout << "Test 32 Passed!" << endl;

	stringstream allJSON;
	allJSON << "["
		<< flowers.str() << ", "
		<< coke.str() << ", "
		<< apple.str() << ", "
		<< pinesol.str() << ", "
		<< tea.str() << "]";
	assert(inventory.ToJSON() == allJSON.str());
	cout << "Test 33 Passed!" << endl;

	// inventory.Read(stream) and inventory.Write(stream) tests missing

	return 0;
}
