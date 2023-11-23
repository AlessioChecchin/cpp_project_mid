#include <stdexcept>

#include "test/test.h"
#include "Date.h"

bool is_valid(unsigned int day, unsigned int month, unsigned int year)
{
	try {
		prj::Date d(day, month, year);
		return true;
	}
	catch(const std::invalid_argument& e)
	{
		return false;
	}
}

void test_invalid_dates()
{
	assert(is_valid(29, 9, 2003) == true);
	assert(is_valid(29, 13, 2003) == false);
	assert(is_valid(29, 2, 2000) == true);
	assert(is_valid(29, 2, 2001) == false);
	assert(is_valid(12, 2, 1800) == true);
}

TEST {
	test_invalid_dates();
	return 0;
}