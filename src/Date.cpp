#include "Date.h"
#include <stdexcept>
#include <iostream>

/**
 * Construct a Date with the specified day, month and year
 * 
 * @param day Day of the Date
 * @param month Month of the Date
 * @param year Year of the Date
*/
prj::Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
	utc_time.tm_mday = day;
	utc_time.tm_mon = month - kMonthOffset;
	utc_time.tm_year = year - kYearOffset;

	// https://stackoverflow.com/questions/29311412/how-can-i-tell-if-my-struct-tm-has-been-left-in-an-invalid-state
	if(!(std::mktime(&utc_time) != static_cast<std::time_t>(-1) && utc_time.tm_mday == day && utc_time.tm_mon == month - kMonthOffset && utc_time.tm_year == year - kYearOffset))
	{
		throw std::invalid_argument("Invalid date provided");
	}
}

/**
 * Copy constructor
 * 
 * @param date The date to copy
*/
prj::Date::Date(const Date& date): prj::Date(date.getDay(), date.gedMonth(), date.getYear())
{}

/**
 * Move constructor
 * 
 * @param date The date to move
*/
prj::Date::Date(prj::Date&& date): prj::Date(date.getDay(), date.gedMonth(), date.getYear())
{
	utc_time.tm_mday = 0;
	utc_time.tm_mon = 0;
	utc_time.tm_year = 0;
}

unsigned int prj::Date::getDay() const
{
	return utc_time.tm_mday;
}

unsigned int prj::Date::gedMonth() const
{
	return utc_time.tm_mon + kMonthOffset;
}

unsigned int prj::Date::getYear() const 
{
	return utc_time.tm_year + kYearOffset;
}
