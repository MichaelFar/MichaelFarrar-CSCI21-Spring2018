/*
Michael Farrar
February 1st 2018
CSCI 21
Generated Card

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