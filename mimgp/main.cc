#include <iostream>
#include "mimgp/ui/ui.h"
#include "mimgp/eval/eval.h"

int main(int argc, char **argv) {
	UI ui = UI();
	UInp uinp = UInp();
	Eval eval = Eval();

	// TODO: Signal handler and clean exit
	while (1) {
		ui.render();
		uinp = ui.user_input();
		eval.eval(uinp);
	}
	return 0;
}
