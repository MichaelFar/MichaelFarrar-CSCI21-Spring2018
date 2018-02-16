#include "accounts.h"

int main() {
    ofstream fout;
    ifstream fin;
    fout.open("transactions");
    fin.open("creditCards");
    int monthArray[30];
    double transactionAmount[30];
    double transactionVar = 0.0;
    int numAccounts = 0;
    int month = 0;
    int day = 0;
    int year = 0;
    int transactions = 0;
    int dayOfTheMonth = 0;
    int a = 0;
    
    
    cout << "How many accounts are there?" << endl;
    cin >> numAccounts;
    long int userCreditCard[numAccounts];
    for (int i = 0; i < numAccounts; i++)
    {
    cout << "Inputting card(s) from file" << endl;
    fin >> userCreditCard[i];
    cout << i << endl;
    CheckBIN(userCreditCard);
    
    while(isCard == false) {
        cout << "That is not a valid credit card, please enter another" << endl;
        fin >> userCreditCard[a];
        CheckBIN(userCreditCard);
    }
    cout << "How many purchases did you make this month?" << endl;
    cin >> transactions;
            for (int i = 0; i < transactions; i++) { 
                cout << "What day did you have this transaction?" << endl;
                cin >> dayOfTheMonth;
                cout << "What month did you have it?" << endl;
                cin >> month;
                cout << "What year?" << endl;
                cin >> year;
                cout << "Day " << dayOfTheMonth << ":" << "purchase" << endl;
                cin >> transactionAmount[i];
                transactionVar = transactionAmount[i];
                fout << setInput(month, dayOfTheMonth, year, numAccounts, userCreditCard, transactionVar) << endl;
            }
    a += 1;
    }
        
}
    
    

    

