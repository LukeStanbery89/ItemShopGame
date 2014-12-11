#include "Player.h"
#include <iostream>

Player::Player() {
}

void Player::init(string name, int money) {
	_name = name;
	_money = money;
}

void Player::printInventory() {
	cout << "\n*** " << _name << "'s inventory ***\n\n";
	list<Item>::iterator lit;

	int i = 1;

	// Print each item to the screen
	for(lit = _items.begin(); lit != _items.end(); lit++) {
		cout << i << ". " << (*lit).getName() << " x " << (*lit).getCount() << endl;
		i++;
	}
}

bool Player::removeItem(string name, Item &newItem) {
	list<Item>::iterator lit;

	// Iterate through all player items
	for(lit = _items.begin(); lit != _items.end(); lit++) {
		if((*lit).getName() == name) {
			// If shop has the item, erase it from the list
			newItem = (*lit);
			(*lit).removeOne();
			if((*lit).getCount() == 0) {
				_items.erase(lit);
			}
			return true;
		}
	}
	return false;
}

void Player::addItem(Item newItem) {
	list<Item>::iterator lit;

	// Iterate through all player items
	for(lit = _items.begin(); lit != _items.end(); lit++) {
		if((*lit).getName() == newItem.getName()) {
			// If player has the item, add one to the shop's stock
			(*lit).addOne();
			return;
		}
	}

	// If the player does not have the item, add it to the list
	_items.push_back(newItem);
}