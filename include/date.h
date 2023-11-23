#ifndef DATE_H
#define DATE_H

#include <initializer_list>

/**
 * Project namespace
*/
namespace prj
{
	/**
	 * Implements a vector similar to std::vector
	*/
	class Date
	{
	private:

        /**
         * The number of days from Octorber 4 1582 (introduction of the Gregorian calendar)
        */
        unsigned long int days_;

        /**
         * True if the date is valid, false otherwise
        */
        bool isValid();


	public:

        /**
         * Construct a Date with the specified day, month and year
         * 
         * @param day Day of the Date
         * @param month Month of the Date
         * @param year Year of the Date
        */
        Date(unsigned int day, unsigned int month, unsigned int year);

        /**
		 * Construct a Date that will contain the day/month/year passed in the initializer_list
		 * 
		 * @param list A list of elements
		*/
		Date(std::initializer_list<unsigned long int> list);

        /**
		 * Copy constructor
		 * 
		 * @param date The date to copy
		*/
		Date(const Date& date);

		/**
		 * Move constructor
		 * 
		 * @param date The date to move
		*/
		Date(Date&& date);

        /**
         * True if the date is within a leaf year, false otherwise
        */
        bool isLeaf();

        /**
         * Year getter
         * @return The year of the date
        */
        unsigned int getYear();

        /**
         * Day getter
         * @return The day of the date
        */
        unsigned int getDay();

        /**
         * Month getter
         * @return The month of the date
        */
        unsigned int gedMonth();

        Date& operator=(const Date& date);
        Date& operator-(const Date& date);
        Date& operator+(const Date& date);
	};
}

#endif