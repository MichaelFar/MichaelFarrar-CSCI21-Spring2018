#ifndef KITTENS_H//I learned that you can name these header guards whatever you want, but they can't be the same as in other files. So these ones are kittens
#define KITTENS_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
class FoodItem : public Item{
    private:
    unsigned int calories_;
    string unit_of_measure_;
    double units_;
    public:
    FoodItem(string name_ = "fooditem", unsigned int value_ = 0, unsigned int calories_ = 0, string unit_of_measure = "nounits", double units_ = 0) {
        
    }
    
    virtual ~FoodItem() {
        
    }
    void set_calories(unsigned int calories_) {
        
    }
    void set_unit_of_measure(string unit_of_measure_) {
        
    }
    void set_units(double units_) {
        
    }
    unsigned int calories() {
        return calories_;
    }
    string unit_of_measure() {
        return unit_of_measure_  ;  
    }
    double units() {
        return units_;
    }
    
    string ToString(){
        stringstream Foodss;
        Foodss << name_ << ", " << " $" << value_ << ", " << units_ << " " << unit_of_measure_ << ", " << calories_;//I used string stream to make it return the string variable.
        string fooditemString = Foodss.str();
        return fooditemString;
    }
    
    
};
#endif