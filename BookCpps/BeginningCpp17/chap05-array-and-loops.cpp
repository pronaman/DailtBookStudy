#include "pch.h"

TEST(chap05, Arrays1) 
{
	unsigned int height[6]{ 26, 37, 47 };

	EXPECT_EQ(26, height[0]);
	EXPECT_EQ(37, height[1]);
	EXPECT_EQ(47, height[2]);
	EXPECT_EQ(0, height[3]);
	EXPECT_EQ(0, height[4]);
	EXPECT_EQ(0, height[5]);
}

TEST(chap05, DeterminingTheSizeOfAnArray)
{
	const int values[]{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
	const size_t size = std::size(values);
	EXPECT_EQ(10, size);
}

TEST(chap05, TheRangeBasedForLoop)
{
	int values[]{ 2, 4, 5, 7, 11, 13, 15, 17, 19, 23, 29 };
	int total{};
	for (int x : values)
		total += x;

	EXPECT_EQ(145, total);
}

TEST(chap05, ArraysOfCharacters)
{
	char vowels[10]{ "Mae West" };
	EXPECT_EQ('\0', vowels[8]);
	EXPECT_EQ('\0', vowels[9]);
}

TEST(chap05, InitializingMultidimensionalArrays)
{
	double carrots[3][4]
	{
		{2.5, 3.2,    },
		{4.1		  },
		{2.8, 2.3, 0.9}
	};

	EXPECT_EQ(0.0, carrots[0][2]);
	EXPECT_EQ(4.1, carrots[1][0]);
	EXPECT_EQ(0.0, carrots[1][1]);
	EXPECT_EQ(0.0, carrots[1][2]);

//	char stars[][80]
//	{
//		"Robert Redford",
//		"Hopalong Cassidy",
//		"Lassie",
//		"Slim Pickens",
//		"Boris Karloff",
//		"Oliver Hardy"
//	};
}

#include <array>
TEST(chap05, AlternativesToUsingAnArray)
{
	std::array<double, 100> values{ 0.5, 1.0, 1.5, 2.0 };
	EXPECT_EQ(2.0, values[3]);
	EXPECT_EQ(0.0, values[4]);
	EXPECT_EQ(0.0, values[5]);

	values.fill(3.1);
	EXPECT_EQ(3.1, values[0]);
	EXPECT_EQ(3.1, values[50]);
	EXPECT_EQ(3.1, values[99]);

	EXPECT_EQ(100, values.size());
}

TEST(chap05, OperatorOnArrayAsAWhole)
{
	std::array<double, 4> these{ 1.0, 2.0, 3.0, 4.0 };
	std::array<double, 4> those{ 1.0, 2.0, 3.0, 4.0 };
	std::array<double, 4> them{ 1.0, 1.0, 5.0, 5.0 };

	EXPECT_TRUE(these == those);
	EXPECT_TRUE(those != them);
	EXPECT_TRUE(these > them);	

	them = these;
	EXPECT_TRUE(them == these);

	const double* data = these.data();	
	EXPECT_EQ(1.0, data[0]);
	EXPECT_EQ(2.0, data[1]);
	EXPECT_EQ(3.0, data[2]);
	EXPECT_EQ(4.0, data[3]);	
}