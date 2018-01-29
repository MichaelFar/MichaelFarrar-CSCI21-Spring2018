#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cctype>


using namespace std;

double humanCalculator(double h, double d, string choice, double w, double l)
{
    double volume = 0.0;
    int numHuman = 0;
    if (choice == "cubic")
    {
        volume = h * l * w;
        numHuman = volume * 0.0711;
        
    }
    else if (choice == "cylinder")
    {
        volume = 3.1415926 * pow((d/2), 2) * h;
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
            for (int i = 0; i < choice.length(); i++)
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