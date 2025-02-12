#include <iostream>
#include <string>


using namespace std;

#pragma region Declarations
enum enPrimNotPrime { Prime = 1, NotPrime = 2 };
enum enEvenOdd { Even, Odd };

#pragma endregion

#pragma region generic Functions

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

string ReadPassword(string msg) {
	string pwd="";

	cout << msg << endl;
	cin >> pwd;
	return pwd;
}

void ReadArray(int arr[100],int &length) {

	length = ReadPositiveNumber("Enter number of elements :");

	for (int i = 0; i < length;i++) {
		cout << "give the elemnt number [" << i + 1 << "]" << endl;
		cin >> arr[i];
	}
}

void PrintArray(int arr[100], int length) {

	for (int i = 0;i < length;i++) 
		cout << arr[i] << " ";
	cout << "\n";
}

void PrintStringArray(string arr[100], int length) {

	for (int i = 0;i < length;i++)
		cout << arr[i] << endl;
	cout << "\n";
}

void Swap(int& num1, int& num2) {
	int swapper = num1;
	num1 = num2;
	num2 = swapper;
}

void AddArrayElement(int arr[100], int& length, int num) {
	arr[length] = num;
	length++;
}

enPrimNotPrime CheckPrime(int Number)
{
	int M = round(Number / 2);
	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)
			return enPrimNotPrime::NotPrime;
	}
	return enPrimNotPrime::Prime;
}

enEvenOdd CheckNumberTypeEvenOrOdd(int num) {
	return (num % 2 == 0 ? enEvenOdd::Even : enEvenOdd::Odd);
}
#pragma endregion

#pragma region Problem Solving from 1 to 10

#pragma region PrintMultiplicationTable
void PrintTableHeader()
{
	cout << "\n\n\t\t\t Multipliaction Table From 1 to 10\n\n";
	cout << "\t";
	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t";
	}
	cout << "\n___________________________________________________________________________________\n";
}

string ColumSperator(int i)
{
	if (i < 10)
		return " |";
	else
		return " |";
}

void PrintMultiplicationTable()
{
	PrintTableHeader();
	for (int i = 1; i <= 10; i++)
	{
		cout << " " << i << ColumSperator(i) << "\t";
		for (int j = 1; j <= 10; j++)
		{
			cout << i * j << "\t";
		}
		cout << endl;
	}
}
#pragma endregion

#pragma region PrintPrimeNumbersFrom1ToN
void PrintPrimeNumbersFrom1ToN(int Number)
{
	cout << "\n";
	cout << "Prime Numbers from " << 1 << " To " << Number;
	cout << " are : " << endl;
	for (int i = 1; i <= Number; i++)
	{
		if (CheckPrime(i) == enPrimNotPrime::Prime)
		{
			cout << i << endl;
		}
	}
}
#pragma endregion

#pragma region PrintPerfectNumbersFrom1ToN
bool IsPerfectNumber(int num) {
	int sum = 0;
	for (int i = 1;i < num;i++) {
		if (num % i == 0)
			sum += i;
	}
	return num == sum;
}

void PrintPerfectNumbersFrom1ToN(int num) {
	for (int i = 1; i <= num;i++) {
		if (IsPerfectNumber(i)) {
			cout << i << endl;
		}
	}
}
#pragma endregion

#pragma region PrintNumberInReversedOrder
void PrintDigitsInReversedOrder(int num) {

	int reminder = 0;
	while (num > 0) {
		reminder = num % 10;
		num /= 10;
		cout << reminder <<"\n";
	}
}

int SumOfDigits(int num) {

	int reminder,sum = 0;
	while (num > 0) {
		reminder = num % 10;
		num /= 10;
		sum += reminder;
	}
	return sum;
}

int ReverseOrderOf(int num) {

	int reminder,reversedNumber = 0;

	while (num > 0) {

		reminder = num % 10;
		num /= 10;
		reversedNumber = reversedNumber * 10 + reminder;
	}
	return reversedNumber;

}
#pragma endregion

