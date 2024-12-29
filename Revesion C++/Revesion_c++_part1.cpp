

#include <iostream>
#include <string>

using namespace std;

int globalVariable = 10;
struct Personne {
	string Name, City, Country;
	short unsigned Age;
	unsigned int MonthlySalary;
	char Gender;
	bool IsMarried;
};

void logGlobalVariable() {
	cout << ::globalVariable;
}

void readInformations(Personne &persn) {
	cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";

	cout << "name : \n";
	cin >> persn.Name;
	cout << "City : \n";
	cin >> persn.City;
	cout << "Country : \n";
	cin >> persn.Country;
	cout << "Age : \n";
	cin >> persn.Age;
	cout << "MonthlySalary : \n";
	cin >> persn.MonthlySalary;
	cout << "Gender : \n";
	cin >> persn.Gender;
	cout << "IsMarried : \n";
	cin >> persn.IsMarried;
	cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";

}

void writeInformations(Personne persn) {
	
	cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	cout << "Name :" << persn.Name << ".\n";
	cout << "Age :" << persn.Age << ". \n";
	cout << "City :" << persn.City << ".\n";
	cout << "Country :" << persn.Country << ".\n";
	cout << "MonthlySalary :" << persn.MonthlySalary << ".\n";
	cout << "YearlySalary :" << persn.MonthlySalary * 12 << ".\n";
	cout << "Gender :" << persn.Gender << ".\n";
	cout << "IsMarried :" << persn.IsMarried << ".\n";
	cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";

}

void readInformationsFromArray(Personne persn[2]) {

	for (int i = 0; i < 2; i++) {
		readInformations(persn[i]);
	}
}

void writeInformationsFromArray(Personne persn[2]) {
	
	for (int i = 0; i < 2; i++) {
		writeInformations(persn[i]);
	}
}

void readAndWriteInformationsWithArray() {
	Personne prs[2];
	readInformationsFromArray(prs);
	writeInformationsFromArray(prs);
}

void readAndWriteInformations() {
	Personne personne1;
	readInformations(personne1);
	writeInformations(personne1);
}

void readAndWriteInformationsUsingStructure() {

	enum enGender { Male, Female};
		
	struct stAdress {
		string Country;
		string City;
		string Street;
		};

	struct stPersonInformation {
		string FirstName;
		string LastName;
		short unsigned Age;
		enGender gender;
	};

	struct stPerson {
		stPersonInformation personInformations;
		stAdress adress;
		unsigned int MonthlySalary;
		bool IsMarried;
	};

		stPerson personne1;
		int genderNum;

		cout << "First name : \n";
		cin >> personne1.personInformations.FirstName;
		cout << "City : \n";
		cin >> personne1.adress.City;
		cout << "Country : \n";
		cin >> personne1.adress.Country;
		cout << "Age : \n";
		cin >> personne1.personInformations.Age;
		cout << "MonthlySalary : \n";
		cin >> personne1.MonthlySalary;
		cout << "IsMarried : \n";
		cin >> personne1.IsMarried;
		cout << "gender : \n";
		cin >> genderNum;
		personne1.personInformations.gender = (enGender)genderNum;

		cout << "Name :" << personne1.personInformations.FirstName << ".\n";
		cout << "Age :" << personne1.personInformations.Age << ". \n";
		cout << "City :" << personne1.adress.City << ".\n";
		cout << "Country :" << personne1.adress.Country << ".\n";
		cout << "MonthlySalary :" << personne1.MonthlySalary << ".\n";
		cout << "YearlySalary :" << personne1.MonthlySalary * 12 << ".\n";
		cout << "Gender :" << personne1.personInformations.gender << ".\n";
		cout << "IsMarried :" << personne1.IsMarried << ".\n";
}

void dataTypeConversion() {
	string st1 = "43.22";
	int n1 = 20;
	double n2 = 33.5;
	float n3 = 55.23;

	double st1ConvertedDouble = stod(st1);
	int st1ConvertedInt = stoi(st1);
	float st1ConvertedFloat = stof(st1);

	string n1String = to_string(n1);
	string n2String = to_string(n2);
	string n3String = to_string(n3);

}

void  swapVariablesUsingReference(int &num1, int &num2) {
	int swapper = num1;
	num1 = num2;
	num2 = swapper;
}

void swapVariable() {
	int numToSwapp1 = 10;
	int numToSwapp2 = 5;
	swapVariablesUsingReference(numToSwapp1, numToSwapp2);

	cout << numToSwapp1 << numToSwapp2;
}

void readArrayElements(float grades[3]) {
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter Grade" << (i + 1);
		cin >> grades[i];
	}
}

float calculateAverage(float grades[3]) {
	return (grades[0] + grades[1] + grades[2]) / 3;
}

void calculateGradeUsingArray() {
	float grades[3];

	readArrayElements(grades); // we send the reference
	cout << "Your Grade is " << calculateAverage(grades);
}

void buildForLoop() {

}

int main()
{
	readAndWriteInformationsWithArray();
	return 0;
}