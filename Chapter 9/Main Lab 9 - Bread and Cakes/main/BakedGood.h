#pragma once
#include <string>
using namespace std;

class BakedGood {
public:
	BakedGood(double newPrice = 0.0);
	virtual string ToStr() = 0;
	virtual double CalculateDiscount(int itemQuantity) = 0;
	void FixPrice(double fixedPrice);
	double GetPrice();
protected:
	double itemPrice;
};

