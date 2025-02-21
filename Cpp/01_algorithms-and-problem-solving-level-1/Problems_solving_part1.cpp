#include <iostream>
#include <string>
#include <math.h>

using namespace std;

enum enPassFail {
	Passed , Failed
};
enum enEvenOdd {Even, Odd};
enum enOperationType {Add='+',Multiply='*', Divide ='/', Substract = '-' };

struct stTaskDuration { int days, hours, minutes, seconds; };

enEvenOdd CheckNumberTypeEvenOrOdd(int num) {
	return (num % 2 == 0 ? enEvenOdd::Even : enEvenOdd::Odd);
}

void ReadNumbers(int nums[3]) {
	for (int i = 0; i < 3;i++) {
		cout << "Please enter Number " <<i+1;
		cin >> nums[i];
	}
}

int CalculatSum(int nums[3]) {
	return nums[0] + nums[1] + nums[2];
}

float CalculateAverage(int nums[3]) {
	return (float)CalculatSum(nums) / 3;
}

enPassFail CheckAverage(float avg) {
	if (avg > 50)
		return enPassFail::Passed;
	else
		return enPassFail::Failed;
}

int GetMaxOfnNumbers(int nums[3]) {
	int maxNumber = 0;
	for (int i = 0; i < 2;i++) {
		int comparaison = nums[i] > nums[i + 1] ? nums[i] : nums[i + 1];
		maxNumber = maxNumber > comparaison ? maxNumber : comparaison;
	}
	return maxNumber;
}

int GetMaxOf3Numbers(int a, int b, int c) {
	int maxNumber = 0;
	
	if (a > b) {
			if (a>c)
				maxNumber = a;
			else
				maxNumber = c;
	}
	else {
		if (b > c) 
			maxNumber = b;
		else 
			maxNumber = c;
	}
	return maxNumber;
}

void Swap2Numbers(int& num1, int& num2) {
	int swapper = num1;
	num1 = num2;
	num2 = swapper;
}

void PrintResults(float avg) {
	if (CheckAverage(avg) == enPassFail::Passed) {
		cout << "You Passed \n";
	}
	else {
		cout << "You Failed";
	}
	cout << "Your Result is " << avg;

}

float CalculateRectangleAreaByDiagonalAndArea(int area,int diagonal) {
	return area * sqrt(pow(diagonal, 2) - pow(area, 2));
}

float CalculateThriangleArea(int a, int h) {
	return (float)(a * h )/2 ;
}

void ReadUntilAgeValid() {
	unsigned short num=0;
	do {
		cout << "Enter a number ";
		cin >> num;
	} while (!(num > 18 && num < 45));
}

int SumOddNumFrom1ToN(int n) {
	int sum = 0;
	for (int i = 1; i < n+1;i++) {
		if (CheckNumberTypeEvenOrOdd(i) == enEvenOdd::Odd)
			sum += i;
	}
	return sum;
}

int CalculateFactorialOfN(int n) {
	int factorial = 1;
	for (int i = 1; i <= n;i++) {
		factorial *= i;
	}
	return factorial;
}

int PowerOf(int power, int number) {
	for (int i = 1; i < power;i++) {
		number *= number;
	}
	return number;
}

float Calculator(float num1,float num2, enOperationType operationSymbol) {
	float result = 0;
	switch (operationSymbol) {
	case enOperationType::Add :
		return result = num1 + num2;
	case enOperationType::Substract :
		return result = num1 - num2;
	case enOperationType::Multiply:
		return result = num1 * num2;
	case enOperationType::Divide:
		return result = num1 / num2;
	default : 
		return 0;
	}
}

bool IsPrimeNumber(int num) {
	for (int i = 2; i < num;i++) {
		if (num % i == 0) 
			return false;
	}
	return true;
}

float HoursToDay(int hours) {
	return (float)hours / 24;
}

float HoursToWeeks(int hours) {
	return HoursToDay(hours) / 7;
}

float CalculateTaskDurationInSeconds(stTaskDuration taskDuration) {
	return (taskDuration.days * 24 * 60 * 60) + (taskDuration.hours * 60 * 60) + (taskDuration.minutes * 60) + (taskDuration.seconds);
}

stTaskDuration SecondsToStTaskDuration(int seconds) {
	stTaskDuration tsk;
	int secondsPerDays =  60 * 60 * 24;
	int secondsPerHours =  60 * 60;
	int secondsPerMinutes = 60;
	int reminder = 0;

	tsk.days = floor(seconds/ secondsPerDays);
	reminder = seconds % secondsPerDays;

	tsk.hours = floor(reminder/secondsPerHours);
	reminder = seconds % secondsPerHours;

	tsk.minutes = floor(reminder/secondsPerMinutes);
	reminder = seconds % secondsPerMinutes;

	tsk.seconds = reminder;
	return tsk;
}

void PrintLettersFromAtoZ() {
	for (int i = 65; i <= 90; i++)
	{
		cout << char(i) << endl;
	}
}


int main() {
}