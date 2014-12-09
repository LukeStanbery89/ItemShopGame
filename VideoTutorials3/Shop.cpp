#include "Shop.h"
#include <iostream>

Shop::Shop(string name, int money) {
	_name = name;
	_money = money;
}

void Shop::printShop() {
	cout << "*** Welcome to " << _name << " ***\n\n";
	list<Item>::iterator lit;

	int i = 0;

	// Print each item to the screen
	for(lit = _items.begin(); lit != _items.end(); lit++) {
		cout << i << ". " << (*lit).getName() << " x " << (*lit).getCount() << endl;
		i++;
	}
}

bool Shop::purchaseItem(string name, Item &newItem) {
	list<Item>::iterator lit;

	// Iterate through all shop items
	for(lit = _items.begin(); lit != _items.end(); lit++) {
		if((*lit).getName() == name) {
			// If shop has item, subtract one from shop and add one to player
			newItem = (*lit);
			newItem.setCount(1);
			(*lit).removeOne();

			// If the shop sold the last one, remove from the display list
			if((*lit).getCount() == 0) {
				_items.erase(lit);
			}
			// Shop had the item, player purchased item, return true
			return true;
		}
	}
	// Shop did not have the item, player could not purchase item, return false
	return false;
}

void Shop::addItem(Item newItem) {
	list<Item>::iterator lit;

	// Iterate through all shop items
	for(lit = _items.begin(); lit != _items.end(); lit++) {
		if((*lit).getName() == newItem.getName()) {
			// If shop has the item, add one to the shop's stock
			(*lit).addOne();
			return;
		}
	}

	// If the shop does not have the item, add it to the list
	_items.push_back(newItem);
}