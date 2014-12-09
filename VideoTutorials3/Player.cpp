#include "Player.h"

Player::Player() {
}

void Player::init(string name, int money) {
	_name = name;
	_money = money;
}

void Player::removeItem(string name) {
	list<Item>::iterator lit;

	// Iterate through all player items
	for(lit = _items.begin(); lit != _items.end(); lit++) {
		if((*lit).getName() == name) {
			// If shop has the item, erase it from the list
			_items.erase(lit);
			return;
		}
	}
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