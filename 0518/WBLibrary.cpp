// WBLibrary.cpp

#include <iostream>
using namespace std;
#include "WBLibrary.h"

string WBLibrary::InputString(string msg) {
	cout << msg << " : ";
	string input;
	cin >> input;

	return input;

}

int WBLibrary::InputNumber(string msg) {
	int number;
	cout << msg << " : ";
	cin >> number;
	return number;
}