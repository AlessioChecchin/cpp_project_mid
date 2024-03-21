#include <stdexcept>
#include <string>

#include "date.h"

namespace prj
{

Date::Date(): day_{1}, month_{1}, year_{kYearBase}
{}

Date::Date(unsigned int day, unsigned int month,unsigned int year): day_ {day}, month_{month}, year_{year} 
{	/**
	 * Why not std::tm and std::mktime?
	 * 
	 * We initially thought of using std::tm and std::mktime to represent dates and to validate them.
	 * After implementing the Date class in this way, doing numerous tests on different platforms we noticed that the behaviors of Linux,
	 * Windows and MacOS changed. On some platforms, dates were invalidated even if they were valid. After some research
	 * we discovered that std::mktime only supports Jan-1-1970 dates by default.
	 * If earlier dates were supported it was because of the specific implementation.
	 * SEE: https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap04.html#tag_04_16
	 * SEE: https://developercommunity.visualstudio.com/t/mktime-does-not-support-dates-before-J/1208504?q=Node+JS+support+
	*/ 
	
	if(!is_valid(day_, month_, year_))
	{
		throw std::invalid_argument("Invalid date provided");
	}
}

Date::Date(const Date& date):
	Date(date.get_day(), date.get_month(), date.get_year())
{}

Date::Date(Date&& date):
	Date(date.get_day(), date.get_month(), date.get_year())
{
	date.day_ = 1;
	date.month_ = 1;
	date.year_ = 1582;
}

unsigned int Date::get_day()   const { return day_; }
unsigned int Date::get_month() const { return month_; }
unsigned int Date::get_year()  const { return year_; }

Date& Date::operator=(const Date& date)
{
	day_ = date.day_;
	month_ = date.month_;
	year_ = date.year_;

	return *this;
}

bool Date::is_valid(const unsigned int day, const unsigned int month, const unsigned int year)
{
	unsigned int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(month == 0 || month > 12)
		return false;
	if(year < 1582)
		return false;

	/**
	 * Year is a Leap Year <=>
	 *   - is not divisible by 100, but is divisible by 4
	 *   - is divisible by 400
	*/
	if( (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0) && month == 2)
	{
		// It's a leap year and month selected is february (it has 29 days)
		if(day > months[month-1]+1) 
			return false;
	}
		// It's not a leap year OR the month selected isn't februrary
	else if(day == 0 || day > months[month-1])
	{
		return false;
	}

	return true;
}

bool operator==(const Date& a, const Date& b)
{
	return a.get_day() == b.get_day() && a.get_month() == b.get_month() && a.get_year() == b.get_year();
}

bool operator!=(const Date& a, const Date& b)
{
	return !(a == b);
}

std::ostream& operator<<(std::ostream& out, const Date date)
{
	std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	out << date.get_day() << " " << months[date.get_month() -1] << " " <<date.get_year();

	return out;
}



} // prj
