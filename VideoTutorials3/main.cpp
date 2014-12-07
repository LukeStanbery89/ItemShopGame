#include <iostream>
#include <string>

using namespace std;

// Global Constants
const int numItems = 6;
const string shopItemNames[numItems] = {"Boots", "Swords", "Helmets", "Kittens", "Poleaxes", "Leggings"};

void printInventory(const int playerInventory[numItems]);
void printShop();
bool buyItems(int playerInventory[numItems]);

int main() {
	// Variables
	bool isDone = false;
	int playerInventory[numItems] = {0, 0, 0, 1, 0, 0};

	cout << "*** Welcome to the item shop! ***" << endl;

	while(!isDone) {
		printShop();
		printInventory(playerInventory);
		isDone = buyItems(playerInventory);
	}

	system("PAUSE");
	return 0;
}

void printInventory(const int playerInventory[numItems]) {
	cout << "Your inventory is:\n\n";
	for(int i = 0; i < numItems; i++) {
		if(playerInventory[i] > 0) {
			cout << playerInventory[i] << "x " << shopItemNames[i] << endl;
		}
	}
}

void printShop() {
	for(int i = 0; i < numItems; i++) {
		cout << i + 1 << ". " << shopItemNames[i] << endl;
	}

	cout << "************\n\n";
}

bool buyItems(int playerInventory[numItems]) {
	int input;

	cout << "What would you like to buy? Enter (1 - " << numItems << "): ";
	cin >> input;

	if(input == -1) {
		return true;	// Program is over
	}

	if(input < 0 || input > numItems) {
		cout << "Invalid input!\n";
		return false; // Keep going
	}

	playerInventory[input - 1]++;
	return false;
}
