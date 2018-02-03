/*
 * Name        : lab_6.cpp
 * Author      : FILL IN
 * Description : Working with Arrays
 */

#include "lab_6.h"

// CODE HERE (FUNCTION DEFINITIONS)
string PrepareForDisplay(int values[], int size, char separator)
{
    values[size];
    stringstream ss;
    if (separator != ',')
    {
        separator = separator;
    }
    else
    {
        separator = ',';
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Input: ";
        cin >> values[i];
        if (i < size - 1)
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
        finalSum += values[i];
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
            isPresent = true;
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
    if (index <= size && index >= 0)
    {
        error = false;
    }
    else
    {
        error = true;
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
        canSwap = true;
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
    int values[size];
    cout << "Please input the separator character" << endl;
    cin >> separator;
    cout << PrepareForDisplay(values, size, separator) << endl;
    
    cout << "Please enter the value you wish to search for" << endl;
    cin >> value;
    
    if (HasValue(values, size, value) == 1)
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
        cout << "INVALID INDEX" << endl;
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
