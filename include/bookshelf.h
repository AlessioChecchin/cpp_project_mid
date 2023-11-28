#ifndef BOOKSHELF_H_
#define BOOKSHELF_H_

#include <algorithm>
#include <stdexcept>
#include <initializer_list>

#include "book.h"

/**
 * Project namespace
*/
namespace prj
{
	/**
	 * Implements a vector similar to std::vector, but made of books
	*/
	class Bookshelf
	{

	public:

		/**
		 * Constructs and empty bookshelf
		*/
		Bookshelf();

		/**
		 * Constructs a bookshelf of 'size' empty books
		 * 
		 * @param size The size of the bookshelf
		*/
		Bookshelf(unsigned long int size);

		/**
		 * Construct a bookshelf that will contain the books passed in the initializer_list
		 * 
		 * @param list A list of books
		*/
		Bookshelf(std::initializer_list<Book> list);

		/**
		 * Copy constructor
		 * 
		 * @param bookshelf The bookshelf to copy
		*/
		Bookshelf(const Bookshelf& bookshelf);

		/**
		 * Move constructor
		 * 
		 * @param bookshelf The bookshelf to move
		*/
		Bookshelf(Bookshelf&& bookshelf);

		/**
		 * Requests that the bookshelf capacity should be equal to new_cap.
		 * If new_cap is greater than the current bookshelf capacity, the function causes the container to reallocate its storage increasing
		 * its capacity to new_cap.
		 * In all other cases, the function call does not cause a reallocation and the bookshelf capacity is not affected.
		 * This function has no effect on the bookshelf size and cannot alter its elements.
		 * 
		 * @param new_cap New capacity of the bookshelf, in number of books 
		*/
		void reserve(unsigned long int new_cap);

		/**
		 * Returns the number of elements that the container has currently allocated space for.
		*/
		void push_back(Book book);

		/**
		 * Removes the last books of the bookshelf.
		 * @throw std::out_of_bounds thrown if the bookshelf is empty
		*/
		void pop_back();

		/**
		 * @param i Position of the book to return
		 * @return Book
		*/
		Book& at(unsigned long int i);

		/**
		 * @param i Position of the book to return
		 * @return Book
		 * @throw std::out_of_range thrown if i is out of range
		*/
		const Book& at(unsigned long int i) const;

		unsigned long int size() const;
		unsigned long int capacity() const;

		Bookshelf& operator=(const Bookshelf& bookshelf);

		/**
		 * First operator[] for non constant bookshelfs, the second one
		 * for constant bookshelfs
		*/
		Book& operator[] (unsigned long int i);
		const Book& operator[] (unsigned long int i) const;

		~Bookshelf();

	private:

		/**
		 * The capacity of the bookshelf. The capacity is the physical memory allocated.
		*/
		unsigned long int capacity_{};

		/**
		 * The number of books stored in the bookshelf
		*/
		unsigned long int size_{};

		/**
		 * Buffer
		*/
		Book* v_{nullptr};
	};
	bool operator==(const prj::Bookshelf& bksh1, const prj::Bookshelf& bksh2);
	bool operator!=(const prj::Bookshelf& bksh1, const prj::Bookshelf& bksh2);
} // prj

#endif // BOOKSHELF_H_
