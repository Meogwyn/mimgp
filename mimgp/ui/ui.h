#ifndef _UI_H
#define _UI_H

#include <iostream>

#include "mimgp/ui/uinp.h"
#include "mimgp/cmd/cmdotp.h"

class UI {
	public:
		UI(void) {
		}
		void render() {
			std::cout << get_last_cmdotp().data << std::endl;
		}
		UInp user_input(void) {
			std::string inp{""};

			std::getline(std::cin, inp);
			
			return UInp(inp);
		}
};
#endif
