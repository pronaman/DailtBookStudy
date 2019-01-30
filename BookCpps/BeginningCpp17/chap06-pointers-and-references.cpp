#include "pch.h"

TEST(chap06, TheDifferenceBetweenPointers) 
{
	long numbers[]{ 10, 20, 30, 40, 50, 60, 70, 80 };
	long *pnum1{ &numbers[6] };
	long *pnum2{ &numbers[1] };

	std::ptrdiff_t difference2{ pnum2 - pnum1 };
	EXPECT_EQ(-5, difference2);
}