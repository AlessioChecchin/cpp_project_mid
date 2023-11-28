#include "date.h"

#include <stdexcept>
#include <iostream>

namespace prj
{

/**
 * Construct a default date with value 01/01/1900
*/
Date::Date(): utc_time_ {}
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
Date::Date(int day, int month, int year): utc_time_ {}
{
	utc_time_.tm_mday = day;                    // tm_mday > 0
	utc_time_.tm_mon = month - kMonthOffset;    // tm_mon  > 0
	utc_time_.tm_year = year - kYearOffset;     // tm_year could be negative

	/**
	 * std::maketime interprets utc_time and, if the structure has invialid data, tries to interpret it.
	 * We check if it changed the structure, if it did, it means that the data was invalid
	 * 
	 * See: https://en.cppreference.com/w/cpp/chrono/c/mktime
	 * See: https://stackoverflow.com/questions/29311412/how-can-i-tell-if-my-struct-tm-has-been-left-in-an-invalid-state
	 * Converts local calendar time to a time since epoch as a std::time_t object. time->tm_wday and time->tm_yday are ignored.
	 * The values in time are permitted to be outside their normal ranges.
     * A negative value of time->tm_isdst causes mktime to attempt to determine if Daylight Saving Time was in effect.
     * If the conversion is successful, the time object is modified. All fields of time are updated to fit their proper ranges. time->tm_wday and time->tm_yday are recalculated using information available in other fields. 
	*/

	time_t op_result = std::mktime(&utc_time_);
	bool is_valid = (op_result != static_cast<std::time_t>(-1)) && (utc_time_.tm_mday == day) && (utc_time_.tm_mon == month - kMonthOffset) && (utc_time_.tm_year == year - kYearOffset);
	
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
Date::Date(const Date& date):
	Date(date.get_day(), date.get_month(), date.get_year())
{}

/**
 * Move constructor
 * 
 * @param date The date to move
*/
Date::Date(Date&& date):
	Date(date.get_day(), date.get_month(), date.get_year())
{
	utc_time_.tm_mday = 1;
	utc_time_.tm_mon = 0;
	utc_time_.tm_year = 0;
}

int Date::get_day()   const { return utc_time_.tm_mday; }
int Date::get_month() const { return utc_time_.tm_mon + kMonthOffset; }
int Date::get_year()  const { return utc_time_.tm_year + kYearOffset; }

Date& Date::operator=(const Date& date)
{
	// Only copies properties of interest for Date
	// Note that std::tm is standard defined at https://en.cppreference.com/w/cpp/chrono/c/tm
	// but some implementation include additional fields for handling timezones (i.e. long int tm_gmtoff; const char *tm_zone;)
	// which are not standard defined.
	// We do not want to copy non-standard values.

	utc_time_.tm_mday = date.utc_time_.tm_mday;
	utc_time_.tm_mon = date.utc_time_.tm_mon;
	utc_time_.tm_year = date.utc_time_.tm_year;

	return *this;
}

} // test
