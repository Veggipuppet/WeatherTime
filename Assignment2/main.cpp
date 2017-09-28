#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>

#include "Weather.h"
#include "Data.h"


using namespace std;

void option1(Weather * wp);
void option2(Weather * wp);
void option3(Weather * wp);
void option4(Weather * wp);
void option5(Weather * wp);
void maxx(Data & da);
int monthcheck(string months);
int yearcheck(string years);
int dayCheck(string day);

string month[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

int main()
{
    char input = 'Z';
    string tempstring;
    string fileName;
    string tempFileName;

    Weather W;

    ifstream infile1 ("data/met_index.txt");
    if(!infile1) return -1;

    while(!infile1.eof())
    {
        getline(infile1,fileName);
        tempFileName = "data/"+fileName;
        cout << "Loading file:" << fileName << endl;
        ifstream infile( tempFileName.c_str() );
        if( !infile ) return -1;

        infile >> W;
    }
    cout << "All files loaded" << endl;
    system("PAUSE");
    system("CLS");


    //cin >> input;
    while(input != 'q')
    {
        cout << "||| Weather Time |||\n\nEnter 'q' to exit at any time." << endl;
        cout << "Please enter the Letter for the option that you require:"<< endl<< endl;
        cout << "\t A: Max Wind Speed for a month."<< endl;
        cout << "\t B: Average Wind Speed per month in a year."<< endl;
        cout << "\t C: Total Solar Radiation per month in a year."<< endl;
        cout << "\t D: Average Wind Speed and total solar radiation."<< endl;
        cout << "\t E: Highest Solar Radiation for a date"<< endl;
        cin >> tempstring;
        if(tempstring.length() >1)
        {
            input = 'Z';
        }
        else
        {
            input = tempstring[0];
        }
        //cout << "string size: " <<input.size() << endl;
        switch(input)
        {
            case 'A':
            case 'a':
                option1(&W);
                break;
            case 'B':
            case 'b':
                option2(&W);
                break;
            case 'C':
            case 'c':
                option3(&W);
                break;
            case 'D':
            case 'd':
                option4(&W);
                break;
            case 'E':
            case 'e':
                option5(&W);
                break;
            case 'q':
                break;
            default:
                cout << "The value entered did not match any of the options." << endl;
        }
        system("CLS");

    }

    return 0;
}
float maxWSpeed;

void maxx(Data & da)
{
    if(maxWSpeed < da.GetWindSpeed())
    {
        maxWSpeed = da.GetWindSpeed();
        //cout << x << " ";
    }
}
///max speed
void option1(Weather * wp)
{
    int month=0, year=0;
    maxWSpeed = 0;
    string temp;

    cin.clear();
    cout << "you chose option A" << endl;

    while(month == 0)
    {
        cout << "Please enter a month in numbers (mm) : ";
        cin >> temp;
        month = monthcheck(temp);
        if(month ==0)
        {
            cout << "Incorrect entry." << endl;
        }
    }

    while(year ==0)
    {
        cout << "Please enter a year in numbers (yyyy): ";
        cin >> temp;
        year = yearcheck(temp);
        if(year ==0)
        {
            cout << "Incorrect entry." << endl;
        }
    }

    wp->MaxWindSpeed(month,year,maxx);

    if(maxWSpeed<=0)
    {
        cout<< "\t No data available for this month" << endl;
    }
    else
    {
        cout<< "\tMax Wind Speed= " << maxWSpeed << endl;
    }

    system("PAUSE");
    cout << "\n \n";

}

void option2(Weather * wp)
{
    int year=0;
    float tempAvWSpeed[12];
    string temp;
    cout << "you chose option B" << endl;


    while(year ==0)
    {
        cout << "Please enter a year in numbers (yyyy): ";
        cin >> temp;
        year = yearcheck(temp);
        if(year ==0)
        {
            cout << "Incorrect entry." << endl;
        }
    }

    wp->AverageWindSpeed(tempAvWSpeed,year);

    cout << "The average wind speed for " << year << " per month is:" <<endl << endl;
    for(int i=0;i<12;i++)
    {
        if(tempAvWSpeed[i]==0)
        {
            cout<< "\t" << month[i] <<": "<< "No data available for this month" << endl;
        }
        else
        {
            cout<< "\t" << month[i] <<": "<< tempAvWSpeed[i] << endl;
        }
    }


    system("PAUSE");
    cout << "\n \n";

}

void option3(Weather * wp)
{
    int year=0;
    float TotSolarRad[12];
    string temp;
    cout << "you chose option C" << endl;

    while(year ==0)
    {
        cout << "Please enter a year in numbers (yyyy): ";
        cin >> temp;
        year = yearcheck(temp);
        if(year ==0)
        {
            cout << "Incorrect entry." << endl;
        }
    }
    wp->TotalSolarRadiation(TotSolarRad,year);
    cout << "Total Solar radiation in " << year << " per month is:" <<endl << endl;
    for(int i=0;i<12;i++)
    {
        if(TotSolarRad[i]==0)
        {
            cout<< "\t" << month[i] <<": "<< "No data available for this month" << endl;
        }
        else
        {
            cout<< "\t" << month[i] <<": "<< TotSolarRad[i] << endl;
        }
    }


    system("PAUSE");
    cout << "\n \n";

}

void option4(Weather * wp)
{
    int year=0;
    float TotSolarRad[12], AvWindSpeed[12];
    string temp;
    cout << "you chose option D" << endl;

    while(year ==0)
    {
        cout << "Please enter a year in numbers (yyyy): ";
        cin >> temp;
        year = yearcheck(temp);
        if(year ==0)
        {
            cout << "Incorrect entry." << endl;
        }
    }

    ofstream ofile( "WindandSolar.csv" );

    ofile << year << "\n";
    wp->TotalSolarRadiation(TotSolarRad,year);
    wp->AverageWindSpeed(AvWindSpeed,year);

    for(int i=0;i<12;i++)
    {
        if(TotSolarRad[i] != 0)
        {
            if((AvWindSpeed[i] !=0))
            {
                ofile << month[i] << "," << AvWindSpeed[i] << "," << TotSolarRad[i] << "\n";
            }
        }
    }

    system("PAUSE");
    cout << "\n \n";

}

void option5(Weather * wp)
{
    int day =0, year=0, month=0;
    float SolarRad;
    string temp;
    vector<int> intVector;

    cout << "you chose option E" << endl;

    while(day == 0)
    {
        cout << "Please enter a day in numbers (dd) : ";
        cin >> temp;
        day = dayCheck(temp);
        if(day ==0)
        {
            cout << "Incorrect entry." << endl;
        }
    }

    while(month == 0)
    {
        cout << "Please enter a month in numbers (mm) : ";
        cin >> temp;
        month = monthcheck(temp);
        if(month ==0)
        {
            cout << "Incorrect entry." << endl;
        }
    }

    while(year ==0)
    {
        cout << "Please enter a year in numbers (yyyy): ";
        cin >> temp;
        year = yearcheck(temp);
        if(year ==0)
        {
            cout << "Incorrect entry." << endl;
        }
    }

    cout << "Date: "<< day << "/" << month << "/" << year << endl;
    SolarRad = wp->MaxSolarRadiation(day, month, year, &intVector);
    if(SolarRad !=0)
    {
        cout << "High solar radiation for the day: " << SolarRad << " W/m2" << endl;
        cout<< "Time:" << endl;
        for(unsigned i=0; i<intVector.size(); i++)
        {
            cout<< intVector.at(i) << ":";
            i++;
            cout<< intVector.at(i) << endl;
        }
    }
    else
    {
        cout << "No data available for this day." << endl;
    }

    system("PAUSE");
}

int dayCheck(string day)
{
    int dy=0;

    if(day.length()==   1)
    {
        if(isdigit(day[0]))
        {
            dy = atoi(day.c_str());
        }
    }
    else if(day.length()==2)
    {
        if(isdigit(day[0]) && isdigit(day[1]))
        {
            dy = atoi(day.c_str());
        }
    }
    else
    {
        dy = 0;
    }

    if(dy>31 || dy<0)
    {
        dy = 0;
    }
    return dy;
}

int monthcheck(string months)
{
    int mon=0;

    if(months.length()==1)
    {
        if(isdigit(months[0]))
        {
            mon = atoi(months.c_str());
        }
    }
    else if(months.length()==2)
    {
        if(isdigit(months[0]) && isdigit(months[1]))
        {
            mon = atoi(months.c_str());
        }
    }
    else
    {
        mon = 0;
    }

    if(mon>12 || mon<0)
    {
        mon = 0;
    }
    return mon;
}

int yearcheck(string years)
{
    int yr=0;

    if(years.length() >4)
    {
        yr = 0;
    }
    else
    {
        if(isdigit(years[0]) && isdigit(years[1]) && isdigit(years[2]) && isdigit(years[3]))
        {
            yr = atoi(years.c_str());
        }
    }

    if(yr>2017 || yr<0)
    {
        yr = 0;
    }
    return yr;
}
