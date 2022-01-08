#pragma once
#define _USE_MATH_DEFINES
#include<math.h>
class Ellipse
{
public:
	Ellipse();
	Ellipse(float r1, float r2);
	Ellipse(Ellipse& c);

	void setRadius1(float r1);
	void setRadius2(float r2);
	float getRadius1();
	float getRadius2();

	float circumference();
	float area();

private:
	float radius1;
	float radius2;
};

