#include "Data.h"

Data::Data()
{
    //ctor
}

Data::~Data()
{
    //dtor
}

int Data::GetSolarRadiation() const
{
  return SolarRadiation;
}

void Data::SetSolarRadiation( unsigned SR )
{
  SolarRadiation = SR;
}

int Data::GetWindSpeed() const
{
  return WindSpeed;
}

void Data::SetWindSpeed( unsigned WS )
{
  WindSpeed = WS;
}

const Date & Data::GetDate() const
{
  return date;
}

void Data::SetDate( const Date & Da )
{
  date = Da;
}

const Time & Data::GetTime() const
{
  return time;
}

void Data::SetTime( const Time & ti )
{
  time = ti;
}

istream & operator >>( istream & input, Data & Da )
{
    string tempString;
    static Date dates;
    static Time times;
    float windSpeed;
    float solarRadiation;


    input >> dates;
    input >> times;

    for(int i=0;i<9;i++)
    {
        getline(input,tempString,',');
    }

    getline(input,tempString,',');
    windSpeed = atof(tempString.c_str());

    getline(input,tempString,',');
    solarRadiation = atof(tempString.c_str());

    getline(input,tempString);

    Da.SetDate(dates);
    Da.SetTime(times);
    Da.SetWindSpeed(windSpeed);
    Da.SetSolarRadiation(solarRadiation);

    return input;
}

ostream& operator <<( ostream & os, Data & Da )
{
    os << Da.GetWindSpeed();

    return os;
}

bool operator <( Data & self, Data & parent )
{
    return (self.GetWindSpeed()<parent.GetWindSpeed());
}

bool operator >( Data & self, Data & parent )
{
    return (self.GetWindSpeed()>parent.GetWindSpeed());
}

