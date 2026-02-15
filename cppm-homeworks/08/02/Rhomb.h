#pragma once
#include "Quadrilateral.h"
#include "Figure.h"

/**
 * @brief класс ромб
 */
class Rhomb : public Quadrilateral {
protected:
	stateCheck checkRhomb() const;
public:
	Rhomb(int a, int b, int c, int d, int A, int B, int C, int D);
};

