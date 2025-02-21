#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct stClient { string AccountNumber; string PinCode; string ClientName; string Phone; double Balance = 0; bool MarkForDelete = false;};
enum enMenu { enShowClientList = 1, enAddNewClient = 2, enDeleteClient = 3, enUpdateClientInfo = 4, enFindClient = 5, TransactionMenu = 6, Exit = 7 };
enum enTransactionMenu { enDeposit = 1, enWithDraw = 2, enTotalBalance = 3, enMainMenu = 4 };
enum enOperationType { Deposit = 1, Withdraw = 2 };

const string ClientsFileName = "C:\\Users\\LEGION\\MyFile.txt";
void GoBackToMainMenu();
void GoBackToTransactionMenu();

#pragma region Conversion

vector<string> Split(string s1, string delim) {

    int pos = 0;
    vector < string> vStrings;

    while ((pos = s1.find(delim)) != string::npos) {
        string word = s1.substr(0, pos);
        if (word != "")
            vStrings.push_back(word);

        s1.erase(0, pos + delim.length());
    }
    if (s1 != "")
        vStrings.push_back(s1);

    return vStrings;
}

string Join(vector<string>& vStrings, string delim) {
    string text = "";
    for (string& s1 : vStrings) {
        if (text != "")
            text = text + delim + s1;
        else
            text = s1;
    }
    return text;
}

stClient ConvertStringToStruct(string sClient) {
    vector<string> vClientData = Split(sClient, "#//#");
    stClient stClient;

    stClient.AccountNumber = vClientData[0];
    stClient.PinCode = vClientData[1];
    stClient.ClientName = vClientData[2];
    stClient.Phone = vClientData[3];
    stClient.Balance = stod(vClientData[4]);
    return stClient;
}

string ConvertStructToString(stClient stClient) {
    vector<string> vClientData;
    string sClient;

    vClientData.push_back(stClient.AccountNumber);
    vClientData.push_back(stClient.PinCode);
    vClientData.push_back(stClient.ClientName);
    vClientData.push_back(stClient.Phone);
    vClientData.push_back(to_string(stClient.Balance));

    sClient = Join(vClientData, "#//#");

    return sClient;
}

#pragma endregion

#pragma region Print and Read
void PrintShortClientListHeader(int size) {
    cout << "\n\t\t\t\t\tClient List (" << size << ") Client(s).";
    cout << "\n________________________________________________________________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n________________________________________________________________________________________________\n" << endl;
}

void PrintClientListHeader(int size) {
    cout << "\n\t\t\t\t\tClient List (" << size << ") Client(s).";
    cout << "\n________________________________________________________________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n________________________________________________________________________________________________\n" << endl;
}

void PrintShortClient(stClient& client) {
    cout << "| " << left << setw(15) << client.AccountNumber;
    cout << "| " << left << setw(40) << client.ClientName;
    cout << "| " << left << setw(12) << client.Balance << endl;
}

void PrintClient(stClient& client) {
    cout << "| " << left << setw(15) << client.AccountNumber;
    cout << "| " << left << setw(10) << client.PinCode;
    cout << "| " << left << setw(40) << client.ClientName;
    cout << "| " << left << setw(12) << client.Phone;
    cout << "| " << left << setw(12) << client.Balance <<endl;
}

void PrintClients(vector<stClient>& vClients, bool isShortList = false) {
    double totalBalance = 0;
    for (stClient& C : vClients) {
        isShortList ? PrintShortClient(C) : PrintClient(C);
        totalBalance += C.Balance;
    }
    cout << "________________________________________________________________________________________________\n" << endl;
    if (isShortList)
        cout << "\t\t\t Total Balances = " << totalBalance << endl << endl << endl;
}

void PrintGenericHeader(string title) {
    cout << "\n---------------------------------------------------\n";
    cout << "---------------------------------------------------\n";
    cout << "\t\t" << title;
    cout << "\n---------------------------------------------------\n";
    cout << "---------------------------------------------------\n";
}

void ReadClientFromUser(stClient& client) {
    cout << "Enter Pin Code? ";
    getline(cin >> ws, client.PinCode);
    cout << "Enter ClientName? ";
    getline(cin, client.ClientName);
    cout << "Enter Phone? ";
    getline(cin, client.Phone);
    cout << "Enter Balance? ";
    cin >> client.Balance;
}

string ReadAccountNumber() {
    string AccountNumber;
    cout << "Enter Account Number? ";
    cin >> AccountNumber;
    return AccountNumber;
}

