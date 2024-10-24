#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
public:
	Student(string initialName = "No Name") {
		name = initialName;
	}
	virtual string ToStr() {
		string outString = "";
		outString.append(name);
		outString.append(" is an undergraduate student.");
		return outString;
	}

protected:
	string name;
};

class GradStudent : public Student {
public:
	GradStudent(string initialName = "No Name", string initialResearch = "No Research") {
		name = initialName;
		researchArea = initialResearch;
	}
	virtual string ToStr() {
		string outString = "";
		outString.append(name);
		outString.append(" is a graduate student researching the area of ");
		outString.append(researchArea);
		outString.append(".");
		return outString;
	}

private:
	string researchArea;
};

int main() {
	string usrOption;
	string inpName;
	string inpResearch;
	vector<Student*> classMembers;

	do {
		cout << "Option: ";
		cin >> usrOption;
		cout << endl;
		if (usrOption == "print") {
			for (unsigned int i = 0; i < classMembers.size(); i++) {
				cout << classMembers.at(i)->ToStr() << endl;
			}
			cout << endl;
		}

		else if (usrOption == "add") {
			cout << "Name: ";
			cin >> inpName;
			cout << endl;
			cout << "If grad student enter a one word research area, else enter \"NO\": ";
			cin >> inpResearch;
			cout << endl;
			if (inpResearch == "NO") {
				Student* newStudent = new Student(inpName);
				classMembers.push_back(newStudent);
			}
			else {
				GradStudent* newStudent = new GradStudent(inpName, inpResearch);
				classMembers.push_back(newStudent);
			}
		}
	} while (usrOption != "quit");
	return 0;
}