#pragma region PrintAllDigitsFrequencey
int CountDigitFrequencyOf(int num, short digit) {

	int reminder, frequency = 0;
	while (num > 0) {
		reminder = num % 10;
		num /= 10;
		if (reminder == digit)
			frequency++;
	}
	return frequency;
}

void PrintAllDigitsFrequencey(int Number)
{
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		short DigitFrequency = 0;
		DigitFrequency = CountDigitFrequencyOf(Number, i);
		if (DigitFrequency > 0)
		{
			cout << "Digit " << i << " Frequencey is "
				<< DigitFrequency << " Time(s).\n";
		}
	}
}
#pragma endregion

#pragma region PrintDigitsOf
void PrintDigitsOf(int num) {
	PrintDigitsInReversedOrder(ReverseOrderOf(num));
}
#pragma endregion

#pragma endregion

#pragma region Problem Solving from 11 to 20

#pragma region Palindrome
bool IsPalindrome(int num) {
	return ReverseOrderOf(num) == num;
}
#pragma endregion

#pragma region Inverted Pattern
void PrintInvertedPattern(int num) {
	for (int i = num; i > 0; i--) {
		for (int j = i; j > 0;j--) 
			cout << i ;

		cout << "\n";
	}
}

void PrintPattern(int num) {
	for (int i = 1; i <= num; i++) {
		for (int j = i; j > 0;j--)
			cout << i;

		cout << "\n";
	}
}

void PrintInvertedLetterPattern(int num) {
	
	for (int i=65+num-1 ; i >= 65;i--) {
		for (int j = num; j > 0; j--) {
			cout << char(i);
		}
		num--;
		cout << "\n";
	}
}

void PrintLetterPattern(int num) {

	for (int i = 65; i <= 65 + num - 1;i++) {

		for (int j = 1; j <= i - 64; j++) {
			cout << char(i);
		}
		cout << "\n";
	}
}
#pragma endregion

#pragma region Words

void PrintAllWordsFromAAAtoZZZ() {
	
	for (int i = 65; i <= 90;i++) {
		for (int j = 65; j <= 90; j++) {
			for(int z =65; z <=90;z++) 
			cout << char(i) << char(j) << char(z) << endl;
		}
	}
}

bool GuessPassword(string pwd) {
	string word = "";
	int trial = 0;

	for (int i = 65; i <= 90;i++) {
		for (int j = 65; j <= 90; j++) {
			for (int z = 65; z <= 90;z++)
			{
				word += char(i);
				word += char(j);
				word += char(z);

				cout << "Trial [" << trial <<"] :" << word <<endl;
				trial++;

				if (word==pwd)
				{
					cout << "Password is " << char(i) << char(j) << char(z) << " Found after " << trial << " trial(s)";
					return true;
				}
				word = "";
			}
		}
	}
	return false;
}

#pragma endregion

#pragma region Encrypt / Decrypt

string EncryptPwd(string pwd, short encryptionKey) {
	
	for (int i = 0;i <= pwd.length();i++) {
			pwd[i] = char(pwd[i] + encryptionKey);
	}
	return pwd;
}

string DecryptPwd(string pwdEncrypted,short encryptionKey) {
	for (int i = 0;i <= pwdEncrypted.length();i++) {
		pwdEncrypted[i] = char(pwdEncrypted[i] - encryptionKey);
	}
	return pwdEncrypted;
}
#pragma endregion

#pragma region Random Numbers
enum characterEnum  { SmallLetter, CapitalLetter, SpecialCharacter, Digit };

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From+1) + From;
	return randNum;
}

