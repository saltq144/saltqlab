#pragma once
#include <fstream>
#include <string>

std::string getContent(std::string path) {
	std::string content = "";
	std::string line = "";
	std::ifstream file(path);

	if (file.is_open()) {
		while (std::getline(file, line)) {
			content = content + line;
			content = content + "\n";
		}
	}

	file.close();
	return content;
}


bool exists(std::string path) {
	std::ifstream file(path);
	if (file) {
		file.close();
		return true;
	} else {
		file.close();
		return false;
	}
}

bool overwriteContent(std::string path, std::string content) {
	std::ofstream file(path,
		std::ios::in                      | 
		std::ios::out                     | 
		std::ios::binary                  | 
		std::ios::trunc);
	if (file.is_open()) {
		file << content;
		file.close();
		return true;
	}
	return false;
}
