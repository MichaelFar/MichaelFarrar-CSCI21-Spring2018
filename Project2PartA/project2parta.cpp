#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <time.h>


using namespace std;

class player {
    
    protected:
    
    
    
    public:
    
    void setCoordinate_play(char letterChoice, int numberChoice);
        
    
};

class human : player{
    
    
    
    protected:
    
    char letterChoice;
    int numberChoice;
    int coordinateIndex;
    bool invalidIndex;
    bool invalidNumberIndex;
    int trueIndex;
    bool trueInvalidNumber;
    bool trueInvalidIndex;
    public:
    
    human() {
    numberChoice = 0, coordinateIndex = 0, invalidIndex = false, invalidNumberIndex = false;
        
    }
    
    void setCoordinate_play(char letterChoice, int numberChoice) {
        invalidIndex = false;
        invalidNumberIndex = false;
        int coordinateIndex = 0;
        if (letterChoice == 'a' || letterChoice == 'A') {
            coordinateIndex = 0;
        }
        else if (letterChoice == 'b' || letterChoice == 'B') {
            coordinateIndex = 10;
        }
        else if (letterChoice == 'c' || letterChoice == 'C') {
            coordinateIndex = 20;
        }
        else if (letterChoice == 'd' || letterChoice == 'D') {
            coordinateIndex = 30;
        }
        else if (letterChoice == 'e' || letterChoice == 'E') {
            coordinateIndex = 40;
        }
        else if (letterChoice == 'f' || letterChoice == 'F') {
            coordinateIndex = 50;
        }
        else if (letterChoice == 'g' || letterChoice == 'G') {
            coordinateIndex = 60;
        }
        else if (letterChoice == 'h' || letterChoice == 'H') {
            coordinateIndex = 70;
        }
        else if (letterChoice == 'i' || letterChoice == 'I') {
            coordinateIndex = 80;
        }
        else if (letterChoice == 'j' || letterChoice == 'J') {
            coordinateIndex = 90;
        }
        else {
            invalidIndex = true;
            
        }
        numberChoice -= 1;
        
        if (numberChoice < 0 || numberChoice > 9) {
            invalidNumberIndex = true;
            
        }
        else {
            invalidNumberIndex = false;
        }
        coordinateIndex += numberChoice;
        trueIndex = coordinateIndex;
    };
    
    
    
    int getCoordinate_play() {
        
       return trueIndex;
    };
    
    bool getInvalidIndex() {
        return invalidIndex;
    };
    
    bool getInvalidNumberIndex() {
        return invalidNumberIndex;
    };
};

class computer : human {
    protected:
    
    int letterChoice_;
    int numberChoice_;
    int choice;
    int trueChoice;
    public:
    
    computer() {
        choice = 0;
    }
    void setCoordinate_play() {
    srand(time(NULL));
    choice = rand() % 90;
    choice += rand() % 10;
    srand(choice);
    trueChoice = choice;
    
    }
    int getCoordinate_play() {
        return trueChoice;
        
    }
};

class grid {
    protected:
    vector<char>Grid;
    vector<char>humanGrid;
    vector<char>computerGrid;
    int shipCoordinate;
    int amountOFS;
    int actualShipNumber;
    public:
    
    grid() {
    amountOFS = 0;
        humanGrid.resize(100);
    Grid.resize(100);
//    vector<char>humanGrid(100);
    computerGrid.resize(100);
    }
    
