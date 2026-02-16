﻿/**
 * @brief Задача 1. Статическая библиотека
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/11/01
 */

#pragma once
#include <iostream>

class Greeter
{
	public:
	Greeter();
	void greet(std::string name);
};

std::string cp1251ToUtf8(const std::string& cp1251Str);

std::string utf8To1251(const std::string& utf8Str);

