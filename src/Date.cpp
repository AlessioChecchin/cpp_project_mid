#include <stdexcept>
#include <iostream>

#include "Date.h"

/**
 * Construct a default date with value 01/01/1900
*/
prj::Date::Date(): utc_time_ {}
{
	utc_time_.tm_mday = 1;
	utc_time_.tm_mon = 0;
	utc_time_.tm_year = 0;
}

/**
 * Construct a Date with the specified day, month and year
 * 
 * @param day Day of the Date
 * @param month Month of the Date
 * @param year Year of the Date
*/
prj::Date::Date(int day, int month, int year): utc_time_ {}
{
	utc_time_.tm_mday = day;                    // tm_mday > 0
	utc_time_.tm_mon = month - kMonthOffset;    // tm_mon  > 0
	utc_time_.tm_year = year - kYearOffset;     // tm_year could be negative

	// https://stackoverflow.com/questions/29311412/how-can-i-tell-if-my-struct-tm-has-been-left-in-an-invalid-state
	/**
	 * std::maketime interprets utc_time and, if the structure has invialid data, tries to interpret it
	 * we check if it changed the structure, if it did, it means that the data was invalid
	*/

	time_t op_result = std::mktime(&utc_time_);
	bool is_valid = op_result != static_cast<std::time_t>(-1) && utc_time_.tm_mday == day && utc_time_.tm_mon == month - kMonthOffset && utc_time_.tm_year == year - kYearOffset;
	
	if(!is_valid)
	{
		throw std::invalid_argument("Invalid date provided");
	}
}

/**
 * Copy constructor
 * 
 * @param date The date to copy
*/
prj::Date::Date(const Date& date):
	prj::Date(date.get_day(), date.get_month(), date.get_year())
{}

/**
 * Move constructor
 * 
 * @param date The date to move
*/
prj::Date::Date(prj::Date&& date):
	prj::Date(date.get_day(), date.get_month(), date.get_year())
{
	utc_time_.tm_mday = 1;
	utc_time_.tm_mon = 0;
	utc_time_.tm_year = 0;
}

int prj::Date::get_day()   const { return utc_time_.tm_mday; }
int prj::Date::get_month() const { return utc_time_.tm_mon + kMonthOffset; }
int prj::Date::get_year()  const { return utc_time_.tm_year + kYearOffset; }

prj::Date& prj::Date::operator=(const Date& date)
{
	// Only copies properties of interest for prj::Date
	// Note that std::tm is standard defined at https://en.cppreference.com/w/cpp/chrono/c/tm
	// but some implementation include additional fields for handling timezones (i.e. long int tm_gmtoff; const char *tm_zone;)
	// which are not standard defined.
	// We do not want to copy non-standard values.

	utc_time_.tm_mday = date.utc_time_.tm_mday;
	utc_time_.tm_mon = date.utc_time_.tm_mon;
	utc_time_.tm_year = date.utc_time_.tm_year;

	return *this;
}