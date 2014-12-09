#pragma once
#include <string>
#include <list>
#include "Item.h"

using namespace std;

class Player {
public:
	Player();

	void init(string name, int money);

	void removeItem(string name);
	void addItem(Item newItem);

	// Getters
	int getMoney() {
		return _money;
	}
	void subtractMoney(int amount) {
		_money += amount;
	}
private:
	string _name;
	list<Item> _items;
	int _money;
};

