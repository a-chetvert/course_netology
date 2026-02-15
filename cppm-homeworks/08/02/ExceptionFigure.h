#pragma once
#include <iostream>
#include <exception>

class ExceptionFigure :
    public std::exception
{
private:
    std::string message;    ///<сообщение об ошибке
public:
    ExceptionFigure(const std::string& meassge);
    const char* what() const override;
};