char RandomCharactere(characterEnum charEnum)
{
	switch (charEnum)
	{
	case SmallLetter:
		return char(RandomNumber(97, 122));
	case CapitalLetter:
		return char(RandomNumber(65, 90));
	case SpecialCharacter:
		return char(RandomNumber(33, 47));
	case Digit:
		return char(RandomNumber(48, 57));
	default:
		return 0;
	}
}
#pragma endregion

#pragma endregion

#pragma region Problem Solving from 21 to 30

#pragma region Keys
string GenrateWord(characterEnum charType, short length) {
	string word = "";

	for (int j = 1; j <= length;j++) {
		word += RandomCharactere(charType);
	}
	return word;
}

string GenerateKey() {
	string key = "";
	for (int i = 1; i <= 4;i++) {
		key += GenrateWord(characterEnum::CapitalLetter, 4);
		if (i < 4)
			key += "-";
	}
	return key;
}

void GenerateKeys(short nTime) {
	for (int a = 1;a <= nTime;a++) {
		cout << "Key [" << a << "] :" << GenerateKey() << endl;
	}
}
#pragma endregion

#pragma region Arrays
int TimesRepeated(int arr[100], int length, int num) {
	
	int count = 0;

	for (int i = 0;i < length;i++) {
		if (arr[i] == num) {
			count++;
		}
	}
	return count;
}

void PrintArrayElementsAndCheckGivenElement() {
	int arr[100];
	int length = 0;

	ReadArray(arr, length);
	int numToChek=ReadPositiveNumber("Enter the number you want to check");
	PrintArray(arr,length);
	cout << numToChek << " is repeated " << TimesRepeated(arr,length, numToChek) << " time(s)";
}

void FillArrayWithRandomNumbers(int arr[100],int length) {
	for (int i = 0;i < length;i++) {
		arr[i] = RandomNumber(-100, 100);
	}
}

int MaxArray(int arr[100], int length) {
	int max = 0;
	for (int i = 0; i < length;i++) {
		if (arr[i] > max) 
			max = arr[i];
	}
	return max;
}

int MinArray(int arr[100], int length) {
	int min = arr[0];
	for (int i = 0; i < length;i++) {
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

int SumArray(int arr[100], int length) {
	int sum = 0;
	for (int i = 0; i < length;i++) {
		sum += arr[i];
	}
	return sum;
}

float AvgArray(int arr[100], int length) {
	return (float)SumArray(arr, length)/length;
}

void CopyArray(int arr[100], int arrCopy[100], int length) {

	for (int i = 0;i < length;i++) 
		arrCopy[i] = arr[i];
}

int CopyOnlyPrimeNumbers(int arr[100], int arr2[100], int length) {
	int counter = 0;
	for (int i = 0;i < length;i++) {
		if (CheckPrime(arr[i]) == enPrimNotPrime::Prime) {
			arr2[counter] = arr[i];
			counter++;
		}
	}
	return counter;
}

void SumTwoArrays(int arr[100], int arr2[100], int arrSum[100], int length) {

	for (int i = 0; i < length; i++) 
		arrSum[i] = arr[i] + arr2[i];
}
#pragma endregion

#pragma endregion

#pragma region Problem Solving from 31 to 40

#pragma region ShuffleArray
void GetOrderedArray(int arr[100], int length) {
	for (int i = 0;i < length;i++) {
		arr[i] = i + 1;
	}
}

void ShuffleArray(int arr[100], int length) {

	for (int i = 0;i < length;i++) {
		Swap(arr[RandomNumber(0, length - 1)], arr[RandomNumber(0, length - 1)]);
	}
}
#pragma endregion

#pragma region Copy Array in Reverse Order

void CopyArrayInReverseOrder(int src[100], int destination[100],int length) {
	for (int i = 0; i < length; i++)
	{
		destination[i] = src[length - 1 - i];
	}

}

#pragma endregion

#pragma region  fill Array With keys

void FillArrayWithKeys(string arr[100], int length) {
	for (int i = 0; i < length; i++)
	{
		arr[i] = GenerateKey();
	}
}

#pragma endregion

#pragma region Search In Arrays

int SearchInArray(int arr[100],int length, int num) {
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == num) {
			return i;
		}
	}
	return -1;
}

