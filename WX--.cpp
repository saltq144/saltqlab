
//All required header inclusions
#include "inc.h"


int main(int argc, char* argv[]) {
	
	bool boolean_flags_forceHelp = false;
	bool boolean_flags_help = false;
	for (int i = 1; i < argc; i++) {
		//Lack of switch statement because std::string(argv[i]) is not an integral or
		//enumerated value.
		if (std::string(argv[i]) == "-h") {
			boolean_flags_help = true;
		}
		else if (std::string(argv[i]) == "-t") {
			std::cout << "Testing not implemented";
		}
		else {
			boolean_flags_forceHelp = true;
		}
	}
	if (boolean_flags_forceHelp || boolean_flags_help || argc == 1) {
		usage();
	}
	USsleep(5000000);
}
