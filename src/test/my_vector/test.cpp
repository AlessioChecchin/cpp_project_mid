#include "test/test.h"
#include "my_vector.h"

void test_constructor()
{
	prj::my_vector a;
	assert(a.size() == 0);
	assert(a.capacity() == 0);

	constexpr int size = 10;

	prj::my_vector b(size);
	assert(b.size() == size);
	assert(b.capacity() == size);

	prj::my_vector c(b);
	assert(c.size() == size);
	assert(c.capacity() == size);

	prj::my_vector d(c);
}

void test_push_back()
{
	prj::my_vector a;

	constexpr int size = 100;

	for(int i = 0; i < size; i++)
	{
		a.push_back(i + 1);
	}

	for(int i = 0; i < size; i++)
	{
		assert(a[i] == i + 1);
		assert(a.at(i) == i + 1);
	}

	a.pop_back();

	assert(a[a.size() - 1] == size - 1);
	assert(a.size() == size - 1);
}

TEST {

	test_constructor();
	test_push_back();

	LOG("okok", "done", 123);

	return 0;
}