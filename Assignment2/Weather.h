#ifndef WEATHER_H
#define WEATHER_H

#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include "Data.h"
#include "binaryTreeType.h"

     /**
	 * @class Weather
	 * @brief  Stores data into structures, retrieves the relevant information and carries out simple calculations
	 *
	 *
	 * @author Liam Goerke
	 * @version 01
	 * @date 3/06/2017 Liam Goerke
	 */

typedef map<int,map< int,vector<Data> > > CustomMap;
//typedef map< int,Vector<Data> > month;
//typedef Vector<Data> datavect;


class Weather
{
    public:
        Weather();
        virtual ~Weather();

            /**
             * @brief  Getter method for count
             *
             * Gets the count variable
             *
             * @return count
            */
        int GetCount() const;
            /**
             * @brief  Setter method for count
             *
             * Sets the count variable
             *
             * @param ct an unsigned argument
             * @return void
            */
        void SetCount( unsigned ct );

            /**
            *@brief Data object getter function
            *
            * Return the object Data from within the template array Array by a specified location count.
            *
            *@param count an unsigned argument
            *@return const Data&
            */
        const Data& GetData(unsigned count) const;

            /**
            *@brief Setter function for the data
            *
            * Enters data objects into the template array Array
            *
            *@param count an unsigned argument, Dd a const Data &
            *@return void
            */
        void SetData(const Data& Da, unsigned count);

            /**
             * @brief  Gets the max wind speed for a given month and year.
             *
             * Fills a binary search tree with data for a month and calculates the max wind speed for that month from the tree.
             *
             * @param int month, the given month. int year, the given year, void maxx(Data 7 da), a function pointer for the binary tree.
             * @return maxWSpeed
            */
        void MaxWindSpeed( int month, int year, void maxx(Data & da));

            /**
             * @brief  Gets the Average wind speed for every month in a year.
             *
             * Calculates the average wind speed for every month of the year.
             *
             * @param float AvWindSpeed[], int year, an array for the average wind speed, the given year.
             * @return AveWSpeed
            */
        void AverageWindSpeed( float AvWindSpeed[], int year);

            /**
             * @brief  Gets the Total solar radiation for every month in a year.
             *
             * Calculates the Total solar radiation for every month in the year.
             *
             * @param float TotSolarRad[], int year, an array for total solar radiation,  the given year.
             * @return void
            */
        void TotalSolarRadiation( float TotSolarRad[], int year);

            /**
             * @brief  Gets the maximum solar radiation for a specific date
             *
             * Locates the given day, month and year and calculates the Total solar radiation for that month.
             *
             * @param int day, int month, int year, vector<int>* VectorInt. The given day, month, year and an integer vector.
             * @return MaxSolarRad
            */
        float MaxSolarRadiation( int day, int month, int year, vector<int>* VectorInt);


    private:

        unsigned count;
        CustomMap YearDateMap;

        //int year, month;
};

istream & operator >>( istream & input, Weather & W );

#endif // WEATHER_H
