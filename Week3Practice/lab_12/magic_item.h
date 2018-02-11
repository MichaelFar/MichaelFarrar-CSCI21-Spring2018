#ifndef BUTTER_H// I thought of other pleasant things to name these ones
#define BUTTER_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
class MagicItem : public Item{//I had to look up several tutorials on inheritance and I ended up using a mish mash of different methods. But it works so I don't really mind.

private:
string description_;
unsigned int mana_required_;

public:

MagicItem(string description = "no description", unsigned int mana_required_ = 0, string name_  = "magicitem", unsigned int value_ = 0) {
   
    
}

virtual ~MagicItem();

void set_description(string description_) {
    
}

void set_mana_required(unsigned int mana_required_) {
    
}

string description() {
    return description_;
}

unsigned int mana_required() {
    return mana_required_;
}
string ToString() {
    stringstream magicSS;
    magicSS << name_ << ", $" << value_ << ", " << description_ << ", " << "requires " << mana_required_ << " mana";////I used string stream again for all the other string return functions
    string magicString = magicSS.str();
    return magicString;
}

    
};

#endif