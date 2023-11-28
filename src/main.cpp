#include <iostream>
#include <vector>

#include "test/test_date.h"
#include "test/test_book.h"
#include "test/test_bookshelf.h"

int main()
{
	test::test_date_valid();
	test::test_date_invalid();
	test::test_date_getter();
	test::test_date_leap_years();
	
	test::test_book_constructor();

	return 0;
}
