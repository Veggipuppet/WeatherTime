#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <cstring>
#include <cstdlib>


using namespace std;

    /**
	 * @class Date
	 * @brief  Stores date data read into it.
	 *
	 *
	 * @author Liam Goerke
	 * @version 01
	 * @date 3/06/2017 Liam Goerke
	 */

class Date
{
    public:
        Date();
        virtual ~Date();

        /**
		 * @brief  Getter method for Day
		 *
		 * Gets the day variable
		 *
		 * @return day
        */
        int GetDay() const;

        /**
		 * @brief  Setter method for Day
		 *
		 * Sets the day variable
		 *
		 * @param da, unsigned argument
		 * @return void
        */
        void SetDay( unsigned da );

        /**
		 * @brief  Getter method for Month
		 *
		 * Gets the month variable
		 *
		 * @return month
        */
        int GetMonth() const;

        /**
		 * @brief  Setter method for month
		 *
		 * Sets the month variable
		 *
		 * @param mo, unsigned argument
		 * @return void
        */
        void SetMonth( unsigned mo );

        /**
		 * @brief  Getter method for Year
		 *
		 * Gets the Year variable
		 *
		 * @return Year
        */
        int GetYear() const;

        /**
		 * @brief  Setter method for Year
		 *
		 * Sets the Year variable
		 *
		 * @param ye, unsigned argument
		 * @return void
        */
        void SetYear( unsigned ye );

    private:
            ///day of the week(dd)
        int day;
            ///month of the year (mm)
        int month;
            ///year (yyyy)
        int year;
};

istream & operator >>( istream & input, Date & Da );

#endif // DATE_H
