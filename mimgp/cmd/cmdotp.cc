#include "cmdotp.h"

std::deque<CmdOtp> gcmdotp; // Stores the output of the previous n commands.

CmdOtp get_last_cmdotp(void) {
	if (!gcmdotp.size()) {
		return CmdOtp("", "none");
	}

	return gcmdotp.front();
}
