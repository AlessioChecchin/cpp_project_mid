#include "test/test_date.h"

#include <stdexcept>
#include <vector>
#include <sstream>
#include <string>

#include "test/test.h"
#include "date.h"


namespace test
{

void test_date_operators()
{
	// operator=
	prj::Date a;
	prj::Date b = a;
	check(b.get_day() == a.get_day());
	check(b.get_month() == a.get_month());
	check(b.get_year() == a.get_year());

	// operator==
	check(a == b);

	// operator !=
	prj::Date c(1,1,1300);
	check(a != c);

	// operator<<
	std::ostringstream os;
	std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	for(int i=0; i<12; i++)
	{
		prj::Date date(1,i+1,1900);
		os << date;
		std::string dateString = "1 "+months[i]+" 1900";
		check(os.str() == dateString);
		
		// Resets ostringstream
		os.str("");		//required to clear the stream
		os.clear();		//required to clear errors
	}

}

void test_date_constructors()
{
	// Default constructor
	prj::Date a;
	check(a.get_day() == 1);
	check(a.get_month() == 1);
	check(a.get_year() == 1900);

	// Complete constructor
	prj::Date b(4,3,2003);
	check(b.get_day() == 4);
	check(b.get_month() == 3);
	check(b.get_year() == 2003);

	// Copy constructor
	prj::Date c(b);
	check(b.get_day() == c.get_day());
	check(b.get_month() == c.get_month());
	check(b.get_year() == c.get_year());

	// Move constructor
	prj::Date moved (std::move(c));
	check(b.get_day() == moved.get_day());
	check(b.get_month() == moved.get_month());
	check(b.get_year() == moved.get_year());

}

bool is_valid_date(int day, int month, int year)
{
	try
	{
		prj::Date d(day, month, year);
		return true;
	}
	catch(const std::invalid_argument& e)
	{
		return false;
	}
}

void test_date_valid()
{
	check(is_valid_date(12, 2, -1) == true);

	check(is_valid_date(12, 2, 1800) == true);
	check(is_valid_date(15, 2, 1899) == true);
	check(is_valid_date(15, 2, 1900) == true);
	check(is_valid_date(15, 2, 1932) == true);
	check(is_valid_date(29, 9, 2003) == true);
}

void test_date_leap_years()
{
	std::vector<int> leap_years {
		1904, 1908, 1912, 1916, 1920, 1924, 1928, 1932, 1936,
		1940, 1944, 1948, 1952, 1956, 1960, 1964, 1968, 1972, 1976,
		1980, 1984, 1988, 1992, 1996, 2000, 2004, 2008, 2012, 2016,
		2020, 2024, 2028, 2032, 2036, 2040, 2044, 2048, 2052, 2056,
		2060, 2064, 2068, 2072, 2076, 2080, 2084, 2088, 2092, 2096,
		2104, 2108, 2112, 2116, 2120, 2124, 2128, 2132, 2136,
		2140, 2144, 2148, 2152, 2156, 2160, 2164, 2168, 2172, 2176,
		2180, 2184, 2188, 2192, 2196, 2204, 2208, 2212, 2216,
		2220, 2224, 2228, 2232, 2236, 2240, 2244, 2248, 2252, 2256,
		2260, 2264, 2268, 2272, 2276, 2280, 2284, 2288, 2292, 2296,
		2304, 2308, 2312, 2316, 2320, 2324, 2328, 2332, 2336,
		2340, 2344, 2348, 2352, 2356, 2360, 2364, 2368, 2372, 2376,
		2380, 2384, 2388, 2392, 2396, 2400, 2404, 2408, 2412, 2416,
		2420, 2424, 2428, 2432, 2436, 2440, 2444, 2448, 2452, 2456,
		2460, 2464, 2468, 2472, 2476, 2480, 2484, 2488, 2492, 2496,
		2504, 2508, 2512, 2516, 2520, 2524, 2528, 2532, 2536,
		2540, 2544, 2548, 2552, 2556, 2560, 2564, 2568, 2572, 2576,
		2580, 2584, 2588, 2592, 2596, 2604, 2608, 2612, 2616,
		2620, 2624, 2628, 2632, 2636, 2640, 2644, 2648, 2652, 2656,
		2660, 2664, 2668, 2672, 2676, 2680, 2684, 2688, 2692, 2696,
		2704, 2708, 2712, 2716, 2720, 2724, 2728, 2732, 2736,
		2740, 2744, 2748, 2752, 2756, 2760, 2764, 2768, 2772, 2776,
		2780, 2784, 2788, 2792, 2796, 2800, 2804, 2808, 2812, 2816,
		2820, 2824, 2828, 2832, 2836, 2840, 2844, 2848, 2852, 2856,
		2860, 2864, 2868, 2872, 2876, 2880, 2884, 2888, 2892, 2896,
		2904, 2908, 2912, 2916, 2920, 2924, 2928, 2932, 2936,
		2940, 2944, 2948, 2952, 2956, 2960, 2964, 2968, 2972, 2976,
		2980, 2984, 2988, 2992, 2996
	};

	std::vector<int> not_leap_years = { 1900, 2100, 2300, 2500, 2700, 2900, 2200, 2600, 3000 };

	for(int i = 0; i < leap_years.size(); i++)
	{
		check(is_valid_date(29, 2, leap_years[i]) == true);
	}

	for(int i = 0; i < not_leap_years.size(); i++)
	{
		check(is_valid_date(29, 2, not_leap_years[i]) == false);
	}
}

void test_date_invalid()
{
	check(is_valid_date(29, 13, 2003) == false);
	check(is_valid_date(29, 2, 2001) == false);
	check(is_valid_date(12, 13, 2001) == false);
	check(is_valid_date(-1, 1, 2001) == false);
	check(is_valid_date(1, 13, 1384) == false);
}

void test_date_getter()
{
	prj::Date a(29, 12, 1999);
	check(a.get_day() == 29);
	check(a.get_month() == 12);
	check(a.get_year() == 1999);

	prj::Date b(4, 6, -1);
	check(b.get_day() == 4);
	check(b.get_month() == 6);
	check(b.get_year() == -1);
}

} // test