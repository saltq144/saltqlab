#pragma once
#include <fstream>
#include <string>
#include <errno.h>
#include "inc.h"

namespace disk {
	namespace file {
		std::string getContent(std::string path) {
			std::string content = "";
			std::string line = "";
			std::ifstream fil(path);

			if (fil.is_open()) {
				while (std::getline(fil, line)) {
					content = content + line;
					content = content + "\n";
				}
			}

			fil.close();
			return content;
		}



		bool exists(std::string path) {
			std::ifstream fil(path);
			if (fil) {
				fil.close();
				return true;
			}
			else {
				fil.close();
				return false;
			}
		}
		bool create(std::string path) {
			std::ofstream fil(path,
				std::ios::in |
				std::ios::out |
				std::ios::binary |
				std::ios::trunc);
			if (fil) return true;
			fil << std::endl;
			if (fil) return true;
			return false;
		}


		bool overwriteContent(std::string path, std::string content) {
			std::ofstream file(path,
				std::ios::in |
				std::ios::out |
				std::ios::binary |
				std::ios::trunc);
			if (file.is_open()) {
				file << content;
				file.close();
				return true;
			}
			return false;
		}
	}
	namespace dir {
		bool exists(std::string path) {
			struct stat info;

			int statRC = stat(path.c_str(), &info);
			if (statRC != 0)
			{
				if (errno == ENOENT) { return false; } // something along the path does not exist
				if (errno == ENOTDIR) { return false; } // something in path prefix is not a dir
				throw EXCEPT_DIR_EXISTS_ERROR;
			}

			return (info.st_mode & S_IFDIR) ? true : false;
		}
		void create(std::string path) {
			std::string mkdirstr = "mkdir ";
			system(const_cast<char*>((mkdirstr + path).c_str()));
		}
	}
}
