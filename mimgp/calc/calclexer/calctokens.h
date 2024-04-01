#ifndef _CALCTOKENS_H
#define _CALCTOKENS_H

#define CALCTOK_TAG_NUM 0
#define CALCTOK_TAG_OP 1
#define CALCTOK_TAG_BR 2

#include <string>
#include <vector>

class CalcToken {
	public:
		std::string val;
		int tag;
		bool operator==(const CalcToken &op) const {
			return (this->val == op.val) && (this->tag == op.tag);
		}
};
// For number literals.
class CalcTokenNum : public CalcToken {
	public:
		CalcTokenNum(std::string tok) {
			this->val = tok;
			this->tag = CALCTOK_TAG_NUM;
		}
};
// For operators.
class CalcTokenOp : public CalcToken {
	public:
		CalcTokenOp(std::string tok) {
			this->val = tok;
			this->tag = CALCTOK_TAG_OP;
		}
};
// For opening and closing brackets.
class CalcTokenBr : public CalcToken {
	public:
		CalcTokenBr(std::string tok) {
			this->val = tok;
			this->tag = CALCTOK_TAG_BR;
		}
};
class CalcTokens : public std::vector<CalcToken> {
};
#endif
