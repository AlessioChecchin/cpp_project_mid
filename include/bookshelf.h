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
	 * Implements a vector similar to std::vector, but made of books.
	*/
	class Bookshelf
	{
	
	public:

		/**
		 * Creates an empty bookshelf.
		*/
		Bookshelf();

		/**
		 * Creates a bookshelf of 'size' empty books.
		 * 
		 * @param size The size of the bookshelf.
		*/
		Bookshelf(unsigned long int size);

		/**
		 * Creates a bookshelf that will contain the books passed in the initializer_list.
		 * 
		 * @param list A list of books.
		*/
		Bookshelf(std::initializer_list<Book> list);

		/**
		 * Copy constructor.
		 * 
		 * @param bookshelf The bookshelf to copy.
		*/
		Bookshelf(const Bookshelf& bookshelf);

		/**
		 * Move constructor.
		 * 
		 * @param bookshelf The bookshelf to move.
		*/
		Bookshelf(Bookshelf&& bookshelf);

		/**
		 * Requests that the bookshelf capacity should be equal to new_cap.
		 * If new_cap is greater than the current bookshelf capacity, the function causes the container to reallocate its storage increasing
		 * its capacity to new_cap.
		 * In all other cases, the function call does not cause a reallocation and the bookshelf capacity is not affected.
		 * This function has no effect on the bookshelf size and cannot alter its elements.
		 * 
		 * @param new_cap New capacity of the bookshelf, in number of books.
		*/
		void reserve(unsigned long int new_cap);

		/**
		 * Add a book at the end.
		 * 
		 * @param book The book to add.
		*/
		void push_back(const Book& book);

		/**
		 * Deletes the last book.
		 * 
		 * @throw std::out_of_bounds Thrown if the bookshelf is empty.
		*/
		void pop_back();

		/**
		 * Returns a reference to the book at position i,
		 * checking whether i is within the bounds of valid elements in the bookshelf.
		 * 
		 * @param i Position of the book to return.
		 * @return The book at position i in the bookshelf.
		 * @throw std::out_of_range thrown if i is out of range.
		*/
		Book& at(unsigned long int i);

		/**
		 * Returns a reference to the book at position i,
		 * checking whether i is within the bounds of valid elements in the bookshelf.
		 * 
		 * @param i Position of the book to return.
		 * @return The book at position i in the bookshelf.
		 * @throw std::out_of_range thrown if i is out of range.
		*/
		const Book& at(unsigned long int i) const;

		/**
		 * Size getter.
		 * 
		 * @return The size of the bookshelf.
		*/
		unsigned long int size() const;
		
		/**
		 * Capacity getter.
		 * 
		 * @return The capacity of the bookshelf.
		*/
		unsigned long int capacity() const;

		/**
		 * Assign operator.
		 * 
		 * @param bookshelf The bookshelf to assign.
		*/
		Bookshelf& operator=(const Bookshelf& bookshelf);

		/**
		 * Returns a reference to the book at position i.
		 * 
		 * @param i Position of the book to return.
		 * @return The book at position i in the bookshelf.
		*/
		Book& operator[] (unsigned long int i);

		/**
		 * Returns a reference to the book at position i.
		 * 
		 * @param i Position of the book to return.
		 * @return The book at position i in the bookshelf.
		*/
		const Book& operator[] (unsigned long int i) const;

		/**
		 * Destructor.
		*/
		~Bookshelf();

	private:

		/**
		 * The capacity of the bookshelf. The capacity is the physical memory allocated.
		*/
		unsigned long int capacity_{};

		/**
		 * The capacity of the bookshelf. The size is the number of books currently stored in the bookshelf.
		*/
		unsigned long int size_{};

		/**
		 * The buffer in wich every book of the bookshelf is stored (in order).
		*/
		Book* v_{nullptr};
	};

	bool operator==(const prj::Bookshelf& bksh1, const prj::Bookshelf& bksh2);
	bool operator!=(const prj::Bookshelf& bksh1, const prj::Bookshelf& bksh2);
} // prj

#endif // BOOKSHELF_H_
