#ifndef TEST_H_
#define TEST_H_

#include <cassert>
#include <iostream>

#ifndef LOGGER_SEPARATOR 
	#define LOGGER_SEPARATOR " "
#endif // !LOGGER_SEPARATOR

#ifndef LOGGER_ENDL 
	#define LOGGER_ENDL std::endl
#endif // !LOGGER_ENDL

template <typename T>
void Print(T value) { std::cout << value; }

template <typename First, typename... Rest>
void Print(First firstValue, Rest... rest) { Print(firstValue); std::cout << LOGGER_SEPARATOR; Print(rest...); }

#define TEST int main(void)
#define LOG(...) Print(__VA_ARGS__);

#endif