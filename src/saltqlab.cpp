
//All required header inclusions
#include "inc.hpp"
#include "saltqlab.hpp"

// Debug stuff
#define DEBUG_
#ifdef DEBUG_
#define debugPrint(x) std::cout << "\x1b[32m" << __LINE__ << " - " << (__FILE__) << " - " << (x) << "\x1b[0m";
#else
#define debugPrint(x)
#endif

struct test_t;

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
	} if (boolean_flags_help         || boolean_flags_forceHelp    || boolean_flags_license_help || boolean_flags_test) {
    	exit(0);
  }
}

namespace test {
	void test() {

	}
}
namespace bdss {
	std::string stringInt(char x) {
		std::string o = "";
		// Extract individual digits
		o += '0' + (x % 10); x = ( x - (x % 10 )) / 10;
		o += '0' + (x % 10); x = ( x - (x % 10 )) / 10;
		o += '0' + (x % 10); x = ( x - (x % 10 )) / 10;
		// Reverse character order
		o = std::string(o.rbegin(), o.rend());
		// Remove leading zeros
		o.erase(0, std::min(o.find_first_not_of('0'), o.size()-1));
		return o;
	}
	std::string encode(std::string x) {
		std::string o = "";
		for (const char& c : x) {
			o += stringInt(c);
			o += ":";
		}
		debugPrint(":" + o);
		return ":" + o;
	}
}

struct test_t {
	std::string output;
	bool output_raw;
	std::string arguments;
	bool arguments_raw;
};