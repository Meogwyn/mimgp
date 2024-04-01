#include <gtest/gtest.h>
#include "mimgp/calc/calclexer/calclexer.h"

// Case 1: 'normal expr'.
TEST(CalcLexer, SimpleLex) {
	CalcLexer cl{};
	CalcTokens ct{};
	CalcTokens ct_true{};
	Expression expr{"2 + 3 *8 ^ (16 * 3 + 1)"}; 

	ct_true.push_back(CalcTokenNum("2"));
	ct_true.push_back(CalcTokenOp("+"));
	ct_true.push_back(CalcTokenNum("3"));
	ct_true.push_back(CalcTokenOp("*"));
	ct_true.push_back(CalcTokenNum("8"));
	ct_true.push_back(CalcTokenOp("^"));
	ct_true.push_back(CalcTokenBr("("));
	ct_true.push_back(CalcTokenNum("16"));
	ct_true.push_back(CalcTokenOp("*"));
	ct_true.push_back(CalcTokenNum("3"));
	ct_true.push_back(CalcTokenOp("+"));
	ct_true.push_back(CalcTokenNum("1"));
	ct_true.push_back(CalcTokenBr(")"));

	cl.lex(ct, expr);

	ASSERT_EQ(ct_true, ct);
}
TEST(CalcLexer, SingleToken) {
	CalcLexer cl{};
	CalcTokens ct{};
	CalcTokens ct_true{};
	Expression expr{"5"};

	ct_true.push_back(CalcTokenNum("5"));

	cl.lex(ct, expr);

	ASSERT_EQ(ct_true, ct);
}
TEST(CalcLexer, Whitespace) {
	CalcLexer cl{};
	CalcTokens ct{};
	CalcTokens ct_true{};
	Expression expr{"2 ^     	3"};

	ct_true.push_back(CalcTokenNum("2"));
	ct_true.push_back(CalcTokenOp("^"));
	ct_true.push_back(CalcTokenNum("3"));

	cl.lex(ct, expr);

	ASSERT_EQ(ct_true, ct);
}
