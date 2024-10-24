#include "BakedGood.h"

BakedGood::BakedGood(double newPrice){
	itemPrice = newPrice;
}

void BakedGood::FixPrice(double fixedPrice) {
	itemPrice = fixedPrice;
}

string BakedGood::ToStr() {
	return to_string(itemPrice);
}

double BakedGood::GetPrice() {
	return itemPrice;
}