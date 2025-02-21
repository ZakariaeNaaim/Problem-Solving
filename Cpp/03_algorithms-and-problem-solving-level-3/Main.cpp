#pragma warning(disable : 4996)

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cctype>

using namespace std;

#pragma region Files

void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            vFileContent.push_back(Line);
        }
        MyFile.close();
    }
}

void SaveDataFromVectorToFile(string FileName, vector <string>& vFileContent) {
    fstream MyFile;
    MyFile.open(FileName, ios::out);//read Mode
    if (MyFile.is_open())
    {
        for (string& Line : vFileContent)
        {
            if (Line != "")
            {
                MyFile << Line << endl;
            }
        }
        MyFile.close();
    }
}

void DeleteRecordFromFile(string FileName, string record) {

    fstream MyFile;
    vector<string> vMyFile;
    LoadDataFromFileToVector(FileName, vMyFile);

    for (string& v : vMyFile)
    {
        if (v == record)
            v = "";
    }
    SaveDataFromVectorToFile(FileName, vMyFile);
}

void UpdateRecordInFile(string FileName, string record, string updateTo) {

    fstream MyFile;
    vector<string> vMyFile;
    LoadDataFromFileToVector(FileName, vMyFile);

    for (string& v : vMyFile)
    {
        if (v == record)
            v = updateTo;
    }
    SaveDataFromVectorToFile(FileName, vMyFile);

}

#pragma endregion

#pragma region DateTime

void GetDateTime() {
    time_t t = time(0); // get time now
    char* dt = ctime(&t); // convert in string form
    cout << "Local date and time is: " << dt << "\n";
    // converting now to tm struct for UTC date/time
    tm* gmtm = gmtime(&t);
    dt = asctime(gmtm);
    cout << "UTC date and time is: " << dt;
}

void DateStructure() {
    //int tm_sec; // seconds of minutes from 0 to 61
    //int tm_min; // minutes of hour from 0 to 59
    //int tm_hour; // hours of day from 0 to 24
    //int tm_mday; // day of month from 1 to 31
    //int tm_mon; // month of year from 0 to 11
    //int tm_year; // year since 1900
    //int tm_wday; // days since sunday
    //int tm_yday; // days since January 1st
    //int tm_isdst; // hours of daylight savings time

    time_t t = time(0); // get time now
    tm* now = localtime(&t);
    cout << "Year: " << now->tm_year + 1900 << endl;
    cout << "Month: " << now->tm_mon + 1 << endl;
    cout << "Day: " << now->tm_mday << endl;
    cout << "Hour: " << now->tm_hour << endl;
    cout << "Min: " << now->tm_min << endl;
    cout << "Second: " << now->tm_sec << endl;
    cout << "Week Day (Days since sunday): " << now->tm_wday << endl;
    cout << "Year Day (Days since Jan 1st): " << now->tm_yday << endl;
    cout << "hours of daylight savings:" << now->tm_isdst << endl;
}

#pragma endregion

#pragma region Problem Solving from 1 to 10 

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(5);
            printf("%0*d", 2, arr[i][j]);
            cout << " ";

        }
        cout << "\n";
    }
}

int RowSum(int arr[3][3], short RowNumber, short Cols)
{
    int Sum = 0;
    for (short j = 0; j <= Cols - 1; j++)
    {
        Sum += arr[RowNumber][j];
    }
    return Sum;
}

void SumMatixRowsInArry(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        arrSum[i] = RowSum(arr, i, Cols);
    }
}

int ColSum(int arr[3][3], short Rows, short ColNumber)
{
    int Sum = 0;
    for (short i = 0; i <= Rows - 1; i++)
    {
        Sum += arr[i][ColNumber];
    }
    return Sum;
}

void SumMatixColsInArry(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
    int Sum = 0;
    for (short j = 0; j < Cols; j++)
    {
        arrSum[j] = ColSum(arr,Rows , j);
    }
}

void PrintRowsSumArray(int arr[3], short Rows)
{
    cout << "\nThe the following are the sum of each row in the matrix:\n";
        for (short i = 0; i < Rows; i++)
        {
            cout << " Row " << i + 1 << " Sum = " << arr[i] << endl;
        }
}

void PrintColsSumArray(int arr[3], short Cols)
{
    cout << "\nThe the following are the sum of each column in the matrix:\n";
    for (short i = 0; i < Cols; i++)
    {
        cout << " Col " << i + 1 << " Sum = " << arr[i] << endl;
    }
}

void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
{
    short num = 1;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = num++;
        }
    }
}

void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arrTransposed[j][i] = arr[i][j];
        }
    }
}

