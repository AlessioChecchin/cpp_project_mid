#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <ostream>

#include "date.h"

/**
 * Project namespace
*/
namespace prj
{
	/**
	 * Implements a Book.
	*/
	class Book
	{
	
	public:
	
		/**
		 * Enum that represents possible states for a book.
		*/
		enum class State { Available, OnLoan };

		/**
		 * Creates an empty book.
		 * It will have all parameters set to an empty string except the isbn,
		 * that will be initialized as a string containing kIsbnSize zeros.
		*/
		Book();
		
		/**
		 * Creates a book initialized with the passed parameters.
		 * Its default state is available and not copyright date is set.
		 * 
		 * @param author_name
		 * @param author_surname
		 * @param title
		 * @param isbn
		*/
		Book(const std::string& author_name, const std::string& author_surname, const std::string& title, const std::string& isbn);
		
		/**
		 * Creates a book initialized with the passed parameters.
		 * 
		 * @param author_name
		 * @param author_surname
		 * @param title
		 * @param isbn
		 * @param copyright_date
		 * @param state
		*/
		Book(const std::string& author_name, const std::string& author_surname, const std::string& title, const std::string& isbn, const Date& copyright_date, State state);
		
		/**
		 * Copy constructor.
		 * 
		 * @param book The book to copy.
		*/
		Book(const Book& book);

		/**
		 * Move constructor.
		 * 
		 * @param book The book to move.
		*/
		Book(Book&& book);

		/**
		 * Destructor.
		*/
		~Book();
		
		/**
		 * Isbn getter.
		 * 
		 * @return The isbn.
		*/
		std::string get_isbn() const;

		/**
		 * Title getter.
		 * 
		 * @return The title.
		*/
		std::string get_title() const;

		/**
		 * Author name getter.
		 * 
		 * @return The author name.
		*/
		std::string get_author_name() const;

		/**
		 * Author surname getter.
		 * 
		 * @return The author surname.
		*/
		std::string get_author_surname() const;

		/**
		 * Copyright date getter.
		 * 
		 * @return The copyright date.
		 * @throw std::logic_error If the book does not have a copyright date.
		*/
		Date get_copyright_date() const;

		/**
		 * Returns if the book has a copyright date.
		 * 
		 * @return true if the book has copyright date, false otherwise.
		*/
		bool has_copyright() const;

		/**
		 * State getter.
		 * 
		 * @return The state of the book.
		*/
		State get_state() const;

		/**
		 * Isbn setter.
		 * 
		 * @param isbn The new isbn.
		*/
		void set_isbn(const std::string& isbn);

		/**
		 * Title setter.
		 * 
		 * @param title The new title.
		*/
		void set_title(const std::string& title);

		/**
		 * Author name setter.
		 * 
		 * @param name The new name.
		*/
		void set_author_name(const std::string& name);

		/**
		 * Author surname setter.
		 * 
		 * @param surname The new surname.
		*/
		void set_author_surname(const std::string& surname); 
		
		/**
		 * Copyright date setter.
		 * 
		 * @param date The date to set.
		*/
		void set_copyright_date(const Date& date);

		/**
		 * Copyright date setter.
		 * 
		 * @param date A pointer to a date. If the pointer is null, the book will not have a copyright date.
		*/
		void set_copyright_date(const Date* date);

		/**
		 * Copyright state setter.
		 * 
		 * @param state The new state.
		*/
		void set_state(State state);

		/**
		 * Assign operator.
		 * 
		 * @param book The book to assign.
		*/
		Book& operator=(const Book& book);
		
	private:
		
		/**
		 * The size required for a valid isbn.
		*/
		static const unsigned short kIsbnSize = 13;

		/**
		 * The author name.
		*/
		std::string author_name_ {};
		
		/**
		 * The author surname.
		*/
		std::string author_surname_ {};
		
		/**
		 * The book title.
		*/
		std::string title_ {};
		
		/**
		 * The book isbn.
		*/
		std::string isbn_ {};

		/**
		 * The book copyright date (if it has one).
		*/
		Date* copyright_date_ {};

		/**
		 * The book state.
		*/
		State state_ {};
	
	};
	
	bool operator==(const Book& a, const Book& b);
	bool operator!=(const Book& a, const Book& b);
	
	std::ostream& operator<<(std::ostream& out, const Book& book);
} // prj

#endif // BOOK_H_