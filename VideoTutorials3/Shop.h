#pragma once
#include <string>
#include <list>
#include "Item.h"

using namespace std;

class Shop {
public:
	Shop(string name, int money);

	void printShop();
	bool purchaseItem(string name, Item &newItem);
	void addItem(Item newItem);

	// Getters
	string getName() { return _name; }

private:
	string _name;
	list<Item> _items;
	int _money;
};
