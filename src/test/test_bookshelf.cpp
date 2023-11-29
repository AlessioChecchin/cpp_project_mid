#include "test/test_bookshelf.h"
#include "test/test.h"

#include "bookshelf.h"

namespace test
{
    void test_bookshelf_constructors()			
	{
		constexpr int kSize = 10;

		// Default constructor
		prj::Bookshelf a;
		check(a.size() == 0);
		check(a.capacity() == 0);

		// Sized constructor
		prj::Bookshelf b(kSize);
		check(b.size() == kSize);
		check(b.capacity() == kSize);

		// List-initialized constructor;
		prj::Bookshelf c {prj::Book(), prj::Book(), prj::Book()};
		check(c.size() == 3);
		check(c.capacity() == 3);

		// Copy constructor
		prj::Bookshelf d(c);
		check(d == c);

		// Move constructor
		prj::Bookshelf e = std::move(d);
		check(e == c);
		check(e != a);		
	}

    void test_bookshelf_methods()
	{
		// Test of 
		// 		.size()
		// 		.capacity()
		// 		.reserve()

		prj::Bookshelf a(3);
		check(a.size() == 3);
		check(a.capacity() == 3);

		a.reserve(100);

		check(a.size() == 3);
		check(a.capacity() == 100);

		// Test of 
		// 		.push_back();
		//		.pop_back();

		prj::Bookshelf b(5);
		for(int i=0; i<100; i++)
			b.push_back(prj::Book());

		check(b.size() == 5+100); 
		// when the space reserved is filled, it's doubled 
		// 5 -> 10 -> 20 -> 40 -> 80 -> 160
		check(b.capacity() == 160); 

		for(int i=0; i<105; i++)
			b.pop_back();
		check(b.size() == 0);
		check(b.capacity() == 160);


		// Test of 
		// 		at()
		//		const at()
		prj::Bookshelf c {
			prj::Book("a","aa","aaa","aaaaaaaaaaaaa"),
			prj::Book("b","bb","bbb","bbbbbbbbbbbbb"),
			prj::Book("c","cc","ccc","ccccccccccccc"),
			prj::Book("d","dd","ddd","ddddddddddddd")
		};
		check(c.at(0) == prj::Book("a","aa","aaa","aaaaaaaaaaaaa"));

		try
		{
			c.at(10);
			throw CheckError();
		}
		catch(const std::out_of_range& e){}
		
		
		const prj::Bookshelf c_const{
			prj::Book("a","aa","aaa","aaaaaaaaaaaaa"),
			prj::Book("b","bb","bbb","bbbbbbbbbbbbb"),
			prj::Book("c","cc","ccc","ccccccccccccc"),
			prj::Book("d","dd","ddd","ddddddddddddd")
		};
		check(c_const.at(1) == prj::Book("b","bb","bbb","bbbbbbbbbbbbb"));
		try
		{
			c_const.at(10);
			throw CheckError();
		}
		catch(const std::out_of_range& e){}
	
	}


    void test_bookshelf_operators()
	{

		// operator= 
		// operator== 
		// operator!=
		prj::Bookshelf a{ prj::Book("a","aa","aaa","aaaaaaaaaaaaa") };
		prj::Bookshelf b;
		b = a;
		check(a == b);
		b.push_back(prj::Book("d","dd","ddd","ddddddddddddd"));
		check(a != b);
		
		// operator[]
		// const operator[]
		check(prj::Book("a","aa","aaa","aaaaaaaaaaaaa") == a[0]);
		const prj::Bookshelf a_const{
			prj::Book("a","aa","aaa","aaaaaaaaaaaaa"),
			prj::Book("b","bb","bbb","bbbbbbbbbbbbb")
		};
		check(a[0] == a_const[0]);
	}


} //test