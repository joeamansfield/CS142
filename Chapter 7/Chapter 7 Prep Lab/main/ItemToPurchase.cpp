#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

void ItemToPurchase::SetName(string name = "none") {
	itemName = name;
}

string ItemToPurchase::GetName() {
	return itemName;
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