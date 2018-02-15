#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <fstream>

bool isCard = false;
using namespace std;

string setInput(int month, int day, int year, int numAccounts, long int creditCardNum, double transactionAmount)
{
    stringstream creditCardss;
    
    creditCardss << creditCardNum << ":" << month << "/" << day << "/" << year << ":" << transactionAmount << ":";
    string creditCardAccounts = creditCardss.str();
    
    return creditCardAccounts;
    
}

int CheckBIN(long int cardNum)// Checks BIN of each card company and tells you if you have a valid card
{
    stringstream cardNumSS;
    int tempSum = 0;
    stringstream luhnSS_1;
    int numCards = 1;
    ifstream fin;
    ofstream fout;
    fin.open("creditCards");
    fout.open("dump");
    int asciiValue = 0;
    char luhnChar_ = 'i';
    long int creditCard[numCards];
    int sum_1 = 0;
    
    int checksum = 0;
    int a = 0;
    long int creditCardLuhn[numCards];
    int i = 0;
    for (int i = 0; i < numCards; i++)//This assigns a credit card number to its proper element
    {
        fin >> creditCard[i];
    }
    fin.close();
    fin.open("dump");
    for (i = 0; i < numCards; i++)
    {
    creditCardLuhn[i] = creditCard[i];
    }
    
    luhnSS_1 << creditCardLuhn[0];

    string luhnStr_1 = luhnSS_1.str();
    
    int luhnNum_1[luhnStr_1.length()];
    int luhnDoubleNum_1[luhnStr_1.length()];
    
    
    
    
    
    
    
    cout << endl;
    for (int i = 0; i < numCards; i++)
    {
    if (i == 0)
    {
        a = 1;
    }
    else
    {
        a = i + 1;
    }
    
    for (int i = 0; i < luhnStr_1.length(); i++)
    {
        
        luhnNum_1[i] = luhnStr_1[i];
        if (i != 0)
        {
        fout << " ";
        }
        fout << char(luhnNum_1[i]);
        
        fin >> luhnNum_1[i];
    }
    fout << endl;
    
    for (int i = 0; i < luhnStr_1.length(); i++)
        {
        int digit = luhnNum_1[i] - '0';
        cout << digit << endl;
        if (digit % 2 == 0)
        {
            tempSum = digit * 2;
            if (tempSum < 9) {
                cout << "even " << tempSum << endl;
            }
            if (tempSum > 9){
               tempSum -= 9;
               cout << "reduced even "<< tempSum << endl;
            }
            tempSum += tempSum;
        }
        else 
        {
            sum_1 += tempSum;
            cout << "odd " <<digit << endl;
        }
        
            
}
         
    cout << sum_1 << endl;
    checksum = sum_1 % 10;
    
    cout << "Checking Card " << a <<" for American Express: " << creditCard[i] << endl;
    long int visaDynamicLength = 0;
    if (creditCard[i] >=340000000000000 && creditCard[i] <= 349999999999999&& checksum == 0)// How I checked the BIN numbers
    {
        cardNumSS << creditCard[i]- 340000000000000;
    }
    else if (creditCard[i] >= 370000000000000 && creditCard[i] <= 379999999999999&& checksum == 0)
    {
        cardNumSS << creditCard[i]- 370000000000000;
    }
    string americanStr = cardNumSS.str();
    
    if (americanStr.length() == 13 && checksum == 0)
    {
        cout << " is an American Express Card" << endl;
        isCard = true;
        cout << checksum;
    }
    else
    {
        if (isCard == false){//This bool is for stopping the loop in the main
            cout << "Checking: is NOT American Express Card" << endl;
        }
        else
        {
        cout << " is NOT American Express Card" << endl;
        }
    }
    
    cout << "Checking Card " << a << " for Discover: " << creditCard[i] <<  endl;
    if (creditCard[i] >=601100000000000 && creditCard[i] <= 601199999999999&& checksum == 0)
    {
        cout << " is a Discover Card" << endl;  
                isCard = true;
cout << checksum;
    }
    else if (creditCard[i] >= 622126000000000 && creditCard[i] <= 622925999999999&& checksum == 0)
    {
        
        cout << " is a Discover Card" << endl;
                isCard = true;
cout << checksum;
    }
    
    else if (creditCard[i] >= 644000000000000 && creditCard[i] <= 649999999999999&& checksum == 0)
    {
        cout << " is a Discover Card" << endl;
                isCard = true;

        cout << checksum;
    }
    else if (creditCard[i] >= 650000000000000 && creditCard[i] <= 659999999999999&& checksum == 0)
    {
        cout << " is a Discover Card" << endl;
                isCard = true;
cout << checksum;
    }
    else
    {
        if (isCard == false){
            cout << "Checking: is NOT Discover Card" << endl;
        }
        else
        {
        cout << " is NOT Discover Card" << endl;
        }
            
    }
    
    cout << "Checking Card " << a << " for Master Card: " << creditCard[i] <<  endl;
    cout << checksum << endl;
    if (creditCard[i] >=510000000000000 && creditCard[i] <= 559999999999999&& checksum == 0)
    {
        cout << " is a Master Card" << endl;
            isCard = true;
            cout << checksum;
    }
    else
    {
        if (isCard == false){
            cout << "Checking: is NOT Master Card" << endl;
        }
        else
        {
        cout << " is NOT Master Card" << endl;
        }
    }
    
    
    cout << "Checking Card " << a <<" Visa: " << creditCard[i] <<  endl;
    stringstream visaSS;
    visaSS << creditCard[i];
    string visaStr = visaSS.str();
    if (creditCard[i] >= 4000000000000 && creditCard[i] <= 4999999999999 && checksum == 0 || creditCard[i] >= 40000000000000 && creditCard[i] <= 49999999999999 && checksum == 0 || creditCard[i] >= 400000000000000 && creditCard[i] <= 499999999999999 && visaStr.length() <= 16 && visaStr.length() >= 13 && checksum == 0)
    {
        cout << " is a Visa Card" << endl;
                cout << checksum;
                isCard = true;

    }
    else
    {
        if (isCard == false){
            cout << "Checking: is NOT Visa Card" << endl;
        }
        else
        {
        cout << " is NOT Visa Card" << endl;
        }
    }
    }
    fout.close();
    
    
}

