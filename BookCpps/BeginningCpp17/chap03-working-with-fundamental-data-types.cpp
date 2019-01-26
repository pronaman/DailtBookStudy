#include "pch.h"

TEST(chap03, UsingTheBitwiseAnd) 
{
	//unsigned short font{ 0x064c };
	const unsigned short font{ 0b00000110'010'01100 };	//style 6m, italic, 12point
	const unsigned short sizeMask{ 0x1F };
	const auto size = static_cast<unsigned short>(font & sizeMask);
	EXPECT_EQ(0b0000'0000'0000'1100, size);
}

TEST(chap03, UsingBitwiseExclusiveOR)
{
	const unsigned short font{ 0b0000'0110'0100'1100 };
	const unsigned short bold{ 0b0000'0000'0010'0000 };
	EXPECT_EQ(0b0000'0110'0110'1100, font ^ bold);
}

TEST(chap03, EnumeratedDataTypes2)
{
	enum class Punctuation : char
	{
		Comma = ',',
		Exclamation = '!',
		Question = '?'
	};

	EXPECT_EQ(',', static_cast<char>(Punctuation::Comma));
}

TEST(chap03, AliasesForDataTypes)
{
	using BigOnes = unsigned long long;
	BigOnes myNum{};

	using StrPtr = std::shared_ptr<std::string>;
}

int value1 = 3;
TEST(chap03, TheLifetimeOfAVariable)
{
	int value1 = 4;
	EXPECT_EQ(3, ::value1);
	EXPECT_EQ(4, value1);
}