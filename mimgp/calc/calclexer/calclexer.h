#ifndef _CALCLEXER_H
#define _CALCLEXER_H
#include "mimgp/lexer/tokens.h"
#include "mimgp/calc/calclexer/calctokens.h"

class CalcLexer {
	public:
		/*
		 * Lexes expr, stores the result in tkns.
		 */
		void lex(CalcTokens &tkns, Expression expr) {
		}
};

#endif
