#ifndef _UINP_H
#define _UINP_H
#include <string>

class UInp {
	public:
		std::string data;

		UInp(std::string data) {
			this->data = data;
		}
		UInp() {
			this->data = std::string("");
		}
};
#endif
