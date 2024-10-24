#include <iostream>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void printOptions() {
	cout << "MENU" << endl;
	cout << "add - Add item to cart" << endl;
	cout << "remove - Remove item from cart" << endl;
	cout << "change - Change item quantity" << endl;
	cout << "descriptions - Output items' descriptions" << endl;
	cout << "cart - Output shopping cart" << endl;
	cout << "options - Print the options menu" << endl;
	cout << "quit - Quit" << endl;
}
 
int main() {
	string userChoice = "";
	string modItem = "";
	int modNum = 0;
	string customerName;
	string todaysDate;
	cout << "Enter Customer's Name: ";
	getline(cin, customerName);
	cout << endl;
	cout << "Enter Today's Date: ";
	getline(cin, todaysDate);
	cout << endl << endl;
	ShoppingCart customerCart(customerName, todaysDate);
	while (true) {
		userChoice = "";
		cout << "Enter option: ";
		cin >> userChoice;
		cin.ignore();
		cout << endl;
		if (userChoice == "add") {
			customerCart.AddItem();
		}
		else if (userChoice == "remove") {
			modItem = "";
			cout << "Enter name of the item to remove: ";
			getline(cin, modItem);
			customerCart.RemoveItem(modItem);
		}
		else if (userChoice == "change") {
			modItem = "";
			cout << "Enter the item name: ";
			getline(cin, modItem);
			cout << endl;
			cout << "Enter the new quantity: ";
			cin >> modNum;
			cin.ignore();
			cout << endl;
			customerCart.UpdateItem(modItem, modNum);
		}
		else if (userChoice == "descriptions") {
			cout << customerCart.GetCustomerName() << "'s Shopping Cart - " << customerCart.GetCreationDate() << endl;
			if (customerCart.TotalItems() == 0) {
				cout << "Shopping cart is empty." << endl;
			}
			else {
				customerCart.PrintDescriptions();
			}
		}
		else if (userChoice == "cart") {
			cout << customerCart.GetCustomerName() << "'s Shopping Cart - " << customerCart.GetCreationDate() << endl;
			if (customerCart.TotalItems() == 0) {
				cout << "Shopping cart is empty." << endl;
			}
			else {
				cout << "Number of items: " << customerCart.TotalItems() << endl << endl;
				customerCart.PrintCosts();
				customerCart.TotalCost();
			}
			cout << endl;
		}
		else if (userChoice == "options") {
			printOptions();
		}
		else if (userChoice == "quit") {
			cout << "Goodbye." << endl;
			return 0;
		}
		else {
			printOptions();
		}
	}
}