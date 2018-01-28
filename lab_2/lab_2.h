/*
*  Name        : lab_2.h
*  Author      : Michael Farrar
*  Description : Using Arithmetic to finish the functions MakeChange()
and
*  LaunchHumanCannonball()
*  Sources     : SEE MAIN
*/
#ifndef LAB_H
#define LAB_H
// Please note the header above. You need to include the name of the file,

// author, a description of the program and any sources used
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
// Function Prototypes (DO NOT ALTER)
void Make_Change(int initial_value, int &quarters, int &dimes, int
&nickels,int &pennies);
class ChangeMachine {// This class is for making change out of a set amount of cents.
   private:
   int initial_value;
   int quarters;
   int dimes;
   int nickels;
   int pennies;
   int numQuarters;
    int numDimes;
   int numNickels;
    int numPennies;
   public:

void MakeChange(int initial_value, int &quarters, int &dimes, int
&nickels,int &pennies) {
    int inputValue = initial_value;//Two variables are needed to facilate this kind of arithmetic in code. A number that holds the amount of that type of coin that can go into the original input and a number that holds how much is left over. numCoin variables are how much of that coin there are and coin variables are how much left over there are after division.
    
    numQuarters = inputValue / 25;
    quarters = inputValue % 25;
    numDimes = quarters / 10;
    dimes = quarters % 10;
    numNickels = dimes / 5;
    nickels = dimes % 5;
    numPennies = nickels;//SIDE NOTE: I like how this turned out compared to my original code for this last semester. My old code looked like spaghetti, but this looks nice and readable.
}
int getQuarters(){
    return numQuarters;
}
int getDimes(){
    return numDimes;
}
int getNickels(){
    return numNickels;
}
int getPennies(){
    return numPennies;
}
};
double LaunchHumanCannonball(double initial_velocity, double//After rereading the problem statement for creating the human cannonball I realized that I did not need to calculate vertical values of the trajectory. So I did maybe twice the coding needed.
launch_angle)
{
    int seconds = 1;
    double Vx = 0.0;
    double Vy = 0.0;
    double changeInVy = 9.8;// This is the variable that represents the force of gravity. This is ended up being unused, but I will not delete for I may convert into an actual trajectory calculator.
    double cosValue = 0.0;
    double sinValue = 0.0;
    double launchVal = 0.0;
    double horizontalDistance = 0.0;
    cosValue = cos(launch_angle);
    sinValue = sin(launch_angle);
    launchVal = initial_velocity;
    Vx = launchVal * cosValue;
    Vy = launchVal * sinValue;
    for (int i = 0; i < seconds; i++)
   {
      Vx += Vx;// Vx is the x value of the triangle you make with a trajectory. This value simply needs to be multiplied by the amount of seconds to find the horizontal distance. That is what this loop does.
   }//The reason this was a loop and not a simple equation was due to me thinking that I would also need to calculate the trajectory rather than the horizontal distance alone. Vy changes in a more irregular way, so it had to be a loop.
   if (Vx < 0)
   {
       Vx = Vx;
   }
   return Vx;
}
;
// Create a Constant named kPI which is initialized to 3.1415927
const double kPI = 3.1415927;
// CODE HERE
#endif
