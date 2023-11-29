#ifndef DATE_H_
#define DATE_H_

#include <ostream>

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
		 * Construct a default date with value 01/01/1582
		*/
		Date();

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
		 * Year getter
		 * 
		 * @return The year of the date
		*/
		unsigned int get_year() const;

		/**
		 * Day getter
		 * 
		 * @return The day of the date
		*/
		unsigned int get_day() const;

		/**
		 * Month getter
		 * 
		 * @return The month of the date
		*/
		unsigned int get_month() const;

		/**
		 * Assign operator
		 * 
		 * @param date The date to assign
		*/
		Date& operator=(const Date& date);

	private:

		/**
		 * Object representing the date
		 * https://en.cppreference.com/w/cpp/chrono/c/tm
		*/
		unsigned int day_;
		unsigned int month_;
		unsigned int year_;

		static const int kYearBase = 1582;

		static bool is_valid(const unsigned int day, const unsigned int month, const unsigned int year);

	};
	std::ostream& operator<<(std::ostream& out, const Date date);
	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

} // prj

#endif // DATE_H_