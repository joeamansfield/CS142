#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Student {
public:
	Student(string name = "not intialized", double GPA = 0.0);
	void SetName(string studentName);
	void SetGPA(double newGPA);
	string ToString() const;
private:
	string name;
	double GPA;
};

Student::Student(string initialName, double initialGPA) {
	name = initialName;
	GPA = initialGPA;
}

void Student::SetName(string inputName) {
	name = inputName;
}

void Student::SetGPA(double newGPA) {
	GPA = newGPA;
}

string Student::ToString() const{
	string madLad = "";
	madLad.append(name);
	madLad.append(" has a GPA of ");
	madLad.append(to_string(GPA));
	return madLad;
}

int main() {
	vector<Student*> students;
	string userChoice = "";
	string studentName = "";
	double studentGPA = 0;
	int dropIndex = 0;
	Student* newStudent = nullptr;
	while (true) {
		cout << "Enter Option: ";
		cin >> userChoice;
		if (userChoice == "add") {
			studentName = "";
			studentGPA = 0;
			newStudent = nullptr;
			cout << "Student name: ";
			cin >> studentName;
			cout << studentName << "'s GPA: ";
			cin >> studentGPA;
			newStudent = new Student(studentName, studentGPA);
			students.push_back(newStudent);
			cout << endl;
		}
		else if (userChoice == "drop") {
			cout << "Index of student to drop: ";
			cin >> dropIndex;
			delete students.at(dropIndex);
			students.erase(students.begin() + dropIndex);
			cout << endl << endl;
		}
		else if (userChoice == "print") {
			for (int i = 0; i < students.size(); i++) {
				cout << i << ": " << students.at(i)->ToString() << endl;
			}
			cout << endl;
		}
		else if (userChoice == "quit") {
			return 0;
		}
	}

	return 0;
}