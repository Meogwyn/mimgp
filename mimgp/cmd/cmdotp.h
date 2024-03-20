#ifndef _CMDOTP_H
#define _CMDOTP_H
#include <string>
#include <iostream>
#include <deque>
#include <stdlib.h>
#include <vector>

#define CMD_HISTORY_LEN 5

const std::vector<std::string> allowed_types{"none", "str", "table"};

static_assert(CMD_HISTORY_LEN >= 2);

class CmdOtp {
	public:
		std::string data;
		std::string type;

		CmdOtp(std::string data, std::string type) {
			this->data = data;
			this->type = type;
			bool found = false;

			for (unsigned int i = 0; i < allowed_types.size(); i++) {
				if (allowed_types[i] == type) {
					found = true;
					break;
				}
			}

			if (!found) {
				std::cout << "AAAAAAA" << data << "," << type << std::endl;
				exit(-1); // Replace this with something better.
			}
		}
		CmdOtp() {
			this->data = "";
			this->type = "none";
		}
};

/* 
 * Commands are stored in chronological order - front is the latest, back is the
 * oldest.
 */
extern std::deque<CmdOtp> gcmdotp; // Stores the output of the previous n commands.

/*
 * Gets the output from the latest executed command. Returns a none if there is 
 * no such output.
 */
CmdOtp get_last_cmdotp(void);

#endif
