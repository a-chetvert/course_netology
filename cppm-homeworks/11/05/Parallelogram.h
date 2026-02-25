#pragma once
#include "LibApi.h"
#include "Quadrilateral.h"
/**
 * @brief класс параллелограмма
 */
class FIG_API Parallelogram : public Quadrilateral {
public:
    Parallelogram(int a, int b, int A, int B);
};