bool IsExistInArray(int arr[100], int length, int num) {
	return SearchInArray(arr, length, num) != -1;
}

#pragma endregion

#pragma region Allocate Simi Dynamic Array

void InputUserNumbersInArray(int arr[100], int& length) {
	bool AddMore = 1;
	do {
		AddArrayElement(arr,length, ReadPositiveNumber("Please enter a number :"));
		cout << "Do you want to add more Numbers - [0] : no  - [1] :yes ? \n";
		cin >> AddMore;
	} while (AddMore);
}
#pragma endregion

#pragma region Copy Array Elements with AddElement

void CopyArrayUsingAddElement(int arr[100], int arrCopy[100], int arrLength, int& arrCopyLength) {
	for (int i = 0;i < arrLength;i++)
		AddArrayElement(arrCopy, arrCopyLength, arr[i]);
}

void CopyOddNumbers(int arr[100], int arrOfOddNumber[100], int arrLength, int& arrOddLength) {
	for (int i = 0;i < arrLength;i++) {
		if(CheckNumberTypeEvenOrOdd(arr[i]) == enEvenOdd::Odd)
			AddArrayElement(arrOfOddNumber, arrOddLength, arr[i]);
	}
}

void CopyPrimeNumbers(int arr[100], int arrCopy[100], int arrLength, int& arrCopyLength) {
	for (int i = 0;i < arrLength;i++) {
		if (CheckPrime(arr[i]) == enPrimNotPrime::Prime)
			AddArrayElement(arrCopy, arrCopyLength, arr[i]);
	}
}

#pragma endregion

#pragma region Distinct in Array

void DistinctArray(int arr[10], int arrDistinct[10],int length, int& arrDistinctLength) {

	for (int i = 0; i < length; i++)
	{
		if(!IsExistInArray(arrDistinct, arrDistinctLength,arr[i]))
		AddArrayElement(arrDistinct, arrDistinctLength, arr[i]);
	}
}

#pragma endregion

#pragma endregion

#pragma region Problem Solving from 41 to 50

#pragma region Count From Array
bool IsPalindromArray(int arr[100], int length) {

	for (int i = 0; i < length; i++)
	{
		if (arr[i] != arr[length - 1 - i]) {
			return false;
		}
	}
	return true;
}

int CountOdd(int arr[100], int length) {
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (CheckNumberTypeEvenOrOdd(arr[i]) == enEvenOdd::Odd)
			count++;
	}
	return count;
}

int CountEven(int arr[100], int length) {
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (CheckNumberTypeEvenOrOdd(arr[i]) == enEvenOdd::Even)
			count++;
	}
	return count;
}

int CountPositiveNumbers(int arr[100], int length) {
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] >= 0)
			count++;
	}
	return count;
}

int CountNegativeNumbers(int arr[100], int length) {
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] < 0)
			count++;
	}
	return count;
}
#pragma endregion

#pragma region My Math library

float MyAbs(float num) {
	return num<0 ? (float)num * -1 : (float)num;
}

float GetFractionPart(float num) {
	return num - int(num);
}

int MyRound(float num) {
	int numInt = (int)num;
	
	if (MyAbs(GetFractionPart(num)) >= .5) {
		if (num > 0)
			numInt++;
		else
			numInt--;
	}
	else {
		return numInt;
	}
}

int MyFloor(float num) {
	if (GetFractionPart(num) < 0)
		return int(--num);
	else
		return int(num);
}

int MyCiel(float num) {
	if (GetFractionPart(num) < 0)
		return int(num);
	else
		return int(++num);
}

float MySqrt(float num) {
	return pow(num, 0.5);
}
#pragma endregion

#pragma endregion


int main()
{
	srand(time(NULL));

}