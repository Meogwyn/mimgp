#ifndef _CMDOTP_H
#define _CMDOTP_H
#include <string>

#define CMD_HISTORY_LEN 5

static_assert(CMD_HISTORY_LEN >= 2);

class CmdOtp {
	public:
		std::string data;
		std::string type;

		CmdOtp(std::string data, std::string type) {
			this->data = data;
			this->type = type;
		}
		CmdOtp() {
			this->data = "";
			this->type = "none";
		}
};

CmdOtp gcmdotp[CMD_HISTORY_LEN]; // Stores the output of the previous command n 
				 // commands.

/*
 * Must be called before any commands are processed.
void init_gcmdotp() {
	for (int i = 0; i < CMD_HISTORY_LEN; i++) {
		gcmdotp[i] = CmdOtp("", "none")
	}
}
*/

#endif
