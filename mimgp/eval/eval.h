#ifndef _EVAL_H
#define _EVAL_H
#include "mimgp/cmd/cmdotp.h"
#include "mimgp/ui/uinp.h"

class Eval {
	public:
		CmdOtp eval(UInp &uinp) {
			return CmdOtp("abc", "def");
		}
};
#endif
