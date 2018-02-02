/*
Michael Farrar
February 1st 2018
CSCI 21
BIN Checker

*/

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

using namespace std;
bool isCard = false;

int makeRandomCreditcard() {//Little optional code I made to generate a random credit card number.
    ifstream fin;
    ofstream fout;
    fout.open("CreditCardNumbers");
    srand(time(NULL));
    int V = 0;
    int seed = 0;
    int number = 0;
    const int master = 16;
    const int discover = 16;
    const int american = 15;
    seed = rand() % 100000;
    V = (rand() % 4) + 13;
    
    srand(seed);
    vector<long int>AMERICANamountOfNumbers(american);// Vectors for holding the amount of digits needed per card
    vector<long int>DISCOVERamountOfNumbers(discover);
    vector<long int>MasterCardamountOfNumbers(master);
    vector<long int>VisaAmountOfNumbers(V);
    
    
    number = rand() % 10;
    
    for (int i = 0; i < american; i++)// Calculating for each card number
    {
        seed = rand() % 100000;
        srand(AMERICANamountOfNumbers.at(i) + number + seed);
        number = rand() % 9;
        AMERICANamountOfNumbers.at(i) = number;
        fout << AMERICANamountOfNumbers.at(i);
                

    }
    fout << endl << endl;
    cout << endl << endl;
    for (int i = 0; i < discover; i++)
    {
        seed = rand() % 100000;
        srand(DISCOVERamountOfNumbers.at(i) + number + seed);
        number = rand() % 9;
        DISCOVERamountOfNumbers.at(i) = number;
        fout << DISCOVERamountOfNumbers.at(i);
        
    }
    fout << endl << endl;
        

    for (int i = 0; i < master; i++)
    {
        seed = rand() % 100000;
        srand(MasterCardamountOfNumbers.at(i) + number + seed);
        number = rand() % 9;
        MasterCardamountOfNumbers.at(i) = number;
        fout << MasterCardamountOfNumbers.at(i);
        
    }
    fout << endl << endl;
        cout << endl << endl;
    for (int i = 0; i < V; i++)
    {
        seed = rand() % 100000;
        srand(VisaAmountOfNumbers.at(i) + number + seed);
        number = rand() % 9;
        VisaAmountOfNumbers.at(i) = number;
        fout << VisaAmountOfNumbers.at(i);
        
    }
    
}
int CheckBIN(long int american, long int master, long int discover, long int visa, int numCards)// Checks BIN of each card company and tells you if you have a valid card
{
    stringstream americanSS;
    stringstream masterSS;
    stringstream discoverSS;
    stringstream visaSS;
    stringstream luhnSS_1;
    stringstream luhnSS_2;
    stringstream luhnSS_3;
    stringstream luhnSS_4;
    ifstream fin;
    ofstream fout;
    fin.open("CreditCardNumbers");
    fout.open("dump");
    int asciiValue = 0;
    char luhnChar_ = 'i';
    long int creditCard[numCards];
    int sum = 0;
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
    luhnSS_2 << creditCardLuhn[1];
    luhnSS_3 << creditCardLuhn[2];
    luhnSS_4 << creditCardLuhn[3];
    string luhnStr_4 = luhnSS_4.str();
    string luhnStr_3 = luhnSS_3.str();
    string luhnStr_2 = luhnSS_2.str();
    string luhnStr_1 = luhnSS_1.str();
    int luhnNum_1[luhnStr_1.length()];
    int luhnDoubleNum_1[luhnStr_1.length()];
    int luhnNum_2[luhnStr_2.length()];
    int luhnDoubleNum_2[luhnStr_2.length()];
    int luhnNum_3[luhnStr_3.length()];
    int luhnDoubleNum_3[luhnStr_3.length()];
    int luhnNum_4[luhnStr_4.length()];
    int luhnDoubleNum_4[luhnStr_4.length()];
    
    for (i = 0; i < luhnStr_1.length(); i++)
    {
        
        luhnNum_1[i] = luhnStr_1[i];
        fout << " ";
        fout << char(luhnNum_1[i]);
        fout << " ";
        fin >> luhnNum_1[i];
    }
    for (i = 0; i < luhnStr_1.length(); i++)
        {
        int   digit = luhnStr_1[i] - '0';   // Char to number
        if  (i & 1)  // Digit 1, 3, 5 not 0, 2, 4 - "even digits" starting at 1
            if  ((digit <<= 1) >= 10) //  Double it, check >= 10
                digit -= 9;           //  Same as summing the digits
         sum += digit;
        }
    checksum = sum % 10;
    
    
    
    
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
    
    cout << "Checking Card " << a <<" for American Express: " << creditCard[i] << endl;
    long int visaDynamicLength = 0;
    if (creditCard[i] >=340000000000000 && creditCard[i] <= 349999999999999&& checksum == 0)// How I checked the BIN numbers
    {
        americanSS << creditCard[i]- 340000000000000;
    }
    else if (creditCard[i] >= 370000000000000 && creditCard[i] <= 379999999999999&& checksum == 0)
    {
        americanSS << creditCard[i]- 370000000000000;
    }
    string americanStr = americanSS.str();
    for (int i = 0; i < luhnStr_1.length(); i++)
    {
        
        luhnNum_1[i] = luhnStr_1[i];
        fout << " ";
        fout << char(luhnNum_1[i]);
        fout << " ";
        fin >> luhnNum_1[i];
    }
    for (int i = 0; i < luhnStr_1.length(); i++)
        {
        int   digit = luhnStr_1[i] - '0';   
        if  (i & 1)  
            if  ((digit <<= 1) >= 10) 
                digit -= 9;           
         sum += digit;
        }
    checksum = sum % 10;
    
    if (americanStr.length() == 13 && checksum == 0)
    {
        cout << " is an American Express Card" << endl;
        isCard = true;
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
    for (int i = 0; i < luhnStr_2.length(); i++)
    {
        
        luhnNum_2[i] = luhnStr_2[i];
        fout << " ";
        fout << char(luhnNum_2[i]);
        fout << " ";
        fin >> luhnNum_2[i];
    }
    for (int i = 0; i < luhnStr_2.length(); i++)
        {
        int   digit = luhnStr_2[i] - '0';   
        if  (i & 1)  
            if  ((digit <<= 1) >= 10) 
                digit -= 9;          
         sum += digit;
        }
    checksum = sum % 10;
    cout << "Checking Card " << a << " for Discover: " << creditCard[i] <<  endl;
    if (creditCard[i] >=601100000000000 && creditCard[i] <= 601199999999999&& checksum == 0)
    {
        cout << " is a Discover Card" << endl;  
                isCard = true;

    }
    else if (creditCard[i] >= 622126000000000 && creditCard[i] <= 622925999999999&& checksum == 0)
    {
        
        cout << " is a Discover Card" << endl;
                isCard = true;

    }
    
    else if (creditCard[i] >= 644000000000000 && creditCard[i] <= 649999999999999&& checksum == 0)
    {
        cout << " is a Discover Card" << endl;
                isCard = true;

        
    }
    else if (creditCard[i] >= 650000000000000 && creditCard[i] <= 659999999999999&& checksum == 0)
    {
        cout << " is a Discover Card" << endl;
                isCard = true;

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
    for (int i = 0; i < luhnStr_3.length(); i++)
    {
        
        luhnNum_3[i] = luhnStr_3[i];
        fout << " ";
        fout << char(luhnNum_3[i]);
        fout << " ";
        fin >> luhnNum_3[i];
    }
    for (int i = 0; i < luhnStr_3.length(); i++)
        {
        int   digit = luhnStr_3[i] - '0';   
        if  (i & 1)  
            if  ((digit <<= 1) >= 10) 
                digit -= 9;          
         sum += digit;
        }
    checksum = sum % 10;
    cout << "Checking Card " << a << " for Master Card: " << creditCard[i] <<  endl;
    if (creditCard[i] >=510000000000000 && creditCard[i] <= 559999999999999&& checksum == 0)
    {
        cout << " is a Master Card" << endl;
                isCard = true;

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
    for (int i = 0; i < luhnStr_4.length(); i++)
    {
        
        luhnNum_4[i] = luhnStr_4[i];
        fout << " ";
        fout << char(luhnNum_4[i]);
        fout << " ";
        fin >> luhnNum_4[i];
    }
    for (int i = 0; i < luhnStr_4.length(); i++)
        {
        int   digit = luhnStr_4[i] - '0';   
        if  (i & 1)  
            if  ((digit <<= 1) >= 10) 
                digit -= 9;           
         sum += digit;
        }
    checksum = sum % 10;
    cout << "Checking Card " << a <<" Visa: " << creditCard[i] <<  endl;
    visaSS >> visa;
    string visaStr = visaSS.str();
    if (creditCard[i] >= 4000000000000 && creditCard[i] <= 4999999999999 || creditCard[i] >= 40000000000000 && creditCard[i] <= 49999999999999 || creditCard[i] >= 400000000000000 && creditCard[i] <= 499999999999999 && visaStr.length() <= 16 && visaStr.length() >= 13 && checksum == 0)
    {
        cout << " is a Visa Card" << endl;
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
    ifstream fin;
    ofstream fout;
    
    long int american = 0;
    long int master = 0;
    long int discover = 0;
    long int visa = 0;
    int disableLoop = 0;
    char choice = 'i';
    int numCards = 0;
    cout << "It must take 4 credit card numbers to work properly. Luhn's algorithm will not work with this code otherwise" << endl;
    numCards = 4;
    cout << "Do you want this program to loop?" << endl;
    cout << "1 for yes, 2 for no" << endl;
    cin >> disableLoop;
    cout << "Do you want to use your own input file values? y/n" << endl;
    cin >> choice;
    if (choice == 'n')
    {
        makeRandomCreditcard();
    }
    CheckBIN(0, 0, 0, 0, numCards);
    while (isCard == false && disableLoop == 1)//This loop generates new cards until at least one of them is a valid card. NOTE: Crashes often due to how I programmed the random number generator, So if it crashes when you test it please rerun the program
    {
    makeRandomCreditcard();
    CheckBIN(0, 0, 0, 0, numCards);
    }
}


/*
Checking American Express: 836660038142782
Checking
Checking Discover: 836660038142782
Checking
Checking Master Card: 836660038142782
Checking
Checking Visa: 836660038142782
Checking
Checking American Express: 1103648054017472
Checking
Checking Discover: 1103648054017472
Checking
Checking Master Card: 1103648054017472
Checking
Checking Visa: 1103648054017472
Checking
Checking American Express: 5411157141574723
Checking
Checking Discover: 5411157141574723
Checking
Checking Master Card: 5411157141574723
Checking
Checking Visa: 5411157141574723
Checking
Checking American Express: 4341575773077
Checking
Checking Discover: 4341575773077
Checking
Checking Master Card: 4341575773077
Checking
Checking Visa: 4341575773077
 is a Visa Card
 
 
 
 
 
 
 
 Do you want this program to loop?
1 for yes, 2 for no
1





Checking American Express: 873844578716680
Checking
Checking Discover: 873844578716680
Checking
Checking Master Card: 873844578716680
Checking
Checking Visa: 873844578716680
Checking
Checking American Express: 5732513566565455
Checking
Checking Discover: 5732513566565455
Checking
Checking Master Card: 5732513566565455
Checking
Checking Visa: 5732513566565455
Checking
Checking American Express: 4024751833572115
Checking
Checking Discover: 4024751833572115
Checking
Checking Master Card: 4024751833572115
Checking
Checking Visa: 4024751833572115
Checking
Checking American Express: 4468715834061
Checking
Checking Discover: 4468715834061
Checking
Checking Master Card: 4468715834061
Checking
Checking Visa: 4468715834061
 is a Visa Card

 */