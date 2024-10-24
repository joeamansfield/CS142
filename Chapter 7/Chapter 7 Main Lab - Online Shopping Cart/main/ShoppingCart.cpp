#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"
using namespace std;

ShoppingCart::ShoppingCart() {
	customerName = "none";
	creationDate = "none";
}

ShoppingCart::ShoppingCart(string name, string date) {
	customerName = name;
	creationDate = date;
}

string ShoppingCart::GetCustomerName() {
	return customerName;
}

string ShoppingCart::GetCreationDate() {
	return creationDate;
}

void ShoppingCart::AddItem() {
	bool itemFound = false;
	string name;
	string description;
	double price;
	int quantity;
	cout << "Enter the item name: ";
	getline(cin, name);
	cout << endl;
	cout << "Enter the item description: ";
	getline(cin, description);
	cout << endl;
	cout << "Enter the item price: ";
	cin >> price;
	cin.ignore();
	cout << endl;
	cout << "Enter the item quantity: ";
	cin >> quantity;
	cin.ignore();
	cout << endl;
	ItemToPurchase itemToAdd(name, description, price, quantity);
	for (int i = 0; i < cart.size(); i++) {
		if (cart.at(i).GetName() == itemToAdd.GetName()) {
			itemFound = true;
			cout << "Item is already in cart. Nothing added." << endl;
			break;
		}
	}
	if (itemFound == false) {
		cart.push_back(itemToAdd);
	}
}

void ShoppingCart::RemoveItem(string itemName) {
	bool itemFound = false;
	for (int i = 0; i < cart.size(); i++) {
		if (cart.at(i).GetName() == itemName) {
			itemFound = true;
			cart.erase(cart.begin() + i);
			break;
		}
	}
	if (itemFound == false) {
		cout << "Item not found in cart. Nothing removed." << endl;
	}
}

void ShoppingCart::UpdateItem(string itemName, int newQuantity) {
	bool itemFound = false;
	for (int i = 0; i < cart.size(); i++) {
		if (cart.at(i).GetName() == itemName) {
			cart.at(i).SetQuantity(newQuantity);
			itemFound = true;
		}
	}
	if (itemFound == false) {
		cout << "Item not found in cart. Nothing modified." << endl;
	}
}

int ShoppingCart::TotalItems() {
	int totalItems = 0;
	for (int i = 0; i < cart.size(); i++) {
		totalItems += cart.at(i).GetQuantity();
	}
	return totalItems;
		
}

double ShoppingCart::TotalCost() {
	double totalCost = 0;
	for (int i = 0; i < cart.size(); i++) {
		totalCost += cart.at(i).GetQuantity() * cart.at(i).GetPrice();
	}
	return totalCost;
}

void ShoppingCart::PrintCosts() {
	double totalCost = 0;
	for (int i = 0; i < cart.size(); i++) {
		cart.at(i).PrintCost();
		totalCost += cart.at(i).GetQuantity() * cart.at(i).GetPrice();
	}
	cout << fixed << setprecision(2) << endl;
	cout << "Total: $" << totalCost << endl;
}

void ShoppingCart::PrintDescriptions() {
	cout << "Item Descriptions" << endl;
	for (int i = 0; i < cart.size(); i++) {
		cart.at(i).PrintDescription();
	}
}