#pragma once
#include "Quadrilateral.h"
#include "Figure.h"

/**
 * @brief класс параллелограмма
 */
class Parallelogram : public Quadrilateral {
protected:
	stateCheck checkFRect() const;
public:
    Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D);
};