    void generateBlankGrid() {
        for (int i = 0; i < 100; i++) {
            
            Grid[i] = 'o';
            
        }
                
    }

    
    bool chooseShipPlacement(string fileName, bool isComputer) {
        ifstream fin;
        vector<bool>shipPlaced(4);
        vector<int>shipIndex(4);
        
        bool allPlaced = false;
        
        int amountOFS = 0;
        fin.open(fileName);
        
    if (isComputer == false) {
        
        while (fin.is_open() == false) {
            cout << "Invalid file name, please enter another" << endl;
            cin >> fileName;
            fin.open(fileName);
        }
    }
        for (int i = 0; i < 100; i++) {
            //cout<<i<<" " ;
             fin >> humanGrid.at(i);
             //cout << humanGrid[i] << endl;
            // fin>>c;
            // cout<<c<<endl;
        }
        
        for (int i = 0; i < 100; i++) {
            //cout<<i<<endl;
            
            if (humanGrid[i] == 'S') {
                amountOFS += 1;
                actualShipNumber = amountOFS;
            }
            
            
            if (actualShipNumber > 17 && i == 100) {
                cout << "There are too many ship units, please edit your file " << endl;
                
            }
            else if (actualShipNumber < 17 && i == 100) {
                cout << "There are not enough ship units, please edit your file " << endl;
            }
            
            
            
            
            
            
            if (humanGrid[i] == 'S' && humanGrid[i + 1] == 'S' && humanGrid[i + 2] == 'S' && humanGrid[i + 3] == 'S' && humanGrid[i + 4] == 'S' && shipIndex[3] != i|| humanGrid[i] == 'S' && humanGrid[i - 1] == 'S' && humanGrid[i - 2] == 'S' && humanGrid[i - 3] == 'S' && humanGrid[i - 4] == 'S' && shipIndex[3] != i || humanGrid[i] == 'S' && humanGrid[i + 10] == 'S' && humanGrid[i + 20] == 'S'&& humanGrid[i + 30] == 'S' && humanGrid[i + 40] == 'S' && shipIndex[3] != i|| humanGrid[i] == 'S' && humanGrid[i - 10] == 'S'&& humanGrid[i - 20] == 'S' && humanGrid[i - 30] == 'S' && humanGrid[i - 40] == 'S' && shipIndex[3] != i){
                shipIndex[0] = i;
                shipPlaced[0] = true;
            }
            else if (humanGrid[i] == 'S' && humanGrid[i + 1] == 'S' && humanGrid[i + 2] == 'S' && humanGrid[i + 3] == 'S' && shipIndex[0] != i|| humanGrid[i] == 'S' && humanGrid[i - 1] == 'S' && humanGrid[i - 2] == 'S' && humanGrid[i - 3] == 'S' && shipIndex[0] != i || humanGrid[i] == 'S' && humanGrid[i + 10] == 'S' && humanGrid[i + 20] == 'S'&& humanGrid[i + 30] == 'S' && shipIndex[0] != i|| humanGrid[i] == 'S' && humanGrid[i - 10] == 'S'&& humanGrid[i - 20] == 'S' && humanGrid[i - 30] == 'S' && shipIndex[0] != i) {
            shipIndex[1] = i;
            shipPlaced[1] = true;
            
            }
            else if (humanGrid[i] == 'S' && humanGrid[i + 1] == 'S' && humanGrid[i + 2] == 'S' && shipIndex[1] != i|| humanGrid[i] == 'S' && humanGrid[i - 1] == 'S' && humanGrid[i - 2] == 'S' && shipIndex[1] != i|| humanGrid[i] == 'S' && humanGrid[i + 10] == 'S' && humanGrid[i + 20] == 'S'&& shipIndex[1] != i|| humanGrid[i] == 'S' && humanGrid[i - 10] == 'S'&& humanGrid[i - 20] == 'S' && shipIndex[1] != i) {
            shipIndex[2] = i;
            shipPlaced[2] = true;
            }
            else if (humanGrid[i] == 'S' && humanGrid[i + 1] == 'S' && humanGrid[i + 2] == 'S' && shipIndex[2] != i|| humanGrid[i] == 'S' && humanGrid[i - 1] == 'S' && humanGrid[i - 2] == 'S' && shipIndex[2] != i|| humanGrid[i] == 'S' && humanGrid[i + 10] == 'S' && humanGrid[i + 20] == 'S' && shipIndex[2] != i|| humanGrid[i] == 'S' && humanGrid[i - 10] == 'S'&& humanGrid[i - 20] == 'S' && shipIndex[2] != i) {
            shipIndex[3] = i;
            shipPlaced[3] = true;
            }
            else if (humanGrid[i] == 'S' && humanGrid[i + 1] == 'S' && shipPlaced[3] == false|| humanGrid[i] == 'S' && humanGrid[i - 1] == 'S' && shipPlaced[3] == false|| humanGrid[i] == 'S' && humanGrid[i + 10] == 'S' && shipPlaced[3] == false || humanGrid[i] == 'S' && humanGrid[i - 10] == 'S' && shipPlaced[3] == false){
            shipIndex[4] = i;
            shipPlaced[4] = true;
            
                }
            
            }
            if (shipPlaced[4] == true) {
                return allPlaced = true;
            }
            else {
                cout << "This file does not have proper ship placement, edit your file" << endl;
            }
        }
        
    vector<char> getBlankGrid() {
        return Grid;
    }
    int getAmountOFS() {
        
        return actualShipNumber;
    }
};