int main() {
    ofstream fout;
    ifstream fin;
    fout.open("transactions");
    fin.open("creditCards");
    int monthArray[30];
    double transactionAmount[30];
    long int userCreditCard = 0;
    int numAccounts = 0;
    int month = 0;
    int day = 0;
    int year = 0;
    int transactions = 0;
    int dayOfTheMonth = 0;
    int a = 0;
    
    
    cout << "How many accounts are there?" << endl;
    cin >> numAccounts;
    while (a != numAccounts)
    {
    cout << "Inputting card from file" << endl;
    fin >> userCreditCard;
    CheckBIN(userCreditCard);
    while(isCard == false) {
        cout << "That is not a valid credit card, please enter another" << endl;
        cin >> userCreditCard;
        CheckBIN(userCreditCard);
    }
    cout << "How many purchases did you make this month?" << endl;
    cin >> transactions;
            for (int i = 0; i < transactions; i++) { 
                cout << "What day did you have this transaction?" << endl;
                cin >> dayOfTheMonth;
                cout << "What month did you have it?" << endl;
                cin >> month;
                cout << "What year?" << endl;
                cin >> year;
                cout << "Day " << dayOfTheMonth << ":" << "purchase" << endl;
                cin >> transactionAmount[i];
                fout << setInput(month, dayOfTheMonth, year, numAccounts, userCreditCard, transactionAmount[i]) << endl;
            }
    a += 1;
    }
        
}
    
    

    

