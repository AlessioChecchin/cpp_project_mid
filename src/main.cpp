#include <iostream>
#include <vector>

#include "book.h"
#include "bookshelf.h"

#include "test/test_date.h"
#include "test/test_book.h"
#include "test/test_bookshelf.h"

int main(int argv, char* argc[])
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


	// Test richiesto dalla consegna
	
	prj::Book mybook("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4");
	prj::Bookshelf shelf(10);
	shelf.push_back(mybook);
	std::cout << shelf[10];
	shelf.pop_back();


	return 0;
}
