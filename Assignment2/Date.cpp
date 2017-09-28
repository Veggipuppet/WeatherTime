#include "Date.h"

Date::Date()
{
    //ctor
}

Date::~Date()
{
    //dtor
}

int Date::GetDay() const
{
  return day;
}

void Date::SetDay( unsigned da )
{
  day = da;
}

int Date::GetMonth() const
{
  return month;
}

void Date::SetMonth( unsigned mo )
{
  month = mo;
}

int Date::GetYear() const
{
  return year;
}

void Date::SetYear( unsigned ye )
{
  year = ye;
}

istream & operator >>( istream & input, Date & Da )
{
    string tempString;


    getline(input,tempString,'/');
    Da.SetDay(atoi(&tempString[0]));
    getline(input,tempString,'/');
    Da.SetMonth(atoi(tempString.c_str()));
    getline(input,tempString,' ');
    Da.SetYear(atoi(tempString.c_str()));


    return input;
}
