#include <iostream>
#include <chrono>
#include <ctime>


int main()
{
	// Since c++ 11
	// https://en.cppreference.com/w/cpp/chrono/system_clock
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

	std::time_t time = std::chrono::system_clock::to_time_t(now);

	std::tm utc_tm = *std::gmtime(&time);

	std::cout << "Year" << (1900 + utc_tm.tm_year) << " " << utc_tm.tm_mday << " " << utc_tm.tm_mon;

	return 0;
}