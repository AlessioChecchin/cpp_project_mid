#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

#include <algorithm>
#include <stdexcept>
#include <initializer_list>

/**
 * Project namespace
*/
namespace prj
{
	/**
	 * Implements a vector similar to std::vector
	*/
	class my_vector
	{
	private:

		/**
		 * The capacity of the vector. The capacity is the physical memory allocated.
		*/
		unsigned long int capacity_;

		/**
		 * The number of elements stored in the vector
		*/
		unsigned long int size_;

		/**
		 * Buffer
		*/
		double* v_;
	public:

		/**
		 * Constructs and empty vector
		*/
		my_vector();

		/**
		 * Constructs a vector of size elements initialized to 0
		 * 
		 * @param size The size of the vector
		*/
		my_vector(unsigned long int size);

		/**
		 * Construct a vector that will contain the elment passed in the initializer_list
		 * 
		 * @param list A list of elements
		*/
		my_vector(std::initializer_list<double> list);

		/**
		 * Copy constructor
		 * 
		 * @param vector The vector to copy
		*/
		my_vector(const my_vector& vector);

		/**
		 * Move constructor
		 * 
		 * @param vector The vector to move
		*/
		my_vector(my_vector&& vector);

		/**
		 * Requests that the vector capacity should be equal to new_cap.
		 * If new_cap is greater than the current vector capacity, the function causes the container to reallocate its storage increasing
		 * its capacity to new_cap.
		 * In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.
		 * This function has no effect on the vector size and cannot alter its elements.
		 * 
		 * @param new_cap New capacity of the vector, in number of elements 
		*/
		void reserve(unsigned long int new_cap);

		/**
		 * Returns the number of elements that the container has currently allocated space for.
		*/
		void push_back(double value);

		/**
		 * Removes the last element of the container.
		 * @throw std::out_of_bounds thrown if the vector is empty
		*/
		void pop_back();

		/**
		 * @param i Position of the element to return
		 * @return Element
		*/
		double& at(unsigned long int i);

		/**
		 * @param i Position of the element to return
		 * @return Element
		 * @throw std::out_of_range thrown if i is out of range
		*/
		const double& at(unsigned long int i) const;

		unsigned long int size() const;
		unsigned long int capacity() const;

		my_vector& operator=(const my_vector& vector);

		// per vettori non costanti
		double& operator[] (unsigned long int i);
		const double& operator[] (unsigned long int i) const;

		~my_vector();
	};
}

#endif