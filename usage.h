#pragma once

#include <iostream>
#include "lpi.h"

void usage() {
	std::cout << "\n*\n**\n***\n****\n";
	std::cout << "Usage: WX-- [ -h ]                                  \n";
	std::cout << "     Argument:          Description:                \n\n";
	std::cout << "     No args            Displays help.              \n";
	std::cout << "     Invalid args       Displays help.              \n";
	std::cout << "     -h                 Displays help.              \n";
	std::cout << "****\n***\n**\n*";
	USsleep(1000000);
}