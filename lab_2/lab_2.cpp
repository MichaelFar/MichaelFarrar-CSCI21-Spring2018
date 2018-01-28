/*
*  Name        : lab_2.cpp
*  Author      : Michael Farrar
*  Description : Using Arithmetic to finish the functions MakeChange()
and
*  LaunchHumanCannonball()
*  Sources     : http://www.physicsclassroom.com/class/vectors/Lesson-2/Horizontally-Launched-Projectiles-Problem-Solving
*/
// Please note the header above. You need to include the name of the file, the
// author, a description of the program and any sources used
#include "lab_2.h"
/*
*  Given an initial integer value (representing change to be given, such
as in a
*  financial transaction), break the value down into the number of
quarters,
*  dimes, nickels, and pennies that would be given as change.
*  @param int initial_value - The amount of change to be broken down in
pennies.
*  @param int quarters  - The number of quarters that come out of
initial_value
*  @param int dimes - The number of dimes that come out of initial_value,
*  after quarters have been taken out
*  @param int nickels - The number of nickels that come out of
initial_value,
*  after quarters and dimes have been taken out
*  @param int pennies - The number of pennies that come out of
initial_value,
*  after quarters, dimes, and nickels have been taken out
*/



int main(){
    ChangeMachine one;
    int userMoney = 0;
    int change = 0;
    int quarters_one = 0;
    int dimes_one = 0;
    int nickels_one = 0;
    int pennies_one = 0;
    cout << "Please input the money to be converted to change" << endl;
    cin >> userMoney;
    one.MakeChange(userMoney, quarters_one, dimes_one, nickels_one, pennies_one);
    cout << one.getQuarters() << endl;
    if (one.getQuarters() > 1 || one.getQuarters() == 0)
    {
        cout << " quarters" << endl;
    }
    else
    {
        cout << " quarter" << endl;
    }
    cout << one.getDimes() << endl;
    if (one.getDimes() > 1|| one.getDimes() == 0)
    {
        cout << " dimes" << endl;
    }
    else
    {
        cout << " dime" << endl;
    }
    cout << one.getNickels() << endl;
    if (one.getNickels() > 1 || one.getNickels() == 0)
    {
        cout << " nickels" << endl;
    }
    else
    {
        cout << " nickel" << endl;
    }
    cout << one.getPennies() << endl;
    if (one.getPennies() > 1|| one.getPennies() == 0)
    {
        cout << " pennies" << endl;
    }
    else
    {
        cout << " penny" << endl;
    }

int seconds = 0;
cout << "Now for the human cannonball" << endl;
cout << "input initial velocity" << endl;
double initialVelocity = 0;
cin >> initialVelocity;
double angle = 0;
cout << "Please input the angle" << endl;
cin >> angle;
cout << "Please input the amount of seconds it'll take to reach it's destination" << endl;
cin >> seconds;
cout << LaunchHumanCannonball(initialVelocity, angle) * seconds << " is the horizontal distance";
    
    
}
/*
*  Computes the horizontal distance traveled by a human cannonball given
an
*  initial velocity and launch angle. Simplified -- does not account for
many
*  factors that affect projectile motion.
*  @param double initial_velocity - Represents the initial velocity of
the
*  human cannonball in meters/second
*  @param double launch_angle -  Represents the launch angle of the human
*  cannonball in degrees
*  @return double  - Represents the horizontal distance the human
cannonball
*  will travel
*/

