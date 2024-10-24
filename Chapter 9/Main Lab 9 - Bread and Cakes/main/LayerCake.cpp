#include <string>
#include "LayerCake.h"

using namespace std;

LayerCake::LayerCake(string newFlavor, string newFrosting, int newLayers) : Cake(newFlavor, newFrosting) {
	numLayers = newLayers;
}

string LayerCake::ToStr() {
	//2-layer Chocolate cake with vanilla frosting ($12.000000
	string returnString = to_string(numLayers);
	returnString.append("-layer ");
	returnString.append(flavorType);
	returnString.append(" cake with ");
	returnString.append(frostingType);
	returnString.append(" frosting ($");
	returnString.append(this->BakedGood::ToStr());
	returnString.append(")");
	return returnString;
}

double LayerCake::CalculateDiscount(int itemQuantity) {
	double layerCakeDiscount = 2.0;
	double itemDiscount = 0;
	if (itemQuantity >= 3) {
		itemDiscount = itemQuantity * layerCakeDiscount;
	}
	return itemDiscount;
}