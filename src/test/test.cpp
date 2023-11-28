#include "test/test.h"

namespace test
{
	void check(bool flag)
	{
		if(!flag) throw CheckError();
	}
} // test