void MultiplyMatrix(int arrMul[3][3],int arr1[3][3], int arr2[3][3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols;j++) {
            arrMul[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
}

void GetMiddleRow(int arr[3][3], int arrMiddleRow[3], short Rows, short Cols) {

    for (int i = 0; i < Cols; i++)
    {
        arrMiddleRow[i] = arr[(int)Rows / 2][i];
    }
}

void GetMiddleCol(int arr[3][3], int arrMiddleCol[3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++)
    {
        arrMiddleCol[i] = arr[i][(int)Cols / 2];
    }
}

void PrintMiddleRow(int arr[3][3], int arrMiddleRow[3], short Rows, short Cols) {
    GetMiddleRow(arr, arrMiddleRow, Rows, Cols);

    for (short i = 0; i < Cols; i++)
    {
        cout << setw(5);
        printf("%0*d", 2, arrMiddleRow[i]);
        cout << " ";
    }
    cout << endl;
}

void PrintMiddleCol(int arr[3][3], int arrMiddleCol[3], short Rows, short Cols) {

    GetMiddleCol(arr, arrMiddleCol, Rows, Cols);

    for (short i = 0; i < Cols; i++)
    {
        cout << setw(5);
        printf("%0*d", 2, arrMiddleCol[i]);
        cout << " ";
    }
    cout << endl;
}

int SumOfMatrixElements(int arr[3][3], short Rows, short Cols) {
    int Sum = 0;

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Sum += arr[i][j];
        }
    }
    return Sum;
}

#pragma endregion

#pragma region Problem Solving from 11 to 20

bool AreMatricesEqual(int mtrx1[3][3], int mtrx2[3][3], short Rows, short Cols) {
    return SumOfMatrixElements(mtrx1, Rows, Cols) == SumOfMatrixElements(mtrx2, 3, 3);
}

bool AreMatricesTypical(int mtrx1[3][3], int mtrx2[3][3], short Rows, short Cols) {

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols;j++) {
            if (mtrx1[i][j] != mtrx2[i][j])
                return false;
        }
    }
    return true;
}

bool IsIdentityMatrix(int matrix[3][3], short Rows, short Cols) {

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols;j++) {
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0))
                return false;
        }
    }
    return true;
}

bool IsScalarMatrix(int matrix[3][3], short Rows, short Cols) {

    int FirstVal = matrix[0][0];
    
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols;j++) {
            if ( (i == j && matrix[i][j] != FirstVal) || (i != j && matrix[i][j] != 0))
                return false;
        }
    }
    return true;
}

short CountNumberInMatrix(int matrix[3][3], short Rows, short Cols, short NumberToCount) {

    int Count = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols;j++) {
            if (matrix[i][j] == NumberToCount)
                Count++;
        }
    }
    return Count;
}

bool IsSparseMatrix (int matrix[3][3], short Rows, short Cols) {

    return CountNumberInMatrix(matrix, Rows, Cols, 0) >= (Rows * Cols )/2;
}

bool IsExistInMatrix(int matrix[3][3], short Rows, short Cols, short NumberToSearch) {

    int Count = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols;j++) {
            if (matrix[i][j] == NumberToSearch)
                return true;
        }
    }
    return false;
}

void PrintIntersectedNumsIn2Matrix(int mtrx1[3][3], int mtrx2[3][3], short Rows, short Cols) {

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols;j++) {
            if (IsExistInMatrix(mtrx2, Rows, Cols, mtrx1[i][j]))
                cout << mtrx1[i][j] << "\t";
        }
    }

}

short MaxNumberInMatrix(int matrix[3][3], short Rows, short Cols) {

    int MaxNum = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols;j++) {
            if (matrix[i][j] > MaxNum)
                MaxNum = matrix[i][j];
        }
    }
    return MaxNum;
}

short MinNumberInMatrix(int matrix[3][3], short Rows, short Cols) {

    int MinNum = matrix[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols;j++) {
            if (matrix[i][j] < MinNum)
                MinNum = matrix[i][j];
        }
    }
    return MinNum;
}

void ReverseMatrix(int matrix[3][3], int reversedMatrix[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols;j++) {
            reversedMatrix[Rows-1-i][Cols-1-j] = matrix[i][j];
        }
    }
}

int IsPalindromeMatrixHadhoud(int Matrix1[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols / 2; j++)
        {
            if (Matrix1[i][j] != Matrix1[i][Cols - 1 - j])
            {
                return false;
            }
        }
    }
    return true;
}

#pragma endregion

#pragma region Problem Solving from 21 to 30

