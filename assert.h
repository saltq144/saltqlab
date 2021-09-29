#pragma once

#include "inc.h"

void assert(bool condition, string error) {
	if (!condition) {
		std::cout << error;
		exit(EXIT_FAILURE);
	}
}