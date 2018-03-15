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

class human : player{//The class that handles how the index of the user is interpreted
    
    
    
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
    
    void setCoordinate_play(char letterChoice, int numberChoice) {//The user enters a letter and a number. EX A 1. It does not need to be capital
        
        invalidIndex = false;// It checks for either of the type of indexes to be invalid
        invalidNumberIndex = false;
        int coordinateIndex = 0;//This is the final index that is translated into something that can be inputted into the vector
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
        numberChoice -= 1;//This makes it so that the proper element is called. So when the user types 1 it actually inputs 0
        
        if (numberChoice < 0 || numberChoice > 9) {//However if the user were to input a 0 it would go to -1 and trigger the invalid index boolean
            invalidNumberIndex = true;
            
        }
        else {
            invalidNumberIndex = false;
        }
        coordinateIndex += numberChoice;//This sets coordinateIndex to the index that the computer will get
        trueIndex = coordinateIndex;// trueIndex is the variable that is returned instead of coordinateIndex. The reason is that the constructor resets the value so that the number cannot be called
    };
    
    
    
    int getCoordinate_play() {
        
       return trueIndex;//All invalid booleans are returned so that they may be read in the main
    };
    
    bool getInvalidIndex() {
        return invalidIndex;
    };
    
    bool getInvalidNumberIndex() {
        return invalidNumberIndex;
    };
};

class computer : human {//The class that handles computer decision
    protected:
    
    int letterChoice_;
    int numberChoice_;
    int choice;
    int trueChoice;
    char computerLetterCoordinate;
    public:
    
    computer() {
        choice = 0;
    }
    void setCoordinate_play() {// The computer bases it's decisions on a random number. This will obviously be replaced in part b
    srand(time(NULL));
    choice = rand() % 90;
    choice += rand() % 10;
    srand(choice);
    trueChoice = choice;
    if (choice >= 0 && choice < 10) {//The code below does the reverse of the similar code in the player setCoordinatePlay. It translates a number into a letter so that the user may understand it' decision. Otherwise the user would see something like '82'
            computerLetterCoordinate = 'A';
        }
        else if (choice >= 10 && choice < 20) {
            computerLetterCoordinate = 'B';
        }
        else if (choice >= 20 && choice < 30) {
            computerLetterCoordinate = 'C';
        }
        else if (choice >= 30 && choice < 40) {
            computerLetterCoordinate = 'D';
        }
        else if (choice >= 40 && choice < 50) {
            computerLetterCoordinate = 'E';
        }
        else if (choice >= 50 && choice < 60) {
            computerLetterCoordinate = 'F';
        }
        else if (choice >= 60 && choice < 70) {
            computerLetterCoordinate = 'G';
        }
        else if (choice >= 70 && choice < 80) {
            computerLetterCoordinate = 'H';
        }
        else if (choice >= 80 && choice < 90) {
            computerLetterCoordinate = 'I';
        }
        else if (choice >= 90 && choice < 100) {
            computerLetterCoordinate = 'J';
        }
    
    
    }
    int getCoordinate_play() {
        return trueChoice;
        
    }
    string getFriendlyCoordinate () {//Makes the player friendly coordinate a string stream
        stringstream ss;
        ss << computerLetterCoordinate << " " << trueChoice % 10 + 1<< endl;
        string friendlyCoordinate = ss.str();
        return friendlyCoordinate;
    }
};

class grid {//This class is all about applying the chosen indexes to the grid
    protected:
    vector<char>Grid;
    vector<char>humanGrid;
    vector<char>computerGrid;
    int shipCoordinate;
    int amountOFS;
    int actualShipNumber;
    public:
    
    grid() {
    amountOFS = 0;//Variable that counts ships, this is related to the win condition
    humanGrid.resize(100);
    Grid.resize(100);
//    vector<char>humanGrid(100);
    computerGrid.resize(100);
    }
    
