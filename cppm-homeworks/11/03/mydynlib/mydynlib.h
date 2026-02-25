/**
 * @brief Задача 3. Динамическая библиотека CMake
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/11/03
 */

#pragma once

#include <iostream>

#ifdef MYDYNLIB_EXPORTS
#define MYDYNLIB_API __declspec(dllexport)
#else
#define MYDYNLIB_API __declspec(dllimport)
#endif

class MYDYNLIB_API Leaver {
public:
	Leaver() {};
	void leave(std::string name);
};

MYDYNLIB_API std::string cp1251ToUtf8(const std::string& cp1251Str);

MYDYNLIB_API std::string utf8To1251(const std::string& utf8Str);
