#include "test/test_book.h"

#include "test/test.h"
#include "book.h"

namespace test
{

void test_book_constructor()
{
	// Default constructor
	prj::Book e {};
	check(e.get_isbn() == "0000000000000");
	check(e.get_title() == "");
	check(e.get_author_name() == "");
	check(e.get_author_surname() == "");
	check(e.get_state() == prj::Book::State::Available);
	check(e.has_copyright() == false);

	// Copyright date not present
	try { e.get_copyright_date(); check(false); }
	catch(const std::logic_error& err) { check(true); }

	// Constructor 2
	prj::Book a{"Name", "Surname", "Title", "isbn-00001111"};
	check(a.get_isbn() == "isbn-00001111");
	check(a.get_author_name() == "Name");
	check(a.get_author_surname() == "Surname");
	check(a.get_title() == "Title");
	check(a.get_state() == prj::Book::State::Available);
	check(a.has_copyright() == false);

	// Complete constructor
	prj::Book b{"Name2", "Surname2", "Title2", "isbn-22221111", prj::Date(29, 9, 2003), prj::Book::State::OnLoan };
	check(b.get_isbn() == "isbn-22221111");
	check(b.get_author_name() == "Name2");
	check(b.get_author_surname() == "Surname2");
	check(b.get_title() == "Title2");
	check(b.get_state() == prj::Book::State::OnLoan);
	check(b.has_copyright() == true);

	// Copy constructor
	prj::Book c(b);

	check(b.get_author_name() == c.get_author_name());
	check(b.get_author_surname() == c.get_author_surname());
	check(b.get_copyright_date() == c.get_copyright_date());
	check(b.get_isbn() == c.get_isbn());
	check(b.get_state() == c.get_state());
	check(b.get_title() == c.get_title());

	// Checking references
	c.set_copyright_date(prj::Date(11, 12, 2013));
	check(b.get_copyright_date() != c.get_copyright_date());
}

void test_book_getter()
{

	// Complete constructor
	prj::Book b{"Name2", "Surname2", "Title2", "isbn-22221111", prj::Date(29, 9, 2003), prj::Book::State::OnLoan };
	check(b.get_isbn() == "isbn-22221111");
	check(b.get_author_name() == "Name2");
	check(b.get_author_surname() == "Surname2");
	check(b.get_title() == "Title2");
	check(b.get_state() == prj::Book::State::OnLoan);
	check(b.has_copyright() == true);

	// Getter
	try
	{
		prj::Date dt = b.get_copyright_date();

		check(dt.get_day() == 29);
		check(dt.get_month() == 9);
		check(dt.get_year() == 2003);
	}
	catch(const std::logic_error& err) { check(false); }
}

} // test
