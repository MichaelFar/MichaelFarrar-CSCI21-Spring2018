/*
Michael Farrar
2/17/18
Project 1 part b
*/
#include "accounts.h"

bool isCard = true;//These global variables were necessary for keeping track of which card was which in the transaction file

bool isAmerican = false;
bool isDiscover = false;
bool isMaster = false;
bool isVisa = false;

int main() {
    
    ofstream fout;
    ifstream fin;
    
    ofstream balancesFout;
    balancesFout.open("balances");
    fin.open("creditCards");
    int monthArray[30];
    double transactionAmount[30];
    double transactionVar = 0.0;
    int numAccounts = 0;//Some of these variables are now unused, I was too afraid to delete them
    int month = 0;
    int day = 0;
    int year = 0;
    int transactions = 0;
    int dayOfTheMonth = 0;
    int a = 0;
    int currentCard = 0;
    int numMonths = 12;
    int currentYear = 0;
    int c = 0;
    int d = 0;
    double rebate = 0.0;
    double difference = 0.0;
    
    cout << "How many accounts are there?" << endl;
    cin >> numAccounts;
    cout << "What year is it?" << endl;
    cin >> currentYear;
    string accountBalance[numAccounts];
    long int userCreditCard[numAccounts];//These arrays are all parallel and are sorted into their proper spots by the for loop.
    string type[numAccounts];
    string firstName[numAccounts];
    string lastName[numAccounts];
    double balance[numAccounts];
    
    bool overCharge = false;//This is the flag that holds the result if a card is overcharged
    int numOfTransaction = 0;//Temporary variable that holds the total transaction in one month
    int i = 0;
    for (int i = 0; i < numAccounts; i++)
    {
        cout << "Inputting card from file" << endl;// The input file is used to assign values to some of the previous arrays. This is all the "Account" information
        fin >> userCreditCard[i];
        fin >> firstName[i];
        fin >> lastName[i];
        fin >> type[i];
        fin >> balance[i];
        cout << userCreditCard[i] << endl;
        
    }
    
    fout.open("transactions");
    
for (int a = 0; a < numAccounts; a++)//This program loops as long as there are accounts
{
    numOfTransaction = 0;
                    if (a == 0)//This keeps track of the account. C doesn't change until both the other two for loops are done. That represents 1 month and one account
                    {
                        c = 1;
                    }
                    else
                    {
                        c = a + 1;
                    }
        for (int b = 0; b < numMonths; b++)//The transactions are held for one year
        {
            if (b == 0)
            {
                        d = 1;//Same code as earlier, but d holds the current month.
                    }
                    else
                    {
                        d = b + 1;
                    }
                    numOfTransaction = 0;
                    
                cout << "Month " << d << endl;
                cout << "Account " << c << endl;
               
                cout << "How many purchases did you make this month?" << endl;
                cin >> transactions;//This is how many times the "transactions" loop runs. After it is done, a month has passed
                
                for (i = 0; i < transactions; i++) 
                { 
                    overCharge = false;
                    cout << "What day did you have this transaction?" << endl;
                    cin >> dayOfTheMonth;
                    cout << "Day " << dayOfTheMonth << ":" << "purchase" << endl;
                    cin >> transactionAmount[i];
                    cout << type[c - 1] << endl;//The reason this array is indexed weird is due to which variable holds which account. C holds the account number, but c is displayed as 1 not 0. So In order to access index 0 I need to subtract one. This never attempts to find an element that doesn't exist
                    while (transactionAmount[c - 1] > balance[c - 1] && type[c - 1] == "Gold")//This checks if you're trying to overcharge a gold card. If you do, it does not let complete the purchase
                    {
                        cout << "That purchase attempt exceeds the balance of your account" << endl << "Please enter a valid charge or enter 0 for no charge" << endl;
                        cin >> transactionAmount[i];
                    }
                    //The balance of the current purchaser is balance[c - 1]
                    //type[c - 1] is the type of card that the account has. As in one of the three 'tiers' of card
                    while (type[c - 1] == "Platinum" && transactionAmount[i] > balance[c - 1] + 1000){
                        cout << "That purchase attempt exceeds the overcharge limit on your account" << endl << "Please enter a valid charge or enter 0 for no charge" << endl;
                        cin >> transactionAmount[i];//You must reenter a purchase amount until it no longer overcharges
                    }
                    //This line  |  is the conditional statement that determines if you are allowed to overcharge or not. It checks type then the rules for that type
                    //           v
                        if (type[c - 1] == "Platinum" && transactionAmount[i] <= balance[c - 1] + 1000 && transactionAmount[i] > balance[c - 1] || type[c - 1] == "Corporate" && transactionAmount[i] <= balance[c - 1] + 5000 && transactionAmount[i] > balance[c - 1] ){
                            overCharge = true;
                        }
                        else
                        {
                            overCharge = false;
                        }
                    numOfTransaction += transactionAmount[i];// numOfTransaction is the total amount of money spent in one month
                    if (type[c - 1] == "Gold") {// These are the different rebate values
                        rebate = numOfTransaction * 0.01;
                    }
                    else if (type[c - 1] == "Platinum") {
                        rebate = numOfTransaction * 0.02;
                    }
                    else if (type[c - 1] == "Corporate") {
                        rebate = numOfTransaction * 0.05;
                    }
                    
                    transactionVar = transactionAmount[i];
                    balance[c - 1] = balance[c - 1] - transactionVar;//This is the final balance calculator 
                }
                balance[i] += rebate;// This is balance plus rebate
                difference = balance[i] - numOfTransaction;// Monthly expense
                cout << "This month's expense :" << difference << endl;
                if (overCharge == true)  {//This outputs to the file with an additional flag if overcharged
                    
                fout << transactionInput(d, dayOfTheMonth, currentYear, numAccounts, userCreditCard, transactionVar, a, CheckBIN(userCreditCard, numAccounts, a), type) << " : IS OVERCHARGED" <<endl;
                overCharge == false;
                    
                }
                else
                {
                    fout << transactionInput(d, dayOfTheMonth, currentYear, numAccounts, userCreditCard, transactionVar, a, CheckBIN(userCreditCard, numAccounts, a), type) << endl;
                }
                balancesFout << balance[a] << endl;
        } 
    }
}