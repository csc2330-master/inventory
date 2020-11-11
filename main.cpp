#include "item.h"

#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::stringstream;
using std::string;


int main() {
	cout << "Welcome to my program!!" << endl;
	Item empty("");
	cout << "Please input an item (name category price quantity): ";
	empty.Read(cin);
	cout << "Your input in JSON is: " << endl;
	cout << empty.ToJSON() << endl;

	return 0;
}
