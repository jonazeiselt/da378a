#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>

class Strategy
{
public:
	Strategy() {}
	virtual ~Strategy() {}
	virtual int compute(int operand1, int operand2) const = 0;
};

#endif // !STRATEGY_H
