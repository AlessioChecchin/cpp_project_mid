#ifndef DATE_H_
#define DATE_H_

#include <ostream>

/**
 * Project namespace
*/
namespace prj
{
	/**
	 * Implements a Date.
	*/
	class Date
	{

	public:

		/**
		 * Creates a default date with value 01/01/1582.
		*/
		Date();

		/**
		 * Creates a Date with the specified day, month and year.
		 * 
		 * @param day Day of the Date
		 * @param month Month of the Date
		 * @param year Year of the Date
		*/
		Date(unsigned int day, unsigned int month, unsigned int year);

		/**
		 * Copy constructor.
		 * 
		 * @param date The date to copy.
		*/
		Date(const Date& date);

		/**
		 * Move constructor.
		 * 
		 * @param date The date to move.
		*/
		Date(Date&& date);

		/**
		 * Year getter.
		 * 
		 * @return The year of the date.
		*/
		unsigned int get_year() const;

		/**
		 * Day getter.
		 * 
		 * @return The day of the date.
		*/
		unsigned int get_day() const;

		/**
		 * Month getter.
		 * 
		 * @return The month of the date.
		*/
		unsigned int get_month() const;

		/**
		 * Assign operator.
		 * 
		 * @param date The date to assign.
		*/
		Date& operator=(const Date& date);

	private:

		/**
		 * The day of the date.
		*/
		unsigned int day_;
		
		/**
		 * The month of the date.
		*/
		unsigned int month_;
		
		/**
		 * The year of the date.
		*/
		unsigned int year_;

		/**
		 * The minimum year required to make the date valid.
		*/
		static const int kYearBase = 1582;

		/**
		 * Checks wheter a date is valid or not.
		 * 
		 * @param day The day of the date to check.
		 * @param month The month of the date to check.
		 * @param year The year of the date to check.
		*/
		static bool is_valid(const unsigned int day, const unsigned int month, const unsigned int year);

	};

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	std::ostream& operator<<(std::ostream& out, const Date date);
} // prj

#endif // DATE_H_