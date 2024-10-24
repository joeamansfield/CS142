#pragma once
#include <string>
#include <vector>

#include "ItemToPurchase.h"

class ShoppingCart {
public:
	ShoppingCart();
	ShoppingCart(std::string name, std::string date);
	std::string GetCustomerName();
	std::string GetCreationDate();
	void AddItem();
	void RemoveItem(std::string itemName);
	void UpdateItem(std::string itemName, int newQuantity);
	int TotalItems();
	double TotalCost();
	void PrintCosts();
	void PrintDescriptions();
private:
	std::string customerName;
	std::string creationDate;
	std::vector<ItemToPurchase> cart;
};