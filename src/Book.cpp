#include "Book.h"

#include <stdexcept>
#include <string>


prj::Book::Book(): prj::Book("", "", "", std::string(kIsbnSize, '0'))
{
	// Delegating constructor
	// An empty book has a 0-value isbn and all other infromations are empty
}

prj::Book::Book(std::string author_name, std::string author_surname, std::string title, std::string isbn, Date copyright_date, State state):
	author_name_ { author_name },
	author_surname_ { author_surname },
	title_ { title },
	isbn_ { isbn_ },
	copyright_date_ { new Date(copyright_date) },
	state_ { state }
{
	// Check size
	if(isbn_.size() != kIsbnSize) throw std::invalid_argument("Invalid isbn provided");
}

prj::Book::Book(std::string author_name, std::string author_surname, std::string title, std::string isbn):
	author_name_ { author_name },
	author_surname_ { author_surname },
	title_ { title },
	isbn_ { isbn_ },
	copyright_date_ { nullptr },
	state_ { prj::Book::State::Available }
{
	// Check size
	if(isbn_.size() != kIsbnSize) throw std::invalid_argument("Invalid isbn provided");
}

prj::Book::Book(const prj::Book& book): prj::Book(book.author_name_, book.author_surname_, book.title_, book.isbn_)
{
	// We can't delegate the copy to the other constructor because we need to check if the copyright_date is null
	// Dereferenciating a nullptr results in undefined behaviour
	if(book.copyright_date_ != nullptr)
	{
		// Deep copy
		*copyright_date_ = *book.copyright_date_;
	}
	else 
	{
		copyright_date_ = nullptr;
	}
	
	state_ = book.state_;
}

prj::Book::Book(prj::Book&& book): prj::Book(book.author_name_, book.author_surname_, book.title_, book.isbn_)
{
	// We can't delegate the copy to the other constructor because we need to check if the copyright_date is null
	// Dereferenciating a nullptr results in undefined behaviour

	if(book.copyright_date_ != nullptr)
	{
		// Copying pointer (shallow copy)
		copyright_date_ = book.copyright_date_;
	}
	else 
	{
		copyright_date_ = nullptr;
	}
	
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

prj::Book::~Book()
{
	// Note that if copyright_date_ is nullptr the operation results in a well-defined behaviour.
	// A null pointer deletion is effectively mapped to no-op
	delete copyright_date_;
}


std::string prj::Book::get_isbn() const { return isbn_; }
std::string prj::Book::get_title() const { return title_; }
std::string prj::Book::get_author_name() const { return author_name_; }
std::string prj::Book::get_author_surname() const { return author_surname_; }
prj::Date prj::Book::get_copyright_date() const { return *copyright_date_; }
prj::Book::State prj::Book::get_state() const { return state_; }

void prj::Book::set_state(prj::Book::State state)
{
	if(state != prj::Book::State::Available && state != prj::Book::State::OnLoan)
	{
		throw std::invalid_argument("Invalid enum provided");
	}

	state_ = state;
}

prj::Book& prj::Book::operator=(const prj::Book& book)
{
	isbn_ = book.isbn_;
	author_name_ = book.author_name_;
	author_surname_ = book.author_surname_;
	title_ = book.title_;
	state_ = book.state_;

	// Deep copy
	*copyright_date_ = *book.copyright_date_;

	return *this;
}