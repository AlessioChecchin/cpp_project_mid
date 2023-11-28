#include "test/test_book.h"

#include "test/test.h"
#include "book.h"

namespace test
{

void test_book_constructor()
{
	prj::Book e {};
	check(e.get_isbn() == "0000000000000");
	check(e.get_title() == "");
	check(e.get_author_name() == "");
	check(e.get_author_surname() == "");
	check(e.get_state() == prj::Book::State::Available);
	check(e.has_copyright() == false);

	try { e.get_copyright_date(); check(false); }
	catch(const std::logic_error& err) { check(true); }

	prj::Book a{"Name", "Surname", "Title", "isbn-00001111"};
	check(a.get_isbn() == "isbn-00001111");
	check(a.get_author_name() == "Name");
	check(a.get_author_surname() == "Surname");
	check(a.get_title() == "Title");
	check(a.get_state() == prj::Book::State::Available);
	check(a.has_copyright() == false);

	prj::Book b{"Name2", "Surname2", "Title2", "isbn-22221111", prj::Date(29, 9, 2003), prj::Book::State::OnLoan };
	check(b.get_isbn() == "isbn-22221111");
	check(b.get_author_name() == "Name2");
	check(b.get_author_surname() == "Surname2");
	check(b.get_title() == "Title2");
	check(b.get_state() == prj::Book::State::OnLoan);
	check(b.has_copyright() == true);

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
