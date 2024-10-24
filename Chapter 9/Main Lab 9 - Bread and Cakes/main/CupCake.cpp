#include "CupCake.h"

CupCake::CupCake(string newFlavor, string newFrosting, string newSprinkle) : Cake(newFlavor, newFrosting) {
	sprinkleType = newSprinkle;
}

string CupCake::ToStr() {
	string returnString = flavorType;
	returnString.append(" cupcake with ");
	returnString.append(frostingType);
	returnString.append(" frosting and ");
	returnString.append(sprinkleType);
	returnString.append(" sprinkles ($");
	returnString.append(this->BakedGood::ToStr());
	returnString.append(")");
	return returnString;
}

double CupCake::CalculateDiscount(int itemQuantity) {
	const double discountForTwo = 0.3;
	const double discountForFour = 0.4;
	double itemDiscount = 0;
	if (itemQuantity >= 2) {
		itemDiscount = itemQuantity * discountForTwo;
	}
	if (itemQuantity >= 4) {
		itemDiscount = itemQuantity * discountForFour;
	}
	return itemDiscount;
}