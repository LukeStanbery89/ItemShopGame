#include <iostream>
#include <string>
#include "Shop.h"
#include "Player.h"

using namespace std;

void initShops(list<Shop> &shops);
void initPlayer(Player &player);
void pickShop(list<Shop> &shops);

int main() {
	list<Shop> shops;
	Player player;

	// Initialize
	initPlayer(player);
	initShops(shops);

	// Tells us when the game is over
	bool isDone = false;

	while(!isDone) {
		cout << "Which shop would you like to enter? ";
	}

	system("PAUSE");
	return 0;
}

void initShops(list<Shop> &shops) {
	shops.push_back(Shop("Bill's Leather Shop", 500));
	shops.back().addItem(Item("Leather Boots", 50));
	shops.back().addItem(Item("Leather Hat", 50));
	shops.back().addItem(Item("Leather Gloves", 50));
	shops.back().addItem(Item("Leather Gauntlets", 50));
	shops.back().addItem(Item("Leather Chestpiece", 100));

	shops.push_back(Shop("The Blacksmith", 1500));
	shops.back().addItem(Item("Iron Boots", 100));
	shops.back().addItem(Item("Iron Hat", 100));
	shops.back().addItem(Item("Iron Gloves", 100));
	shops.back().addItem(Item("Iron Gauntlets", 100));
	shops.back().addItem(Item("Iron Chestpiece", 200));
	shops.back().addItem(Item("Iron Sword", 150));
	shops.back().addItem(Item("Iron Shield", 150));

	shops.push_back(Shop("Beverly's Fruity Fruit Shop", 1500));
	shops.back().addItem(Item("Grapes", 5));
	shops.back().addItem(Item("Apple", 5));
	shops.back().addItem(Item("Orange", 10));
	shops.back().addItem(Item("Watermelon", 10));
	shops.back().addItem(Item("Tomato", 3));
}

void initPlayer(Player &player) {
	cout << "Enter your name: " << endl;
	string name;
	cin >> name;
	player.init(name, 100);

	player.addItem(Item("Bronze Sword", 5));
}