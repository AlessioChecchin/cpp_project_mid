#ifndef TEST_DATE_H_
#define TEST_DATE_H_

#include "date.h"

namespace test
{
void is_valid_date(const prj::Date& date);

void test_date_valid();
void test_date_invalid();
void test_date_leap_years();
void test_date_getter();
void test_date_constructors();
void test_date_operators();
} // test

#endif // TEST_DATE_H_