#ifndef calendarType_H
#define calendarType_H

#include <string>

#include "dayType.h"
#include "dateType.h"
#include "extDateType.h"


class calendarType: public dayType, public extDateType {
  public:
      //public functions
      void setMonth(int);
      //preconditions: month must be between 1-12
      //postconditions: month is set to int
      void setYear(int);
      //preconditions:year is greater than 1900
      //postcondtions: year is set to int
      int getMonth() const;
      //postconditions: returns month
      int getYear() const;
      //postconditions: returns year
      void printCalendar();
      //postconditions: prints a calendar using private functions
      calendarType(int=1, int= 1900); //default constructor with arguments
  private:
      //private functions
      dayType firstDayOfMonth();
      //postconditions: determines the first day of the month for a given year
      void printTitle();
      //postconditions: outputs the extDateType::printLongMonthYear for the given month and year to head calendar
      void printDates();
      //preconditions: firstDayOfMonth has to be called first in sequence.
      //postconditions: outputs a calendar starting at the correct day of the month and ending on the correct day of the month
      
      //private variables
      extDateType firstDate();
      dayType firstDay();
};

#endif