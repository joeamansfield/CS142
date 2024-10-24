#pragma once
#include <string>
#include "Cake.h"

class LayerCake : public Cake {
public:
	LayerCake(std::string newFlavor = "", std::string newFrosting = "", int newLayers = 0);
	virtual string ToStr();
	virtual double CalculateDiscount(int itemQuantity);
protected:
	int numLayers;
};

