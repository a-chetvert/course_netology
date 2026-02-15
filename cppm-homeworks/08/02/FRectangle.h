#pragma once
#include "Quadrilateral.h"
#include "Figure.h"

/**
* @brief класс прямоугольник
*/
class FRectangle : public Quadrilateral {
protected:
	stateCheck checkFRect() const;
public:
	FRectangle(int a, int b, int c, int d, int A, int B, int C, int D);
};
