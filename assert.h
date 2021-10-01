#pragma once

#include "inc.h"

void assert(bool condition, std::string error) {
	if (!condition) {
		std::cout << error;
		exit(EXIT_FAILURE);
	}
}