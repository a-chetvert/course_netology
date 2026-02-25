#pragma once

#ifdef FIG_EXPORTS
#define FIG_API __declspec(dllexport)
#else
#define FIG_API __declspec(dllimport)
#endif