#include "Book.h"
#include <stdexcept>

prj::Book::Book() {}

prj::Book::Book(std::string author_name, std::string author_surname, std::string title, std::string isbn, Date copyright_date, State state):
	author_name_ { author_name },
	author_surname_ { author_surname },
	title_ { title },
	isbn_ { isbn_ },
	copyright_date_ { new Date(copyright_date) },
	state_ { state }
{
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
	if(isbn_.size() != kIsbnSize) throw std::invalid_argument("Invalid isbn provided");
}
