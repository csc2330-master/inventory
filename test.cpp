#include "item.h"

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

	return 0;
}
