

#include <iostream>
#include <string>

using namespace std;

struct Personne {
	string Name, City, Country;
	short unsigned Age;
	unsigned int MonthlySalary;
	char Gender;
	bool IsMarried;
};

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

int readInformationsFromArray(Personne persn[100]) {

	int arrayLength;
	cout << "how many personnes you want to create";
	cin >> arrayLength;

	for (int i = 0; i < arrayLength; i++) {
		cout << "give personne's "<< i+1 <<"info";
		readInformations(persn[i]);
	}
	return arrayLength;
}

void writeInformationsFromArray(Personne persn[100], int arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		writeInformations(persn[i]);
	}
}

void useReadAndWriteInformations() {

	Personne persn[100];

	int arrayLength = readInformationsFromArray(persn);
	writeInformationsFromArray(persn, arrayLength);
}

void nestedLoopAsciiTable() {
	for (int i = 65; i <= 90; i++) {
		for (int j = 65; j <= 90; j++) {
			cout << char(i) << char(j) << "\n";
		}
		cout << "\n";
	}
}

void nestedLoopAsciiTable2() {
	for (int i = 65; i <= 72; i++) {
		for (int j = 65; j <= i; j++) {
			cout << char(j);
		}
		cout << "\n";
	}
}

void nestedLoopStars() {
	for (int i = 1; i < 10; i++) {
		for (int j = 10; j > i; j--) {
			cout << "*";
		}
		cout << "\n";
	}
}

void nestedLoopNumbersGtoL() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j;
		}
		cout << "\n";
	}
}

void nestedLoopNumbersLtoG() {
	for (int i = 10; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			cout << j;
		}
		cout << "\n";
	}
}

void searchInArr() {
	int arr[10] = {10,20,44,55,33,22,99,88,99,100};

	for (int i = 0; i <= 10; i++) {
		if (arr[i] == 20) {
			cout << "the position of 20 is : " << i;
			break;
		}
	}
}

void readNumbersAsLongAsNumLowerThan50() {

	int i = 0;
	int sum = 0;
	int numToAdd = 0;

	while (i < 5) {
		cout << "give a number lower then 50";
		cin >> numToAdd;

		if (numToAdd > 50) {
			continue;
		}
		sum += numToAdd;
		i++;
	}
	cout << "the Sum is" << sum;

}

int main() {
	readNumbersAsLongAsNumLowerThan50();
	return 0;
}