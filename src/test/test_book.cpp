#include <sstream>
#include <string>

#include "test/test_book.h"

#include "test/test.h"
#include "book.h"

namespace test
{

void test_book_constructor()
{
	// Testing default constructor
	prj::Book e {};
	check(e.get_isbn() == "0000000000000");
	check(e.get_title() == "");
	check(e.get_author_name() == "");
	check(e.get_author_surname() == "");
	check(e.get_state() == prj::Book::State::Available);
	check(e.has_copyright() == false);

	// Default constructor must not have a date. If object 'e' has a date, an exception must be thrown	
	try 
	{ 
		e.get_copyright_date();
		check(false); 
	}
	catch(const std::logic_error& err) 
	{ 
		check(true); 
	}

	// Testing required constructor (name, surname, isbn)
	prj::Book a{"Name", "Surname", "Title", "isbn-00001111"};
	check(a.get_isbn() == "isbn-00001111");
	check(a.get_author_name() == "Name");
	check(a.get_author_surname() == "Surname");
	check(a.get_title() == "Title");
	check(a.get_state() == prj::Book::State::Available);
	check(a.has_copyright() == false);

	// Testing complete constructor (name, surname, isbn, date, state)
	prj::Book b{"Name2", "Surname2", "Title2", "isbn-22221111", prj::Date(29, 9, 2003), prj::Book::State::OnLoan };
	check(b.get_isbn() == "isbn-22221111");
	check(b.get_author_name() == "Name2");
	check(b.get_author_surname() == "Surname2");
	check(b.get_title() == "Title2");
	check(b.get_state() == prj::Book::State::OnLoan);
	check(b.has_copyright() == true);

	// Testing copy constructor
	prj::Book c(b);
	check(b.get_author_name() == c.get_author_name());
	check(b.get_author_surname() == c.get_author_surname());
	check(b.get_copyright_date() == c.get_copyright_date());
	check(b.get_isbn() == c.get_isbn());
	check(b.get_state() == c.get_state());
	check(b.get_title() == c.get_title());

	// Checking references (Date)
	c.set_copyright_date(prj::Date(11, 12, 2013));
	check(b.get_copyright_date() != c.get_copyright_date());

	// Testing move constructor
	prj::Book moved(std::move(b));
	check(moved.get_isbn() == "isbn-22221111");
	check(moved.get_author_name() == "Name2");
	check(moved.get_author_surname() == "Surname2");
	check(moved.get_title() == "Title2");
	check(moved.get_state() == prj::Book::State::OnLoan);
	check(moved.has_copyright() == true);

	// Testing destructor
	prj::Book* d = new prj::Book {"Name", "Surname", "Title", "1234567890123"};
	check(d->get_isbn() == "1234567890123");
	check(d->get_title() == "Title");
	check(d->get_author_name() == "Name");
	check(d->get_author_surname() == "Surname");
	delete d;
	
}

void test_book_getter()
{

	// Testing getters
	prj::Book b{"Name2", "Surname2", "Title2", "isbn-22221111", prj::Date(29, 9, 2003), prj::Book::State::OnLoan };
	check(b.get_isbn() == "isbn-22221111");
	check(b.get_author_name() == "Name2");
	check(b.get_author_surname() == "Surname2");
	check(b.get_title() == "Title2");
	check(b.get_state() == prj::Book::State::OnLoan);
	check(b.has_copyright() == true);

	// Testing date getter
	try
	{
		prj::Date dt = b.get_copyright_date();

		check(dt.get_day() == 29);
		check(dt.get_month() == 9);
		check(dt.get_year() == 2003);
	}
	catch(const std::logic_error& err)
	{
		check(false);
	}
}

void test_book_operators()
{
	prj::Book a {"Name", "Surname", "Title", "1234567890123"};

	// Testing operator=
	prj::Book b = a;
	check(b.get_author_name() == "Name");
	check(b.get_author_surname() == "Surname");
	check(b.get_title() == "Title");
	check(b.get_isbn() == "1234567890123");

	// Testing operator== 	(a == b <=> a.get_isbn == b.get_isbn)
	check(a == b);

	// Testing operator!=
	a.set_isbn("0000000000000");
	check(a != b);

	// Testing operator<<
	std::ostringstream os;
	std::string auth_names[3] = {"Mario", "Luigi" , "Gianni"};
	std::string auth_surnames[3] = {"Rossi", "Bianchi" , "Verdi"};
	std::string titles[3] = {"Libro1", "Libro1 2: La Vendetta" , "Libro1 3: Il Ritorno"};
	std::string isbn_codes[3] = {"000-000-000-1", "000-000-000-2" , "000-000-000-3"};
	for(int i = 0; i < 3; i++)
	{
		prj::Book book(auth_names[i], auth_surnames[i], titles[i], isbn_codes[i]);
		os << book;
		std::string bookString = book.get_title() + "\n" + book.get_author_name() + "\n" + book.get_author_surname() + "\n" + book.get_isbn() + "\n" + "No copyright date" + "\n";
		check(os.str() == bookString);
		
		// Resets ostringstream
		os.str("");		// Required to clear the stream
		os.clear();		// Required to clear errors
	}

}

} // test