#include "ExceptionFigure.h"

ExceptionFigure::ExceptionFigure(const std::string& message) : message{ message }
{
}

const char* ExceptionFigure::what() const
{
    return message.c_str();
}
