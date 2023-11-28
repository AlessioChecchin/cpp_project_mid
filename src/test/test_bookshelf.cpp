#include "test/test_bookshelf.h"
#include "test/test.h"

#include "bookshelf.h"

namespace test
{
    void test_bookshelf_constructors()			//WIP
	{
		constexpr int kSize = 10;

		// Default constructor
		prj::Bookshelf a;
		check(a.size() == 0);

		// Sized constructor
		prj::Bookshelf b(kSize);
		check(b.size() == kSize);

		// List-initialized constructor;
		prj::Bookshelf c {prj::Book(), prj::Book(), prj::Book()};
		check(c.size() == 3);


		/*
			SISTEMARE - segmentation fault :(
		*/

		// Copy constructor
		prj::Bookshelf d(c);
		check(d == c);

		// Move constructor
		// prj::Bookshelf e = std::move(d);
		// check(e == c);
		// check(e != a);
		
	}

    void test_bookshelf_methods(){};			//WIP
    void test_bookshelf_operators(){};			//WIP


} //test