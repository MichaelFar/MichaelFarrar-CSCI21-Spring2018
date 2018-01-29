/*
Michael Farrar
1/30/2018
CSCI21
How many humans can fit into this thing? Calculator




*/
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cctype>


using namespace std;

double humanCalculator(double h, double d, string choice, double w, double l)//These are the dimensions of each container
{
    double volume = 0.0;
    int numHuman = 0;
    if (choice == "cubic")//This if statement handles the choice between cubic and cylinder
    {
        volume = h * l * w;//volume of cubic objects
        numHuman = volume * 0.0711;//How many humans would fit
        
    }
    else if (choice == "cylinder")
    {
        volume = 3.1415926 * pow((d/2), 2) * h;//volume of cylinders
        numHuman = volume * 0.0711;
    }
    return numHuman;
}

int main(){
    
    double h = 0.0;
    double d = 0.0;
    double w = 0.0;
    double l = 0.0;
    string choice = "h";
    
    cout << "Hello, welcome to the 'How many humans would fit in this thing?' calculator" << endl;
    cout << "Is the container a cylinder or a cubic object?(please answer either 'cylinder' or 'cubic'" << endl;
    cin >> choice;
            for (int i = 0; i < choice.length(); i++)//I really enjoy this uncase sensitive code.
        {
                if (isupper(choice[i]))
            {
                choice[i] = tolower(choice[i]);//This code makes all uppercase characters into lower case characters
                
            }
        
            
        }
    if (choice == "cubic")
    {
        cout << "OK, what is the length? In meters" << endl;
        cin >> l;
        cout << "OK, what is the height? In meters" << endl;
        cin >> h;
        cout << "Ok, what is the width? In meters" << endl;
        cin >> w;
        
    }
    else if (choice == "cylinder")
    {
        cout << "OK, what is the height? In meters" << endl;
        cin >> h;
        cout << "Ok, what is the diameter? In meters" << endl;
        cin >> d;
    }
cout << "You can fit " << humanCalculator(h, d, choice, w, l)<<" humans in that thing!" << endl;
cout << "Although, you may have to blend them all up into a human smoothy to get them all in there"<< endl;


}