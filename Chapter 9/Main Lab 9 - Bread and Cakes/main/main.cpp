#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include "CupCake.h"
#include "LayerCake.h"
using namespace std;

int main() {
	//Constants for control of baked good prices
	const double breadPrice = 4.5;
	const double layerCakeBasePrice = 6.0;
	const double layerCakePerLayerPrice = 3.0;
	const double layerCakeCreamCheeseFrostingPrice = 1.0;
	const double cupcakeBasePrice = 1.95;
	const double cupcakeCreamCheeseFrostingPrice = 0.2;


    cout << "**Bread and Cakes Bakery**" << endl << endl;
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;
	string bakedGoodType = "";
	vector<BakedGood*> shoppingCart;

	//Take user input and populate vector of baked goods
	do {
		cout << "Sub-order: ";
		cin >> bakedGoodType;
		cout << endl;

		if (bakedGoodType == "Bread") {
			string breadType = "";
			int breadQuantity = 0;
			cin >> breadType >> breadQuantity;
			for (int i = 0; i < breadQuantity; i++) {
				BakedGood* newBread = new Bread(breadType, breadPrice);
				shoppingCart.push_back(newBread);
			}
		}

		else if (bakedGoodType == "Layer-cake") {
			string cakeFlavor = "";
			string frostingFlavor = "";
			int numLayers = 0;
			int numCakes = 0;
			cin >> cakeFlavor >> frostingFlavor >> numLayers >> numCakes;
			for (int i = 0; i < numCakes; i++) {
				BakedGood* newCake = new LayerCake(cakeFlavor, frostingFlavor, numLayers);
				if (frostingFlavor == "cream-cheese") {
					newCake->FixPrice(layerCakeBasePrice + numLayers * (layerCakePerLayerPrice + layerCakeCreamCheeseFrostingPrice));
				}
				else {
					newCake->FixPrice(layerCakeBasePrice + numLayers * layerCakePerLayerPrice);
				}
				shoppingCart.push_back(newCake);
			}
		}

		else if (bakedGoodType == "Cupcake") {
			string cupcakeFlavor = "";
			string frostingFlavor = "";
			string sprinkleColor = "";
			int numCupcakes = 0;
			cin >> cupcakeFlavor >> frostingFlavor >> sprinkleColor >> numCupcakes;
			for (int i = 0; i < numCupcakes; i++) {
				BakedGood* newCupcake = new CupCake(cupcakeFlavor, frostingFlavor, sprinkleColor);
				if (frostingFlavor == "cream-cheese") {
					newCupcake->FixPrice(cupcakeBasePrice + cupcakeCreamCheeseFrostingPrice);
				}
				else {
					newCupcake->FixPrice(cupcakeBasePrice);
				}
				shoppingCart.push_back(newCupcake);
			}
		}
	} while (bakedGoodType != "done");

	//print order confirmation
	cout << "Order Confirmations:" << endl;
	for (unsigned int i = 0; i < shoppingCart.size(); i++) {
		cout << shoppingCart.at(i)->ToStr() << endl;
	}
	cout << endl;

	//create invoice item and count vector
	vector<BakedGood*> invoiceItems;
	vector<int> invoiceCount;
	BakedGood* compareGood = nullptr;
	for (int i = shoppingCart.size() - 1; i >= 0 ; i--) {
		invoiceItems.push_back(shoppingCart.at(i));
	}
	shoppingCart.clear();
	for (unsigned int i = 0; i < invoiceItems.size(); i++) {
		shoppingCart.push_back(invoiceItems.at(i));
	}
	invoiceItems.clear();
	while (shoppingCart.size() > 0) {
		int itemCounter = 0;
		compareGood = shoppingCart.back();
		invoiceItems.push_back(compareGood);
		for (int i = shoppingCart.size() - 1; i >= 0; i--) {
			if (compareGood->ToStr() == shoppingCart.at(i)->ToStr()) {
				itemCounter += 1;
				shoppingCart.erase(shoppingCart.begin() + i);
			}
		}
		invoiceCount.push_back(itemCounter);
	}

	//print invoice
	double totalCost = 0;
	double totalQuantity = 0;
	cout << fixed << setprecision(2);
	cout << "Invoice:" << endl;
	cout << setw(75) << left << "Baked Good" << setw(9) << right << "Quantity" << setw(9) << "Total" << endl;
	for (unsigned int i = 0; i < invoiceItems.size(); i++) {
		double totalCostPerItem = invoiceItems.at(i)->GetPrice() * invoiceCount.at(i) - invoiceItems.at(i)->CalculateDiscount(invoiceCount.at(i));
		totalCost += totalCostPerItem;
		totalQuantity += invoiceCount.at(i);
		cout << setw(75) << left << invoiceItems.at(i)->ToStr() << setw(9) << right << invoiceCount.at(i) << setw(9) << totalCostPerItem << endl;
	}
	cout << setw(75) << left << "Totals" << setw(9) << right << setprecision(0) << totalQuantity << setw(9) << setprecision(2) << totalCost << endl;
	cout << "Good Bye" << endl;
}