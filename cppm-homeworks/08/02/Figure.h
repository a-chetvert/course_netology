#pragma once
#include <iostream>


// можно было определить в отдельном файле, но показалось избыточным
// в figure не использую, но использую в производных классах
enum class stateCheck { allOk, sidesError, engError, allBad };

class Figure {
protected:
	std::string name;  ///< название фигуры

public:
	Figure(std::string name) : name(name) {};
	std::string get_name() const;
	virtual void print_info() const = 0;
	virtual bool check() const = 0;
};

