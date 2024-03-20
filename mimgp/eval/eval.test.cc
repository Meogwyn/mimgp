#include <gtest/gtest.h>
#include "mimgp/eval.h"

/*
 * The 'test' command outputs 'tost', followed by an enumerated and 
 * newline-separated list of the arguments passed to it.
 */
TEST(Eval, SimpleIO) {
	Eval ev = Eval();
	UInp uinp = UInp("test");
	CmdOtp cmdotp;
	CmdOtp cmdotp_true = CmdOtp("tost", "str");

	cmdotp = ev.eval(uinp);
	ASSERT_EQ(cmdotp.type, cmdotp_true.type);
	ASSERT_EQ(cmdotp.data, cmdotp_true.data);
}
TEST(Eval, ExprIO) {
	Eval ev = Eval();
	UInp uinp1 = UInp("group 25"); // Set modulus to 25.
	UInp uinp2 = UInp("test (2 + 3) bla (4+ 5*   (3+ 7) + 4^2 + 3^(5 *1))");
	CmdOtp cmdotp1;
	CmdOtp cmdotp_true1 = CmdOtp("", "str");
	CmdOtp cmdotp2;
	CmdOtp cmdotp_true2 = CmdOtp(
		"tost\n" 
		"1. 5\n"
		"2. bla\n"
		"3. 13"
	, "str");
	ASSERT_EQ(cmdotp1.type, cmdotp1_true.type);
	ASSERT_EQ(cmdotp1.data, cmdotp1_true.data);
	ASSERT_EQ(cmdotp2.type, cmdotp2_true.type);
	ASSERT_EQ(cmdotp2.data, cmdotp2_true.data);
}
