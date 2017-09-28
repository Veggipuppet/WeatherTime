#include "Time.h"

Time::Time()
{
    //ctor
}

Time::~Time()
{
    //dtor
}

int Time::GetHour() const
{
  return Hour;
}

void Time::SetHour( unsigned hr )
{
    Hour = hr;
}

int Time::GetMinute() const
{
  return Minute;
}

void Time::SetMinute( unsigned mn )
{
  Minute = mn;
}

istream & operator >>( istream & input, Time & Ti )
{
    string tempString;
    unsigned hour;
    unsigned minute;

    getline(input,tempString,':');
    hour = atoi(tempString.c_str());
    getline(input,tempString,',');
    minute = atoi(tempString.c_str());

    Ti.SetHour(hour);
    Ti.SetMinute(minute);

    return input;
}
