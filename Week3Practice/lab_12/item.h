#ifndef ADD_H//I didn't know that you needed these header things to make the code function, but I understand the general idea why you would use them.
#define ADD_H


#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
class Item{
    protected:// I really couldn't get this to work with private sections. I would like some help in class so I can resubmit it properly. 
    string name_;
    unsigned int value_;
    public:
    Item(string name_ = "item", unsigned int value_ = 0){
        
    }
    
    virtual ~Item();
    
    
    void set_name(string name_) {
        
    }
    string name() {
        return name_;
    }
    
    void set_value(unsigned int value_){
        
    }
    unsigned int value(){
        return value_;
    }
    
    string ToString(){
        stringstream ss;
        ss << name_ << ", " << "$" << value_;
        string returnedString = ss.str();
        return returnedString;
    }
    
};
#endif