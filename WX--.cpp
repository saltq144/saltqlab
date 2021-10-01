
//All required header inclusions
#include "inc.h"


//Switch out the "//#pragma"s for "#pragma"s if you are using  GCC / clang like this:
//If you are using vs then dont, if you are using neither i have no words for you
/*
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
//#pragma warning( push )
//#pragma warning( disable : 4100 )
int main(int argc, char* argv[]) {
//#pragma warning( pop )
#pragma GCC diagnostic pop
*/

//#pragma GCC diagnostic push
//#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma warning( push )
#pragma warning( disable : 4100 )
int main(int argc, char* argv[]) {
#pragma warning( pop )
//#pragma GCC diagnostic pop
	
	int boolean_flags_argvIndex = 1;
	bool boolean_flags_forceHelp = false;
	bool boolean_flags_help = false;
	
boolean_flags_whileStart:
	//string(argv[1]) == "file"
	if (argv[boolean_flags_argvIndex] == NULL) {
		goto boolean_flags_whileEnd;
	} else if (std::string(argv[boolean_flags_argvIndex]) == "-h") {
		boolean_flags_help = true;
	} else if (std::string(argv[boolean_flags_argvIndex]) == argv[0]) {
		std::cout << "\n*\n**\n***\n****\n";
		std::cout << "This message should not be displayed under normal circumstances          \n";
		std::cout << "Please contact support@creationship27.com and report this error          \n";
		std::cout << "*\n**\n***\n****";
	} else {
		boolean_flags_forceHelp = true;
	}
	boolean_flags_argvIndex++;
	goto boolean_flags_whileStart;
boolean_flags_whileEnd:
	if (boolean_flags_forceHelp || boolean_flags_help) {
		usage();
	}
	USsleep(5000000);
}