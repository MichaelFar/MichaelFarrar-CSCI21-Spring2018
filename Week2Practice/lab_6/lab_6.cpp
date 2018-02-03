/*
 * Name        : lab_6.cpp
 * Author      : Michael Farrar
 * Description : Working with Arrays
 */

#include "lab_6.h"

// CODE HERE (FUNCTION DEFINITIONS)
string PrepareForDisplay(int values[], int size, char separator)
{
    values[size];//This bit is unnecessary, but I will leave it in
    stringstream ss;
    if (separator != ',')
    {
        separator = separator;//I needed to occupy this if statement with something, so I made it do nothing
    }
    else
    {
        separator = ',';//This is how it defaults to ','
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Input: ";//here you may enter any value you wish the array to possess
        cin >> values[i];
        if (i < size - 1)//This makes it so that the separator is not put after the last element value
        {
            ss << values[i] << separator;
        }
        else 
        {
            ss << values[i];
        }
        
    }
    string returnedString = ss.str();
    return returnedString;
}
int Sum(int values[], int size)
{
    int finalSum = 0;
    for (int i = 0; i < size; i++) 
    {
        finalSum += values[i];//Simply adds final sum to the array location and back again
    }
    return finalSum;
}
bool HasValue(int values[], int size, int value)
{
    bool isPresent = true;
    for (int i = 0; i < size + 1; i++)
    {
        if (values[i] == value)
        {
            isPresent = true;//will return this if it's true
            return isPresent;
        }
        else
        {
            isPresent = false;
        }
    }

    return isPresent;
}

int ValueAt(int values[], int size, int index, bool &error)
{
    if (index <= size && index >= 0)//Checks for a valid index choice
    {
        error = false;
    }
    else
    {
        error = true;//Will not execute next code if error is true
        return error;
    }
    if (error == false)
    {
        return values[index];
    }
    
}
bool SwapValues(int values[], int size, int index1, int index2)
{
    bool canSwap = true;
    if (index1 <= size && index1 >= 0)
    {
        canSwap = true;//I realize that I could've simply ended the function here, but I also proved that they could swap by swapping them later
    }
    else
    {
        canSwap = false;
    }
    
    if (canSwap == true)
    {
    values[index1] = values[index2] + values[index1];
    
    values[index2] = values[index2] - values[index1];
    
    values[index1] = values[index1] - values[index2];
    
    return canSwap;
        
    }
    else
    {
        return canSwap;
    }
}

int main () {
    int size = 0;
    int index1 = 0;
    int index2 = 0;
    int value = 0;
    char separator = ',';
    int index = 0;
    bool error;
    cout << "Please input the size of the array" << endl;
    cin >> size;
    int values[size];//I had a mysterious glitch where if the size was above 6, it would never let it above 6. But it would operate under the assumption that it was the value you typed in the function themselves, this would only cause issue with the "check index value" function. It had something to do with where I declared the array
    cout << "Please input the separator character" << endl;
    cin >> separator;
    cout << PrepareForDisplay(values, size, separator) << endl;
    
    cout << "Please enter the value you wish to search for" << endl;
    cin >> value;
    
    if (HasValue(values, size, value) == 1)//1 is what true returns if given a numerical value
    {
        cout << "Your value was found" << endl;
    }
    else
    {
        cout << "Your value was not found" << endl;
    }
       
    cout << " Please enter the index of the value you wish to search for: ";
    cin >> index;
    

    if (ValueAt(values, size, index, error) == 1)
    {
        cout << "INVALID INDEX" << endl;//Knows which index is valid based on specified size of array
    }
    else
    {
        cout <<"The value at index " << index <<" is " << ValueAt(values, size, index, error) << endl;
    }
    cout << "The sum of all the values: " << Sum(values, size) << endl;
    
    cout << "Input index locations to swap: index 1 " << endl;
    cin >> index1;
    cout << "index 2" << endl;
    cin >> index2;
    
    if (SwapValues(values, size, index1, index2) == 1)
    {
        cout << "Those index locations can swap" << endl;
    }
    else
    {
        cout << "Those index locations cannot swap" << endl;
    }
    
}
