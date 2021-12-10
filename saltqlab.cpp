
//All required header inclusions
#include "inc.hpp"


int main(int argc, char* argv[]) {
	
	bool boolean_flags_forceHelp = false;
	bool boolean_flags_help = false;
	bool boolean_flags_test = false;
  bool boolean_flags_license_help = false;
	for (int i = 1; i < argc; i++) {
		//Lack of switch statement because std::string(argv[i]) is not an integral or
		//enumerated value.
		if (std::string(argv[i]) == "-h") {
			boolean_flags_help = true;
		} else if (std::string(argv[i]) == "-t") {
			boolean_flags_test = true;
    } else if (std::string(argv[i]) == "-hl") {
      boolean_flags_license_help = true;
		} else {
			boolean_flags_forceHelp = true;
		}
	}
	if (boolean_flags_forceHelp || boolean_flags_help || argc == 1) {
		usage();
	} if (boolean_flags_test) {
		std::cout << "Testing mode not implemented\n";
	} if (boolean_flags_license_help) {
    license();
  } if (boolean_flags_help || boolean_flags_forceHelp || boolean_flags_license_help || boolean_flags_test) {
    exit(0);
  }
}