double ReadAmount(string msg) {
    double Amount;
    cout << msg;
    cin >> Amount;
    return Amount;
}

bool ReadBool(string msg) {
    char YesNo ='n';
    cout << msg;
    cin >> YesNo;
    return YesNo == 'y';
}
#pragma endregion

#pragma region Crud in File
vector<stClient> ReadRecordsFromFile(string FileName) {
    fstream MyFile;
    vector<stClient> vClients;

    MyFile.open(FileName, ios::in);
    if (MyFile.is_open()) {

        string Line;
        while (getline(MyFile, Line))
            vClients.push_back(ConvertStringToStruct(Line));
    }
    MyFile.close();
    return vClients;
}

void AddRecordToFile(string FileName,stClient& record) {
    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open()) {
        string DataLine = ConvertStructToString(record);
        MyFile << DataLine << endl;
    }
    MyFile.close();
}

void UpdateOrDeleteRecordInFile(string FileName, stClient record) {
    fstream MyFile;
    vector<stClient> vClients = ReadRecordsFromFile(FileName);

    MyFile.open(FileName, ios::out);
    if (MyFile.is_open()) {
        for (stClient C : vClients)
        {
            if (C.AccountNumber == record.AccountNumber)
                C = record;

            if (!C.MarkForDelete) {
                string DataLine = ConvertStructToString(C);
                MyFile << DataLine << endl;
            }
        }
    }
    MyFile.close();
}
#pragma endregion

#pragma region Crud

void ShowClientDetail(stClient& sClient) {
    cout << "\nThe following are the client details :";
    cout << "\n______________________________________\n" << endl;
    cout << "Account Number : " << sClient.AccountNumber << endl;
    cout << "Pin Code : " << sClient.PinCode << endl;
    cout << "Name : " << sClient.ClientName << endl;
    cout << "Phone : " << sClient.Phone << endl;
    cout << "Account Balance : " << sClient.Balance << endl;
    cout << "\n______________________________________\n" << endl;
}

void ShowClientList() {
    system("cls");
    vector<stClient> vClients = ReadRecordsFromFile(ClientsFileName);
    PrintClientListHeader(vClients.size());
    PrintClients(vClients);
    GoBackToMainMenu();
}

bool GetClientByAccountNumber(stClient& sClient) {

    vector<stClient> vClients = ReadRecordsFromFile(ClientsFileName);

    for (stClient C : vClients) {
        if (C.AccountNumber == sClient.AccountNumber) {
            sClient = C;
            return true;
        }
    }
    return false;
}

void AddNewClients() {
    system("cls");
    stClient Client;

    PrintGenericHeader("Add New Client");
    cout << "Add New Client : \n\n";
    char again = 'n';

    do {
        Client.AccountNumber = ReadAccountNumber();
            
        while (GetClientByAccountNumber(Client)) {
            cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
            cin >> Client.AccountNumber;
        }

        ReadClientFromUser(Client);
        AddRecordToFile(ClientsFileName, Client);
        cout << "\n\nClient Added Successfully, do you want to add another Client ? Y/N ";
        cin >> again;
    } while (tolower(again) == 'y');
    GoBackToMainMenu();
}

void DeleteClient() {
    system("cls");
    stClient sClient;

    sClient.AccountNumber = ReadAccountNumber();
    char again = 'f';

    if (GetClientByAccountNumber(sClient))
    {
        ShowClientDetail(sClient);

        char sure = 'n';
        cout << "\nAre You Sure to Delete the Client ? [Y/N] ";
        cin >> sure;

        if (tolower(sure) =='y') {
            sClient.MarkForDelete = true;
            UpdateOrDeleteRecordInFile(ClientsFileName, sClient);
            cout << "\n Client Deleted successfully.";
        }
    }
    else 
        cout << "Client Not Found";
    GoBackToMainMenu();
}

void UpdateClient() {
    system("cls");
    stClient sClient;
    sClient.AccountNumber = ReadAccountNumber();

    if (GetClientByAccountNumber(sClient))
    {
        ShowClientDetail(sClient);

        char sure = 'n';
        cout << "\nAre You Sure to Update the Client ? [Y/N] ";
        cin >> sure;

        if (tolower(sure) == 'y') {
            ReadClientFromUser(sClient);
            UpdateOrDeleteRecordInFile(ClientsFileName, sClient);
            cout << "\n Client Updated successfully.";
        }
    } else
        cout << "Client Not Found";
    GoBackToMainMenu();
}

