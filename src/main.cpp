#include <iostream>
#include <vector>
#include "my_vector.h"

int main()
{
	prj::my_vector xx;

	for(int i = 0; i < xx.size(); i++)
	{
		std::cout << xx[i] << " ";
	}
}
