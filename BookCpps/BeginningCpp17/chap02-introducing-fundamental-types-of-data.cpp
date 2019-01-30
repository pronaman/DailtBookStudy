#include "pch.h"

TEST(chap02, Initilization)
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

TEST(chap02, InitializationWithoutPermittedRange)
{
	//const unsigned char highScore{ 513 };
	const unsigned char highScore = 513;
	EXPECT_FALSE(513 == highScore);
}

TEST(chap02, HexadecimalLiterals)
{
	const unsigned int color = 0x0f0d0e;
	EXPECT_EQ(0x0f0d0e, color);

	const unsigned int color2{ 0x0f0d0e };
	EXPECT_EQ(0x0f0d0e, color2);

	const unsigned long value{ 0xDEADlu };
	EXPECT_EQ(57005, value);
}

TEST(chap02, OctalLiterals)
{
	const int value1 = 0657;
	const int value2{ 0657 };
	EXPECT_EQ(431, value2);
}

TEST(chap02, SizeOf)
{
	int height{ 74 };
	EXPECT_EQ(4, sizeof(height));

	EXPECT_EQ(8, sizeof(long long));

	EXPECT_EQ(4, sizeof(height * height / 2));
}

TEST(chap02, MathematicalFunctions)
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

TEST(chap02, ExplicitTypeConversion)
{
	double value1{ 10.9 };
	double value2{ 15.9 };
	int wholeNumber{ static_cast<int>(value1) + static_cast<int>(value2) };
	EXPECT_EQ(25, wholeNumber);	
}

//TEST(Chap02, FindingTheLimits)
//{
//	double maxValue{ std::numeric_limits<double>::max() };
//	//EXPECT_EQ(1.79769e+308, maxValue);
//	//EXPECT_TRUE(abs(1.79769e+308 - maxValue) < 3331);
//	EXPECT_EQ(33, abs(1.79769e+308 - maxValue));
//}


TEST(chap02, WorkingWithUnicdeCharacters)
{
	wchar_t wch{ L'Z' };
	wchar_t wch2{ L'\x0438' };

	char16_t letter{ u'B' };
	char16_t cyr{ u'\x0438' };

	char32_t letter32{ U'B' };
	char32_t cyr32{ U'\x044f' };
}

TEST(chap02, AutoKeyword)
{
	auto list = { 1, 2, 3 };
	
}
