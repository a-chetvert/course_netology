#pragma once
#include <iostream>
#include <string>

class Transport
{
protected:
	std::string name;
	int speed; 

public:
	// хочу сделать конструктор отдельно, чтобы в дальнейшем мог добавить throw
	// но при использовании - выскакивают ошибки
	// LNK2001. LNK2019, LNK1120
	Transport(std::string name, int speed) : name(name), speed(speed) {};
	std::string getName() const;
	virtual double calcTime(int distance) const = 0;
};
