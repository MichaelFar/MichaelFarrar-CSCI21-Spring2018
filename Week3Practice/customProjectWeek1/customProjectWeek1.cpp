//Michael Farrar
//CSCI21
//CustomProject week3?

#include <cstdlib>
#include <string>
#include <time.h>
#include <iostream>
#include <fstream>

//This code doesn't really do anything useful. What it does do is generate as many equations as the number you have entered is big. The equation will only subtract and will subtract the number you have entered after it asks what to base the pattern on.
using namespace std;//After that you can search the index of equations you just created and find the one you want. So if you say, generate 30 numbers. base the pattern on 3, then say give me equation 10. It will output 10*7 = 70.
int main(){//This started as a flash card number game program, but I turned it into an index equation searcher. As you can tell it has no point other than to be a strange thing that exists.
    ifstream fin;
    ofstream fout;
    
    fin.open("numberAmountStore");
    int numbers = 0;
    int makePattern = 0;
    int index = 0;
    int a = 0;
    int t = 0;
    char newNumbers = 'y';
    cout << "Do you want to use new numbers? y/n" << endl;//Also you can store your generated number from last time, or enter in a number manually. I was sort of experimenting with rudimentary save files.
    cin >> newNumbers;
    if (newNumbers == 'y'){
    cout << "How many numbers are there?" << endl;
    fout.open("numberAmountStore");
    cin >> numbers;
    fout << numbers;
    fout.close();
    }
    fout.close();
    fin >> numbers;
    string findResult[numbers];
    cout << "What do you want to base the pattern on? Type a number" << endl;
    cin >> makePattern;
    fout.close();
    fout.open("numbers_1");
    for (int i = 0; i < numbers; i++)//This loop makes new numbers if you so desired.
    {
        if (newNumbers == 'y')
        {
        fout << i << " ";
        }
        t = i - 1;
        a =  i * (i - 1);
    }
    fout.close();
    fout.open("multiplicationResult");
    fin.close();
    fin.open("multiplicationResult");
    for (int i = 1; i < numbers; i++)//This loop makes the pattern from your specification
    {
        t = i - makePattern;
        a =  i * (i - makePattern);
        fout << i << "*" << t <<"=" << a << endl;//This is the file output that goes into the other file for storage
        
            
    }
    for (int i = 1; i < numbers; i++){
        fin >> findResult[i];//Each line is an equation. And findResult is a string array that will hold your search result
    }
    char choice = 'y';
    while (choice == 'y') {
    cout << "Please input an index to search the equations for" << endl;
    cin >> index;
    while (index > numbers || index < 0)//This while loop makes sure you input a valid index.
    {
        cout << "That is an invalid index, please input another" << endl;
        cin >> index;
    }
    cout << findResult[index] << endl;//Out puts your desired equation
    cout << "Do you wish to search another index with the same pattern?" << endl;
    cin >> choice;
    }
    fin.close();
    
    
}