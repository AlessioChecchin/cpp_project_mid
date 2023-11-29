#include <stdexcept>
#include <string>
#include <iostream>

#include "book.h"

namespace prj
{

Book::Book():
	Book("", "", "", std::string(kIsbnSize, '0'))
{
	// Delegating constructor
	// An empty book has a 0-value isbn and all other infromations are empty
}

Book::Book(const std::string& author_name, const std::string& author_surname, const std::string& title, const std::string& isbn, const Date& copyright_date, State state):
	author_name_    { author_name },
	author_surname_ { author_surname },
	title_          { title },
	isbn_           { isbn },
	copyright_date_ { new Date(copyright_date) },
	state_          { state }
{
	set_isbn(isbn);
}

Book::Book(const std::string& author_name, const std::string& author_surname, const std::string& title, const std::string& isbn):
	author_name_    { author_name },
	author_surname_ { author_surname },
	title_          { title },
	isbn_           { isbn },
	copyright_date_ { nullptr },
	state_          { Book::State::Available }
{
	set_isbn(isbn);
}

Book::Book(const Book& book):
	Book(book.author_name_, book.author_surname_, book.title_, book.isbn_)
{
	// Pointer handling is delegated to the setter (the one that takes a pointer)
	set_copyright_date(book.copyright_date_);
	
	state_ = book.state_;
}

Book::Book(Book&& book):
	Book(book.author_name_, book.author_surname_, book.title_, book.isbn_)
{
	// Pointer handling is delegated to the setter (the one that takes a pointer)
	set_copyright_date(book.copyright_date_);

	state_ = book.state_;

	// Invalidating book => Isbn is empty (violates the kIsbnSize constraint)
	// After being moved, the object can't be used anymore. For this reason
	// we want to empty all members.
	book.author_name_ = "";
	book.author_surname_ = "";
	book.copyright_date_ = nullptr;
	book.title_ = "";
	book.isbn_ = "";
	book.state_ = State::Available;
}

Book::~Book()
{
	// Note that if copyright_date_ is nullptr the operation results in a well-defined behaviour.
	// A null pointer deletion is effectively mapped to no-op
	delete copyright_date_;
}

std::string Book::get_isbn()           const { return isbn_; }
std::string Book::get_title()          const { return title_; }
std::string Book::get_author_name()    const { return author_name_; }
std::string Book::get_author_surname() const { return author_surname_; }
Book::State Book::get_state()     const { return state_; }

Date Book::get_copyright_date() const
{
	if(!has_copyright())
	{
		throw std::logic_error("The book is not protected by copyright");
	}

	return *copyright_date_;
}

bool Book::has_copyright() const
{
	return copyright_date_ != nullptr;
}

void Book::set_isbn(const std::string& isbn)
{
	if(isbn_.size() != kIsbnSize) { throw std::invalid_argument("Invalid isbn provided"); }
	isbn_ = isbn;
}

void Book::set_title(const std::string& title) 
{
	title_ = title;
}

void Book::set_author_name(const std::string& name)
{
	author_name_ = name;
}

void Book::set_author_surname(const std::string& surname)
{
	author_surname_ = surname;
}

void Book::set_copyright_date(const Date& date)
{
	// Free eventual resources
	delete copyright_date_;
	copyright_date_ = new Date(date);
}

void Book::set_copyright_date(const Date* date)
{
	if(date != nullptr)
	{
		// Call overloaded setter, takes a reference
		set_copyright_date(*date);
	}
	else 
	{
		// Free eventual resources
		delete copyright_date_;
		copyright_date_ = nullptr;
	}
}

void Book::set_state(Book::State state)
{
	if(state != Book::State::Available && state != Book::State::OnLoan)
	{
		throw std::invalid_argument("Invalid enum provided");
	}

	state_ = state;
}

Book& Book::operator=(const Book& book)
{
	isbn_ = book.isbn_;
	author_name_ = book.author_name_;
	author_surname_ = book.author_surname_;
	title_ = book.title_;
	state_ = book.state_;

	set_copyright_date(book.copyright_date_);

	return *this;
}

bool operator==(const Book& a, const Book& b)
{
	return a.get_isbn() == b.get_isbn();
}

bool operator!=(const Book& a, const Book& b)
{
	return !(a == b);
}

std::ostream& operator<<(std::ostream& out, const Book& book)
{
	out << book.get_title() << "\n"
	    << book.get_author_name() << "\n"
		<< book.get_author_surname() << "\n"
		<< book.get_isbn() << "\n" ;
	if(book.has_copyright())
		out << book.get_copyright_date();
	else
		out << "No copyright date";	
	out << std::endl;	
	return out;
}

} // prj