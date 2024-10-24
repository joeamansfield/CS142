#pragma once
#include <string>

class ItemToPurchase {
public:
	ItemToPurchase();
	ItemToPurchase(std::string name, std::string description, double price, int quantity);
	void SetName(std::string name);
	std::string GetName();
	void SetDescription(std::string description);
	std::string GetDescription();
	void SetPrice(double price);
	double GetPrice();
	void SetQuantity(int quantity);
	int GetQuantity();
	void PrintCost();
	void PrintDescription();
private:
	std::string itemName;
	std::string itemDescription;
	double itemPrice;
	int itemQuantity;
};