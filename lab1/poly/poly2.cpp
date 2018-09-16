#include "poly2.h"
#include <iostream>
#include <cmath>

Poly2::Poly2(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

float Poly2::eval(float x)
{
    return (a*(pow(x, 2)))+(b*x)+c;
}

void Poly2::findRoots(float &x1, float &x2, int &nbrOfRoots)
{
	float d = pow(b, 2) - (4*a*c);
	if (d < 0)
	{
		nbrOfRoots = 0;
	}
	else
	{
		if (d == 0)
		{
			x1 = -(b/(2*a));
			x2 = x1;
		}
		else 
		{ 	// d > 0
			x1 = (-b-sqrt(d))/(2*a);
			x2 = (-b+sqrt(d))/(2*a);
		}
		nbrOfRoots = 2;
	} 
}