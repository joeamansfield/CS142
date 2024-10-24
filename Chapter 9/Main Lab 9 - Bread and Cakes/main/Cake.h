#pragma once
#include <string>
#include "BakedGood.h"
class Cake : public BakedGood {
public:
	Cake(string newFlavor = "", string newFrosting = "");
	virtual string ToStr() = 0;
	virtual double CalculateDiscount(int itemQuantity) = 0;
protected:
	string flavorType;
	string frostingType;
};

