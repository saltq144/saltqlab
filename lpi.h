#pragma once
#if !defined(_WIN32) && (defined(__unix__) || defined(__linux__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
#include <unistd.h>
#else
#include <Windows.h>
#endif

#if !defined(_WIN32) && (defined(__unix__) || defined(__linux__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
void USsleep(int time) {
	usleep(time);
}
#else
void USsleep(int time) {
	Sleep(time / 1000);
}
#endif