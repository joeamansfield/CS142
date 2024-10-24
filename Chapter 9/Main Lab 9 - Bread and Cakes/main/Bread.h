#pragma once
#include "BakedGood.h"
#include <string>

class Bread : public BakedGood {
public:
	Bread(string newGrain, double newPrice);
	virtual string ToStr();
	virtual double CalculateDiscount(int itemQuantity);
private:
	string grainType;;
};