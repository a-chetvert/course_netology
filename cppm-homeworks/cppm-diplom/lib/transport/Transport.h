#pragma once
#include <string>
#include "LibApi.h"

/*
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4275)  // Отключаем предупреждение C4251
#endif
*/

class Transport
{
protected:
	std::string name;
	int speed;

public:
	// хочу сделать конструктор отдельно, чтобы в дальнейшем мог добавить throw
	// но при использовании - выскакивают ошибки
	// LNK2001. LNK2019, LNK1120
	TRANSPORTRACE_API Transport(std::string name, int speed);
	TRANSPORTRACE_API const std::string getName() const;
	TRANSPORTRACE_API virtual double calcTime(int distance) const = 0;
};

