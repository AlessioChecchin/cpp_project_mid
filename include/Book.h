#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <iostream>

namespace prj
{
	class Date
	{
	};

	class Book
	{
	
	public:
	
		enum class State { Available, OnLoan };

		Book();
		Book(std::string author_name, std::string author_surname, std::string title, std::string isbn);
		Book(std::string author_name, std::string author_surname, std::string title, std::string isbn, Date copyright_date, State state);
		Book(const Book& book);
		Book(Book&& book);
		~Book();
		
		std::string get_isbn() const;
		std::string get_title() const;
		std::string get_author_name() const;
		std::string get_author_surname() const;
		Date get_copyright_date() const;
		State get_state() const;
		
		void set_state(State state);

		Book& operator=(const Book& book);
		
	private:
		
		static const unsigned short kIsbnSize = 13;

		std::string author_name_;
		std::string author_surname_;
		std::string title_;
		std::string isbn_;

		Date* copyright_date_;
		State state_;
	};
	
	bool operator==(const Book& a, const Book& b);
	bool operator!=(const Book& a, const Book& b);
	
	std::ostream& operator<<(std::ostream& out, const Book& book);
}

#endif