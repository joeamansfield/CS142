#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

void OutputOptions() {
	cout << "Please select one of the following options:" << endl;
	cout << endl;
	cout << "quit - Quit the program" << endl;
	cout << "display - Display all restaurants" << endl;
	cout << "add - Add a restaurant" << endl;
	cout << "remove - Remove a restaurant" << endl;
	cout << "cut - \"Cut\" the list of restaurants" << endl;
	cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
	cout << "battle - Begin the tournament" << endl;
	cout << "options - Print the options menu" << endl;
	cout << endl;
}

void Display(vector<string> &restaurantList) {
	cout << "Here are the current restaurants:" << endl << endl;
	for (int i = 0; i < restaurantList.size(); i++) {
		cout << "\t\"" << restaurantList.at(i) << "\"" << endl;
	}
	cout << endl;
}

bool PowerOfTwo(int checkNumber) {
	double factorCounter = checkNumber;
	while (factorCounter >= 2) {
		factorCounter = factorCounter / 2;
	}
	if (factorCounter == 1) {
		return true;
	}
	else {
		return false;
	}
}

int FindRestaurant(const vector<string>& restaurantList, string restaurantName) {
	int count = 0;
	for (int i = 0; i < restaurantList.size(); i++) {
		count += 1;
		if (restaurantList.at(i) == restaurantName) {
			return count;
		}
	}
	return 0;
}
//FindRestaurant returns index + 1, or 0 if restaurant is not found, in order to be used directly in logic statements

void Add(vector<string> &restaurantList) {
	string restaurantName = "";
	bool AddToList = true;
	cout << "What is the name of the restaurant you want to add?" << endl;
	getline(cin, restaurantName);
	if (!FindRestaurant(restaurantList, restaurantName)) {
		restaurantList.push_back(restaurantName);
		cout << restaurantName << " has been added." << endl << endl;
	}
	else {
		cout << "That restaurant is already in the list, you can not add it again." << endl << endl;
	}
}

void Remove(vector<string> &restaurantList) {
	string restaurantName = "";
	bool AddToList = true;
	cout << "What is the name of the restaurant you want to remove?" << endl;
	getline(cin, restaurantName);
	if (FindRestaurant(restaurantList, restaurantName)) {
		restaurantList.erase(restaurantList.begin() + FindRestaurant(restaurantList, restaurantName) - 1);
		cout << restaurantName << " has been removed." << endl << endl;
	}
	else {
		cout << "That restaurant is not in the list, you can not remove it." << endl << endl;
	}
}

void Cut(vector<string> &restaurantList) {
	vector<string> tempList;
	int cutPoint = 0;
	do {
		cout << "How many restaurants should be taken from the top and put on the bottom? ";
		cin >> cutPoint;
		if (cin.fail()) {
			cin.clear();
			cutPoint = -1;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
		if (cutPoint > restaurantList.size() || cutPoint < 0) {
			cout << "The cut number must be between 0 and " << restaurantList.size() << endl;
		}
		else {
			if (cutPoint == 0 || cutPoint == restaurantList.size()) {
				//do nothing
			}
			else {
				for (int i = cutPoint; i < restaurantList.size(); i++) {
					tempList.push_back(restaurantList.at(i));
				}
				for (int i = 0; i < cutPoint; i++) {
					tempList.push_back(restaurantList.at(i));
				}
				for (int i = 0; i < restaurantList.size(); i++) {
					restaurantList.at(i) = tempList.at(i);
				}
			}
		}
	} while (cutPoint < 0 || cutPoint > restaurantList.size());
}

void Shuffle(vector<string> &restaurantList) {
	vector<string> topDeck;
	vector<string> bottomDeck;
	if (PowerOfTwo(restaurantList.size())) {
		for (int i = 0; i < restaurantList.size(); i++) {
			if (i < restaurantList.size() / 2) {
				topDeck.push_back(restaurantList.at(i));
			}
			else {
				bottomDeck.push_back(restaurantList.at(i));
			}
		}
		restaurantList.clear();
		for (int i = 0; i < topDeck.size(); i++) {
			restaurantList.push_back(bottomDeck.at(i));
			restaurantList.push_back(topDeck.at(i));
		}
	}
	else {
		cout << "The current tournament size (" << restaurantList.size() << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A shuffle is not possible. Please add or remove restaurants." << endl;
	}
}

void Battle(vector<string> &restaurantList) {
	vector<string> battleList;
	int roundNumber = 0;
	int userChoice = 0;
	if (PowerOfTwo(restaurantList.size())) {
		while (restaurantList.size() > 1) {
			roundNumber += 1;
			cout << "Round: " << roundNumber << endl << endl;
			for (int i = 0; i < restaurantList.size(); i += 2) {
				do {
					cout << "Type \"1\" if you prefer " << restaurantList.at(i) << " or" << endl;
					cout << "type \"2\" if you prefer " << restaurantList.at(i + 1) << endl;
					cout << "Choice: ";
					cin >> userChoice;
					if (cin.fail()) {
						cin.clear();
						userChoice = -1;
					}
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << endl;
					if (userChoice != 1 && userChoice != 2) {
						cout << "Invalid choice" << endl;
					}
				} while (userChoice != 1 && userChoice != 2);
				if (userChoice == 1) {
					battleList.push_back(restaurantList.at(i));
				}
				else {
					battleList.push_back(restaurantList.at(i + 1));
				}
			}
			restaurantList.clear();
			for (int i = 0; i < battleList.size(); i++) {
				restaurantList.push_back(battleList.at(i));
			}
			battleList.clear();
		}
		cout << "The winning restaurant is " << restaurantList.at(0) << "." << endl << endl;
	}
	else {
		cout << "The current tournament size (" << restaurantList.size() << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A battle is not possible. Please add or remove restaurants." << endl;
	}
}

int main() {
	string userChoice = "";
	vector<string> restaurantList;
	cout << "Welcome to the restaurant battle! Enter \"options\" to see options." << endl << endl;
	while (true) {
		cout << "Enter your selection: ";
		getline(cin, userChoice);
		cout << endl;
		if (userChoice == "options") {
			OutputOptions();
		}
		else if (userChoice == "quit") {
			cout << "Goodbye!";
			return 0;
		}
		else if (userChoice == "display") {
			Display(restaurantList);
		}
		else if (userChoice == "add") {
			Add(restaurantList);
		}
		else if (userChoice == "remove") {
			Remove(restaurantList);
		}
		else if (userChoice == "cut") {
			Cut(restaurantList);
		}
		else if (userChoice == "shuffle") {
			Shuffle(restaurantList);
		}
		else if (userChoice == "battle") {
			Battle(restaurantList);
		}
		else {
			cout << "Invalid Selection" << endl;
			OutputOptions();
		}
	}
}