string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

void PrintFibonacciSeriesOf(short num) {
    vector<int> vFibonacci;

    for (short i = 0; i < num; i++)
    {
        i == 0 || i == 1 ? vFibonacci.push_back(1): vFibonacci.push_back(vFibonacci[i-1]+ vFibonacci[i - 2] );
    }
    for (int& num : vFibonacci) {
        cout << num << " ";
    }
}

void PrintFibonacciUsingRecursion(short num, int& previous1, int& previous2 ) {

    cout << previous1+ previous2 << " ";
    int swapper = previous1;
    previous1 = previous1 + previous2;
    previous2 = swapper;

    if (num > 2) {
        num--;
        PrintFibonacciUsingRecursion(num, previous1,previous2);
    }
}

void PrintFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;
    cout << "\nFirst letters of this string: \n";
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
            cout << S1[i] << endl;
        
        isFirstLetter = S1[i] == ' ';
    }
}

void PrintFirstLetterUpperOfEachWord(string S1)
{
    bool isFirstLetter = true;
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
            S1[i] = toupper( S1[i]);

        isFirstLetter = S1[i] == ' ';
    }
    cout << endl << S1;
}

string UpperAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = toupper(S1[i]);
    }
    return S1;
}

string LowerAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}

char InvertCase(char C1) {
   return isupper(C1) ? tolower(C1) : toupper(C1);
}

string InvertString(string S1) {
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] =  InvertCase(S1[i]);
    }
    return S1;
}

short CountLetter(string S1, char Letter,bool MatchCase = false)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if(MatchCase && S1[i] == Letter)
            Counter++;

        if (!MatchCase && tolower(S1[i]) == tolower(Letter))
            Counter++;
    }
    return Counter;
}
#pragma endregion

#pragma region Problem Solving from 31 to 40

bool IsVowel(char Letter)
{
    Letter = tolower(Letter);
    return Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'a' || Letter == 'o' || Letter == 'u';
}

enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3, VowelLetters = 4 };
short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
{
    if (WhatToCount == enWhatToCount::All)
        return S1.length();

    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
            Counter++;
        if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
            Counter++;
        if (WhatToCount == enWhatToCount::VowelLetters && IsVowel(S1[i]))
            Counter++;
    }
    return Counter;
}

void PrintEachWord(string S1) {

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] == ' ' && S1[i+1] != ' ')
            cout << endl;
        if (S1[i] != ' ')
            cout << S1[i];
    }
}

void PrintEachWordInString(string S1)
{
    short pos = 0;
    string delim = " ";
    while ( (pos = S1.find(delim)) != string::npos) {

        string word = S1.substr(0, pos);
        if (word !="") {
            cout << word << " ";
        }
        S1.erase(0, pos + delim.length());
    }
    cout << S1;
}

int CountWordsInString(string S1) {
    short pos = 0;
    int count = 0;

    while ((pos = S1.find(" ")) != string::npos) {
        string word = S1.substr(0, pos);
        if (word != "")
            count++;

        S1.erase(0, pos + 1);
    }

    if (S1 != "")
        count++;

    return count;
}

vector<string> Split(string S1,string splitter) {
    vector<string> vWords;
    short pos = 0;
    string delim = splitter;
    while ((pos = S1.find(delim)) != string::npos) {

        string word = S1.substr(0, pos);
        if (word != "") {
            vWords.push_back(word);
        }
        S1.erase(0, pos + delim.length());
    }
    if(S1 !="")
      vWords.push_back(S1);

    return vWords;
}

string TrimLeft(string S1) {
    string delim = " ";
    int pos = 0;

    while ((pos = S1.find(" ")) != string::npos)
    {
        string word = S1.substr(0, pos);
        if (word != "")
            return S1;

        S1.erase(0, pos + delim.length());
    }
    return S1;
}

string TrimRight(string S1) {
    
    for (int i = S1.length()-1 ; i >= 0 ; i--)
    {
        if (S1[i] != ' ')
            return S1.substr(0, i);
    }
    return S1;
}

string JoinString(vector<string>& vWords, string delim) {

    string text = "";

    for (string& word : vWords) {
        text += word + delim;
    }
    
    return text.substr(0,text.length()- delim.length());
}

string JoinString(string arrWords[100], int length, string delim) {

    string text = "";
    
    for (int  i = 0; i < length; i++)
    {
        text += arrWords[i] + delim;

    }
    return text.substr(0, text.length() - delim.length());
}

#pragma endregion

#pragma region Problem Solving from 41 to 45

