 #include <iostream>
#include <string>
#include <iomanip>


#include "calendarType.h"

using namespace std;

int main() 
{
 int month = 1;
 int year = 1900;
 
 string userInput = "y";

 calendarType date;

while(userInput == "y"){
  //cout << date1.getMonth() << endl << date1.getYear() << endl;
  cout << "Enter a month (as an integer bewteen 1 and 12): ";
  cin >> month;
  cout << "Enter a year (as a 4-digit integer >=1900): ";
  cin >> year;
  cout<< "\n";
  
  date.setMonth(1);
  date.setYear(1900);
  //reinitializes to correct an error where loop was causing the data to get thrown off.

  date.setMonth(month);
  date.setYear(year);
    
  //cout << date1.getMonth() << endl << date1.getYear();
  date.printCalendar();

  cout << "\n" << "\n" << "Print another calendar(y or n)? ";
  cin >> userInput;

  if(userInput == "y"){
    userInput="y";
    }
  else if (userInput=="n"){
    break;
    }
  else{
    cout << "invlaid input, error";
    break;
    }
  };
}