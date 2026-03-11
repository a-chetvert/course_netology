#pragma once

#ifdef TRANSPORTRACE_EXPORTS
#define TRANSPORTRACE_API __declspec(dllexport)
#else
#define TRANSPORTRACE_API __declspec(dllimport)
#endif


#include <iostream>