string ReverseWords(string S1) {

    string delim = " ";
    vector<string> vWords = Split(S1, delim);

    string text = "";
    vector<string>::iterator i = vWords.end();
 
    while (i != vWords.begin())
    {
        i--;
        text += *i + delim;
    }

    return text.substr(0, text.length() - delim.length());
}

string ReplaceWordsUsingBuiltInFunction(string S1, string FindWhat, string ReplaceWith) {

    short pos = 0;

    while ((pos= S1.find(FindWhat)) != string::npos) {
        S1.replace(pos, FindWhat.length(), ReplaceWith);
    }

    return S1;
}

string ReplaceWords(string S1, string FindWhat, string ReplaceWith, bool MatchCase = true) {

    short pos = 0;
    if (!MatchCase) {
        FindWhat = LowerAllString(FindWhat);
        S1 = LowerAllString(S1);
    }

    while ((pos = S1.find(FindWhat)) != string::npos) {
        string leftSide = S1.substr(0,pos);
        string rightSide = S1.substr(pos+ FindWhat.length(), S1.length());
        S1 = leftSide + ReplaceWith + rightSide;
    }

    return S1;
}

string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
{
    if (!MatchCase) {
        StringToReplace = LowerAllString(StringToReplace);
        S1 = LowerAllString(S1);
    }

    vector<string> vWords = Split(S1," ");

    for (string& word : vWords) {
        if (word == StringToReplace)
            word = sRepalceTo;
    }
    return JoinString(vWords, " ");
}

string RemovePonctuations(string S1) {
    
    string S2 = "";

    for (short i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i])) {
            S2 += S1[i];
        }
    }
    return S1;
}
#pragma endregion

#pragma region Problem Solving from 44 to 51

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};
const string ClientsFileName = "C:\\Users\\LEGION\\MyFile.txt";

sClient ReadNewClient()
{
    sClient Client;
    cout << "Enter Account Number? ";
    getline(cin, Client.AccountNumber);
    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator ="#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

sClient ConvertLinetoRecord(string Line, string Seperator ="#//#")
{
    sClient Client;
    vector<string> vClientData;
    vClientData = Split(Line, Seperator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);
    return Client;
}

void PrintClientRecord(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance <<endl;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;
        MyFile.close();
    }
}

void AddNewClient()
{
    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddClients()
{
    char AddMore = 'Y';
    do
    {
        system("cls");
        cout << "Adding New Client:\n\n";
        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients ? Y / N ? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

vector<sClient> LoadClientsDataFromFile(string FileName) {

    fstream MyFile;
    vector<sClient> vClientsData;

    MyFile.open(FileName, ios::in);
    if (MyFile.is_open()) {
        string Line = "";
        while(getline(MyFile, Line))
       vClientsData.push_back(ConvertLinetoRecord(Line));
    }
    MyFile.close();

    return vClientsData;
}

void PrintHeader(int size) {
    cout << "\n\t\t\t\t\tClient List (" << size << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

void PrintClientsData() {
   vector<sClient> vClientsData = LoadClientsDataFromFile(ClientsFileName);

   PrintHeader(vClientsData.size());
   for (sClient& client : vClientsData) {
       PrintClientRecord(client);
   }
   cout << "\n_______________________________________________________";
   cout << "_________________________________________\n" << endl;
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client)
{
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
    for (sClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

vector <sClient> SaveClientsDataToFile(string FileName, vector <sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite
    string DataLine;
    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveClientsDataToFile(ClientsFileName, vClients);
            //Refresh Clients
            vClients = LoadClientsDataFromFile(ClientsFileName);
            cout << "\n\nClient Deleted Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

bool UpdateClient(sClient client, vector<sClient>& vClients) {
    for (sClient& C : vClients)
    {
        if (C.AccountNumber == client.AccountNumber)
        {
            C = client;
            return true;
        }
    }
    return false;
}

void ReadNewValuesForClient(sClient& Client) {
    cout << "Name ? ";
    cin >> Client.Name;
    cout << "PinCode? ";
    cin >> Client.PinCode;
    cout << "Phone ? ";
    cin >> Client.Phone;
    cout << "AccountBalance ? ";
    cin >> Client.AccountBalance;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want to Update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            ReadNewValuesForClient(Client);
            UpdateClient(Client, vClients);
            SaveClientsDataToFile(ClientsFileName, vClients);
            cout << "\n\nClient Updated Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

#pragma endregion



int main()
{
    vector<int> nums{ 0, 1, 2, 2, 3, 0, 4, 2 };

    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadString();
    UpdateClientByAccountNumber(AccountNumber, vClients);
    return 0;

}