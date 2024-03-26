#ifndef _TOKENS_H
#define _TOKENS_H

#define TOK_TAG_KEYWORD 0 
#define TOK_TAG_EXPRESSION 1 

#include <string>
#include <vector>

class Token {
	public:
		int tag;
		std::string val;
};
class Keyword : public Token {
	public:
		Keyword(std::string tokstr) {
			this->tag = 0;
			this->val = std::string(tokstr);
		}
};
class Expression : public Token {
	public:
		Expression(std::string tokstr) {
			this->tag = 1;
			this->val = std::string(tokstr);
		}
};
class Tokens : public std::vector<Token> {
};
#endif
