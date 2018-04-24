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
#include <cstdlib>
#include <time.h>

extern bool isCard;
extern bool isAmerican;
extern bool isDiscover;
extern bool isMaster;
extern bool isVisa;

using namespace std;

class CreditCard {
    private:
    
    long int cardNum[];
    int numAccounts;
    int currentCard;
    int month; 
    int day; int year; 
    int numAccounts; 
    long int creditCardNum[]; 
    double transactionAmount; 
    int currentCard; 
    bool hello;
    string type[];
    
    
void setCheckBIN(cardNum[], numAccounts, currentCard)// Checks BIN of each card company and tells you if you have a valid card
{
    bool isValidAmerican;
    bool isValidDiscover;
    bool isValidMaster;
    bool isValidVisa;
    
    
    int superSum = 0;
    int evenSum = 0;
    int oddSum = 0;
    stringstream cardNumSS;
    int tempSum = 0;
    stringstream luhnSS_1;
    int numCards = numAccounts;
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
        /*cout << digit << endl;*/
        if (digit % 2 == 0)
        {
            tempSum = (digit * 2);
            if (tempSum < 9) {
                /*cout << "even " << tempSum << endl;*/
            }
            else if (tempSum > 9){
               tempSum -= 9;
               /*cout << "reduced even "<< tempSum << endl;*/
            }
            evenSum += tempSum;
            /*cout << "Current even " << evenSum << endl;*/
        }
        else 
        {
            oddSum += digit;
            /*cout << "odd " <<digit << endl;
            cout << "Current odd " << oddSum << endl; */
        }
        
        
            
}
}
    i = currentCard;
    sum_1 = oddSum + evenSum;
    
    superSum = sum_1 * 9;
    superSum = superSum % 10;
    sum_1 += superSum;
    /*cout << sum_1 << endl;
    cout << superSum << endl;
    cout << checksum << endl;*/
    /*if (checksum == 0)
    {
        cout << "Holy cow" << endl;
    }
    */
    
    long int visaDynamicLength = 0;
    if (creditCard[i] >=340000000000000 && creditCard[i] <= 349999999999999&& checksum == 0)// How I checked the BIN numbers
    {
        cardNumSS << creditCard[i]- 340000000000000;
    }
    else if (creditCard[i] >= 370000000000000 && creditCard[i] <= 379999999999999&& checksum == 0)
    {
        cardNumSS << creditCard[i] - 370000000000000;
    }
    string americanStr = cardNumSS.str();
    
    if (americanStr.length() == 13 && checksum == 0)
    {
        isAmerican = true;
    }
    
    
    
    if (creditCard[i] >=601100000000000 && creditCard[i] <= 601199999999999&& checksum == 0)
    {
          
                
                isDiscover = true;

    }
    else if (creditCard[i] >= 622126000000000 && creditCard[i] <= 622925999999999&& checksum == 0)
    {
        isDiscover = true;
    }
    
    else if (creditCard[i] >= 644000000000000 && creditCard[i] <= 649999999999999&& checksum == 0)
    {
            isDiscover = true;
    }
    else if (creditCard[i] >= 650000000000000 && creditCard[i] <= 659999999999999&& checksum == 0)
    {
                isDiscover = true;
    }
    
    
    
    if (creditCard[i] >=5100000000000000 && creditCard[i] <= 5599999999999999 && checksum == 0)
    {                   
            isMaster = true;
    }
    
    
    
    
    stringstream visaSS;
    visaSS << creditCard[i];
    string visaStr = visaSS.str();
    if (creditCard[i] >= 4000000000000 && creditCard[i] <= 4999999999999 && checksum == 0 || creditCard[i] >= 40000000000000 && creditCard[i] <= 49999999999999 && checksum == 0 || creditCard[i] >= 400000000000000 && creditCard[i] <= 499999999999999 && visaStr.length() <= 16 && visaStr.length() >= 13 && checksum == 0)
    {
                isVisa = true;
    }
    
    
    fout.close();
    
    if (isAmerican == false && isDiscover == false && isMaster == false && isVisa == false)
    {
        isCard = false;
    }
    else
    {
        isCard = true;
    }
}


void setTransactionInput(int month, int day, int year, int numAccounts, long int creditCardNum[], double transactionAmount, int currentCard, bool hello, string type[])
{
        srand(time(NULL));
        
        string company = "INVALID";
        stringstream creditCardss;
        
    if (isCard == true) {
        if (isAmerican == true && isCard == true ) {
            
            company = " American-Express";
            
        }
        else if (isDiscover == true  && isCard == true ) {
            
            company = " Discover-Card";
            isDiscover = false;
            
        }
        else if (isMaster == true && isCard == true ) {
            
            company = " Master-Card";
            isMaster = false;
            
        }
        else if (isVisa == true && isCard == true ) {
            
            company = " Visa-Card";
            isVisa = false;
            
        }
        else 
        {
            company == "INVALID";
        }
    }
        
        
        int random = rand() % 99999 + 10000; 
        creditCardss << creditCardNum[currentCard] << ":" << month << "/" << day << "/" << year << ":" << random << ":" << company <<":" << type[currentCard] << ":" << transactionAmount <<endl;
        
        string creditCardAccounts = creditCardss.str();
        
        
    
}

    get
}