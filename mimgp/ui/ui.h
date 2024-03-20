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
			std::cout << "lollololol" << std::endl;
		}
		UInp user_input(void) {
			return UInp("lol");
		}
};
#endif
