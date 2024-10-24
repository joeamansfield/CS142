#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> jerseyNumber(5);
	vector<int> playerRating(5);
	char menuOption;
	int input = 0;
	int input2 = 0;

	for (int i = 0; i < jerseyNumber.size(); i++) {
		cout << "Enter player " << i + 1 << "'s jersey number: ";
		cin >> jerseyNumber.at(i);
		cout << endl;
		cout << "Enter player " << i + 1 << "'s rating: ";
		cin >> playerRating.at(i);
		cout << endl << endl;
	}
	
	cout << "ROSTER" << endl;
	for (int i = 0; i < jerseyNumber.size(); i++) {
		cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNumber.at(i) << ", Rating: " << playerRating.at(i) << endl;
	}

	while (true) {
		cout << "MENU" << endl;
		cout << "a - Add player" << endl;
		cout << "d - Remove player" << endl;
		cout << "u - Update player rating" << endl;
		cout << "r - Output players above a rating" << endl;
		cout << "o - Output roster" << endl;
		cout << "q - Quit" << endl << endl;
		cout << "Choose an option : ";
		cin >> menuOption;
		if (menuOption == 'a') { //add player
			cout << "Enter another player's jersey number: ";
			cin >> input;
			jerseyNumber.push_back(input);
			cout << "Enter another player's rating: ";
			cin >> input;
			playerRating.push_back(input);
		}
		else if (menuOption == 'd') { //delete player
			cout << "Enter a jersey number : ";
			cin >> input;
			cout << endl;
			for (int i = 0; i < jerseyNumber.size(); i++) {
				if (input == jerseyNumber.at(i)) {
					jerseyNumber.erase(jerseyNumber.begin() + i);
					playerRating.erase(playerRating.begin() + i);
				}
			}
		}
		else if (menuOption == 'u') { //update player rating
			cout << "Enter a jersey number: ";
			cin >> input;
			cout << endl;
			cout << "Enter a new rating for player: ";
			cin >> input2;
			cout << endl;
			for (int i = 0; i < jerseyNumber.size(); i++) {
				if (jerseyNumber.at(i) == input) {
					playerRating.at(i) = input2;
				}
			}
		}
		else if (menuOption == 'r') { //output players above a rating
			cout << "Enter a rating: ";
			cin >> input;
			cout << "ABOVE " << input << endl;
			for (int i = 0; i < jerseyNumber.size(); i++) {
				if (playerRating.at(i) > input) {
					cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNumber.at(i) << ", Rating: " << playerRating.at(i) << endl;
				}
			}
		}
		else if (menuOption == 'o') { //output roster
			cout << "ROSTER" << endl;
			for (int i = 0; i < jerseyNumber.size(); i++) {
				cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNumber.at(i) << ", Rating: " << playerRating.at(i) << endl;
			}
			cout << endl;
		}
		else if (menuOption == 'q') { //quit program
			return 0;
		}
		else { //invalid ption
			cout << "Please choose a valid option!" << endl;
		}

	}
}