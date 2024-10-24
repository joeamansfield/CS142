#include <iostream>
#include <iomanip>
using namespace std;

#include "ItemToPurchase.h"

int main()
{
	ItemToPurchase item1;
	ItemToPurchase item2;

	string itemName = "";
	double itemPrice = 0.0;
	int itemQuantity = 0;
	cout << "Item 1" << endl;
	cout << "Enter the item name: ";
	getline(cin, itemName);
	cout << endl;
	cout << "Enter the item price: ";
	cin >> itemPrice;
	cin.ignore();
	cout << endl;
	cout << "Enter the item quantity: ";
	cin >> itemQuantity;
	cin.ignore();
	cout << endl;
	item1.SetName(itemName);
	item1.SetPrice(itemPrice);
	item1.SetQuantity(itemQuantity);

	cout << "Item 2" << endl;
	cout << "Enter the item name: ";
	getline(cin, itemName);
	cout << endl;
	cout << "Enter the item price: ";
	cin >> itemPrice;
	cin.ignore();
	cout << endl;
	cout << "Enter the item quantity: ";
	cin >> itemQuantity;
	cin.ignore();
	cout << endl;
	item2.SetName(itemName);
	item2.SetPrice(itemPrice);
	item2.SetQuantity(itemQuantity);

	cout << fixed << setprecision(2);
	cout << "TOTAL COST" << endl;
	cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << item1.GetQuantity() * item1.GetPrice() << endl;
	cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << item2.GetQuantity() * item2.GetPrice() << endl;
	cout << endl;
	cout << "Total: $" << item1.GetQuantity() * item1.GetPrice() + item2.GetQuantity() * item2.GetPrice() << endl;
}