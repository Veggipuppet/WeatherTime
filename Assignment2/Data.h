#ifndef DATA_H
#define DATA_H

#include "Time.h"
#include "Date.h"

    /**
	 * @class Data
	 * @brief  Stores data and has access to date and time
	 *
	 *
	 * @author Liam Goerke
	 * @version 01
	 * @date 3/06/2017 Liam Goerke
	 */


class Data
{
    public:
        Data();
        virtual ~Data();

        /**
		 * @brief  Getter method for SolarRadiation
		 *
		 * Gets the SolarRadiation variable
		 *
		 * @return SolarRadiation
        */
        int GetSolarRadiation() const;

        /**
		 * @brief  Setter method for SolarRadiation
		 *
		 * Sets the SolarRadiation variable
		 *
		 * @param SR, unsigned argument
		 * @return void
        */
        void SetSolarRadiation( unsigned SR );

        /**
		 * @brief  Getter method for WindSpeed
		 *
		 * Gets the WindSpeed variable
		 *
		 * @return WindSpeed
        */
        int GetWindSpeed() const;

        /**
		 * @brief  Setter method for WindSpeed
		 *
		 * Sets the WindSpeed variable
		 *
		 * @param WS, unsigned argument
		 * @return void
        */
        void SetWindSpeed( unsigned WS );

        /**
		 * @brief  Getter method for a Date
		 *
		 * Gets a date object reference from the date class.
		 *
		 * @return date
        */
        const Date & GetDate() const;

        /**
		 * @brief  Setter method for a date object.
		 *
		 * Passes a date object through to create a new date object.
		 *
		 * @param Da, a const date&
		 * @return void
        */
        void SetDate(const Date & Da);

        /**
		 * @brief  Getter method for a Time object.
		 *
		 * Gets a time object reference from the Time class.
		 *
		 * @return time&
        */
        const Time & GetTime() const;

        /**
		 * @brief  Setter method for a Time object.
		 *
		 * Passes the object reference through to create a new Time object.
		 *
		 * @param ti, a const Time&
		 * @return void
        */
        void SetTime(const Time & ti);

    private:
        Date date;
        Time time;
        float SolarRadiation;
        float WindSpeed;
};

istream & operator >>( istream & input, Data & Da );
ostream& operator <<( ostream & os, Data & date );

bool operator <( Data & self, Data & parent );
bool operator >( Data & self, Data & parent );

#endif // DATA_H