void FindClient() {
    system("cls");
    stClient sClient;
    sClient.AccountNumber = ReadAccountNumber();
    if (GetClientByAccountNumber(sClient))
        ShowClientDetail(sClient);
    else
        cout << "Client Not Found";
    GoBackToMainMenu();
}

#pragma endregion

#pragma region Transaction Operations

void WithDrawOrDepositAccount(enOperationType opType) {
    
    string depoOrWithDraw = opType == enOperationType::Deposit ? "Deposit" : "Withdraw";

    PrintGenericHeader(depoOrWithDraw + " Screen");
    stClient Client;
    Client.AccountNumber = ReadAccountNumber();

    while (!GetClientByAccountNumber(Client)) {
        cout << "\nClient with [" << Client.AccountNumber << "] not exists, Enter another Account Number? ";
        cin >> Client.AccountNumber;
    }
    ShowClientDetail(Client);

    double Amount = ReadAmount( "Please enter a " + depoOrWithDraw +" Amount " );
    if (ReadBool("Are You Sure you want to perform this transaction ? y/n ")) {
        opType == enOperationType::Deposit ? Client.Balance += Amount : Client.Balance -= Amount;
        UpdateOrDeleteRecordInFile(ClientsFileName, Client);
    }
    GoBackToTransactionMenu();
}

void ShowTotalBalances() {

    vector<stClient> vClients = ReadRecordsFromFile(ClientsFileName);
    PrintShortClientListHeader(vClients.size());
    PrintClients(vClients, true);
    GoBackToTransactionMenu();
}

#pragma endregion

#pragma region Transaction Menu

enTransactionMenu ChooseTransactionMenu() {
    int num = 0;

    cout << "\t [1] Deposite." << endl;
    cout << "\t [2] WithDraw." << endl;
    cout << "\t [3] Total Balances" << endl;
    cout << "\t [4] Exit" << endl;
    cout << "---------------------------------------------------\n" << endl;
    cout << "Choose what do you want to do? [1 - 4]? ";
    cin >> num;
    return (enTransactionMenu)num;
}

void ShowTransactionMenu() {
    system("cls");
    PrintGenericHeader("Transaction Menu");
    switch (ChooseTransactionMenu())
    {
    case enTransactionMenu::enDeposit: {
        system("cls");
        WithDrawOrDepositAccount(enOperationType::Deposit);
        break;
    }
    case enTransactionMenu::enWithDraw: {
        system("cls");
        WithDrawOrDepositAccount(enOperationType::Withdraw);
        break;
    }
    case enTransactionMenu::enTotalBalance: {
        system("cls");
        ShowTotalBalances();
        break;
    }
    case enTransactionMenu::enMainMenu: {
        system("cls");
        GoBackToMainMenu();
        break;
    }
    default:
        break;
    }
}

void GoBackToTransactionMenu()
{
    cout << "\n\nPress any key to go back to Main Menu...";
    system("pause");
    ShowTransactionMenu();
}

#pragma endregion

#pragma region Menu

enMenu ChooseMenu() {
    int num =0;

    cout << "\t [1] Show Client List." << endl;
    cout << "\t [2] Add New Client." << endl;
    cout << "\t [3] Delete Client." << endl;
    cout << "\t [4] Update Client Info." << endl;
    cout << "\t [5] Find Client." << endl;
    cout << "\t [6] Transaction Menu." << endl;
    cout << "\t [7] Exit." << endl;
    cout << "---------------------------------------------------\n"<<endl;
    cout << "Choose what do you want to do? [1 - 7]? ";
    cin >> num;
    return (enMenu)num;
}

void ShowMainMenu() {
    system("cls");
    PrintGenericHeader("Main Menu Screen");

    switch (ChooseMenu())
    {
    case enMenu::enAddNewClient: {
        AddNewClients();
        break;
    }
    case enMenu::enDeleteClient: {
        DeleteClient();
        break;
    }
    case enMenu::enFindClient: {
        FindClient();
        break;
    }
    case enMenu::enShowClientList: {
        ShowClientList();
        break;
    }
    case enMenu::enUpdateClientInfo: {
        UpdateClient();
        break;
    }
    case enMenu::TransactionMenu: {
        system("cls");
        ShowTransactionMenu();
        break;
    }
    default:
        break;
    }
}

void GoBackToMainMenu()
{
    cout << "\n\nPress any key to go back to Main Menu...";
    system("pause");
    ShowMainMenu();
}

#pragma endregion



int main() {
    ShowMainMenu();
}