#pragma once
#include <string>

class ItemToPurchase {
public:
	void SetName(std::string name);
	std::string GetName();
	void SetPrice(double price);
	double GetPrice();
	void SetQuantity(int quantity);
	int GetQuantity();
private:
	std::string itemName; //Initialized in default constructor to "none"
	double itemPrice; //Initialized in default constructor to 0.0
	int itemQuantity; //Initialized in default constructor to 0
};