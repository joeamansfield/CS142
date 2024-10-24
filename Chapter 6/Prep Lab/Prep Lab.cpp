#include <iostream>
#include <string>
using namespace std;

int GetNumOfSpaces(const string countString) {
	int numSpaces = 0;
	for (int i = 0; i < countString.length(); i++) {
		if (countString.at(i) == ' ') {
			numSpaces++;
		}
	}
	return numSpaces;
}

void OutputWithoutWhitespace(string modString) {
	for (int i = 0; i < modString.length(); i++) {
		if (modString.at(i) == ' ' || modString.at(i) == '\t') {
			modString.erase(modString.begin() + i);
		}
	}
	cout << "String with no whitespace: " << modString << endl;
}
int main()
{
	string userPhrase;
	cout << "Enter a sentence or phrase: ";
	getline(cin, userPhrase);
	cout << endl;
	cout << "You entered: " << userPhrase << endl << endl;
	cout << "Number of spaces: " << GetNumOfSpaces(userPhrase) << endl;
	OutputWithoutWhitespace(userPhrase);

	return 0;
}
