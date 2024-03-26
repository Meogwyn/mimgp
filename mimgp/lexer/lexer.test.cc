#include <gtest/gtest.h>
#include "mimgp/lexer/lexer.h"

/*
 * Tests
 */

TEST(Lexer, BasicKeywords) {
	Lexer lxr{};
	Tokens tkns{};
	Tokens tkns_true{};
	int size = 0;
	UInp uinp1{"abc def XYZ"};

	// Set up true tokens.
	tkns_true.push_back(Keyword{"abc"});
	tkns_true.push_back(Keyword{"def"});
	tkns_true.push_back(Keyword{"XYZ"});

	// Get test tokens.
	lxr.lex(tkns, uinp1);

	// Compare results.
	size = tkns.size();
	ASSERT_EQ(tkns_true.size(), size);
	for (int i = 0; i < size; i++) {
		ASSERT_EQ(tkns_true[i].val, tkns_true[i].val);
	}
}
TEST(Lexer, BasicQuotedKeywords) {
	Lexer lxr{};
	Tokens tkns{}; // Tokens produced by lexer.
	Tokens tkns_true{};
	int size = 0; // Size of final tokens.
	UInp uinp1{"abc \"def abcfg\" XYZ"}; // Test user input.

	// Set up true tokens.
	tkns_true.push_back(Keyword{"abc"});
	tkns_true.push_back(Keyword{"def abcfg"});
	tkns_true.push_back(Keyword{"XYZ"});

	// Get test tokens.
	lxr.lex(tkns, uinp1);

	// Compare results.
	size = tkns.size();
	ASSERT_EQ(tkns_true.size(), size);
	for (int i = 0; i < size; i++) {
		ASSERT_EQ(tkns_true[i].val, tkns_true[i].val);
	}
}
TEST(Lexer, EscapeChars) {
	Lexer lxr{};
	Tokens tkns{}; // Tokens produced by lexer.
	Tokens tkns_true{};
	int size = 0; // Size of final tokens.
	UInp uinp1{"abc \"def \\\\ \\\"abcfg\" XYZ"}; // Test user input.

	// Set up true tokens.
	tkns_true.push_back(Keyword{"abc"});
	tkns_true.push_back(Keyword{"def \\ \" abcfg"});
	tkns_true.push_back(Keyword{"XYZ"});

	// Get test tokens.
	lxr.lex(tkns, uinp1);

	// Compare results.
	size = tkns.size();
	ASSERT_EQ(tkns_true.size(), size);
	for (int i = 0; i < size; i++) {
		ASSERT_EQ(tkns_true[i].val, tkns_true[i].val);
	}
}
TEST(Lexer, Expressions) {
	Lexer lxr{};
	Tokens tkns{}; // Tokens produced by lexer.
	Tokens tkns_true{};
	int size = 0; // Size of final tokens.
	UInp uinp1{"abc XYZ [2 + 3 *8 ^ (16 * 3 + 1)]"}; // Test user input.

	// Set up true tokens.
	tkns_true.push_back(Keyword{"abc"});
	tkns_true.push_back(Keyword{"XYZ"});
	tkns_true.push_back(Expression{"[2 + 3 *8 ^ (16 * 3 + 1)]"});

	// Get test tokens.
	lxr.lex(tkns, uinp1);

	// Compare results.
	size = tkns.size();
	ASSERT_EQ(tkns_true.size(), size);
	for (int i = 0; i < size; i++) {
		ASSERT_EQ(tkns_true[i].val, tkns_true[i].val);
	}
}