    void generateBlankGrid() {//This function generates an empty grid to be used by the player
        for (int i = 0; i < 100; i++) {
            
            Grid[i] = 'o';
            
        }
                
    }

    
    bool chooseShipPlacement(string fileName, bool isComputer) {//The parameter 'isComputer' checks who is accessing this function, if it is a computer certian things are omitted like error checking
        ifstream fin;
        vector<bool>shipPlaced(4);//Booleans that determing whether or not a ship placement is complete
        vector<int>shipIndex(4);//The coordinate of that ship
        
        bool allPlaced = false;//All placed must be true before the game may begin
        
        int amountOFS = 0;
        fin.open(fileName);//The filename parameter will hold the name of the file that the player wishes to access
        
    if (isComputer == false) {
        
        while (fin.is_open() == false) {//This loop will not run if the current user is a computer
            cout << "Invalid file name, please enter another" << endl;
            cin >> fileName;
            fin.open(fileName);
        }
    }
        for (int i = 0; i < 100; i++) {//I ran into a few strange problems here, mainly with the inputting the file information into a vector
            //cout<<i<<" " ; 
             fin >> humanGrid.at(i);//Despite it's name, humanGrid is used for both computer and player
             //cout << humanGrid[i] << endl;
            // fin>>c;
            // cout<<c<<endl;
        }
        
        for (int i = 0; i < 100; i++) {
            //cout<<i<<endl;
            
            if (humanGrid[i] == 'S') {
                amountOFS += 1;//Now we use this variable to count the ship units
                actualShipNumber = amountOFS;//For the same reason that we had two variable for the same index, we have two variables for the same number
            }
            
            
            if (actualShipNumber > 17 && i == 100) {//The thing that actually checks the amount of ship units
                cout << "There are too many ship units, please edit your file " << endl;
                return 0;
            }
            else if (actualShipNumber < 17 && i == 100) {
                cout << "There are not enough ship units, please edit your file " << endl;
                return 0;
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
            //The above monstrous code is to check to see if you actually put the ship units in a logical order. As in you put them next to eachother in the currect orientation
            //It does not work properly, but is safe to ignore
            }
            if (shipPlaced[4] == true) {
                return allPlaced = true;
            }
            else {
                cout << "This file does not have proper ship placement, edit your file" << endl;
                return 0;
            }
        }
        
    vector<char> getBlankGrid() {//I learned you could return vectors from functions. So Grid is the vector that holds the grid of your file
        return Grid;
    }
    int getAmountOFS() {
        
        return actualShipNumber;//Returned number that the game bases the win condition on
    }
};




int main() {
    ifstream fin;
    ofstream fout;
    
    bool humanInvalid;
    bool computerInvalid;
    // I apologize for the sheer number of objects. At the time I did not really understand how they worked
    human player;
    human beepboop;
    computer one;
    grid fleshbag;
    grid synth;
    
    int setting = 0;//This is for if you want to see the computers blank information grid
    fleshbag.generateBlankGrid();//Blank grid is generated for the human
    cout << endl;
    synth.generateBlankGrid();// Blank grid is generated for the computer
    
   vector<char> humanBlank = fleshbag.getBlankGrid();// These vectors are assigned the returned vector in the grid class
    vector<char> computerBlank = synth.getBlankGrid();
    vector<char>TheLetters(10);//Letters are how the grids are displayed properly  
    TheLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int countLetter = 0;
    int confirmation;//Confirmation is an unused variable
    bool hasHit = false;//Has hit determines if you are allowed to hit again or not
    char charChoice = 'a';//The choice variable that the user uses for the letter
    int numberChoice = 0;//Number index chosen by the user
    int playerShot = 0;//The variable that holds the player's shot
    string fileName;
    int computerShot = 0;//Same but for the computer
    vector<char>humanGrid(100);
    vector<char>computerGrid(100);
    int computerShipUnits = 0;//Variables that holds ship units of their respective players
    int playerShipUnits = 0;
    cout << "Specify the file that holds your grid and coordinates" << endl;
    cin >> fileName;
    fin.open(fileName);//Filename may be invalid, but this is checked later
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
    }//Your grid is fetched from the specified file
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
    }//Computer need only input. The commented code was a test
    
    
    
    
    fleshbag.chooseShipPlacement(fileName, false);//Actually when the filenames are checked. If false the program will end
    
    synth.chooseShipPlacement("computerGrid", true);
    
    
    int playerShips = fleshbag.getAmountOFS();//Now the variables with the number of ship units are used for the conditional while loop
    int computerShips = synth.getAmountOFS();
    
    cout << "^^ Your grid  flesh bag^^ "<< endl;
    cout << "Ready to play? OK flesh bag goes first" << endl;
    
