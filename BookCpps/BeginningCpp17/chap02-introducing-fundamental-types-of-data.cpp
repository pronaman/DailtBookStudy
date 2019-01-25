#include "pch.h"

TEST(Chap02, Initilization)
{
	const int countDefault0{0};
	EXPECT_EQ(0, countDefault0);

	const int countNoDefault{};
	EXPECT_EQ(0, countNoDefault);

	const int countDefault20{20};
	EXPECT_EQ(20, countDefault20);

	//note that there are no restrictions on how to group the digit.
	const long long distance{15'000'000LL};
	EXPECT_EQ(15000000, distance);
}

TEST(Chap02, InitializationWithoutPermittedRange)
{
	//const unsigned char highScore{ 513 };
	const unsigned char highScore = 513;
	EXPECT_FALSE(513 == highScore);
}

TEST(Chap02, HexadecimalLiterals)
{
	const unsigned int color = 0x0f0d0e;
	EXPECT_EQ(0x0f0d0e, color);

	const unsigned int color2{ 0x0f0d0e };
	EXPECT_EQ(0x0f0d0e, color2);

	const unsigned long value{ 0xDEADlu };
	EXPECT_EQ(57005, value);
}

TEST(Chap02, OctalLiterals)
{
	const int value1 = 0657;
	const int value2{ 0657 };
	EXPECT_EQ(431, value2);
}

TEST(Chap02, SizeOf)
{
	int height{ 74 };
	EXPECT_EQ(4, sizeof(height));

	EXPECT_EQ(8, sizeof(long long));

	EXPECT_EQ(4, sizeof(height * height / 2));
}

TEST(Chap02, MathematicalFunctions)
{
	EXPECT_EQ(2, abs(-2));

	EXPECT_EQ(3, ceil(2.5));
	EXPECT_EQ(-2, ceil(-2.5));

	EXPECT_EQ(2, floor(2.5));
	EXPECT_EQ(-3, floor(-2.5));

	EXPECT_TRUE(abs(7.38906 - exp(2)) < 0.0001);
	//EXPECT_EQ(0.693147, log(2));
	EXPECT_TRUE(abs(0.693147 - log(2)) < 0.0001);

	EXPECT_EQ(2, log10(100));

	EXPECT_EQ(100, pow(10, 2));

	EXPECT_EQ(3, sqrt(9));
	//EXPECT_EQ(3.1662, sqrt(11));

	EXPECT_EQ(4, round(3.5));
	EXPECT_EQ(3, round(3.4));
	EXPECT_EQ(-3, round(-2.5));
}