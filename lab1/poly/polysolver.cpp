#include <iostream>
#include "poly2.h"

int main(int argc, char** argv)
{
	float x1 = 0;
	float x2 = 0;
	int nbrOfRoots = 0;
	
	float val;
	int counter = 0;
	
	int a = 0; 
	int b = 0;
	int c = 0;
	
	while (std::cin >> val)
	{
		switch (counter)
		{
			case 0:
			a = val;
			counter++;
			break;
			case 1:
			b = val;
			counter++;
			break;
			case 2:
			c = val;
			std::cout << "Root-finding started..." << std::endl;
			Poly2 myPoly(a, b, c);
			myPoly.findRoots(x1, x2, nbrOfRoots);
	
			std::cout << "Number of roots=" << nbrOfRoots << std::endl;
			switch (nbrOfRoots)
			{
				case 0:
				std::cout << "Roots are imaginary!" << std::endl;
				break;
				case 2:
				std::cout << "x1=" << x1 << ", x2=" << x2 << std::endl;
				std::cout << "eval(" << x1 << ")=" << myPoly.eval(x1) << ", eval(" << x2 << ")=" << myPoly.eval(x2) << std::endl;
				break;
			}
			counter = 0;
			break;
		}
	}
	return 0;
}