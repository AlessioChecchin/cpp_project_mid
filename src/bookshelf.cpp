#include "bookshelf.h"

namespace prj
{

Bookshelf::Bookshelf(): Bookshelf(0) {}

Bookshelf::Bookshelf(unsigned long int size): capacity_{ size }, size_{ size }, v_{ new Book[size]() }
{
	/**
	 * N.B. new Book[size]() initializes to 0 all the elements (standard c++ 03)
	 * WARNING: new Book[0] allocates memory even if the buffer has 0 elements. The allocated resource
	 * MUST be released, even if it has 0 elements. If not released it could cause a memory leak.
	 * SEE: https://stackoverflow.com/questions/1087042/c-new-int0-will-it-allocate-memory
	 * 
	 * N.B. Member initializers list are called in the order corresponding to the class declaration
	 * If we do not use size, but size_ or capacity_ to initialize other member we could generate hard to fix bugs.
	 * SEE: https://www.geeksforgeeks.org/order-of-execution-in-initializer-list-in-c/
	*/
}

Bookshelf::Bookshelf(std::initializer_list<Book> list): capacity_( list.size() ), size_( list.size() ), v_( new Book[list.size()] )
{
	std::copy(list.begin(), list.end(), v_);
}

Bookshelf::Bookshelf(const Bookshelf& bookshelf): capacity_{ bookshelf.capacity_ }, size_{ bookshelf.size_ }, v_{ new Book[bookshelf.capacity_] }
{
	std::copy(bookshelf.v_, bookshelf.v_ + bookshelf.size_, v_);
}

Bookshelf::Bookshelf(Bookshelf&& bookshelf): capacity_{ bookshelf.capacity_ }, size_{ bookshelf.size_ }, v_{ bookshelf.v_ }
{
	// Clears original bookshelf
	bookshelf.size_ = 0;
	bookshelf.capacity_ = 0;
	bookshelf.v_ = nullptr;
}

Bookshelf::~Bookshelf()
{
	// N.B it's safe to delete a nullptr
	delete[] v_;
}

void Bookshelf::reserve(unsigned long int new_cap)
{
	// New_cap not greater than actual capacity -> do nothing
	if(new_cap <= capacity_) return;
	
	// Allocating new capacity
	Book* tmp = new Book[new_cap];

	// Copying data to the new buffer
	std::copy(v_, v_ + size_, tmp);

	// Deallocating old buffer (it's translated to no-op if is null)
	delete[] v_;

	// Moving pointer
	v_ = tmp;

	capacity_ = new_cap;
}

void Bookshelf::push_back(const Book& value)
{
	if(size_ == capacity_) 
	{
		if(size_ == 0) reserve(1);
		else reserve(2 * capacity_);
	}
	
	v_[size_] = value;
	size_++;
}

void Bookshelf::pop_back()
{
	if(size_ == 0) throw std::out_of_range("Vector index out of bound, negative index");
	size_--;
}

Book& Bookshelf::at(unsigned long int i)
{
	if(i < 0 || i >= size_) throw std::out_of_range("Vector index out of bound");
	return v_[i];
}

const Book& Bookshelf::at(unsigned long int i) const
{
	if(i < 0 || i >= size_) throw std::out_of_range("Vector index out of bound");
	return v_[i];
}

unsigned long int Bookshelf::size() const
{
	return size_;
}

unsigned long int Bookshelf::capacity() const
{
	return capacity_;
}

Bookshelf& Bookshelf::operator=(const Bookshelf& bookshelf)
{
	Book* tmp = new Book[bookshelf.capacity_];
	std::copy(bookshelf.v_, bookshelf.v_ + bookshelf.size_, tmp);
	delete[] v_;
	v_ = tmp;
	size_ = bookshelf.size_;
	capacity_ = bookshelf.capacity_;
	return *this;
}

Book& Bookshelf::operator[] (unsigned long int i)
{
	return v_[i];
}

const Book& Bookshelf::operator[] (unsigned long int i) const
{
	return v_[i];
}

bool operator==(const prj::Bookshelf& bksh1, const prj::Bookshelf& bksh2)
{
	if(bksh1.size() != bksh2.size())
	{
		return false;
	}

	for(int i = 0; i < bksh1.size(); i++)
	{
		if(bksh1[i] != bksh2[i])
			return false;
	}

	return true;
}

bool operator!=(const prj::Bookshelf& bksh1, const prj::Bookshelf& bksh2)
{
	return !(bksh1 == bksh2);
}

} // prj