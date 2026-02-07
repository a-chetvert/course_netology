#pragma once
#include <iostream>

class Figure {
protected:
	std::string name;  ///< название фигуры

public:
	Figure(std::string name) : name(name) {};
	std::string get_name() const;
	virtual void print_info() const = 0;
};

