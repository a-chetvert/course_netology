#pragma once
#include "Quadrilateral.h"
#include "Figure.h"

/**
 * @brief класс квадрата
 */
class Square : public Quadrilateral {
protected:
	stateCheck checkSquare() const;
public:
	Square(int a, int b, int c, int d, int A, int B, int C, int D);
};

