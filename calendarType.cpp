#include <iostream>
#include <string>
#include <iomanip>

#include "calendarType.h"

using namespace std;

void calendarType::setMonth(int month){
  extDateType::setMonth(month);
}

void calendarType::setYear(int year){
  dateType::setYear(year);
}

int calendarType::getMonth() const{
  return dateType::getMonth();
}

int calendarType::getYear() const{
  return dateType::getYear();
}

void calendarType::printCalendar(){
  //calendarType::firstDayOfMonth();
  //DEVLEOPING
  calendarType::printDates();
}


calendarType::calendarType(int month, int year){
    dateType::setMonth(month);
    dateType::setYear(year);
    dateType::setDay(1);
};


//private functions

dayType calendarType::firstDayOfMonth(){
  //USING TOMOHIKO SAKAMOTOS ALGORITHIM
  int y = dateType::getYear();
  int m = dateType::getMonth();
  int d = dateType::getDay();
  if (m < 3){
      y -= 1;
  }
  int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
   // array with leading number of days values for each month  

  int dayOfWeek = ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7);
  dayType::addDay(dayOfWeek);
  
  string day = dayType::getDay();
  //cout << dayType::getDay();
  return day;
}

void calendarType::printTitle(){
  cout << setw(10);
  extDateType::printLongMonthYear();
}

void calendarType::printDates(){
  //arrays cause I'm honestly tired and don't want to dig through more headerfiles to see if I could simplify this process. 
  //I understand theres probably a more optimal way to do this but functionality + mental health > optimization + insanity haha

  string weekDays[7] = {"Sunday", "Monday", "Tuesday",
                    "Wednesday", "Thursday", "Friday",
                    "Saturday"};

  string shortDay[7] = {"Sun", "Mon", "Tue",
                    "Wed", "Thu", "Fri",
                    "Sat"};
  

  int month = calendarType::getMonth();
  int daysInMonth = dateType::getDaysInMonth();

  int remainingDays=0;

  calendarType::firstDayOfMonth();
  /*
  I cannot figure out for the life of me how to use this in any meaningful way besides just setting
  the day to the correct one. The return value being a dayTypes cannot be used to find the start in 
  a loop unless I made a whole different arry with dayType days of the week. So I'm just going to 
  bypass it intirely to save time and headaches. Works better as a void funct in this case.
  */
  
  string firstDay = dayType::getDay();
  //cout << firstDay << "\n";
  
  cout << "\n";
  extDateType::printLongMonthYear();
  
  for(int i=0; i<7; i++){
    cout << setw(7) << shortDay[i] << " ";
  }
  cout << "\n";

  for (int i=0; i<7; i++){
    if(firstDay == weekDays[i]){
      remainingDays = i-1;
      //cout << remainingDays << endl; 
      break;
    }
  }

  int day = 1;
  int weekDay = 0;

  while(day <= daysInMonth){
    while(remainingDays>0){
      cout << setw(8)<< "   ";
      remainingDays--;
      weekDay++;
    }
    cout << setw(7) << day << " ";
    if (weekDay == 6){
      cout << "\n";
      weekDay=0;
      day++;
    }
    else{
      weekDay++;
      day++;
    }
  }

  

}