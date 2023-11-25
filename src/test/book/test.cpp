#include <stdexcept>

#include "test/test.h"

#include "Date.h"
#include "Book.h"

void test_book_constructor()
{
	prj::Book e {};
	assert(e.get_isbn() == "0000000000000");
	assert(e.get_title() == "");
	assert(e.get_author_name() == "");
	assert(e.get_author_surname() == "");
	assert(e.get_state() == prj::Book::State::Available);
	assert(e.has_copyright() == false);

	try { e.get_copyright_date(); assert(false); }
	catch(const std::logic_error& err) { assert(true); }

	prj::Book a{"Name", "Surname", "Title", "isbn-00001111"};
	assert(a.get_isbn() == "isbn-00001111");
	assert(a.get_author_name() == "Name");
	assert(a.get_author_surname() == "Surname");
	assert(a.get_title() == "Title");
	assert(a.get_state() == prj::Book::State::Available);
	assert(a.has_copyright() == false);

	prj::Book b{"Name2", "Surname2", "Title2", "isbn-22221111", prj::Date(29, 9, 2003), prj::Book::State::OnLoan };
	assert(b.get_isbn() == "isbn-22221111");
	assert(b.get_author_name() == "Name2");
	assert(b.get_author_surname() == "Surname2");
	assert(b.get_title() == "Title2");
	assert(b.get_state() == prj::Book::State::OnLoan);
	assert(b.has_copyright() == true);

	try
	{
		prj::Date dt = b.get_copyright_date();

		assert(dt.get_day() == 29);
		assert(dt.get_month() == 9);
		assert(dt.get_year() == 2003);
	}
	catch(const std::logic_error& err) { assert(false); }

	prj::Book c{b};

	//assert(c == b);
	/*assert(c.get_isbn() == b.get_isbn());
	assert(c.get_author_name() == b.get_author_name());
	assert(c.get_author_surname() == b.get_author_surname());
	assert(c.get_state() == b.get_state());
	assert(c.has_copyright() == b.has_copyright());*/
}


TEST {

	test_book_constructor();

	return 0;
}