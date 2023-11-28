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
	test::test_date_constructors();
	test::test_date_operators();
	
	test::test_book_constructor();
	test::test_book_getter();
	test::test_book_operators();

	test::test_bookshelf_constructors();
	test::test_bookshelf_methods();
	test::test_bookshelf_operators();

	std::cout<<"ok";
	return 0;
}