int main() {
    ifstream fin;
    ofstream fout;
    
    bool humanInvalid;
    bool computerInvalid;
    human player;
    
    human beepboop;
    
    computer one;
    
    grid fleshbag;
    grid synth;
    int setting = 0;
    fleshbag.generateBlankGrid();
    cout << endl;
    synth.generateBlankGrid();
    
   vector<char> humanBlank = fleshbag.getBlankGrid();
    vector<char> computerBlank = synth.getBlankGrid();
    
    int confirmation;
    bool hasHit = false;
    char charChoice = 'a';
    int numberChoice = 0;
    int playerShot = 0;
    string fileName;
    int computerShot = 0;
    vector<char>humanGrid(100);
    vector<char>computerGrid(100);
    int computerShipUnits = 0;
    int playerShipUnits = 0;
    cout << "Specify the file that holds your grid and coordinates" << endl;
    cin >> fileName;
    fin.open(fileName);
    cout << "Do you want the computer to show it's information grid? 1 for yes (not the grid with ships)" << endl;
    cin >> setting;
    for (int i = 0; i < 100; i++) {
        
        fin >> humanGrid[i];
        int countVar = i + 1;
        if (countVar % 10 != 0) {
            cout << humanGrid[i] << " ";
            }
            else {
               cout << humanGrid[i] <<" " <<endl;
            }
    }
    fin.close();
    
    fin.open("computerGrid");
    
    for (int i = 0; i < 100; i++) {
        fin >> computerGrid[i];
        //int countVar = i + 1;
        //if (countVar % 10 != 0) {
            //cout << computerGrid[i] << " ";
            //}
            //else {
             //   cout << computerGrid[i] <<" " <<endl;
            //}
    }
    
    
    
    
    fleshbag.chooseShipPlacement(fileName, false);
    
    synth.chooseShipPlacement("computerGrid", true);
    
    
    int playerShips = fleshbag.getAmountOFS();
    int computerShips = synth.getAmountOFS();
    
    cout << "^^ Your grid  flesh bag^^ "<< endl;
    cout << "Ready to play? OK flesh bag goes first" << endl;
    
while (playerShips!= 0 || computerShips != 0) {
    cout << endl;
    cout << "Please enter the coordinates of where you wish to hit separated by a space. EX: A 1" << endl;
    
    cin >> charChoice;
    
    cin >> numberChoice;
    
    
    
    
    
    player.setCoordinate_play(charChoice, numberChoice);
    humanInvalid = player.getInvalidIndex();
    computerInvalid = beepboop.getInvalidIndex();
    playerShot = player.getCoordinate_play();
    
    while (humanInvalid == true || computerInvalid == true) {
        
        cout << "That coordinate was invalid, please input another" << endl;
        
        cin >> charChoice;
    
        cin >> numberChoice;
        
        
        player.setCoordinate_play(charChoice, numberChoice);
        humanInvalid = player.getInvalidIndex();
        humanInvalid = player.getInvalidNumberIndex();
        
    }
    
    if (computerGrid[playerShot] == 'S' && humanBlank[playerShot] != 'H' && humanBlank[playerShot] != 'M')
    {
        
        
        humanBlank[playerShot] = 'H';
        cout << "HIT!" << endl;
        
        hasHit = true;
        computerShips -= 1;
        
        
        for (int i = 0; i < 100; i++) {
                int countVar = i + 1;
            if (countVar % 10 != 0) {
                cout << humanBlank[i] << " ";
                }
                else {
                    cout << humanBlank[i] <<" " <<endl;
                }
            }
            
    }
    else
    {
        
        hasHit = false;
        
        if (humanBlank[playerShot] != 'H') {
            humanBlank[playerShot] = 'M';
            }
            else
            {
                cout << "Why did you hit the same spot twice? Stupid flesh bag" << endl;
            }
        
        for (int i = 0; i < 100; i++) {
                int countVar = i + 1;
            if (countVar % 10 != 0) {
                cout << humanBlank[i] << " ";
                }
                else {
                    cout << humanBlank[i] <<" " <<endl;
                }
            }
            cout << "^^ Your info ^^" << endl;
        cout << endl;
        cout << "You missed" << endl;
        
    }
    
    while (hasHit == false) {
        
        cout << "Computer's turn " << endl;
        one.setCoordinate_play();
        srand(one.getCoordinate_play());
        computerShot = one.getCoordinate_play();
        cout << computerShot + 1 << endl;
        if (humanGrid[computerShot] == 'S'&& computerBlank[computerShot] != 'H' && computerBlank[computerShot] != 'M') {
            computerBlank[computerShot] = 'H';
            hasHit = false;
            playerShips -= 1;
            
            int countVar = 0;
            for (int i = 0; i < 100; i++) {
            
            countVar = i + 1;
            if (countVar % 10 != 0 && setting != 0) {
                cout << computerBlank[i] << " ";
                }
                else if (setting != 0){
                    cout << computerBlank[i] <<" " <<endl;
                }
            }
            if (setting != 0) {
                cout << "^^ Computer's info ^^ " << endl;
            }
            else
            {
                cout << "^^ Computer's info ^^ " << endl;
            }
            
        cout << endl;
        }
        else
        {
            if (humanGrid[computerShot] != 'H') {
            computerBlank[computerShot] = 'M';
            }
            else
            {
                cout << "Computer hit the same spot" << endl;
            }
            
            hasHit = true;
            int countVar = 0;
            for (int i = 0; i < 100; i++) {
            
            countVar = i + 1;
            if (countVar % 10 != 0 && setting != 0) {
                cout << computerBlank[i] << " ";
                }
                else if (setting != 0) {
                    cout << computerBlank[i] <<" " <<endl;
                }
                
            }
            if (setting != 0) {
            cout << "Computer Missed " << endl;
            }
            else
            {
                cout << "^^ Computer's info ^^ " << endl;
            }
        }
    }
}
    
}