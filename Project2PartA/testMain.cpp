#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;
int main() {
        vector<char>grid(99);
        int shipCoordinate;
    
        ofstream fout;
        ifstream fin;
        
        fout.open("blankGrid");
        
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            int countVar = i + 1;
            grid[i] = 'O';
            if (countVar % 10 == 0)
            {
            cout << countVar << endl;    
            fout << grid[i] << endl;
            }
            else
            {
                fout << grid[i]  << " ";
            }
        }
    }