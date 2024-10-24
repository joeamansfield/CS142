#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
	const int NUM_ROWS = 10;
	const int NUM_COLUMNS = 10;
	double hotplateTemps[NUM_ROWS][NUM_COLUMNS];
	double largestChange = 0;

	cout << "Hotplate simulator" << endl << endl;
	//populate array
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++) {
			hotplateTemps[i][j] = 0.0;
			if (i == 0 || i == NUM_ROWS - 1) {
				if (j != 0 && j != NUM_COLUMNS - 1) {
					hotplateTemps[i][j] = 100.0;
				}
			}
		}
	}

	//duplicate matrix
	double updatedTemps[NUM_ROWS][NUM_COLUMNS];
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++) {
			updatedTemps[i][j] = hotplateTemps[i][j];
		}
	}

	//update matrix
	cout << fixed << setprecision(3) << showpoint;
	int iteration = 0;
	do {
		if (iteration == 0) {
			cout << "Printing initial plate..." << endl;
		}
		if (iteration == 1) {
			cout << "Printing plate after one iteration..." << endl;
		}
		if (iteration <= 2) {
			//display matrix
			for (int i = 0; i < NUM_ROWS; i++) {
				for (int j = 0; j < NUM_COLUMNS; j++) {
					cout << setw(9) << hotplateTemps[i][j];
					if (j < NUM_COLUMNS - 1) {
						cout << ",";
					}
				}
				cout << endl;
			}
			cout << endl;
		}
		largestChange = 0;
		for (int i = 1; i < NUM_ROWS - 1; i++) {
			for (int j = 1; j < NUM_COLUMNS - 1; j++) {
				updatedTemps[i][j] = (hotplateTemps[i + 1][j] + hotplateTemps[i - 1][j] + hotplateTemps[i][j + 1] + hotplateTemps[i][j - 1]) / 4;
			}
		}
		for (int i = 0; i < NUM_ROWS; i++) {
			for (int j = 0; j < NUM_COLUMNS; j++) {
				if (fabs(updatedTemps[i][j] - hotplateTemps[i][j]) > largestChange) {
					largestChange = fabs(updatedTemps[i][j] - hotplateTemps[i][j]);
				}
				hotplateTemps[i][j] = updatedTemps[i][j];
			}
		}
		iteration++;
	} while (largestChange > .1);

	//display matrix
	cout << "Printing final plate..." << endl;
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++) {
			cout << setw(9) << hotplateTemps[i][j];
			if (j < NUM_COLUMNS - 1) {
				cout << ",";
			}
		}
		cout << endl;
	}
	cout << endl;

	//output matrix to a file
	cout << "Outputting final plate to file \"Hotplate.csv\"..." << endl << endl;
	ofstream outFS;
	outFS.open("Hotplate.csv");
	outFS << fixed << setprecision(3) << showpoint;
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++) {
			outFS << setw(9) << hotplateTemps[i][j];
			if (j < NUM_COLUMNS - 1) {
				outFS << ",";
			}
		}
		outFS << endl;
	}
	outFS.close();

	//populate array from inputplate
	ifstream inFS;
	inFS.open("Inputplate.txt");
	if (!inFS.is_open()) {
		cout << "Could not open file." << endl;
		return 1;
	}
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++) {
			inFS >> hotplateTemps[i][j];
		}
	}

	//duplicate matrix
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++) {
			updatedTemps[i][j] = hotplateTemps[i][j];
		}
	}

	
	//update matrix
	for (int i = 0; i < 3; i++) {
		for (int i = 1; i < NUM_ROWS - 1; i++) {
			for (int j = 1; j < NUM_COLUMNS - 1; j++) {
				updatedTemps[i][j] = (hotplateTemps[i + 1][j] + hotplateTemps[i - 1][j] + hotplateTemps[i][j + 1] + hotplateTemps[i][j - 1]) / 4;
			}
		}
		for (int i = 0; i < NUM_ROWS; i++) {
			for (int j = 0; j < NUM_COLUMNS; j++) {
				if (abs(updatedTemps[i][j] - hotplateTemps[i][j]) > largestChange) {
					largestChange = abs(updatedTemps[i][j] - hotplateTemps[i][j]);
				}
				hotplateTemps[i][j] = updatedTemps[i][j];
			}
		}
	}

	//display matrix
	cout << "Printing input plate after 3 up[dates..." << endl;
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++) {
			cout << setw(9) << hotplateTemps[i][j];
			if (j < NUM_COLUMNS - 1) {
				cout << ",";
			}
		}
		cout << endl;
	}

	return 0;
}