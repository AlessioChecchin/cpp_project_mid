#include <iostream>
#include <vector>

#include "test/test_date.h"
#include "test/test_book.h"
#include "test/test_bookshelf.h"

int main()
{
	test::test_date_valid();				//test::CheckError throwed
	
	test::test_date_invalid();				//OK
	
	test::test_date_getter();				//std::invalid_argument throwed
											//what():  Invalid date provided
	
	test::test_date_leap_years();			//test::CheckError throwed
	
	test::test_date_constructors();			//OK
	
	test::test_date_operators();			//std::invalid_argument throwed
											//what():  Invalid date provided
	


	test::test_book_constructor();			//OK
	test::test_book_getter();				//OK
	test::test_book_operators();			//OK



	test::test_bookshelf_constructors();	//WIP
	test::test_bookshelf_methods();			//WIP
	test::test_bookshelf_operators();		//WIP

	std::cout<<"ok";
	return 0;
}
