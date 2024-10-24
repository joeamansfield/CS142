#include "Bread.h"

Bread::Bread(string newGrain, double newPrice) : BakedGood(newPrice) {
	grainType = newGrain;
}

string Bread::ToStr() {
	string returnString = grainType;
	returnString.append(" bread ($");
	returnString.append(this->BakedGood::ToStr());
	returnString.append(")");
	return returnString;
}

double Bread::CalculateDiscount(int itemQuantity) {
	double itemDiscount = itemQuantity / 3 * this->GetPrice();
	return itemDiscount;
}