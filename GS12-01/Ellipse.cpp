#include "Ellipse.h"
Ellipse::Ellipse()
{
	radius1 = 0;
	radius2 = 0;
}

Ellipse::Ellipse(float r1, float r2)
{
	radius1 = r1;
	radius2 = r2;
}

Ellipse::Ellipse(Ellipse& c)
{
	radius1 = c.radius1;
	radius2 = c.radius2;
}

void Ellipse::setRadius1(float r1)
{
	radius1 = r1;
}

void Ellipse::setRadius2(float r2)
{
	radius2 = r2;
}

float Ellipse::getRadius1()
{
	return radius1;
}

float Ellipse::getRadius2()
{
	return radius2;
}

float Ellipse::circumference()
{
	return 2 * M_PI * sqrt(radius1 * radius2);
}

float Ellipse::area()
{
	return M_PI * radius1 * radius2;
}