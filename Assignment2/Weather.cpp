#include "Weather.h"

Weather::Weather()
{
    count = 0;
}

Weather::~Weather()
{
    //dtor
}

int Weather::GetCount() const
{
  return count;
}

void Weather::SetCount( unsigned ct )
{
  count = ct;
}

const Data& Weather::GetData(unsigned count) const
{
    //return Array.retrieveAt(count);
}

void Weather::SetData(const Data& Da, unsigned count)
{
    YearDateMap[Da.GetDate().GetYear()][Da.GetDate().GetMonth()].push_back(Da);

    //Array.insertEnd(Da);
}


void Weather::MaxWindSpeed( int month, int year, void maxx(Data & da))
{
    //maxWSpeed = 0;
    binaryTreeType<Data> DataTree;

    for(unsigned j=0; j <YearDateMap[year][month].size(); j++)
    {
            DataTree.insert(YearDateMap[year][month].at(j));
    }


    DataTree.inorderTraversal( maxx);
    //DataTree.preorderTraversal();

}

void Weather::AverageWindSpeed(float tempAvWSpeed[], int year)
{
    float AveWSpeed;
    int counter;

    for(int i=0; i<12; i++)
    {
        AveWSpeed = 0;
        counter = 0;
        for(unsigned j=0; j <YearDateMap[year][i+1].size(); j++)
        {
            AveWSpeed = AveWSpeed + YearDateMap[year][i+1].at(j).GetWindSpeed();
            counter++;
        }
        if(counter != 0)
        {
            tempAvWSpeed[i] = (AveWSpeed/counter);
        }
        else
        {
            tempAvWSpeed[i] = 0;
        }
    }

}

void Weather::TotalSolarRadiation(float TotSolarRad[], int year)
{
    float TSR = 0;

    for(int i=0; i<12; i++)
    {
        TSR = 0;
        for(unsigned j=0; j <YearDateMap[year][i+1].size(); j++)
        {
            if(YearDateMap[year][i+1].at(j).GetSolarRadiation()>80)
            {
                TSR = TSR + YearDateMap[year][i+1].at(j).GetSolarRadiation();
            }

        }
        if(TSR != 0)
        {
            TSR = (TSR/6000);
            TotSolarRad[i] = TSR;
        }
        else
        {
            TotSolarRad[i] = 0;
        }
    }


}

float Weather::MaxSolarRadiation( int day, int month, int year, vector<int>* VectorInt)
{
    float MaxSolarRad=0;

    for(unsigned j=0; j <YearDateMap[year][month].size(); j++)
    {

        if(day == YearDateMap[year][month].at(j).GetDate().GetDay())
        {

            if(MaxSolarRad < YearDateMap[year][month].at(j).GetSolarRadiation())
            {
                MaxSolarRad = YearDateMap[year][month].at(j).GetSolarRadiation();


            }
        }
    }

    for(unsigned j=0; j <YearDateMap[year][month].size(); j++)
    {
        if(YearDateMap[year][month].at(j).GetDate().GetDay() == day)
        {
            if(MaxSolarRad == YearDateMap[year][month].at(j).GetSolarRadiation())
            {
                VectorInt->push_back(YearDateMap[year][month].at(j).GetTime().GetHour());
                VectorInt->push_back(YearDateMap[year][month].at(j).GetTime().GetMinute());

            }
        }
    }

    return MaxSolarRad;
}


istream & operator >>( istream & input, Weather & W )
{
    string tempString;
    static Data Dataobj;
    unsigned count = W.GetCount();

    getline(input,tempString);

    while(!input.eof())
    {
        input >> Dataobj;
        W.SetData(Dataobj, count);
        count++;
        W.SetCount(count);
    }

    return input;
}
