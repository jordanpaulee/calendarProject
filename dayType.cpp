#include <iostream>
#include <string>

#include "dayType.h"   

using namespace std;

//private array

string dayType::weekDays[7] = {"Sunday", "Monday", "Tuesday",
                     "Wednesday", "Thursday", "Friday",
                     "Saturday"};

//public functions

void dayType::print() const{
  //prints current vale of weekDay
  cout << weekDay << endl;
}

string dayType::nextDay() const{
  //checks for value of weekDay to convert to a weekDays array value
  //adds one to index, corrects for Sunday-Saturday
  if (weekDay==weekDays[0]){
    return weekDays[1];
  }
  else if (weekDay==weekDays[1]){
    return weekDays[2];
  }
  else if (weekDay==weekDays[2]){
    return weekDays[3];
  }
  else if (weekDay==weekDays[3]){
    return weekDays[4];
  }
  else if (weekDay==weekDays[4]){
    return weekDays[5];
  }
  else if (weekDay==weekDays[5]){
    return weekDays[6];
  }
  else if (weekDay==weekDays[6]){
    return weekDays[0];
  }
  else {
    cout << "Error" << endl;
    return 0;
  }
}

string dayType::prevDay() const{
  //checks for value of weekDay to convert to a weekDays array value
  //subtracts one from index, corrects for Sunday-Saturday
  if (weekDay==weekDays[0]){
    return weekDays[6];
  }
  else if (weekDay==weekDays[1]){
    return weekDays[0];
  }
  else if (weekDay==weekDays[2]){
    return weekDays[1];
  }
  else if (weekDay==weekDays[3]){
    return weekDays[2];
  }
  else if (weekDay==weekDays[4]){
    return weekDays[3];
  }
  else if (weekDay==weekDays[5]){
    return weekDays[4];
  }
  else if (weekDay==weekDays[6]){
    return weekDays[5];
  }
  else {
    cout << "Error" << endl;
    return 0;
  }
}

void dayType::addDay(int nDays){
  int entry = nDays % 7;
  //corrects for extra weeks to get day remainder
  int currentIndex=0;
  //initializes the current index of weekDay in the weekDays array
  int tempVar=0;
  //used for passing computation
  int newIndex;
  //used as the new index for the weekDays array after computation
  
  if (weekDay==weekDays[0]){
    currentIndex = 0;
  }
  else if (weekDay==weekDays[1]){
    currentIndex = 1;
  }
  else if (weekDay==weekDays[2]){
    currentIndex = 2;
  }
  else if (weekDay==weekDays[3]){
    currentIndex = 3;
  }
  else if (weekDay==weekDays[4]){
    currentIndex = 4;
  }
  else if (weekDay==weekDays[5]){
    currentIndex = 5;
  }
  else if (weekDay==weekDays[6]){
    currentIndex = 6;
  }
  
  if(entry <= 6 - currentIndex && entry>=0){
    weekDay = weekDays[currentIndex+entry];
  }
  //corrects for values that could lead to a negative index value
  else if(entry > 6-currentIndex){
    tempVar = 7-currentIndex;
    newIndex = entry-tempVar;
    weekDay = weekDays[newIndex];
  }
  //calculates days after Saturday and re-loops the array
  else{
    cout << "Error" << endl;
  }

}

//getters and setters
void dayType::setDay(string d){
  //setting and returning values for weekDay
  if (d =="Sunday"){
    weekDay = weekDays[0];
  }
  else if (d =="Monday"){
    weekDay = weekDays[1];
  }
  else if (d =="Tuesday"){
    weekDay = weekDays[2];
  }
  else if (d =="Wednesday"){
    weekDay = weekDays[3];
  }
  else if (d =="Thursday"){
    weekDay = weekDays[4];
  }
  else if (d =="Friday"){
    weekDay = weekDays[5];
  }
  else if (d =="Saturday"){
    weekDay = weekDays[6];
  }
  else {
    cout << "Error, reinitialize" << endl;
  }
}

string dayType::getDay() const{
  return weekDay;
}

//constructor definitions
dayType::dayType(string d){
  //value verification
  if (d =="Sunday"){
    weekDay=weekDays[0];
  }
  else if (d == "Monday"){
    weekDay=weekDays[1];
  }
  else if (d == "Tuesday"){
    weekDay=weekDays[2];
  }
  else if (d == "Wednesday"){
    weekDay=weekDays[3];
  }
  else if (d == "Thursday"){
    weekDay=weekDays[4];
  }
  else if (d == "Friday"){
    weekDay=weekDays[5];
  }
  else if (d == "Saturday"){
    weekDay=weekDays[6];
  }
  else{
    cout << "Error, set to default" << endl;
    weekDay = weekDays[0];
  }
}

dayType::dayType(){
  //default constructor
  weekDay= weekDays[0];
}