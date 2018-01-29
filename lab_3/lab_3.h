/*
 * Name        : lab_3.cpp
 * Author      : Luke Sathrum
 * Description : Header File for Lab #3. Do NOT Alter this file.
 */

#ifndef LAB_H
#define LAB_H

#include <iostream>//Many of these libraries were unnecessary and ended up not being used.
#include <string.h>
#include <cctype>
#include <ctype.h>
#include <locale>
#include <stdio.h>
using namespace std;

// Function Prototypes (DO NOT ALTER)
string Goldilocks(string item, int number){
for (int i = 0; i < item.length(); i++)
{
        if (isupper(item[i]))
    {
        item[i] = tolower(item[i]);//This code makes all uppercase characters into lower case characters
        
    }

    
}
if (number > 3 || number < 1)//If else tree that has all options that the user can input
  {
    number = 3;
  }
  if (item != "bed" && item != "porridge" && item != "chair")
  {
    item = "bed";
  }
  
  if (item == "porridge" && number == 1)
  {
    cout << "This porridge is too hot" << endl;
  }
  else if (item == "porridge" && number == 2)
  {
    cout << "This porridge is too cold" << endl;
  }
  else if (item == "porridge" && number == 3)
  {
    cout << "This porridge is just right" << endl;
  }
  else if (item == "chair" && number == 1)
  {
    cout << "This chair is too big" << endl;
  }
  else if (item == "chair" && number == 2)
  {
    cout << "This chair is too small" << endl;
  }
  else if (item == "chair" && number == 3)
  {
    cout << "This chair is just right" << endl;
  }
  else if (item == "bed" && number == 1)
  {
    cout << "This bed is too hard" << endl;
  }
  else if (item == "bed" && number == 2)
  {
    cout << "This bed is too soft" << endl;
  }
  else if (item == "bed" && number == 3)
  {
    cout << "This bed is just right" << endl;
  }
};
int RockScissorPaper(char player_one, char player_two)
{
    const char p = 'p';//For some reason, switches demanded const char variables
    const char r = 'r';
    const char s = 's';
        for (int i = 0; i < 1; i++)//modified loop from earlier that makes all things typed in lower case.
    {
            if (isupper(player_one))
        {
            player_one = tolower(player_one);
            
        }
        
    
        
    }
       for (int i = 0; i < 1; i++)
    {
            if (isupper(player_two))
        {
            player_two = tolower(player_two);
            
        }
        
    
        
    }
    switch (player_one){//I used a combination of switch and if statements to get the desired outcome
        case r: 
            if (player_two == s)
            {
            cout << 1<< endl;
            }
            if (player_two == p) 
        {
            cout << 2<< endl;
        }
        if (player_one == player_two)
        {
            cout << 3<< endl;
        }
        break;
        
        
        
         case s: 
         if (player_two == r) 
         {
             cout << 2<< endl;
         }
         if (player_two == p) 
         {
         cout << 1<< endl;
         }
         if (player_one == player_two)
        {
            cout << 3 << endl;
        }
        break;
         case p:
         if (player_two == s)
         {
         
         cout << 2<< endl;
         }
         if (player_two == r) 
         {
             cout << 1<< endl;
         }
         if (player_one == player_two)
        {
            cout << 3<< endl;
        }
        
        break;
        
        
        
    }
    
    
    
}
string ToLower(string input);
string ToUpper(string input);

#endif