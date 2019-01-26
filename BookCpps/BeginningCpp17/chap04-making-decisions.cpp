#include "pch.h"
#include <locale>
#include <cctype>

TEST(chap04, InitializationStatements) 
{
	const char input = 'A';
	if (const auto lo{ static_cast<char>(std::tolower(input)) };  lo >= 'a' && lo <= 'z')
	{
		EXPECT_TRUE(true);
	}
	else
	{
		EXPECT_TRUE(false);
	}

	switch (const auto lo{ static_cast<char>(std::tolower(input)) };lo)
	{
	case 'a':
		EXPECT_TRUE(true);
		break;
	default:
		EXPECT_TRUE(false);
		break;
	}
}