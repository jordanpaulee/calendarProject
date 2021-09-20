#ifndef H_dayType
#define H_dayType
  
#include <string>
  
using namespace std;

/* dayType keeps track of a day of the week 
   and provides the following services:
   Set the day. 
   Print the day.
   Return the day. 
   Return the next day. 
   Return the previous day.
   Calculate and return the day by adding certain days to the current day.
*/

class dayType
{
public:
    void print() const;
    //Post condition - displays value of weekDay
    string nextDay() const;
    //Post condition - returns the next day (does not change weekDay)
    string prevDay() const;
    //Post condition - returns the previous day (does not change weekDay)
    void addDay(int nDays);
    //Precondition - nDays must be positive
    //Post condition - Changes the value of weekDay

    //Getters and setters
    void setDay(string d);
    string getDay() const;

    //Constructors
    dayType();
    dayType(string d);
    //Precondition - d must be one of Sun, Mon, Tue, Wed, Thu, Fri, Sat

private:
    string weekDay;
    static string weekDays[7];
};

#endif
