#pragma once
#include <string>
#include "Cake.h"

class CupCake : public Cake {
public:
	CupCake(string newFlavor = "", string newFrosting = "", string newSprinkle = "");
	virtual string ToStr();
	virtual double CalculateDiscount(int itemQuantity);
protected:
	string sprinkleType;
};