#include <iostream>
#include <string>
#include <iomanip>

#include "extDateType.h"

using namespace std;

string extDateType::months[13] = {"Error; No 0 Month","January","February","March","April","May","June","July","August","September","October","November","December"};

void extDateType::printLongDate(){
  int monthInt = dateType::getMonth();
  int day = dateType::getDay();
  int year = dateType::getYear();

  string month = months[monthInt];

  cout << month << " " << day << ", " << year; 
};

void extDateType::setDate(int month, int day, int year){
  dateType::setYear(year);
  dateType::setMonth(month);
  dateType::setDay(day);
  
};

void extDateType::setMonth(int monthInt){
  if(monthInt > 0 && monthInt < 13){
    dateType::setMonth(monthInt);
    string month = months[monthInt];
    if(monthInt==2 && isLeapYear()){
      if (getDay()>29){
        setDay(1);
      }
    }
    else if(monthInt==2 && !isLeapYear()){
      if(getDay()>28){
        setDay(1);
      }
    }
  }
  else{
    dateType::setMonth(1);
    string convertMonth = months[1];
  }
  
};

int extDateType::getMonth() const{
  return dateType::getMonth();
};

int extDateType::getDay() const{
  return dateType::getDay();
};

int extDateType::getYear() const{
  return dateType::getYear();
};

void extDateType::printLongMonthYear(){
  int monthInt = dateType::getMonth();
  int year = dateType::getYear();

  cout << months[monthInt] << " " << year << endl;
};

extDateType::extDateType(int month, int day, int year){
  extDateType::setDate(month, day, year);
};