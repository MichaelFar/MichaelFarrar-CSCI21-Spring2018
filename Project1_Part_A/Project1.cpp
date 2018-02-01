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
int CheckBIN(long int american, long int master, long int discover, long int visa)// Checks BIN of each card company and tells you if you have a valid card
{
    stringstream americanSS;
    stringstream masterSS;
    stringstream discoverSS;
    stringstream visaSS;
    ifstream fin;
    fin.open("CreditCardNumbers");
    long int creditCard[4];
    for (int i = 0; i < 4; i++)
    {
        fin >> creditCard[i];
    }
    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        
    
    cout << "Checking American Express: " << creditCard[i] << endl;
    long int visaDynamicLength = 0;
    if (creditCard[i] >=340000000000000 && creditCard[i] <= 349999999999999)// How I checked the BIN numbers
    {
        americanSS << creditCard[i]- 340000000000000;
    }
    else if (creditCard[i] >= 370000000000000 && creditCard[i] <= 379999999999999)
    {
        americanSS << creditCard[i]- 370000000000000;
    }
    string americanStr = americanSS.str();
    
    if (americanStr.length() == 13)
    {
        cout << " is a American Express Card" << endl;
        isCard = true;
    }
    else
    {
        if (isCard == false){
            cout << "Checking" << endl;
        }
        else
        {
        cout << " INVALID CARD" << endl;
        }
    }
    cout << "Checking Discover: " << creditCard[i] <<  endl;
    if (creditCard[i] >=601100000000000 && creditCard[i] <= 601199999999999)
    {
        cout << " is a Discover Card" << endl;  
                isCard = true;

    }
    else if (creditCard[i] >= 622126000000000 && creditCard[i] <= 622925999999999)
    {
        
        cout << " is a Discover Card" << endl;
                isCard = true;

    }
    
    else if (creditCard[i] >= 644000000000000 && creditCard[i] <= 649999999999999)
    {
        cout << " is a Discover Card" << endl;
                isCard = true;

        
    }
    else if (creditCard[i] >= 650000000000000 && creditCard[i] <= 659999999999999)
    {
        cout << " is a Discover Card" << endl;
                isCard = true;

    }
    else
    {
        if (isCard == false){
            cout << "Checking" << endl;
        }
        else
        {
        cout << " INVALID CARD" << endl;
        }
            
    }
    cout << "Checking Master Card: " << creditCard[i] <<  endl;
    if (creditCard[i] >=510000000000000 && creditCard[i] <= 559999999999999)
    {
        cout << " is a Master Card" << endl;
                isCard = true;

    }
    else
    {
        if (isCard == false){
            cout << "Checking" << endl;
        }
        else
        {
        cout << " INVALID CARD" << endl;
        }
    }
    cout << "Checking Visa: " << creditCard[i] <<  endl;
    visaSS >> visa;
    string visaStr = visaSS.str();
    if (creditCard[i] >= 4000000000000 && creditCard[i] <= 4999999999999 || creditCard[i] >= 40000000000000 && creditCard[i] <= 49999999999999 || creditCard[i] >= 400000000000000 && creditCard[i] <= 499999999999999)
    {
        cout << " is a Visa Card" << endl;
                isCard = true;

    }
    else
    {
        if (isCard == false){
            cout << "Checking" << endl;
        }
        else
        {
        cout << " INVALID CARD" << endl;
        }
    }
    }
    
    
    
}
int main() {
    ifstream fin;
    ofstream fout;
    
    long int american = 0;
    long int master = 0;
    long int discover = 0;
    long int visa = 0;
    int disableLoop = 0;
    cout << "Do you want this program to loop?" << endl;
    cout << "1 for yes, 2 for no" << endl;
    cin >> disableLoop;
    makeRandomCreditcard();//Note: Erase this line to put custom inputs into the Credit Card Numbers File
    CheckBIN(0, 0, 0, 0);
    while (isCard == false && disableLoop == 1)//This loop generates new cards until at least one of them is a valid card. NOTE: Crashes often due to how I programmed the random number generator, So if it crashes when you test it please rerun the program
    {
    makeRandomCreditcard();//Note: Erase this line to put custom inputs into the Credit Card Numbers File
    CheckBIN(0, 0, 0, 0);
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
 */