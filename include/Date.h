#ifndef DATE_H_
#define DATE_H_

#include <chrono>
#include <ctime>
#include <initializer_list>

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
	private:

		/**
		 * Object representing the date
		 * https://en.cppreference.com/w/cpp/chrono/c/tm
		*/
		std::tm utc_time;

		static const int kMonthOffset = 1;
		static const int kYearOffset = 1900;

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
		 * True if the date is within a leap year, false otherwise
		*/
		//bool isLeap() const;

		/**
		 * Year getter
		 * @return The year of the date
		*/
		unsigned int getYear() const;

		/**
		 * Day getter
		 * @return The day of the date
		*/
		unsigned int getDay() const;

		/**
		 * Month getter
		 * @return The month of the date
		*/
		unsigned int gedMonth() const;

		/*Date& operator=(const Date& date);
		Date& operator-(const Date& date);
		Date& operator+(const Date& date);*/
	};
}

#endif