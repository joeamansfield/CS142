#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
	itemName = "none";
	itemDescription = "none";
	itemPrice = 0.0;
	itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string name, string description, double price, int quantity) {
	itemName = name;
	itemDescription = description;
	itemPrice = price;
	itemQuantity = quantity;
}

void ItemToPurchase::SetName(string name = "none") {
	itemName = name;
}

string ItemToPurchase::GetName() {
	return itemName;
}

void ItemToPurchase::SetDescription(string description) {
	itemDescription = description;
}

string ItemToPurchase::GetDescription() {
	return itemDescription;
}

void ItemToPurchase::SetPrice(double price = 0.0) {
	itemPrice = price;
}

double ItemToPurchase::GetPrice() {
	return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity = 0) {
	itemQuantity = quantity;
}

int ItemToPurchase::GetQuantity() {
	return itemQuantity;
}

void ItemToPurchase::PrintCost() {
	double totalCost = itemPrice * itemQuantity;
	cout << fixed << setprecision(2);
	cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << totalCost << endl;
}

void ItemToPurchase::PrintDescription() {
	cout << itemName << ": " << itemDescription << endl;
}