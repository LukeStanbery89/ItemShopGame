#include <iostream>
#include <string>
#include "Shop.h"
#include "Player.h"

using namespace std;

void initShops(list<Shop> &shops);
void initPlayer(Player &player);
void pickShop(list<Shop> &shops);
void enterShop(Player &player, Shop &shop);

int main() {
	list<Shop> shops;
	list<Shop>::iterator lit;
	Player player;
	string shopName;

	// Initialize
	initPlayer(player);
	initShops(shops);

	// Tells us when the game is over
	bool isDone = false;

	while(!isDone) {
		cout << "Shops:\n";
		int i = 1;
		for(lit = shops.begin(); lit != shops.end(); lit++) {
			cout << i++ << ". " << (*lit).getName() << endl;
		}
		cout << "\nWhich shop would you like to enter? ";

		//cin.clear();
		//cin.ignore(64, '\n');
		getline(cin, shopName);

		//cout << "You inputted: " << shopName << endl;
		cout << endl;

		bool validShop = false;

		for(lit = shops.begin(); lit != shops.end(); lit++) {
			if((*lit).getName() == shopName) {
				enterShop(player, (*lit));
				validShop = true;
			}
		}

		if(!validShop) {
			cout << "Invalid Shop!\n\n";
		}
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
	cout << "Enter your name: ";
	string name;
	getline(cin, name);
	player.init(name, 100);

	player.addItem(Item("Bronze Sword", 5));
}

void enterShop(Player &player, Shop &shop) {
	bool isDone = false;
	char input;
	string itemName;
	Item newItem("NOITEM", 0);

	while(!isDone) {
		shop.printShop();
		player.printInventory();

		cout << "\nWould you like to buy or sell? (B/S): ";
		cin >> input;
		cin.ignore();
		cin.clear();

		if(input == 'Q' || input == 'q') {
			return;
		}

		if(input == 'B' || input == 'b') { // buy
			cout << "Enter the item you wish to buy: ";
			getline(cin, itemName);

			if(shop.canAffordItem(itemName, player.getMoney())) {

				if(shop.purchaseItem(itemName, newItem) == true) {
					player.addMoney(-newItem.getValue());
					player.addItem(newItem);
					shop.addMoney(newItem.getValue());
				} else {
					cout << "That is an invalid item!" << endl;
					system("PAUSE");
				}
			} else {
				cout << "You don't have enough money!\n";
				system("PAUSE");
			}

		} else { //sell
			cout << "Enter the item you wish to sell: ";
			getline(cin, itemName);

			if(player.canAffordItem(itemName, shop.getMoney())) {

				if(player.removeItem(itemName, newItem)) {
					shop.addMoney(-newItem.getValue());
					shop.addItem(newItem);
					player.addMoney(newItem.getValue());
				} else {
					cout << "That is an invalid item!" << endl;
					system("PAUSE");
				}
			} else {
				cout << "The shop doesn't have enough money!\n";
				system("PAUSE");
			}
		}
	}
}
