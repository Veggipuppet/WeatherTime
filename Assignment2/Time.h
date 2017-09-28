#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

    /**
	 * @class Time
	 * @brief  Stores the time data read in
	 *
	 *
	 * @author Liam Goerke
	 * @version 01
	 * @date 3/06/2017 Liam Goerke
	 */

class Time
{
    public:
        Time();
        virtual ~Time();

        /**
		 * @brief  Getter method for Hour
		 *
		 * Gets the Hour variable
		 *
		 * @return Hour
        */
        int GetHour() const;

        /**
		 * @brief  Setter method for Hour
		 *
		 * Sets the Hour variable
		 *
		 * @param hr, unsigned argument
		 * @return void
        */
        void SetHour( unsigned hr );

        /**
		 * @brief  Getter method for Minute
		 *
		 * Gets the Minute variable
		 *
		 * @return Minute
        */
        int GetMinute() const;

        /**
		 * @brief  Setter method for Minute
		 *
		 * Sets the Minute variable
		 *
		 * @param mn, unsigned argument
		 * @return void
        */
        void SetMinute( unsigned mn );

    private:
            ///hour of the day in 24 hour clock
        int Hour;
            ///minute of the day
        int Minute;
};

istream & operator >>( istream & input, Time & Ti );

#endif // TIME_H
