/**
 * @brief Задача 2. Динамическая библиотека
 * @note  https://github.com/netology-code/cppm-homeworks/blob/main/11/02
 */

#pragma once

#include <iostream>

#ifdef FRSTDLL_EXPORTS
#define FRSTDLL_API __declspec(dllexport)
#else
#define FRSTDLL_API __declspec(dllimport)
#endif

class Leaver {
public:
	Leaver() {};
	FRSTDLL_API void leave(std::string name);
};

FRSTDLL_API std::string cp1251ToUtf8(const std::string& cp1251Str);

FRSTDLL_API std::string utf8To1251(const std::string& utf8Str);
