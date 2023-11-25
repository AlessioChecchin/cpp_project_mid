#ifndef DATE_H_
#define DATE_H_

#include <chrono>
#include <ctime>

/**
 * Project namespace
*/
namespace prj
{
	/**
	 * Implements a Date
	*/
	class Date
	{

	public:

		/**
		 * Construct a default date with value 01/01/1900
		*/
		Date();

		/**
		 * Construct a Date with the specified day, month and year
		 * 
		 * @param day Day of the Date
		 * @param month Month of the Date
		 * @param year Year of the Date
		*/
		Date(int day, int month, int year);

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
		 * Year getter
		 * 
		 * @return The year of the date
		*/
		int get_year() const;

		/**
		 * Day getter
		 * 
		 * @return The day of the date
		*/
		int get_day() const;

		/**
		 * Month getter
		 * 
		 * @return The month of the date
		*/
		int get_month() const;

		/**
		 * Assign operator
		 * 
		 * @param date The dateto assign
		*/
		Date& operator=(const Date& date);

	private:

		/**
		 * Object representing the date
		 * https://en.cppreference.com/w/cpp/chrono/c/tm
		*/
		std::tm utc_time_ {};

		static const int kMonthOffset = 1;
		static const int kYearOffset = 1900;
	};
}

#endif