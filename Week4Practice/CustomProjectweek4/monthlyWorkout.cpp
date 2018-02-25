#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;



int main() {
  stringstream filedataSS;
  string yourFile;
  ofstream fout;
  ifstream fin("fileNames");
  bool isFound = false;
  string answer = "y";
  int numWeeks = 0;
  int a = 0;
  int numDays = numWeeks * 7;
  string excercises[1024];
  string files[1024];
  string exercise = "hello";
  int i = 0;
  for (int i = 0; !fin.eof(); i++) 
    {
      fin >> files[i];
      cout << files[i] << endl;
    }
      
      
  cout << "Would you like to make a new routine? y/n" << endl;
  cin >> answer;
  if (answer == "y") {
  cout << "How many weeks will this workout last?" << endl;
  
  

    
  cin >> numWeeks;
  int numDays = numWeeks * 7;
  cout << "Let's plan this week's workout" << endl;
  cout << "What is the name of the routine? If this routine already exists it will be overridden" << endl;
  
  cin >> yourFile;
  
  yourFile = yourFile + ".txt";
  
  fout.open("fileNames");
  fout << yourFile;
  fout.close();
  fout.open(yourFile.c_str());
      for (int i = 0; i < numDays; i++)
      {
          int day = i + 1;
          cout << "What exercise will you do on day " << day <<"?"<<endl;
          cin >> exercise;
          fout << "Day " << day << " " <<exercise << endl;
          
      }
  }
  else
  {
      cout << "Which routine do you want to see?" << endl;
      cin >> answer;
      for (int i = 0; i < fin.eof(); i++) 
      {
          cout << "Hello" << endl;
          if (answer == files[i]) 
          {
            isFound = true;
            cout << files[i] <<" has been found" << endl;
            a = i;
            
          }
          else
          {
              cout << "File not found" << endl;
          }
          ifstream savedFile(files[a]);
         if (isFound == true)
      {
          
          ifstream savedFile(files[a]);
          
          for (int i = 0; i < savedFile.eof(); i++)
          {
            cout << "Hello" << endl;
            savedFile >> excercises[i];
            filedataSS << excercises[i];
            excercises[i] = filedataSS.str();
            cout << excercises[i];
          }
          for (int i = 0; i < numDays; i++){
            cout << excercises[i] << endl;
          }
      } 
      }
           
  }
}