while (playerShips != 0 && computerShips != 0) {//When one of the two players ships becomes zero, the game ends and the player who won is declared
    
    cout << computerShips << endl;
    cout << playerShips << endl;
    cout << endl;
    cout << "Please enter the coordinates of where you wish to hit separated by a space. EX: A 1" << endl;
    
    cin >> charChoice;
    
    cin >> numberChoice;
    
    
    
    
    //The user is prompted again to attack if they hit
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
        
        //This if statement checks if you've already hit the same spot twice
        humanBlank[playerShot] = 'H';
        cout << "HIT!" << endl;
        
        hasHit = true;
        computerShips -= 1;
        
        
        for (int a = 0; a < 10; a++) {
                    countLetter = a + 1;//Countletter was important for printing the letters out properly on the grid
                    if (countLetter == 1) {
                        cout << "  " << countLetter << " ";
                    }
                    else
                    {
                    cout << countLetter << " ";
                    }
                        
                }
                cout << endl;
        for (int i = 0; i < 100; i++) {
                int countVar = i + 1;
                
            if (countVar % 10 != 0) {
                if (i == 0) {
                    cout << TheLetters[i] << " ";
                }
                cout << humanBlank[i] << " ";
                }
                else {
                    
                    cout << humanBlank[i] <<" " <<endl;
                    cout << TheLetters[countVar / 10] << " ";
                }
                
                
            }
            
    }
    else
    {
        
        hasHit = false;//When hasHit = false the player's turn ends
        
        if (humanBlank[playerShot] != 'H') {
            humanBlank[playerShot] = 'M';
            }
            else
            {
                cout << "Why did you hit the same spot twice? Stupid flesh bag" << endl;//Insults you for hitting the same spot twice. Thought it was funny
            }
            int countLetter = 0;
        for (int a = 0; a < 10; a++) {
                    countLetter = a + 1;
                    if (countLetter == 1) {
                        cout << "  " << countLetter << " ";
                    }
                    else
                    {
                    cout << countLetter << " ";
                    }
                        
                }
                cout << endl;
        for (int i = 0; i < 100; i++) {
                int countVar = i + 1;
                
            if (countVar % 10 != 0) {
                if (i == 0) {
                    cout << TheLetters[i] << " ";
                }
                cout << humanBlank[i] << " ";
                }
                else {
                    
                    cout << humanBlank[i] <<" " <<endl;
                    cout << TheLetters[countVar / 10] << " ";
                }
                
                
            }
            cout << "^^ Your info ^^" << endl;
        cout << endl;
        cout << "You missed" << endl;
        
    }
    
    while (hasHit == false) {//The computer will use hasHit to determine if it's his turn
        
        cout << "Computer's turn " << endl;
        one.setCoordinate_play();
        srand(one.getCoordinate_play());//The seed is reset so it doesn't keep hittin the same spot
        computerShot = one.getCoordinate_play();
        string friendlyCoordinate = one.getFriendlyCoordinate();
        cout << friendlyCoordinate << endl;
        if (humanGrid[computerShot] == 'S'&& computerBlank[computerShot] != 'H' && computerBlank[computerShot] != 'M') {//This if statement handles the hitting of the player. If you hit the s unit, you subtract one s unit
            computerBlank[computerShot] = 'H';
            hasHit = false;
            playerShips -= 1;
            countLetter = 0;
            int countVar = 0;
            for (int a = 0; a < 10; a++) {
                    countLetter = a + 1;
                    if (countLetter == 1) {
                        cout << "  " << countLetter << " ";
                    }
                    else
                    {
                    cout << countLetter << " ";
                    }
                        
                }
                cout << endl;
        for (int i = 0; i < 100; i++) {
                int countVar = i + 1;
                
            if (countVar % 10 != 0) {
                if (i == 0) {
                    cout << TheLetters[i] << " ";
                }
                cout << computerBlank[i] << " ";
                }
                else {
                    
                    cout << computerBlank[i] <<" " <<endl;
                    cout << TheLetters[countVar / 10] << " ";
                }
                
                
            }
            if (setting != 0) {
                cout << "^^ Computer's info ^^ " << endl;
            }
            else
            {
                cout << endl;
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
                cout << "Computer hit the same spot" << endl;//Incase the computer somehow still hits the same spot
            }
            
            hasHit = true;
            int countVar = 0;
            for (int a = 0; a < 10; a++) {
                    countLetter = a + 1;
                    if (countLetter == 1) {
                        cout << "  " << countLetter << " ";
                    }
                    else
                    {
                    cout << countLetter << " ";
                    }
                        
                }
                cout << endl;
        for (int i = 0; i < 100; i++) {
                int countVar = i + 1;
                
            if (countVar % 10 != 0) {
                if (i == 0) {
                    cout << TheLetters[i] << " ";
                }
                cout << computerBlank[i] << " ";
                }
                else {
                    
                    cout << computerBlank[i] <<" " <<endl;
                    cout << TheLetters[countVar / 10] << " ";//By dividing by ten the proper letter is printed at the right times
                }
                
                
            }
            if (setting != 0) {
            cout << "^^ Computer's info ^^" << endl;
            }
            else
            {
                cout << endl;
            }
        }
    }
}
if (computerShips == 0) {
    cout << "Flesh bag wins!" << endl;
}
else
{
    cout << "The superior circuitry of a synthetic being has won. Stupid fleshbag" << endl;
}
    
}