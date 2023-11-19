#include "my_vector.h"

prj::my_vector::my_vector(): my_vector(0) {}

prj::my_vector::my_vector(unsigned long int size): capacity_{ size }, size_{ size }, v_{ new double[size]() }
{
	/**
	 * N.B. new double[size]() initializes to 0 all the elements (standard c++ 03)
	 * WARNING: new double[0] allocates memory even if the buffer has 0 elements. The allocated resource
	 * MUST be released, even if it has 0 elements. If not released it could cause a memory leak.
	 * SEE: https://stackoverflow.com/questions/1087042/c-new-int0-will-it-allocate-memory
	*/
}

prj::my_vector::my_vector(std::initializer_list<double> list): capacity_{ list.size() }, size_{ capacity_ }, v_{ new double[capacity_] }
{
	std::copy(list.begin(), list.end(), v_);
}

prj::my_vector::my_vector(const my_vector& vector): capacity_{ vector.capacity_ }, size_{ vector.size_ }, v_{ new double[vector.capacity_] }
{
	std::copy(vector.v_, vector.v_ + vector.size_, v_);
}

prj::my_vector::my_vector(my_vector&& vector): capacity_{ vector.capacity_ }, size_{ vector.size_ }
{
	// clears original vector
	vector.size_ = 0;
	vector.capacity_ = 0;
	vector.v_ = nullptr;
}

prj::my_vector::~my_vector()
{
	// N.B it's safe to delete a nullptr
	delete[] v_;
}

void prj::my_vector::reserve(unsigned long int new_cap)
{
	// new_cap not greater than actual capacity -> do nothing
	if(new_cap <= capacity_) return;
	
	// allocating new capacity
	double* tmp = new double[new_cap];

	// copying data to the new buffer
	std::copy(v_, v_ + size_, tmp);

	// deallocating old buffer (it's translated to no-op if is null)
	delete[] v_;

	// moving pointer
	v_ = tmp;

	capacity_ = new_cap;
}

void prj::my_vector::push_back(double value)
{
	if(size_ == capacity_) 
	{
		if(size_ == 0) { reserve(1); }
		else { reserve(capacity_ * 2); }
	}
	
	v_[size_] = value;
	size_++;
}

void prj::my_vector::pop_back()
{
	if(size_ == 0) throw std::out_of_range("Vector index out of bound, negative index");
	size_--;
}

double& prj::my_vector::at(unsigned long int i)
{
	if(i >= size_) throw std::out_of_range("Vector index out of bound");
	return v_[i];
}

const double& prj::my_vector::at(unsigned long int i) const
{
	return at(i);
}

unsigned long int prj::my_vector::size() const
{
	return size_;
}

unsigned long int prj::my_vector::capacity() const
{
	return capacity_;
}

prj::my_vector& prj::my_vector::operator=(const my_vector& vector)
{
	double* tmp = new double[vector.capacity_];
	std::copy(vector.v_, vector.v_ + vector.size_, tmp);
	delete[] v_;
	v_ = tmp;
	size_ = vector.size_;
	capacity_ = vector.capacity_;
	return *this;
}

double& prj::my_vector::operator[] (unsigned long int i)
{
	return v_[i];
}

const double& prj::my_vector::operator[] (unsigned long int i) const
{
	return operator[](i);
}