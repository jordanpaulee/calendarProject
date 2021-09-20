#ifndef extDateType_H
#define extDateType_H
#include <string>
#include "dateType.h"


class extDateType: public dateType{
public:
    void printLongDate();
    void setDate(int, int, int);
    void setMonth(int);
    void printLongMonthYear();
    extDateType(int=1, int=1, int=1900);

private:
    std::string month;
    static std::string months[13];
};

#endif